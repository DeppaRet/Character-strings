#include <iostream>
#include <fstream>
#include <string>
#include "interface.h"
#include "mixer.h"
using namespace std;

enum user—hoice { About = 1, Start, Exit, Yes = 1, No, Work = 0, Die = 6 };


int workWithMenu() {
	 int menu;
	 int user—hoice;
	 programInterface();
	 for (user—hoice = Work; user—hoice < Die; user—hoice++) {
			cin >> user—hoice;
			menu = check(user—hoice);

			switch (menu) {
			case About: { // About
				 about();
				 if (nextStep() == 0)
						return(0);
			}

			case Start: { // Start
				 inputType();
				 if (nextStep() == 0)
						return(0);
			}

			case Exit: {	// Exit
				 return (0);
			}
			default: {
				 cout << "Not a valid chooice. Please choose again" << endl;
				 user—hoice = 0;
				 continue;
			}
			}
			if (nextStep() == 0)
				 return 0;
			workWithMenu();
	 }
	 return 0;
}
