// frog jump problem
#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int minEnergy(vector<int>& height, int n,vector<int>&dp) {
    if (n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int oneStep = minEnergy(height, n - 1,dp) + abs(height[n] - height[n - 1]);  
    int twoStep = INT_MAX;
    if (n > 1)
        twoStep = minEnergy(height, n - 2,dp) + abs(height[n] - height[n - 2]);
    return dp[n] = min(oneStep, twoStep);
}

int main() {
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;
    vector<int> height(n);
    cout << "Enter the height of stairs: ";
    for (int i = 0; i < n; i++)
        cin >> height[i];
    vector<int>dp(n+1,-1);
    cout << "Minimum energy required: " << minEnergy(height, n - 1,dp);

    return 0;
}
