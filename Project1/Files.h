#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Computing.h"
#include<Windows.h>
using namespace std;
rectangle FileRead(string path); // �������, ����������� �� ����� � ������������ �������� ������ ������� ��������������
rectangle FileReadSecond(string path); // �������, ����������� �� ����� � ������������ �������� ������ ������� ��������������
void FileWriteResult(string str, rectangle firstRec, rectangle secondRec); // �������, ������������ ��������� ��������� � ����
void FileWriteData(rectangle firstRec, rectangle secondRec); // �������, ������������ �������� ������ � ����
                                                             // � ������������ ������������ ������ �� ����
bool FileExist(string path); // �������� �� ������������� �����
bool ReadOnlyChecking(string path); //�������, �����������, �������� �� ���� ��������� ������ ��� ������. ��������� ���� � �����.
bool FileCorrectChecking(string path); //�������, ����������� ������������ �����
bool FileReadCorrectChecking(string path); //�������, ����������� ������������ �����, �� �������� ��������� ������
bool FileOpenChecking(string path); // �������, ����������� �������� �����