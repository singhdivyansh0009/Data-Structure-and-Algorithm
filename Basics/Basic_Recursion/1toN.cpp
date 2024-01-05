void getOutput(int x,vector<int>&result){
    if(x==0)
      return;
    getOutput(x-1, result);
    result.push_back(x);
}

vector<int> printNos(int x) {
     vector<int>result;
     getOutput(x,result);
     return result;
}
