#include <bits/stdc++.h>
using namespace std;

string solve(int N, vector<int>& A) {
    sort(A.begin(), A.end(), greater<int>());
    
    set<int> seen;
    long long alex = 0, bob = 0;
    int turn = 0; // 0 = Alex, 1 = Bob
    
    for (int val : A) {
        if (seen.count(val)) continue; // skip already-consumed quantity
        seen.insert(val);
        if (turn == 0) alex += val;
        else bob += val;
        turn = 1 - turn;
    }
    
    return alex > bob ? "Alex" : "Bob";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        cout << solve(N, A) << "\n";
    }
    return 0;
}
