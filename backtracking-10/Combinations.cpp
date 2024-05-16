//https://www.interviewbit.com/problems/combinations/
#include <bits/stdc++.h>

using namespace std;

void solve(int ind,vector<int>&arr,vector<int>&res,vector<vector<int>>&ans,int k){
    if(res.size()==k){
    ans.push_back(res);
    return;
    }
    for(int i=ind;i<arr.size();i++){
    res.push_back(arr[i]);
    solve(i+1,arr,res,ans,k);
    res.pop_back();
    }
}

vector<vector<int>> combine(int A, int B) {
  vector<int> arr;
  for (int i = 1; i <= A; i++) {
    arr.push_back(i);
  }
  vector<vector<int>> ans;
  vector<int> res;
  solve(0, arr, res, ans, B);
  return ans;
}

int main() {
  int A, B;
  cout << "Enter the value of A: ";
  cin >> A;
  cout << "Enter the value of B: ";
  cin >> B;

  vector<vector<int>> combinations = combine(A, B);

  cout << "All combinations of size " << B << " from 1 to " << A << " are: \n";
  for (const vector<int>& combi : combinations) {
    for (int num : combi) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}
