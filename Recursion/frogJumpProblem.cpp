// frog jump problem
#include <iostream>
#include <vector>
#include<climits>
using namespace std;

int minEnergy(vector<int>& height, int n) {
    if (n == 0) return 0;
    int oneStep = minEnergy(height, n - 1) + abs(height[n] - height[n - 1]);  
    int twoStep = INT_MAX;
    if (n > 1)
        twoStep = minEnergy(height, n - 2) + abs(height[n] - height[n - 2]);
    return min(oneStep, twoStep);
}

int main() {
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;
    vector<int> height(n);
    cout << "Enter the height of stairs: ";
    for (int i = 0; i < n; i++)
        cin >> height[i];
    cout << "Minimum energy required: " << minEnergy(height, n - 1);

    return 0;
}
