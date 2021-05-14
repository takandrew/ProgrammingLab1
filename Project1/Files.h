#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"Computing.h"
#include<Windows.h>
using namespace std;
rectangle FileRead(string path); // Функция, считывающая из файла и возвращающая исходные данные первого прямоугольника
rectangle FileReadSecond(string path); // Функция, считывающая из файла и возвращающая исходные данные второго прямоугольника
void FileWriteResult(string str, rectangle firstRec, rectangle secondRec); // Функция, записывающая результат программы в файл
void FileWriteData(rectangle firstRec, rectangle secondRec); // Функция, записывающая исходные данные в файл
                                                             // с возможностью последующего чтения из него
bool FileExist(string path); // Проверка на существование файла
bool ReadOnlyChecking(string path); //Функция, проверяющая, является ли файл доступным только для чтения. Принимает путь к файлу.
bool FileCorrectChecking(string path); //Функция, проверяющая корректность файла
bool FileReadCorrectChecking(string path); //Функция, проверяющая корректность файла, из которого считывают данные
bool FileOpenChecking(string path); // Функция, проверяющая открытие файла