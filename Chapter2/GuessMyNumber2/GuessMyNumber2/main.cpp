#include "guess_my_number.h"

int main()
{
    srand(time(0));
    int low = 0, high = 100;

    guess(low, high);
}