
#include <bits/stdc++.h>
using namespace std;

// Approach with O(nlogn) time complexity
int majorityElement(vector<int> v) {
  sort(v.begin(), v.end());
  int n = v.size();
  if(n==1) return v[0];
  int count = 1;
  int ans;
  for (int i = 0; i < n - 1; i++){
	  if(v[i]!=v[i+1])
	     count = 1;
	  else
		  count++;
          if (count > (n / 2)) {
                  ans = v[i];
                  break;
          }
  }
  return ans;
}

// Applying Moore's voting algorithm O(n) time complexity
int majorityElement(vector<int> v) {
    //size of the given array:
    int n = v.size();
    int cnt = 0; // count
    int el; // Element

    //applying the algorithm:
    for (int i = 0; i < n; i++) {
        if (cnt == 0) {
            cnt = 1;
            el = v[i];
        }
        else if (el == v[i]) cnt++;
        else cnt--;
    }

    //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == el) cnt1++;
    }

    if (cnt1 > (n / 2)) return el;
    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}
