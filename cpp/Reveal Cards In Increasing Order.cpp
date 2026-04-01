#include <vector>
#include <algorithm>
#include <deque>

class Solution {
public:
    std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
        int n = deck.size();
        std::sort(deck.begin(), deck.end());
        
        std::deque<int> indices;
        for (int i = 0; i < n; ++i) {
            indices.push_back(i);
        }
        
        std::vector<int> result(n);
        for (int card : deck) {
            // Place the smallest available card at the front-most available index
            result[indices.front()] = card;
            indices.pop_front();
            
            // If indices remain, move the next available index to the back
            if (!indices.empty()) {
                indices.push_back(indices.front());
                indices.pop_front();
            }
        }
        
        return result;
    }
};
