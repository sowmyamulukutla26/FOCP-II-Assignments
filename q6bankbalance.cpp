#include<iostream>
#include<unordered_map>
using namespace std;

class Bank {
    unordered_map<int, long long> accounts;

public:
    bool create(int x, long long y) {
        if (accounts.find(x) != accounts.end()) {
            accounts[x] += y;
            return false;
        }
        accounts[x] = y;
        return true;
    }

    bool debit(int x, long long y) {
        if (accounts.find(x) == accounts.end() || accounts[x] < y)
            return false;
        accounts[x] -= y;
        return true;
    }

    bool credit(int x, long long y) {
        if (accounts.find(x) == accounts.end())
            return false;
        accounts[x] += y;
        return true;
    }

    long long balance(int x) {
        if (accounts.find(x) == accounts.end())
            return -1;
        return accounts[x];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    Bank bank;

    while (q--) {
        string query;
        cin >> query;

        if (query == "CREATE") {
            int x;
            long long y;
            cin >> x >> y;
            cout << (bank.create(x, y) ? "true" : "false") << "\n";
        }
        else if (query == "DEBIT") {
            int x;
            long long y;
            cin >> x >> y;
            cout << (bank.debit(x, y) ? "true" : "false") << "\n";
        }
        else if (query == "CREDIT") {
            int x;
            long long y;
            cin >> x >> y;
            cout << (bank.credit(x, y) ? "true" : "false") << "\n";
        }
        else if (query == "BALANCE") {
            int x;
            cin >> x;
            cout << bank.balance(x) << "\n";
        }
    }

    return 0;
}
