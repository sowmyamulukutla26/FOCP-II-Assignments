#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class MovieTicket {
    unordered_map<int, unordered_set<int>> bookings;
    unordered_map<int, int> available;
    const int MAX_SLOTS = 100;

public:
    bool book(int x, int y) {
        if (available.find(y) == available.end())
            available[y] = MAX_SLOTS;
        if (bookings[y].count(x) || available[y] == 0)
            return false;
        bookings[y].insert(x);
        available[y]--;
        return true;
    }

    bool cancel(int x, int y) {
        if (!bookings[y].count(x))
            return false;
        bookings[y].erase(x);
        available[y]++;
        return true;
    }

    bool isBooked(int x, int y) {
        return bookings[y].count(x) > 0;
    }

    int availableTickets(int y) {
        if (available.find(y) == available.end())
            return MAX_SLOTS;
        return available[y];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    MovieTicket mt;

    while (q--) {
        string query;
        cin >> query;

        if (query == "BOOK") {
            int x, y;
            cin >> x >> y;
            cout << (mt.book(x, y) ? "true" : "false") << "\n";
        }
        else if (query == "CANCEL") {
            int x, y;
            cin >> x >> y;
            cout << (mt.cancel(x, y) ? "true" : "false") << "\n";
        }
        else if (query == "IS_BOOKED") {
            int x, y;
            cin >> x >> y;
            cout << (mt.isBooked(x, y) ? "true" : "false") << "\n";
        }
        else if (query == "AVAILABLE_TICKETS") {
            int y;
            cin >> y;
            cout << mt.availableTickets(y) << "\n";
        }
    }

    return 0;
}
