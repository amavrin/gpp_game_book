// Menu Chooser
// Demostartes the switch statement

#include <iostream>

using namespace std;

enum diffLevel {DL_EASY = 1, DL_NORMAL, DL_HARD};

int main() {
	cout << "Difficulty\n\n";
	cout << DL_EASY << " - Easy\n";
	cout << DL_NORMAL << " - Normal\n";
	cout << DL_HARD << " - Hard\n\n";

	int choice;
	cout << "Choice: ";
	cin >> choice;

	switch (choice) {
	case DL_EASY:
		cout << "You picked Easy. \n";
		break;

	case DL_NORMAL:
		cout << "You picked Normal.\n";
		break;

	case DL_HARD:
		cout << "You picked Hard.\n";
		break;

	default:
		cout << "You made an illegal choice.\n";
	}

	return 0;
}