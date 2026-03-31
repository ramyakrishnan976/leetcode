#include <vector>
#include <stack>

class NestedIterator {
private:
    // Stack stores pairs of [current_iterator, end_iterator]
    stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> iterStack;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Push the begin and end iterators of the initial list
        iterStack.push({nestedList.begin(), nestedList.end()});
    }
    
    int next() {
        // hasNext() is always called before next(), so the top is guaranteed to be an integer
        int val = iterStack.top().first->getInteger();
        iterStack.top().first++;
        return val;
    }
    
    bool hasNext() {
        while (!iterStack.empty()) {
            auto& top = iterStack.top();
            
            // 1. If current iterator reached the end of its list, pop it
            if (top.first == top.second) {
                iterStack.pop();
                continue;
            }
            
            // 2. If the current element is an integer, we are ready
            if (top.first->isInteger()) {
                return true;
            }
            
            // 3. If it's a list, move the pointer forward and push the sub-list
            vector<NestedInteger> &subList = top.first->getList();
            top.first++;
            iterStack.push({subList.begin(), subList.end()});
        }
        return false;
    }
};
