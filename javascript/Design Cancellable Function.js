/**
 * @param {Generator} generator
 * @return {Array}
 */
var cancellable = function(generator) {
    let cancel;
    const cancelPromise = new Promise((_, reject) => {
        cancel = () => reject("Cancelled");
    });

    const promise = (async () => {
        let next = generator.next();
        
        while (!next.done) {
            try {
                // Wait for either the yielded promise or a cancel call
                const val = await Promise.race([next.value, cancelPromise]);
                next = generator.next(val);
            } catch (e) {
                // If cancelled or promise rejected, throw error back into generator
                try {
                    next = generator.throw(e);
                } catch (err) {
                    // If generator doesn't catch the error, rethrow to reject outer promise
                    throw err;
                }
            }
        }
        return next.value;
    })();

    return [cancel, promise];
};
