#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
    srand(time(0));

    string name;
    cout << "Enter your name: ";
    cin >> name;

    vector<string> excuses = {
        " couldn't finish the assignment because the laptop decided to install updates for 6 hours.",
        " was about to submit when the Wi-Fi mysteriously disappeared.",
        " tried finishing the homework but the computer keyboard stopped cooperating.",
        " couldn't complete the assignment because the laptop battery died unexpectedly.",
        " tried finishing the homework, but the internet stopped working.",
        " was ready to submit when the file mysteriously disappeared.",
        "'s dog sat on the keyboard and deleted everything.",
        " submitted on time but the portal said 'file too large' for a 2KB document.",
        " had the assignment done but accidentally saved it as .exe.",
        " couldn't focus because the neighbour was on a 6-hour call."
    };

    int index = rand() % excuses.size();
    cout << "\nExcuse: " << name << excuses[index] << endl;

    return 0;
}
