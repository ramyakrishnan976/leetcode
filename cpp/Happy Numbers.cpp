class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do {
            slow = getNext(slow);           // Moves 1 step
            fast = getNext(getNext(fast));   // Moves 2 steps
        } while (slow != fast);

        // If they meet at 1, the number is happy
        return slow == 1;
    }

private:
    int getNext(int num) {
        int total_sum = 0;
        while (num > 0) {
            int digit = num % 10;
            total_sum += digit * digit;
            num /= 10;
        }
        return total_sum;
    }
};
