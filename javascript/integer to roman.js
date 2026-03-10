/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    const valMap = [
        [1000, "M"], [900, "CM"], [500, "D"], [400, "CD"],
        [100, "C"], [90, "XC"], [50, "L"], [40, "XL"],
        [10, "X"], [9, "IX"], [5, "V"], [4, "IV"], [1, "I"]
    ];
    
    let result = "";
    
    for (let [value, symbol] of valMap) {
        // While the current number is larger than the Roman value, 
        // append the symbol and subtract the value.
        while (num >= value) {
            result += symbol;
            num -= value;
        }
    }
    
    return result;
};
