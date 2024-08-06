#include <iostream>
#include <vector>
#include<climits>
using namespace std;

void subSequence(vector<int>& arr, int i,int n, vector<int>& sub) {
   if(i == n)
   {
       for(auto i : sub)
          cout << i  << " ";
       cout << endl;
       return;
   }
   sub.push_back(arr[i]);  // pick the element in subsequence
   subSequence(arr,i+1,n,sub);
   sub.pop_back(); 
   subSequence(arr,i+1,n,sub); // don't pick the element
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int>sub;
    subSequence(arr, 0 ,n, sub);

    return 0;
}
