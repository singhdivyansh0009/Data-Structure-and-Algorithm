#include <iostream>
#include <vector>
using namespace std;

void getSubsequences(vector<int>& a, vector<vector<int>>& sub, vector<int>& temp, int i, int n) {
    if (i == n) {
        sub.push_back(temp);
        return;
    }
    temp.push_back(a[i]);
    getSubsequences(a, sub, temp, i + 1, n);
    temp.pop_back();
    getSubsequences(a, sub, temp, i + 1, n);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> temp;
    vector<vector<int>> sub;
    getSubsequences(a, sub, temp, 0, n);

    vector<vector<int>> ans;

    for (auto& i : sub) {
        int prev = -100;
        int flag = 1;
        for (auto& j : i) {
            if (j < prev) {
                flag = 0;
                break;
            }
            prev = j;
        }
        if (flag == 1)
           ans.push_back(i);
    }

    for (auto& i : ans) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
