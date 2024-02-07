#include "guess_my_number.h"

func_status rnd_between(int lower, int upper, int &res)
{
    if (upper < lower)
    {
        stringstream msg;
        msg << "upper (" << upper << ") in equal or less than lower (" << lower << ")";
        return(FUNC_ERR);
    }
    if (upper == lower) {
        res = upper;
        return FUNC_OK;
    }
    res = rand() % (upper - lower) + lower;
    return FUNC_OK;
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
        int rnd_res;
        func_status g = rnd_between(low, high, rnd_res);
        if (g == FUNC_ERR) {
            cerr << "rnd_between returned error";
            exit(1);
        }
        responce = ask_user(rnd_res);

        switch (responce)
        {
        case GUESS_TOO_HIGH:
            high = rnd_res - 1;
            break;
        case GUESS_TOO_LOW:
            low = rnd_res + 1;
            break;
        case GUESS_OK:
            break;
        default:
            cout << "invalid responce" << endl;
            break;
        }
    }
}
