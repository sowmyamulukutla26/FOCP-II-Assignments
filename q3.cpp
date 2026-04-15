#include <iostream>
using namespace std;

// XOR of numbers from 1 to n has a pattern!
long long xorUpTo(long long n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;  // n % 4 == 3
}

int main() {
    long long l, r;
    cin >> l >> r;
    
    // XOR from L to R = XOR(1..R) ^ XOR(1..L-1)
    long long result = xorUpTo(r) ^ xorUpTo(l - 1);
    
    if (result % 2 == 0)
        cout << "even" << endl;
    else
        cout << "odd" << endl;
}
