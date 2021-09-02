#include <iostream>
#include <fstream>
#include <string>
#include "interface.h"
#include "fileExec.h"
using namespace std;

enum userChoice { Yes = 1, No };


bool validateName(string filePath) {
   string restrictedSymbols[] = { "<", ">", "/", "|", "?", "*", };
   string restrictedNames[] = { "con", "prn", "aux", "nul", "com1", "com2", "com3", "com4", "com5", "com6", "com7",
                                       "com8", "com9", "lpt1", "lpt2", "lpt3", "lpt4", "lpt5", "lpt6", "lpt7", "lpt8", "lpt9" };
   string copyOfPath = filePath;
   for (int i = 0; i != filePath.length(); i++) {
      copyOfPath[i] = tolower(filePath[i]);
   }

   int restrictedSymbolsSize = sizeof(restrictedSymbols) / sizeof(restrictedSymbols[0]);
   int restrictedNamesSize = sizeof(restrictedNames) / sizeof(restrictedNames[0]);
   for (int i = 0; i != restrictedSymbolsSize; ++i) {
      if (string::npos != copyOfPath.find(restrictedSymbols[i]))
         return false;
   }
   for (int i = 0; i != restrictedNamesSize; ++i) {
      if (copyOfPath == restrictedNames[i])
         return false;
   }
   return true;
}


string checkFileName(string filePath) {
   int rewrite;
   while (validateName(filePath) == false) {
      cout << "Invalid file name. Input new name: ";
      cin >> filePath;
   }
   if (ofstream(filePath, ios::out | ios::_Nocreate)) {
      cout << "File with this name already exists. Type 1 to overwrite and 2 to enter a different name: " << endl;
      cin >> rewrite;
      check(rewrite);
      if (rewrite == No) {
         cout << "Enter new name for file:" << endl;
         cin >> filePath;
         checkFileName(filePath);
      }
      else if (rewrite == Yes)
         return(filePath);
   }
   return (filePath);
}




void saveFile(string text, string type) {
   int choose = 0;
   cout << endl << "Do you want to save " + type + " file?" << endl;
   cout << "1. Yes" << endl;
   cout << "2. No" << endl;
   cin >> choose;
   choose = check(choose);
   while (choose != Yes && choose != No) {
      cout << "Wrong choice. Enter only a valid choose" << endl;
      cin >> choose;
      choose = check(choose);
   }
   if (choose == Yes)
   {
      ofstream out;
      string filePath;
      cout << "Enter the path to the file and its name: " << endl;
      cin >> filePath;
      checkFileName(filePath);
      out.open(filePath);
      out << text << endl;
      cout << "File saved successfully" << endl;
      out.close();
   }
   return;
}