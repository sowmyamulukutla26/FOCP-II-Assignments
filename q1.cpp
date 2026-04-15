#include <iostream>
using namespace std;

int main() {
    int n, k;
    string bulbs;
    cin >> n >> k >> bulbs;
    
    int lo = 1, hi = n, ans = n;
    
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        
        // Check if l = mid works
        string b = bulbs;
        int ops = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] == '1') {
                ops++;
                for (int j = i; j < min(n, i + mid); j++)
                    b[j] = '0';
            }
        }
        
        if (ops <= k) {
            ans = mid;
            hi = mid - 1;  // try smaller l
        } else {
            lo = mid + 1;  // need bigger l
        }
    }
    
    cout << ans << endl;
}
