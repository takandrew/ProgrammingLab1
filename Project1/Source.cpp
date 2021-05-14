#include <iostream>
#include "Menu.h"
#include "Computing.h"
#include "Testing.h"
#include "Files.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	Greeting(); // Вывод приветствия
	TestingModules(); // Проведение модульных тестов
	rectangle firstRec, secondRec;
	bool one = true;
	while (true) {
		if (MenuImportData() == true) {
			do { // Чтение исходных данных из файла
				ifstream fin;
				cout << "Введите путь к файлу:" << endl;
				string path;
				int neededData = 12;
				bool fileReadCorrectCheck = 0;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				fileReadCorrectCheck = FileReadCorrectChecking(path);
				while (fileReadCorrectCheck == false) { // Проверка корректности файла
					cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
					cout << "Введите путь к файлу:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					fileReadCorrectCheck = FileReadCorrectChecking(path);
				}
				fin.open(path);
				int countData = 0;
				double tempData = 0;
				while (fin) { // Проверка на количество исходных данных
					fin >> tempData;
					if (fin.fail()) {
						break;
					}
					if (countData == neededData)
						break;
					countData++;
				}
				fin.close();
				while (countData != neededData) {
					cout << "В файле недостаточно данных. Пожалуйста попробуйте еще раз." << endl;
					cout << "Введите путь к файлу:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					fileReadCorrectCheck = FileReadCorrectChecking(path);
					while (fileReadCorrectCheck == false) { // Проверка корректности файла
						cout << "Ошибка открытия файла. Пожалуйста попробуйте еще раз." << endl;
						cout << "Введите путь к файлу:" << endl;
						SetConsoleCP(1251);
						cin >> path;
						SetConsoleCP(866);
						fileReadCorrectCheck = FileReadCorrectChecking(path);
					}
					fin.open(path);
					tempData = 0;
					countData = 0;
					while (fin) {
						fin >> tempData;
						if (fin.fail()) {
							break;
						}
						if (countData == neededData)
							break;
						countData++;
					}
					fin.close();
				}
				firstRec = FileRead(path);
				secondRec = FileReadSecond(path);
				cout << endl;
				// Проверка полученных исходных данных на построение прямоугольников
				if (CheckAngle_textless(firstRec) != one) {
					cout << "Полученные исходные данные точек первого прямоугольника не образуют прямоугольник" << endl;
					cout << endl;
				}
				if (CheckAngle_textless(secondRec) != one) {
					cout << "Полученные исходные данные точек второго прямоугольника не образуют прямоугольник" << endl;
					cout << endl;
				}
			} while ((CheckAngle_textless(firstRec) != one)
				|| (CheckAngle_textless(secondRec) != one));
			cout << "\t" << "Координаты точек первого прямоугольника:" << endl;
			cout << "Верхняя левая точка:" << endl;
			cout << "x = " << firstRec.lt.x << endl;
			cout << "y = " << firstRec.lt.y << endl;
			cout << "Нижняя правая точка:" << endl;
			cout << "x = " << firstRec.rb.x << endl;
			cout << "y = " << firstRec.rb.y << endl;
			cout << "Верхняя правая точка:" << endl;
			cout << "x = " << firstRec.rt.x << endl;
			cout << "y = " << firstRec.rt.y << endl;
			cout << "\t" << "Координаты точек второго прямоугольника:" << endl;
			cout << "Верхняя левая точка:" << endl;
			cout << "x = " << secondRec.lt.x << endl;
			cout << "y = " << secondRec.lt.y << endl;
			cout << "Нижняя правая точка:" << endl;
			cout << "x = " << secondRec.rb.x << endl;
			cout << "y = " << secondRec.rb.y << endl;
			cout << "Верхняя правая точка:" << endl;
			cout << "x = " << secondRec.rt.x << endl;
			cout << "y = " << secondRec.rt.y << endl;
		}
		else { // Ввод исходных данных с клавиатуры
			do {
				cout << "Введите координаты верхней левой точки первого прямоугольника:" << endl;
				cout << "x = ";
				firstRec.lt.x = NumInDouble();
				cout << "y = ";
				firstRec.lt.y = NumInDouble();
				cout << "Введите координаты нижней правой точки первого прямоугольника:" << endl;
				cout << "x = ";
				firstRec.rb.x = NumInDouble();
				cout << "y = ";
				firstRec.rb.y = NumInDouble();
				cout << "Введите координаты верхней правой точки первого прямоугольника:" << endl;
				cout << "x = ";
				firstRec.rt.x = NumInDouble();
				cout << "y = ";
				firstRec.rt.y = NumInDouble();
			} while (CheckAngle(firstRec) != one);
			do {
				cout << "Введите координаты верхней левой точки второго прямоугольника:" << endl;
				cout << "x = ";
				secondRec.lt.x = NumInDouble();
				cout << "y = ";
				secondRec.lt.y = NumInDouble();
				cout << "Введите координаты нижней правой точки второго прямоугольника:" << endl;
				cout << "x = ";
				secondRec.rb.x = NumInDouble();
				cout << "y = ";
				secondRec.rb.y = NumInDouble();
				cout << "Введите координаты верхней правой точки второго прямоугольника:" << endl;
				cout << "x = ";
				secondRec.rt.x = NumInDouble();
				cout << "y = ";
				secondRec.rt.y = NumInDouble();
			} while (CheckAngle(secondRec) != one);
			if (MenuExportData() == true) { // Возможность сохранения исходных данных в файл
				FileWriteData(firstRec, secondRec);
			}
		}
		// Вычисление оставшихся точек прямоугольников
		firstRec.lb.x = firstRec.lt.x + (firstRec.rb.x - firstRec.rt.x);
		firstRec.lb.y = firstRec.lt.y - (firstRec.rt.y - firstRec.rb.y);
		secondRec.lb.x = secondRec.lt.x + (secondRec.rb.x - secondRec.rt.x);
		secondRec.lb.y = secondRec.lt.y - (secondRec.rt.y - secondRec.rb.y);
		Intersection_Result(firstRec, secondRec); // Основной алгоритм, проверяющий наличие общей области у прямоугольников
		string result = "";
		if (MenuResult() == true) { // Возможность сохранения результата программы в файл
			if (Intersection_Result_textless(firstRec, secondRec) == true) {
				result = "Прямоугольники имеют общую область";
				FileWriteResult(result, firstRec, secondRec);
			}
			else {
				result = "Прямоугольники не имеют общей области";
				FileWriteResult(result, firstRec, secondRec);
			}
		} 
		if (Menu() == false) // Вывод меню после работы программы
			return false;
	}
	return 0;
}
