/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let hasBeenCalled = false;
    
    return function(...args){
        if (!hasBeenCalled) {
            hasBeenCalled = true;
            return fn(...args);
        }
        return undefined;
    }
};
