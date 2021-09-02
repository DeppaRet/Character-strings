#include <iostream>
#include "menu_items.h"
#include "interface.h"
using namespace std;

enum iter {Zero = 0, Yes, No};

void about() {
	 cout << "Task: In each word of the text, leave the first and the last letter, and in the middle of the word the letters mix. \nMade by a 4th year student of gr 484: Leviskiy Ilya";
	 cout << endl;
}


void programInterface() {
	 cout << "___________________________________________\n";
	 cout << "********|-----------MENU----------|********\n";
	 cout << "*******************************************\n";
	 cout << "*******|     What's your choice    |*******";
	 cout << "\n*******************************************\n";
	 cout << "* 1. About                                *\n";
	 cout << "* 2. Start                                *\n";
	 cout << "* 3. Exit                                 *\n";
	 cout << "*******************************************\n";
}

int check(int user—hoice) {
	 while (cin.fail()) {
			if (user—hoice <= Zero) {
				 cout << "Enter only a valid choose please. Try again." << endl;
				 cin.clear();
				 cin.ignore(INT_MAX, '\n');
				 user—hoice = 0;
				 cin >> user—hoice;
			}
	 }
	 return (user—hoice);
}

int nextStep() {
	 int user—hoice = 0;
	 cout << endl << "What's next?" << endl;
	 cout << "1. Menu" << endl;
	 cout << "2. Exit" << endl;
	 cin >> user—hoice;
	 user—hoice = check(user—hoice);
	 if (user—hoice == Yes)
			workWithMenu();
	 else if (user—hoice == No)
			return (0);
	 else {
			cout << "Wrong choice. Enter only a valid choose" << endl;
			nextStep();
	 }
	 return (0);
}