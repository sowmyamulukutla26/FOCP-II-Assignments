#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
    srand(time(0)); // seed for random

    string name;
    cout << "Enter your name: ";
    cin >> name;

    // 10 roast templates with {name} placeholder
    vector<string> roasts = {
        " writes code so slow that even a turtle switched to Python.",
        "'s debugging style is staring at the screen until the bug gets embarrassed and leaves.",
        " doesn't debug code — they negotiate with bugs.",
        "'s code runs so slowly that even dial-up internet feels fast.",
        " asked Google 'how to exit vim' and Google said 'good luck'.",
        " thinks 'clean code' means wiping the screen with a cloth.",
        " once pushed to main and called it 'agile development'.",
        "'s WiFi password is their only original idea.",
        " has more Stack Overflow tabs open than brain cells.",
        " calls a typo 'an undocumented feature'."
    };

    // Randomly pick one roast
    int index = rand() % roasts.size();
    cout << "\nRoast: " << name << roasts[index] << endl;

    return 0;
}
