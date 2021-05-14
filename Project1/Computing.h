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

double NumInDouble(); // ‘ункци€ проверки корректности ввода дл€ переменной типа double
int NumInInt(); // ‘ункци€ проверки корректности ввода дл€ переменной типа int
bool CheckAngle(rectangle rec); // ‘ункци€, провер€юща€ исходные данные 
                                     //на составление пр€моугольника из них
bool CheckAngle_textless(rectangle rec); // ‘ункци€, провер€юща€ исходные
                                                            //данные на составление пр€моугольника из них дл€ тестировани€
bool Intersection(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy); // ‘ункци€,
                                                                  //провер€юща€ пересечение отрезков из данных точек
bool Intersection_Result(rectangle firstRec, rectangle secondRec); // ‘ункци€, провер€юща€ наличие
                                                             //общей области у двух пр€моугольников
bool Intersection_Result_textless(rectangle firstRec, rectangle secondRec); // ‘ункци€, провер€юща€ наличие
                                                            //общей области у двух пр€моугольников дл€ тестировани€