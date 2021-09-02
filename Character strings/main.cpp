// main.cpp
// Лабораторная работа №1.
// Символьные строки
// Задан текст. В каждом слове текста оставить 
// на своих местах первую и последнюю буквы, а 
// в середине слова буквы перемешать.
// Студент группы 484, Левинский Илья Владимирович. 2021 год

#include <iostream>
#include <ctime>
#include "interface.h"
#include "menu_items.h"
using namespace std;

int main() {
	 setlocale(LC_ALL, "Russian");
	 system("chcp 1251");
	 srand((unsigned)time(nullptr));
	 workWithMenu();
	 cout << "Good bye!";
	 return (0);
}
