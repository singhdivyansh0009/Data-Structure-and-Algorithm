// frog jump problem
#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int minEnergy(vector<int>& height, int n,int k) {
    if (n == 0) return 0;
    int minE = INT_MAX;
    int jump;
    for(int i = 1; i <= k; i++){
        if(n-i >= 0)
        jump = minEnergy(height, n - i,k) + abs(height[n] - height[n - i]);
        minE = min(minE,jump);
    }
    return minE;
}

int main() {
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;
    vector<int> height(n);
    cout << "Enter the height of stairs: ";
    for (int i = 0; i < n; i++)
        cin >> height[i];
    int k;
    cout << "Enter the max no. of steps:";
    cin >> k;
    cout << "Minimum energy required: " << minEnergy(height, n - 1,k);

    return 0;
}
