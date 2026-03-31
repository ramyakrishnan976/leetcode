#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.length(), n = target.length();
        vector<int> res;
        vector<bool> visited_window(n - m + 1, false);
        vector<bool> visited_char(n, false);
        int total_stamped = 0;

        // windows[i] tracks which characters in target[i...i+m-1] 
        // still need to be matched to the stamp.
        struct Window {
            unordered_set<int> made, todo;
        };
        vector<Window> A(n - m + 1);
        queue<int> q;

        for (int i = 0; i <= n - m; ++i) {
            for (int j = 0; j < m; ++j) {
                if (target[i + j] == stamp[j]) {
                    A[i].made.insert(i + j);
                } else {
                    A[i].todo.insert(i + j);
                }
            }
            // If todo is empty, this window is a perfect match
            if (A[i].todo.empty()) {
                res.push_back(i);
                visited_window[i] = true;
                for (int j = 0; j < m; ++j) {
                    if (!visited_char[i + j]) {
                        visited_char[i + j] = true;
                        q.push(i + j);
                        total_stamped++;
                    }
                }
            }
        }

        // Process characters that have been "cleared" (turned into ?)
        while (!q.empty()) {
            int i = q.front(); q.pop();

            // Check all windows that cover this character
            for (int j = max(0, i - m + 1); j <= min(i, n - m); ++j) {
                if (A[j].todo.count(i)) {
                    A[j].todo.erase(i);
                    if (A[j].todo.empty() && !visited_window[j]) {
                        visited_window[j] = true;
                        res.push_back(j);
                        for (int k = 0; k < m; ++k) {
                            if (!visited_char[j + k]) {
                                visited_char[j + k] = true;
                                q.push(j + k);
                                total_stamped++;
                            }
                        }
                    }
                }
            }
        }

        if (total_stamped != n) return {};
        reverse(res.begin(), res.end());
        return res;
    }
};
