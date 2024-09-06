#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& cost, int k) {
    unordered_map<int, int> mpp;

    for (int i = 0; i < cost.size(); i++) {
        int complement = k - cost[i];

        if (mpp.find(complement) != mpp.end()) {
            return {mpp[complement] + 1, i + 1}; // 1-based indexing
        }

        mpp[cost[i]] = i;
    }

    return {};
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int m, n;
        cin >> m >> n;
        
        vector<int> cost(n);
        for (int i = 0; i < n; i++) {
            cin >> cost[i];
        }

        vector<int> result = twoSum(cost, m);
        if (!result.empty()) {
            cout << result[0] << " " << result[1] << endl;
        }
    }

    return 0;
}

