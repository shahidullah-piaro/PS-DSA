//https://www.interviewbit.com/problems/max-distance/
#include <bits/stdc++.h>

using namespace std;

int maximumGap(const vector<int>& A) {
    int n=A.size();
    int mx=-1;
    vector<pair<int,int>>v;
    for(int i=n-1;i>=0;i--){
    v.push_back(make_pair(A[i],i));
    }
    sort(v.begin(),v.end());
    int mn=INT_MAX;
    int ans=0;
    for(int i=0;i<n;i++){
    mn=min(mn,v[i].second);
    ans=max(ans,v[i].second-mn);
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter the elements (space-separated): ";
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int max_gap = maximumGap(A);
    cout << "The maximum gap in the sorted array is: " << max_gap << endl;

    return 0;
}

