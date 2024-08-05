/* Time complexity : O(n) Space complexity : O(n) */
#include <iostream>
#include <vector>
using namespace std;
int fibo(int n,vector<int>&dp){
    if(n <= 1){
      return  n;
    }
    if(dp[n] != -1)  // if subproblem is already solved return the answer for that problem
       return dp[n]; 
    else
      return dp[n] = fibo(n-1,dp) + fibo(n-2,dp);  // store the answer for the subproblem
}
int main() {
    int n;
    cin >> n;
    vector<int>dp(n+1,-1); // array to store the solution of subproblems
    cout << fibo(n,dp);
    return 0;
}
