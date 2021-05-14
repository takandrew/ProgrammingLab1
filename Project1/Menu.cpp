#include<iostream>
#include"Computing.h"
#include"Testing.h"

using namespace std;

// Приветствие
void Greeting() {
	cout << "Эта программа определяет положение заданных прямоугольников на плоскости." << endl;
	cout << "Позволяет определить наличие общей области у заданных прямоугольников." << endl;
	cout << endl;
	cout << "Автор: Кувылькин Андрей" << endl;
	cout << "Группа: 494" << endl;
	cout << "Лабораторная работа №1" << endl;
	cout << "Вариант 10" << endl;
	cout << endl;
}


// Основное меню
bool Menu() {
	enum MenuCase { again = 1, info, testing, finish };
	int variant;
	cout << endl;
	cout << "MENU" << endl;
	cout << "Выберите вариант:" << endl;
	cout << "1. Начать программу заново." << endl;
	cout << "2. Вывести информацию о программе и авторе." << endl;
	cout << "3. Провести тестирование." << endl;
	cout << "4. Выйти из программы." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case again: return true;
	case info: {cout << endl; Greeting(); return Menu(); }
	case testing: {TestingModules(); return Menu(); }
	case finish: {cout << "Программа завершена." << endl; return false; }
	default: {cout << "Введено неправильное значение." << endl; return Menu(); }
	}
}

// Меню сохранения результата программы
bool MenuResult() {
	enum MenuResuiltCase {Yes = 1, No};
	int variant;
	cout << endl;
	cout << "Сохранить результат в файл?" << endl;
	cout << "1. Да." << endl;
	cout << "2. Нет." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case Yes: return true;
	case No: return false;
	default: {cout << "Введено неправильное значение." << endl; return MenuResult(); }
	}
}

// Меню сохранения исходных данных
bool MenuExportData() {
	enum MenuExportDataCase { Yes = 1, No };
	int variant;
	cout << endl;
	cout << "Сохранить исходные данные в файл?" << endl;
	cout << "1. Да." << endl;
	cout << "2. Нет." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case Yes: return true;
	case No: return false;
	default: {cout << "Введено неправильное значение." << endl; return MenuExportData(); }
	}
}

// Меню чтения исходных данных из файла
bool MenuImportData() {
	enum MenuImportDataCase { Yes = 1, No };
	int variant;
	cout << endl;
	cout << "Загрузить исходные данные из файла?" << endl;
	cout << "1. Загрузить исходные данные из файла." << endl;
	cout << "2. Ввести исходные данные самостоятельно." << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case Yes: return true;
	case No: return false;
	default: {cout << "Введено неправильное значение." << endl; return MenuImportData(); }
	}
}

// Меню выбора перезаписи существующего файла
bool MenuReWrite() {
	enum MenuReWriteCase { ReWrite = 1, SeekClear };
	int variant;
	cout << endl;
	cout << "Файл уже хранит в себе данные. Выберите необходимое действие:" << endl;
	cout << "1. Перезаписать данные в файле" << endl;
	cout << "2. Указать путь к другому файлу" << endl;
	cout << endl;
	variant = NumInInt();
	switch (variant) {
	case ReWrite: return true;
	case SeekClear: return false;
	default: {cout << "Введено неправильное значение." << endl; return MenuReWrite(); }
	}
}