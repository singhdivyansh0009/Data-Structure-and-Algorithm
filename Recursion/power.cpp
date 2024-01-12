#include<iostream>
using namespace std;

void getAns(double x, int n,double &ans){
     if(n==0)
        return;
     ans *= x;
     getAns(x, n-1,ans);
}
double myPow(double x, int n) {
    double ans=1;
    getAns(x, abs(n),ans);
    return n>=0 ? ans : (1/ans);
}
int main(){
  int a,b;
  cout << "Enter the base";
  cin >> a;
  cout << "Enter the power";
  cin >> b;
  mypow(a,b);
}
