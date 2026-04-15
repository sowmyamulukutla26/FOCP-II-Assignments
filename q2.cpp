#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;
        
        int count = 0;
        
        // find all divisor pairs of n
        for (long long x = 1; x * x <= n; x++) {
            if (n % x == 0) {
                long long y = n / x;
                
                // check if gcd is 1
                if (__gcd(x, y) == 1) {
                    if (x == y)
                        count += 1;  // same pair
                    else
                        count += 2;  // (x,y) and (y,x)
                }
            }
        }
        
        cout << count << "\n";
    }
}
