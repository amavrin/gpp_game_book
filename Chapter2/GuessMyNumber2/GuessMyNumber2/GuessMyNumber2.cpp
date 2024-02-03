#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;


void err(string s)
{
    cerr << "ERROR: " << s << endl;
    exit(1);
}

int rnd_between(int lower, int upper)
{
    if (upper <= lower)
    {
        stringstream msg;
        msg << "upper (" << upper << ") in equal or less than lower (" << lower << ")";
        err(msg.str());
    }
    int r = rand() % (upper - lower) + lower;
    return r;
}

enum guessRes { GUESS_TOO_LOW = 1, GUESS_TOO_HIGH, GUESS_OK, GUESS_INITIAL };

int ask_user(int g)
{
    cout << "My guess is " << g << endl;
    cout << "   " << GUESS_TOO_LOW << " - too low; " << GUESS_TOO_HIGH << " - too high; " << GUESS_OK << " - OK" << endl;

    int resp;
    cin >> resp;
    return resp;
}

void guess(int low, int high)
{
    cout << "Choose number between " << low << " and " << high << ", press a key when ready..." << endl;
    cin.get();

    int responce = GUESS_INITIAL;

    while (responce != GUESS_OK)
    {
        int g = rnd_between(low, high);
        responce = ask_user(g);

        switch (responce)
        {
        case GUESS_TOO_HIGH:
            high = g - 1;
            break;
        case GUESS_TOO_LOW:
            low = g + 1;
            break;
        case GUESS_OK:
            break;
        default:
            cout << "invalid responce" << endl;
            break;
        }
    }
}

int main()
{
    srand(time(0));
    int low = 0, high = 100;

    guess(low, high);
}
