#include <iostream>
#include "Menu.h"
#include "Computing.h"
#include "Testing.h"
#include "Files.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	Greeting(); // ����� �����������
	TestingModules(); // ���������� ��������� ������
	rectangle firstRec, secondRec;
	bool one = true;
	while (true) {
		if (MenuImportData() == true) {
			do { // ������ �������� ������ �� �����
				ifstream fin;
				cout << "������� ���� � �����:" << endl;
				string path;
				int neededData = 12;
				bool fileReadCorrectCheck = 0;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				fileReadCorrectCheck = FileReadCorrectChecking(path);
				while (fileReadCorrectCheck == false) { // �������� ������������ �����
					cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
					cout << "������� ���� � �����:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					fileReadCorrectCheck = FileReadCorrectChecking(path);
				}
				fin.open(path);
				int countData = 0;
				double tempData = 0;
				while (fin) { // �������� �� ���������� �������� ������
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
					cout << "� ����� ������������ ������. ���������� ���������� ��� ���." << endl;
					cout << "������� ���� � �����:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					fileReadCorrectCheck = FileReadCorrectChecking(path);
					while (fileReadCorrectCheck == false) { // �������� ������������ �����
						cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
						cout << "������� ���� � �����:" << endl;
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
				// �������� ���������� �������� ������ �� ���������� ���������������
				if (CheckAngle_textless(firstRec) != one) {
					cout << "���������� �������� ������ ����� ������� �������������� �� �������� �������������" << endl;
					cout << endl;
				}
				if (CheckAngle_textless(secondRec) != one) {
					cout << "���������� �������� ������ ����� ������� �������������� �� �������� �������������" << endl;
					cout << endl;
				}
			} while ((CheckAngle_textless(firstRec) != one)
				|| (CheckAngle_textless(secondRec) != one));
			cout << "\t" << "���������� ����� ������� ��������������:" << endl;
			cout << "������� ����� �����:" << endl;
			cout << "x = " << firstRec.lt.x << endl;
			cout << "y = " << firstRec.lt.y << endl;
			cout << "������ ������ �����:" << endl;
			cout << "x = " << firstRec.rb.x << endl;
			cout << "y = " << firstRec.rb.y << endl;
			cout << "������� ������ �����:" << endl;
			cout << "x = " << firstRec.rt.x << endl;
			cout << "y = " << firstRec.rt.y << endl;
			cout << "\t" << "���������� ����� ������� ��������������:" << endl;
			cout << "������� ����� �����:" << endl;
			cout << "x = " << secondRec.lt.x << endl;
			cout << "y = " << secondRec.lt.y << endl;
			cout << "������ ������ �����:" << endl;
			cout << "x = " << secondRec.rb.x << endl;
			cout << "y = " << secondRec.rb.y << endl;
			cout << "������� ������ �����:" << endl;
			cout << "x = " << secondRec.rt.x << endl;
			cout << "y = " << secondRec.rt.y << endl;
		}
		else { // ���� �������� ������ � ����������
			do {
				cout << "������� ���������� ������� ����� ����� ������� ��������������:" << endl;
				cout << "x = ";
				firstRec.lt.x = NumInDouble();
				cout << "y = ";
				firstRec.lt.y = NumInDouble();
				cout << "������� ���������� ������ ������ ����� ������� ��������������:" << endl;
				cout << "x = ";
				firstRec.rb.x = NumInDouble();
				cout << "y = ";
				firstRec.rb.y = NumInDouble();
				cout << "������� ���������� ������� ������ ����� ������� ��������������:" << endl;
				cout << "x = ";
				firstRec.rt.x = NumInDouble();
				cout << "y = ";
				firstRec.rt.y = NumInDouble();
			} while (CheckAngle(firstRec) != one);
			do {
				cout << "������� ���������� ������� ����� ����� ������� ��������������:" << endl;
				cout << "x = ";
				secondRec.lt.x = NumInDouble();
				cout << "y = ";
				secondRec.lt.y = NumInDouble();
				cout << "������� ���������� ������ ������ ����� ������� ��������������:" << endl;
				cout << "x = ";
				secondRec.rb.x = NumInDouble();
				cout << "y = ";
				secondRec.rb.y = NumInDouble();
				cout << "������� ���������� ������� ������ ����� ������� ��������������:" << endl;
				cout << "x = ";
				secondRec.rt.x = NumInDouble();
				cout << "y = ";
				secondRec.rt.y = NumInDouble();
			} while (CheckAngle(secondRec) != one);
			if (MenuExportData() == true) { // ����������� ���������� �������� ������ � ����
				FileWriteData(firstRec, secondRec);
			}
		}
		// ���������� ���������� ����� ���������������
		firstRec.lb.x = firstRec.lt.x + (firstRec.rb.x - firstRec.rt.x);
		firstRec.lb.y = firstRec.lt.y - (firstRec.rt.y - firstRec.rb.y);
		secondRec.lb.x = secondRec.lt.x + (secondRec.rb.x - secondRec.rt.x);
		secondRec.lb.y = secondRec.lt.y - (secondRec.rt.y - secondRec.rb.y);
		Intersection_Result(firstRec, secondRec); // �������� ��������, ����������� ������� ����� ������� � ���������������
		string result = "";
		if (MenuResult() == true) { // ����������� ���������� ���������� ��������� � ����
			if (Intersection_Result_textless(firstRec, secondRec) == true) {
				result = "�������������� ����� ����� �������";
				FileWriteResult(result, firstRec, secondRec);
			}
			else {
				result = "�������������� �� ����� ����� �������";
				FileWriteResult(result, firstRec, secondRec);
			}
		} 
		if (Menu() == false) // ����� ���� ����� ������ ���������
			return false;
	}
	return 0;
}
