#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int factorial = 1;
        vector<int> numbers;
        
        // 1. Calculate (n-1)! and fill the numbers list
        for (int i = 1; i < n; i++) {
            factorial *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        
        // 2. Adjust k to be 0-indexed for easier math
        k--; 
        
        string result = "";
        for (int i = n - 1; i >= 0; i--) {
            // 3. Find the index of the current digit
            int index = k / factorial;
            result += to_string(numbers[index]);
            
            // 4. Remove used number
            numbers.erase(numbers.begin() + index);
            
            // 5. Update k and factorial for the next position
            if (i > 0) {
                k %= factorial;
                factorial /= i;
            }
        }
        
        return result;
    }
};
