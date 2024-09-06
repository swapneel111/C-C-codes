#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        // Initialize a vector of vectors to store the indices of each letter in the alphabet
        vector<vector<int>> d(26, {-1});
        
        // Fill the vector with indices where each letter appears
        for (int i = 0; i < s.size(); ++i) {
            d[s[i] - 'A'].push_back(i);
        }
        
        int ans = 0;
        // Iterate over each letter's index vector
        for (auto& v : d) {
            v.push_back(s.size());
            for (int i = 1; i < v.size() - 1; ++i) {
                // Calculate the contribution of each position
                ans += (v[i] - v[i - 1]) * (v[i + 1] - v[i]);
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "ABC";
    cout << "Output: " << sol.uniqueLetterString(s) << endl;
    return 0;
}

