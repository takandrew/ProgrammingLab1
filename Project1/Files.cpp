#include"Menu.h"
#include"Files.h"
#include<stdlib.h>
#include <experimental/filesystem>
using namespace std::experimental::filesystem;

// �������, ����������� �� ����� � ������������ �������� ������ ������� ��������������
rectangle FileRead(string path) {
	ifstream fin;
	rectangle firstRec;
	fin.open(path);
	double fltx, flty, frbx, frby, frtx, frty, sltx, slty, srbx, srby, srtx, srty;
	fin >> fltx >> flty >> frbx >> frby >> frtx >> frty >> sltx >> slty >> srbx >> srby >> srtx >> srty;
	firstRec.lt.x = fltx; firstRec.lt.y = flty;
	firstRec.rb.x = frbx; firstRec.rb.y = frby;
	firstRec.rt.x = frtx; firstRec.rt.y = frty;
	fin.close();
	return firstRec;
}

// �������, ����������� �� ����� � ������������ �������� ������ ������� ��������������
rectangle FileReadSecond(string path) {
	ifstream fin;
	rectangle secondRec;
	fin.open(path);
	double fltx, flty, frbx, frby, frtx, frty, sltx, slty, srbx, srby, srtx, srty;
	fin >> fltx >> flty >> frbx >> frby >> frtx >> frty >> sltx >> slty >> srbx >> srby >> srtx >> srty;
	secondRec.lt.x = sltx; secondRec.lt.y = slty;
	secondRec.rb.x = srbx; secondRec.rb.y = srby;
	secondRec.rt.x = srtx; secondRec.rt.y = srty;
	fin.close();
	return secondRec;
}

// �������, ������������ ��������� ��������� � ����
void FileWriteResult(string str, rectangle firstRec, rectangle secondRec) {
	ofstream fout;
	string path;
	bool readOnlyCheck = 0;
	bool fileCorrectCheck = 0;
	bool fileOpenCheck = 0;
	cout << endl << "������� ���� � �����:" << endl;
	SetConsoleCP(1251);
	cin >> path;
	SetConsoleCP(866);
	readOnlyCheck = ReadOnlyChecking(path);
	fileCorrectCheck = FileCorrectChecking(path);
	fileOpenCheck = FileOpenChecking(path);
	while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // �������� ������������ �����
		cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
		cout << "������� ���� � �����:" << endl;
		SetConsoleCP(1251);
		cin >> path;
		SetConsoleCP(866);
		readOnlyCheck = ReadOnlyChecking(path);
		fileCorrectCheck = FileCorrectChecking(path);
		fileOpenCheck = FileOpenChecking(path);
	}
	if (FileExist(path) == true) { // �������� ������������� �����
		if (MenuReWrite() == true) { // ����������� ������ ���������� � ����
			fout.open(path);
			// ����� �������� ������ � ����
			fout << "\t" << "���������� ����� ������� ��������������:" << endl;
			fout << "������� ����� �����:" << endl;
			fout << "x = " << firstRec.lt.x << endl;
			fout << "y = " << firstRec.lt.y << endl;
			fout << "������ ������ �����:" << endl;
			fout << "x = " << firstRec.rb.x << endl;
			fout << "y = " << firstRec.rb.y << endl;
			fout << "������� ������ �����:" << endl;
			fout << "x = " << firstRec.rt.x << endl;
			fout << "y = " << firstRec.rt.y << endl;
			fout << "\t" << "���������� ����� ������� ��������������:" << endl;
			fout << "������� ����� �����:" << endl;
			fout << "x = " << secondRec.lt.x << endl;
			fout << "y = " << secondRec.lt.y << endl;
			fout << "������ ������ �����:" << endl;
			fout << "x = " << secondRec.rb.x << endl;
			fout << "y = " << secondRec.rb.y << endl;
			fout << "������� ������ �����:" << endl;
			fout << "x = " << secondRec.rt.x << endl;
			fout << "y = " << secondRec.rt.y << endl;
			fout << "\t" << str << endl;
		}
		else { // ����� �� ���������� � ����� ������� ���� � �����
			cout << "������� ���� � �����:" << endl;
			SetConsoleCP(1251);
			cin >> path;
			SetConsoleCP(866);
			readOnlyCheck = ReadOnlyChecking(path);
			fileCorrectCheck = FileCorrectChecking(path);
			fileOpenCheck = FileOpenChecking(path);
			while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // �������� ������������ �����
				cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
				cout << "������� ���� � �����:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				readOnlyCheck = ReadOnlyChecking(path);
				fileCorrectCheck = FileCorrectChecking(path);
				fileOpenCheck = FileOpenChecking(path);
			}
			while (FileExist(path) == true) { // ���� �������� �������������, ���������� ��� ������ ������� ���� � �����
				if (MenuReWrite() == true) {
					break;
				}
				else {
					cout << "������� ���� � �����:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					readOnlyCheck = ReadOnlyChecking(path);
					fileCorrectCheck = FileCorrectChecking(path);
					fileOpenCheck = FileOpenChecking(path);
					while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // �������� ������������ �����
						cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
						cout << "������� ���� � �����:" << endl;
						SetConsoleCP(1251);
						cin >> path;
						SetConsoleCP(866);
						readOnlyCheck = ReadOnlyChecking(path);
						fileCorrectCheck = FileCorrectChecking(path);
						fileOpenCheck = FileOpenChecking(path);
					}
				}
			}
			SetConsoleCP(866);
			fout.open(path);
			// ����� �������� ������ � ����
			fout << "\t" << "���������� ����� ������� ��������������:" << endl;
			fout << "������� ����� �����:" << endl;
			fout << "x = " << firstRec.lt.x << endl;
			fout << "y = " << firstRec.lt.y << endl;
			fout << "������ ������ �����:" << endl;
			fout << "x = " << firstRec.rb.x << endl;
			fout << "y = " << firstRec.rb.y << endl;
			fout << "������� ������ �����:" << endl;
			fout << "x = " << firstRec.rt.x << endl;
			fout << "y = " << firstRec.rt.y << endl;
			fout << "\t" << "���������� ����� ������� ��������������:" << endl;
			fout << "������� ����� �����:" << endl;
			fout << "x = " << secondRec.lt.x << endl;
			fout << "y = " << secondRec.lt.y << endl;
			fout << "������ ������ �����:" << endl;
			fout << "x = " << secondRec.rb.x << endl;
			fout << "y = " << secondRec.rb.y << endl;
			fout << "������� ������ �����:" << endl;
			fout << "x = " << secondRec.rt.x << endl;
			fout << "y = " << secondRec.rt.y << endl;
			fout << "\t" << str << endl;
		}
	}
	else { // ���� ����� �� ���������� 
		fout.open(path);
		// ����� �������� ������ � ����
		fout << "\t" << "���������� ����� ������� ��������������:" << endl;
		fout << "������� ����� �����:" << endl;
		fout << "x = " << firstRec.lt.x << endl;
		fout << "y = " << firstRec.lt.y << endl;
		fout << "������ ������ �����:" << endl;
		fout << "x = " << firstRec.rb.x << endl;
		fout << "y = " << firstRec.rb.y << endl;
		fout << "������� ������ �����:" << endl;
		fout << "x = " << firstRec.rt.x << endl;
		fout << "y = " << firstRec.rt.y << endl;
		fout << "\t" << "���������� ����� ������� ��������������:" << endl;
		fout << "������� ����� �����:" << endl;
		fout << "x = " << secondRec.lt.x << endl;
		fout << "y = " << secondRec.lt.y << endl;
		fout << "������ ������ �����:" << endl;
		fout << "x = " << secondRec.rb.x << endl;
		fout << "y = " << secondRec.rb.y << endl;
		fout << "������� ������ �����:" << endl;
		fout << "x = " << secondRec.rt.x << endl;
		fout << "y = " << secondRec.rt.y << endl;
		fout << "\t" << str << endl;
	}
	cout << endl << "���� ������� �������." << endl;
	fout.close();
}

// �������, ������������ �������� ������ � ���� � ������������ ������������ ������ �� ����
void FileWriteData(rectangle firstRec, rectangle secondRec) {
	ofstream fout;
	string path;
	bool readOnlyCheck = 0;
	bool fileCorrectCheck = 0;
	bool fileOpenCheck = 0;
	cout << endl << "������� ���� � �����:" << endl;
	SetConsoleCP(1251);
	cin >> path;
	SetConsoleCP(866);
	readOnlyCheck = ReadOnlyChecking(path);
	fileCorrectCheck = FileCorrectChecking(path);
	fileOpenCheck = FileOpenChecking(path);
	while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // �������� ������������ �����
		cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
		cout << "������� ���� � �����:" << endl;
		SetConsoleCP(1251);
		cin >> path;
		SetConsoleCP(866);
		readOnlyCheck = ReadOnlyChecking(path);
		fileCorrectCheck = FileCorrectChecking(path);
		fileOpenCheck = FileOpenChecking(path);
	}
	if (FileExist(path) == true) { // �������� ������������� �����
		if (MenuReWrite() == true) { // ����������� ������ ���������� � ����
			fout.open(path);
			// ����� �������� ������ � ����
			fout << firstRec.lt.x << endl;
			fout << firstRec.lt.y << endl;
			fout << firstRec.rb.x << endl;
			fout << firstRec.rb.y << endl;
			fout << firstRec.rt.x << endl;
			fout << firstRec.rt.y << endl;
			fout << secondRec.lt.x << endl;
			fout << secondRec.lt.y << endl;
			fout << secondRec.rb.x << endl;
			fout << secondRec.rb.y << endl;
			fout << secondRec.rt.x << endl;
			fout << secondRec.rt.y << endl;
		}
		else { // ����� �� ���������� � ����� ������� ���� � �����
			cout << "������� ���� � �����:" << endl;
			SetConsoleCP(1251);
			cin >> path;
			SetConsoleCP(866);
			readOnlyCheck = ReadOnlyChecking(path);
			fileCorrectCheck = FileCorrectChecking(path);
			fileOpenCheck = FileOpenChecking(path);
			while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // �������� ������������ �����
				cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
				cout << "������� ���� � �����:" << endl;
				SetConsoleCP(1251);
				cin >> path;
				SetConsoleCP(866);
				readOnlyCheck = ReadOnlyChecking(path);
				fileCorrectCheck = FileCorrectChecking(path);
				fileOpenCheck = FileOpenChecking(path);
			}
			while (FileExist(path) == true) { // ���� �������� �������������, ���������� ��� ������ ������� ���� � �����
				if (MenuReWrite() == true) {
					break;
				}
				else {
					cout << "������� ���� � �����:" << endl;
					SetConsoleCP(1251);
					cin >> path;
					SetConsoleCP(866);
					readOnlyCheck = ReadOnlyChecking(path);
					fileCorrectCheck = FileCorrectChecking(path);
					fileOpenCheck = FileOpenChecking(path);
					while ((readOnlyCheck == false) || (fileCorrectCheck == false) || (fileOpenCheck == false)) { // �������� ������������ �����
						cout << "������ �������� �����. ���������� ���������� ��� ���." << endl;
						cout << "������� ���� � �����:" << endl;
						SetConsoleCP(1251);
						cin >> path;
						SetConsoleCP(866);
						readOnlyCheck = ReadOnlyChecking(path);
						fileCorrectCheck = FileCorrectChecking(path);
						fileOpenCheck = FileOpenChecking(path);
					}
				}
			}
			SetConsoleCP(866);
			fout.open(path);
			// ����� �������� ������ � ����
			fout << firstRec.lt.x << endl;
			fout << firstRec.lt.y << endl;
			fout << firstRec.rb.x << endl;
			fout << firstRec.rb.y << endl;
			fout << firstRec.rt.x << endl;
			fout << firstRec.rt.y << endl;
			fout << secondRec.lt.x << endl;
			fout << secondRec.lt.y << endl;
			fout << secondRec.rb.x << endl;
			fout << secondRec.rb.y << endl;
			fout << secondRec.rt.x << endl;
			fout << secondRec.rt.y << endl;
		}
	}
	else { // ���� ����� �� ���������� 
		fout.open(path);
		// ����� �������� ������ � ����
		fout << firstRec.lt.x << endl;
		fout << firstRec.lt.y << endl;
		fout << firstRec.rb.x << endl;
		fout << firstRec.rb.y << endl;
		fout << firstRec.rt.x << endl;
		fout << firstRec.rt.y << endl;
		fout << secondRec.lt.x << endl;
		fout << secondRec.lt.y << endl;
		fout << secondRec.rb.x << endl;
		fout << secondRec.rb.y << endl;
		fout << secondRec.rt.x << endl;
		fout << secondRec.rt.y << endl;
	}
	cout << endl << "���� ������� ��������." << endl;
	fout.close();
}

// �������� �� ������������� �����
bool FileExist(string path) {
	WIN32_FIND_DATA wfd;
	LPCSTR pathLPC = path.c_str();
	HANDLE hfind = ::FindFirstFile(pathLPC, &wfd);
	if (INVALID_HANDLE_VALUE != hfind) {
		::FindClose(hfind);
		return true;
	}
	return false;
}

//�������, �����������, �������� �� ���� ��������� ������ ��� ������. ��������� ���� � �����.
bool ReadOnlyChecking(string path) {
	LPCSTR name = path.c_str();
	WIN32_FIND_DATAA findData;
	FindFirstFileA(name, &findData);
	if (findData.dwFileAttributes & FILE_ATTRIBUTE_READONLY) {
		cout << endl << "� ������ ���� ���������� �������� ������. �������� ������ ��� ������." << endl;
		return false;
	}
	else {
		return true;
	}
}

//�������, ����������� ������������ �����
bool FileCorrectChecking(string path) {
	int one = 1, four = 4;
	size_t five = 5;
	size_t found = path.find_last_of("\\");
	size_t point = path.find_last_of(".");
	size_t base = point - found - one;
	string basefilenameStr = path.substr(found + one, base);
	const char* basefilenameChar = basefilenameStr.c_str();
	if (!_strcmpi(basefilenameChar, "con")) {
		cout << endl << "������������ ��� �����." << endl;
		return false;
	}
	if (path.size() < five) {
		cout << endl << "������������ ��� �����. ��������� ������ ���������� ����� ����� ��������" << endl;
		return false;
	}
	if (path.substr(path.size() - four) != ".txt") {
		cout << endl << "������������ ������ �����. ��������� ���� ������� .txt" << endl;
		return false;
	}
	if (!FileExist(path)) {
		return true;
	}
	if (!is_regular_file(path)) {
		cout << endl << "���� �� �������� �������." << endl;
		return false;
	}
	return true;
}

//�������, ����������� ������������ �����, �� �������� ��������� ������
bool FileReadCorrectChecking(string path) {
	int one = 1, four = 4;
	size_t five = 5;
	size_t found = path.find_last_of("\\");
	size_t point = path.find_last_of(".");
	size_t base = point - found - one;
	string basefilenameStr = path.substr(found + one, base);
	const char* basefilenameChar = basefilenameStr.c_str();
	if (!_strcmpi(basefilenameChar, "con")) {
		cout << endl << "������������ ��� �����." << endl;
		return false;
	}
	if (path.size() < five) {
		cout << endl << "������������ ��� �����. ��������� ������ ���������� ����� ����� ��������" << endl;
		return false;
	}
	if (!FileExist(path)) {
		cout << endl << "����� �� ���������� ���� �� ����������" << endl;
		return false;
	}
	if (path.substr(path.size() - four) != ".txt") {
		cout << endl << "������������ ������ �����. ��������� ���� ������� .txt" << endl;
		return false;
	}
	if (!is_regular_file(path)) {
		cout << endl << "���� �� �������� �������." << endl;
		return false;
	}
	return true;
}

// �������, ����������� �������� �����
bool FileOpenChecking(string path) {
	if (!FileExist(path)) {
		ofstream fout;
		fout.open(path);
		if (!fout.is_open()) {
			if (!is_regular_file(path)) {
				return false;
			}
			else {
				remove(path);
				return false;
			}
		}
		fout.close();
		remove(path);
		return true;
	}
	else
		return true;
}