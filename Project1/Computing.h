#pragma once
struct point {
	double x, y;
};

struct rectangle {
	point lt; //left top
	point lb; //left bottom
	point rb; //right bottom
	point rt; //right top
};

double NumInDouble(); // Функция проверки корректности ввода для переменной типа double
int NumInInt(); // Функция проверки корректности ввода для переменной типа int
bool CheckAngle(rectangle rec); // Функция, проверяющая исходные данные 
                                     //на составление прямоугольника из них
bool CheckAngle_textless(rectangle rec); // Функция, проверяющая исходные
                                                            //данные на составление прямоугольника из них для тестирования
bool Intersection(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy); // Функция,
                                                                  //проверяющая пересечение отрезков из данных точек
bool Intersection_Result(rectangle firstRec, rectangle secondRec); // Функция, проверяющая наличие
                                                             //общей области у двух прямоугольников
bool Intersection_Result_textless(rectangle firstRec, rectangle secondRec); // Функция, проверяющая наличие
                                                            //общей области у двух прямоугольников для тестирования