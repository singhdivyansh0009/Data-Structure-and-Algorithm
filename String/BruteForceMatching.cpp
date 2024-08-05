/* Brute force approach for the pattern matching in string */
#include <iostream>
using namespace std;
int isContains(string txt,string pat){
    int m = txt.length(); // length of the text
    int n = pat.length(); // length of the pattern
    for(int i = 0; i <= m-n; i++){  
        int j;
        for(j = 0; j < n; j++){
            if(txt[i+j] != pat[j])  // if char does'nt match no need to check futher
                break;
        }
        if(j == n)  // if loop is complete means the Pattern matched
            return i;
    }
    return -1;
}
int main()
{
    string txt,pat;
    cin >> txt >> pat;
    int ans = isContains(txt,pat);
    (ans != -1) ? cout << "Pattern present at " << ans : cout << "No matching";
    return 0;
}
