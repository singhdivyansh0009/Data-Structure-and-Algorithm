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

    vector<int>ans;
    int max = -1;
    for (auto& i : sub) {
        int prev = -100;
        int flag = 1;
        int count = 0;
        for (auto& j : i) {
            if (j < prev) {
                flag = 0;
                break;
            }
            prev = j;
        }
        if (flag == 1 && count > max){
            ans = i;
            max = count;
        }
           
    }

    for (auto& i : ans) {
        cout << i << " ";
    }

    return 0;
}
