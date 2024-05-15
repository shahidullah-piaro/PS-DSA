//https://www.interviewbit.com/problems/distribute-candy/
#include <bits/stdc++.h>

using namespace std;

int candy(vector<int> &ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1); // Initialize all candies to 1

    // One-pass approach for efficiency
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && candies[i] < candies[i + 1] + 1) {
            candies[i] = candies[i + 1] + 1;
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += candies[i];
    }

    return sum;
}

int main() {
    int n;
    cout << "Enter the number of ratings: ";
    cin >> n;

    vector<int> ratings(n);
    cout << "Enter the ratings (space-separated): ";
    for (int i = 0; i < n; i++) {
        cin >> ratings[i];
    }

    int totalCandies = candy(ratings);
    cout << "Minimum number of candies to distribute: " << totalCandies << endl;

    return 0;
}

