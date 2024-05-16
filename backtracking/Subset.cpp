//https://www.interviewbit.com/problems/subset/
#include <bits/stdc++.h>

using namespace std;

void find(vector<int>& A, vector<vector<int>>& ans, vector<int>& temp, int indx) {
  if (indx == A.size()) {
    ans.push_back(temp);
    return;
  }

  // Exclude current element
  find(A, ans, temp, indx + 1);

  // Include current element
  temp.push_back(A[indx]);
  find(A, ans, temp, indx + 1);
  temp.pop_back();
}

vector<vector<int>> subsets(vector<int>& A) {
    sort(A.begin(),A.end());
    vector<vector<int>> ans;
    vector<int> temp;
    int indx=0;
    find(A,ans,temp,indx);
    sort(ans.begin(),ans.end());
    return ans;
}

int main() {
  int n;
  cout << "Enter the size of the set: ";
  cin >> n;

  vector<int> A;
  cout << "Enter the elements of the set:\n";
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    A.push_back(num);
  }

  vector<vector<int>> all_subsets = subsets(A);

  cout << "All subsets:\n";
  for (int i = 0; i < all_subsets.size(); i++) {
    cout << "{ ";
    for (int j = 0; j < all_subsets[i].size(); j++) {
      cout << all_subsets[i][j] << " ";
    }
    cout << "}\n";
  }

  return 0;
}
