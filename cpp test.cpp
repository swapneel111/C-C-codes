#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> g1;
    vector<int> g2;

    // Input numbers into g1
    for(int i = 0; i < 10; i++) {
        int num;
        cin >> num;
        g1.push_back(num);
    }

    // Copy elements from g1 to g2
    for(auto it : g1) {
        g2.push_back(it);
    }

    // Output elements of g2
    for(auto it : g2) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}

