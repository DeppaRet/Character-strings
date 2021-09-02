#include <iostream>
#include "interface.h"
#include <fstream>
#include <string>
#include <algorithm>
#include "fileExec.h"
using namespace std;

enum user—hoice { File = 1, Manual, Exit, Yes = 1, No, End = 10};


string mix(const string &input) {
	 int size = input.size();
	 cout << endl << "Input: " << input << endl;
	 string tmp;
	 string result;
	 for (int i = 0; i <= size; i++) {
			if (input[i] == ' ' || input[i] == '\0' || input[i] =='\t' || input[i] == '\n' ) {
				 if (tmp.size() == 1) {
						result += tmp + " ";
						tmp = "";
						continue;
				 }
				 random_shuffle(tmp.begin() + 1, tmp.end() - 1);
				 result += tmp + " ";
				 tmp = "";
				 continue;
			}
			
			if (tmp == "" && input[i] == ' ') {
				 continue;
			}
			tmp += input[i];
	 }
	 cout << "Result: " << result << endl;
	 saveFile(input, "original");
	 saveFile(result, "result");
	 return input;
}

void inputType() {
	 setlocale(LC_ALL, "Russian");
	 int user—hoice = 0;
	 string input;
	 string manualInput;
	 string fileName;
	 cout << endl << "Choose input type:" << endl;
	 cout << "1. From file" << endl;
	 cout << "2. Manual input" << endl;
	 cout << "3. Go back" << endl;
	 for (user—hoice = File; user—hoice < End; user—hoice++) {
			cin >> user—hoice;
			user—hoice = check(user—hoice);
			switch (user—hoice)
			{
			case File: {
				 cout << "FileName: ";
				 cin >> fileName;
				 ifstream inf(fileName);
				 if (!inf)
				 {
						cout << "Uh oh, " + fileName + " could not be opened for reading!" << endl;
				 }
				 while (inf)
				 {
						getline(inf, input);
				 }
				 mix(input);
				 return;
			}
			case Manual: {
				 cout << "Manual input: ";
				 getline(cin >> ws, input);
				 cout << endl;
				 mix(input);
				 return;
			}
			case Exit: {
				 return;
			}
			default:
				 cout << "Not a valid chooice. Please choose again" << endl;
				 user—hoice = 0;
				 continue;
			}
	 }
}
