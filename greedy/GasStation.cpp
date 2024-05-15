//https://www.interviewbit.com/problems/gas-station/
#include <bits/stdc++.h>

using namespace std;

int canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int startIndex;
    int n = A.size();
    for(int i = 0; i<n; i++) {
    startIndex = i;
    int gasleft = A[i] -B[i];
    while(gasleft >= 0 && (i - startIndex) < n) {
    gasleft += A[++i%n]-B[i%n];
    }
    if(gasleft >= 0 )
    return startIndex;
    }// end for
    return -1;
}

int main() {
    int n;

    cout << "Enter the number of gas stations (and corresponding costs): ";
    cin >> n;

    vector<int> gas(n), cost(n);

    cout << "Enter the gas available at each station (space-separated): ";
    for (int i = 0; i < n; i++) {
        cin >> gas[i];
    }

    cout << "Enter the cost to travel from each station (space-separated): ";
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    if (canCompleteCircuit(gas, cost)) {
        cout << "A starting circuit can be completed." << endl;
    } else {
        cout << "No starting circuit can be completed." << endl;
    }

    return 0;
}

