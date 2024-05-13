//https://leetcode.com/problems/powx-n
#include <bits/stdc++.h>

using namespace std;

double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0) {
            if(n%2==0)
            {
                double p = myPow(x, n/2);
                return p * p;
            }else{
                return 1.0 / myPow(x, n * -1);
            }
        }
        if(n%2==0){
            double p = myPow(x, n/2);
            return p * p;
        }
        else{
            n = n-1;
            double p = myPow(x, n/2);
            return x * p * p;
        }
    }

int main() {
    double x;
    int n;

    cout << "Enter base value (x): ";
    cin >> x;

    cout << "Enter power value (n): ";
    cin >> n;

    double result = myPow(x, n);

    cout << x << " raised to the power of " << n << " is: " << result << endl;

    return 0;
}
