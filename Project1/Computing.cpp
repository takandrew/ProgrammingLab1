#include<iostream>
#include"Computing.h"

using namespace std;

// Функция проверки корректности ввода для переменной типа double
double NumInDouble() {
	double variable;
	while (!(cin >> variable) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Некорректно введенные данные. Пожалуйста, введите цифру: " << endl;
	}
	return variable;
}

// Функция проверки корректности ввода для переменной типа int
int NumInInt() {
	int variable;
	while (!(cin >> variable) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "Некорректно введенные данные. Пожалуйста, введите цифру: " << endl;
	}
	return variable;
}

// Функция, проверяющая исходные данные на составление прямоугольника из них
bool CheckAngle(rectangle rec) {
	double firstX = rec.rt.x - rec.lt.x;
	double firstY = rec.rt.y - rec.lt.y;
	double secondX = rec.rb.x - rec.rt.x;
	double secondY = rec.rb.y - rec.rt.y;
	double cosine = (firstX*secondX + firstY * secondY)
		/ (pow((firstX*firstX + firstY * firstY), 0.5)*pow((secondX*secondX + secondY * secondY), 0.5));
	if ((((rec.lt.x == rec.rt.x) && (rec.lt.y == rec.rt.y)) || ((rec.lt.x == rec.rb.x)
		&& (rec.lt.y == rec.rb.y)) || ((rec.rb.x == rec.rt.x) && (rec.rb.y == rec.rt.y))) == 0) {
		if ((firstX*secondX + firstY * secondY + 1 == 1) || (cosine == 0))
			return true;
		else {
			cout << endl;
			cout << "Введенные Вами координаты не образуют прямоугольник. Пожалуйста, попробуйте еще раз: " << endl;
			cout << endl;
			return false;
		}
	}
	else {
		cout << endl;
		cout << "Введенные Вами координаты не образуют прямоугольник. Пожалуйста, попробуйте еще раз: " << endl;
		cout << endl;
		return false;
	}
}

// Функция, проверяющая исходные данные на составление прямоугольника из них для тестирования
bool CheckAngle_textless(rectangle rec) {
	double firstX = rec.rt.x - rec.lt.x;
	double firstY = rec.rt.y - rec.lt.y;
	double secondX = rec.rb.x - rec.rt.x;
	double secondY = rec.rb.y - rec.rt.y;
	double cosine = (firstX*secondX + firstY * secondY)
		/ (pow((firstX*firstX + firstY * firstY), 0.5)*pow((secondX*secondX + secondY * secondY), 0.5));
	if ((((rec.lt.x == rec.rt.x) && (rec.lt.y == rec.rt.y)) || ((rec.lt.x == rec.rb.x)
		&& (rec.lt.y == rec.rb.y)) || ((rec.rb.x == rec.rt.x) && (rec.rb.y == rec.rt.y))) == 0) {
		if ((firstX*secondX + firstY * secondY + 1 == 1) || (cosine == 0))
			return true;
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

// Функция, проверяющая пересечение отрезков из данных точек
bool Intersection(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy) {
	if (((ay - by) / (cy - dy)) != ((bx - ax) / (dx - cx))) {
		double zero = 0;
		double det = (ay - by) * (dx - cx) - (cy - dy) * (bx - ax);
		if (det == zero)
			return false;
		else {
			double x = ((bx - ax) * (cx*dy - dx * cy) - (dx - cx) * (ax*by - bx * ay)) / det;
			double y = ((cy - dy) * (ax*by - bx * ay) - (ay - by) * (cx*dy - dx * cy)) / det;
			double leftaxbx, downayby, rightaxbx, upayby, leftcxdx, downcydy, rightcxdx, upcydy;
			if (ax < bx) {
				rightaxbx = bx;
				leftaxbx = ax;
			}
			else {
				rightaxbx = ax;
				leftaxbx = bx;
			}
			if (cx < dx) {
				rightcxdx = dx;
				leftcxdx = cx;
			}
			else {
				rightcxdx = cx;
				leftcxdx = dx;
			}
			if (ay < by) {
				downayby = ay;
				upayby = by;
			}
			else {
				downayby = by;
				upayby = ay;
			}
			if (cy < dy) {
				downcydy = cy;
				upcydy = dy;
			}
			else {
				downcydy = dy;
				upcydy = cy;
			}
			if ((((x <= rightaxbx) && (x >= leftaxbx)) && ((x >= leftcxdx) && (x <= rightcxdx)) && ((y <= upayby) && (y >= downayby)) && ((y <= upcydy) && (y >= downcydy))) != 0) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	else {
		return false;
	} 
}

// Функция, проверяющая наличие общей области у двух прямоугольников
bool Intersection_Result(rectangle firstRec, rectangle secondRec) {
	double i, j, k, kS, jS;
	bool topTop = Intersection(firstRec.lt.x, firstRec.lt.y, firstRec.rt.x, firstRec.rt.y, secondRec.lt.x, secondRec.lt.y, secondRec.rt.x, secondRec.rt.y);
	bool topRight = Intersection(firstRec.lt.x, firstRec.lt.y, firstRec.rt.x, firstRec.rt.y, secondRec.rb.x, secondRec.rb.y, secondRec.rt.x, secondRec.rt.y);
	bool topBottom = Intersection(firstRec.lt.x, firstRec.lt.y, firstRec.rt.x, firstRec.rt.y, secondRec.lb.x, secondRec.lb.y, secondRec.rb.x, secondRec.rb.y);
	bool topLeft = Intersection(firstRec.lt.x, firstRec.lt.y, firstRec.rt.x, firstRec.rt.y, secondRec.lb.x, secondRec.lb.y, secondRec.lt.x, secondRec.lt.y);
	bool rightTop = Intersection(firstRec.rb.x, firstRec.rb.y, firstRec.rt.x, firstRec.rt.y, secondRec.lt.x, secondRec.lt.y, secondRec.rt.x, secondRec.rt.y);
	bool rightRight = Intersection(firstRec.rb.x, firstRec.rb.y, firstRec.rt.x, firstRec.rt.y, secondRec.rb.x, secondRec.rb.y, secondRec.rt.x, secondRec.rt.y);
	bool rightBottom = Intersection(firstRec.rb.x, firstRec.rb.y, firstRec.rt.x, firstRec.rt.y, secondRec.lb.x, secondRec.lb.y, secondRec.rb.x, secondRec.rb.y);
	bool rightLeft = Intersection(firstRec.rb.x, firstRec.rb.y, firstRec.rt.x, firstRec.rt.y, secondRec.lb.x, secondRec.lb.y, secondRec.lt.x, secondRec.lt.y);
	bool bottomTop = Intersection(firstRec.lb.x, firstRec.lb.y, firstRec.rb.x, firstRec.rb.y, secondRec.lt.x, secondRec.lt.y, secondRec.rt.x, secondRec.rt.y);
	bool bottomRight = Intersection(firstRec.lb.x, firstRec.lb.y, firstRec.rb.x, firstRec.rb.y, secondRec.rb.x, secondRec.rb.y, secondRec.rt.x, secondRec.rt.y);
	bool bottomBottom = Intersection(firstRec.lb.x, firstRec.lb.y, firstRec.rb.x, firstRec.rb.y, secondRec.lb.x, secondRec.lb.y, secondRec.rb.x, secondRec.rb.y);
	bool bottomLeft = Intersection(firstRec.lb.x, firstRec.lb.y, firstRec.rb.x, firstRec.rb.y, secondRec.lb.x, secondRec.lb.y, secondRec.lt.x, secondRec.lt.y);
	bool leftTop = Intersection(firstRec.lb.x, firstRec.lb.y, firstRec.lt.x, firstRec.lt.y, secondRec.lt.x, secondRec.lt.y, secondRec.rt.x, secondRec.rt.y);
	bool leftRight = Intersection(firstRec.lb.x, firstRec.lb.y, firstRec.lt.x, firstRec.lt.y, secondRec.rb.x, secondRec.rb.y, secondRec.rt.x, secondRec.rt.y);
	bool leftBottom = Intersection(firstRec.lb.x, firstRec.lb.y, firstRec.lt.x, firstRec.lt.y, secondRec.lb.x, secondRec.lb.y, secondRec.rb.x, secondRec.rb.y);
	bool leftLeft = Intersection(firstRec.lb.x, firstRec.lb.y, firstRec.lt.x, firstRec.lt.y, secondRec.lb.x, secondRec.lb.y, secondRec.lt.x, secondRec.lt.y);
	bool recInRec;
	int recInRecCount = 0;
	int recInRecCountS = 0;
	k = 0;
	j = 0;
	kS = 0;
	jS = 0;
	for (i = firstRec.lt.x; i <= firstRec.rt.x; i += 0.1) {
		recInRec = Intersection((firstRec.lt.x + k), (firstRec.lt.y + j), (firstRec.lb.x + k), (firstRec.lb.y + j), secondRec.lt.x, secondRec.lt.y, secondRec.rt.x, secondRec.rt.y);
		if (recInRec != 0) {
			recInRecCount++;
		}
		recInRec = Intersection((firstRec.lt.x + k), (firstRec.lt.y + j), (firstRec.lb.x + k), (firstRec.lb.y + j), secondRec.rb.x, secondRec.rb.y, secondRec.rt.x, secondRec.rt.y);
		if (recInRec != 0) {
			recInRecCount++;
		}
		recInRec = Intersection((firstRec.lt.x + k), (firstRec.lt.y + j), (firstRec.lb.x + k), (firstRec.lb.y + j), secondRec.lb.x, secondRec.lb.y, secondRec.lt.x, secondRec.lt.y);
		if (recInRec != 0) {
			recInRecCount++;
		}
		recInRec = Intersection((firstRec.lt.x + k), (firstRec.lt.y + j), (firstRec.lb.x + k), (firstRec.lb.y + j), secondRec.lb.x, secondRec.lb.y, secondRec.lt.x, secondRec.lt.y);
		if (recInRec != 0) {
			recInRecCount++;
		}
		if (firstRec.lt.x < firstRec.rt.x)
			k += 0.1;
		else
			k -= 0.1;
		if (firstRec.lt.y < firstRec.rt.y)
			j += 0.1;
		else if (firstRec.lt.y > firstRec.rt.y)
			j -= 0.1;
		else
			j = 0;
	}
	for (i = secondRec.lt.x; i <= secondRec.rt.x; i += 0.1) {
		recInRec = Intersection((secondRec.lt.x + kS), (secondRec.lt.y + jS), (secondRec.lb.x + kS), (secondRec.lb.y + jS), firstRec.lt.x, firstRec.lt.y, firstRec.rt.x, firstRec.rt.y);
		if (recInRec != 0) {
			recInRecCountS++;
		}
		recInRec = Intersection((secondRec.lt.x + kS), (secondRec.lt.y + jS), (secondRec.lb.x + kS), (secondRec.lb.y + jS), firstRec.rb.x, firstRec.rb.y, firstRec.rt.x, firstRec.rt.y);
		if (recInRec != 0) {
			recInRecCountS++;
		}
		recInRec = Intersection((secondRec.lt.x + kS), (secondRec.lt.y + jS), (secondRec.lb.x + kS), (secondRec.lb.y + jS), firstRec.lb.x, firstRec.lb.y, firstRec.lt.x, firstRec.lt.y);
		if (recInRec != 0) {
			recInRecCountS++;
		}
		recInRec = Intersection((secondRec.lt.x + kS), (secondRec.lt.y + jS), (secondRec.lb.x + kS), (secondRec.lb.y + jS), firstRec.lb.x, firstRec.lb.y, firstRec.lt.x, firstRec.lt.y);
		if (recInRec != 0) {
			recInRecCountS++;
		}
		if (secondRec.lt.x < secondRec.rt.x)
			kS += 0.1;
		else
			kS -= 0.1;
		if (secondRec.lt.y < secondRec.rt.y)
			jS += 0.1;
		else if (secondRec.lt.y > secondRec.rt.y)
			jS -= 0.1;
		else
			jS = 0;
	}
	if ((topTop || topRight || topBottom || topLeft || rightTop || rightRight || rightBottom || rightLeft || bottomTop || bottomRight || bottomBottom || bottomLeft || leftTop || leftRight || leftBottom || leftLeft || recInRecCount || recInRecCountS) == 0) {
		cout << "Прямоугольники не имеют общей области" << endl;
		return false;
	}
	else {
		cout << endl;
		cout << "Прямоугольники имеют общую область" << endl;
		return true;
	}
}

// Функция, проверяющая наличие общей области у двух прямоугольников для тестирования
bool Intersection_Result_textless(rectangle firstRec, rectangle secondRec) {
	double i, j, k, kS, jS;
	bool topTop = Intersection(firstRec.lt.x, firstRec.lt.y, firstRec.rt.x, firstRec.rt.y, secondRec.lt.x, secondRec.lt.y, secondRec.rt.x, secondRec.rt.y);
	bool topRight = Intersection(firstRec.lt.x, firstRec.lt.y, firstRec.rt.x, firstRec.rt.y, secondRec.rb.x, secondRec.rb.y, secondRec.rt.x, secondRec.rt.y);
	bool topBottom = Intersection(firstRec.lt.x, firstRec.lt.y, firstRec.rt.x, firstRec.rt.y, secondRec.lb.x, secondRec.lb.y, secondRec.rb.x, secondRec.rb.y);
	bool topLeft = Intersection(firstRec.lt.x, firstRec.lt.y, firstRec.rt.x, firstRec.rt.y, secondRec.lb.x, secondRec.lb.y, secondRec.lt.x, secondRec.lt.y);
	bool rightTop = Intersection(firstRec.rb.x, firstRec.rb.y, firstRec.rt.x, firstRec.rt.y, secondRec.lt.x, secondRec.lt.y, secondRec.rt.x, secondRec.rt.y);
	bool rightRight = Intersection(firstRec.rb.x, firstRec.rb.y, firstRec.rt.x, firstRec.rt.y, secondRec.rb.x, secondRec.rb.y, secondRec.rt.x, secondRec.rt.y);
	bool rightBottom = Intersection(firstRec.rb.x, firstRec.rb.y, firstRec.rt.x, firstRec.rt.y, secondRec.lb.x, secondRec.lb.y, secondRec.rb.x, secondRec.rb.y);
	bool rightLeft = Intersection(firstRec.rb.x, firstRec.rb.y, firstRec.rt.x, firstRec.rt.y, secondRec.lb.x, secondRec.lb.y, secondRec.lt.x, secondRec.lt.y);
	bool bottomTop = Intersection(firstRec.lb.x, firstRec.lb.y, firstRec.rb.x, firstRec.rb.y, secondRec.lt.x, secondRec.lt.y, secondRec.rt.x, secondRec.rt.y);
	bool bottomRight = Intersection(firstRec.lb.x, firstRec.lb.y, firstRec.rb.x, firstRec.rb.y, secondRec.rb.x, secondRec.rb.y, secondRec.rt.x, secondRec.rt.y);
	bool bottomBottom = Intersection(firstRec.lb.x, firstRec.lb.y, firstRec.rb.x, firstRec.rb.y, secondRec.lb.x, secondRec.lb.y, secondRec.rb.x, secondRec.rb.y);
	bool bottomLeft = Intersection(firstRec.lb.x, firstRec.lb.y, firstRec.rb.x, firstRec.rb.y, secondRec.lb.x, secondRec.lb.y, secondRec.lt.x, secondRec.lt.y);
	bool leftTop = Intersection(firstRec.lb.x, firstRec.lb.y, firstRec.lt.x, firstRec.lt.y, secondRec.lt.x, secondRec.lt.y, secondRec.rt.x, secondRec.rt.y);
	bool leftRight = Intersection(firstRec.lb.x, firstRec.lb.y, firstRec.lt.x, firstRec.lt.y, secondRec.rb.x, secondRec.rb.y, secondRec.rt.x, secondRec.rt.y);
	bool leftBottom = Intersection(firstRec.lb.x, firstRec.lb.y, firstRec.lt.x, firstRec.lt.y, secondRec.lb.x, secondRec.lb.y, secondRec.rb.x, secondRec.rb.y);
	bool leftLeft = Intersection(firstRec.lb.x, firstRec.lb.y, firstRec.lt.x, firstRec.lt.y, secondRec.lb.x, secondRec.lb.y, secondRec.lt.x, secondRec.lt.y);
	bool recInRec;
	int recInRecCount = 0;
	int recInRecCountS = 0;
	k = 0;
	j = 0;
	kS = 0;
	jS = 0;
	for (i = firstRec.lt.x; i <= firstRec.rt.x; i += 0.1) {
		recInRec = Intersection((firstRec.lt.x + k), (firstRec.lt.y + j), (firstRec.lb.x + k), (firstRec.lb.y + j), secondRec.lt.x, secondRec.lt.y, secondRec.rt.x, secondRec.rt.y);
		if (recInRec != 0) {
			recInRecCount++;
		}
		recInRec = Intersection((firstRec.lt.x + k), (firstRec.lt.y + j), (firstRec.lb.x + k), (firstRec.lb.y + j), secondRec.rb.x, secondRec.rb.y, secondRec.rt.x, secondRec.rt.y);
		if (recInRec != 0) {
			recInRecCount++;
		}
		recInRec = Intersection((firstRec.lt.x + k), (firstRec.lt.y + j), (firstRec.lb.x + k), (firstRec.lb.y + j), secondRec.lb.x, secondRec.lb.y, secondRec.lt.x, secondRec.lt.y);
		if (recInRec != 0) {
			recInRecCount++;
		}
		recInRec = Intersection((firstRec.lt.x + k), (firstRec.lt.y + j), (firstRec.lb.x + k), (firstRec.lb.y + j), secondRec.lb.x, secondRec.lb.y, secondRec.lt.x, secondRec.lt.y);
		if (recInRec != 0) {
			recInRecCount++;
		}
		if (firstRec.lt.x < firstRec.rt.x)
			k += 0.1;
		else
			k -= 0.1;
		if (firstRec.lt.y < firstRec.rt.y)
			j += 0.1;
		else if (firstRec.lt.y > firstRec.rt.y)
			j -= 0.1;
		else
			j = 0;
	}
	for (i = secondRec.lt.x; i <= secondRec.rt.x; i += 0.1) {
		recInRec = Intersection((secondRec.lt.x + kS), (secondRec.lt.y + jS), (secondRec.lb.x + kS), (secondRec.lb.y + jS), firstRec.lt.x, firstRec.lt.y, firstRec.rt.x, firstRec.rt.y);
		if (recInRec != 0) {
			recInRecCountS++;
		}
		recInRec = Intersection((secondRec.lt.x + kS), (secondRec.lt.y + jS), (secondRec.lb.x + kS), (secondRec.lb.y + jS), firstRec.rb.x, firstRec.rb.y, firstRec.rt.x, firstRec.rt.y);
		if (recInRec != 0) {
			recInRecCountS++;
		}
		recInRec = Intersection((secondRec.lt.x + kS), (secondRec.lt.y + jS), (secondRec.lb.x + kS), (secondRec.lb.y + jS), firstRec.lb.x, firstRec.lb.y, firstRec.lt.x, firstRec.lt.y);
		if (recInRec != 0) {
			recInRecCountS++;
		}
		recInRec = Intersection((secondRec.lt.x + kS), (secondRec.lt.y + jS), (secondRec.lb.x + kS), (secondRec.lb.y + jS), firstRec.lb.x, firstRec.lb.y, firstRec.lt.x, firstRec.lt.y);
		if (recInRec != 0) {
			recInRecCountS++;
		}
		if (secondRec.lt.x < secondRec.rt.x)
			kS += 0.1;
		else
			kS -= 0.1;
		if (secondRec.lt.y < secondRec.rt.y)
			jS += 0.1;
		else if (secondRec.lt.y > secondRec.rt.y)
			jS -= 0.1;
		else
			jS = 0;
	}
	if ((topTop || topRight || topBottom || topLeft || rightTop || rightRight || rightBottom || rightLeft || bottomTop || bottomRight || bottomBottom || bottomLeft || leftTop || leftRight || leftBottom || leftLeft || recInRecCount || recInRecCountS) == 0) {
		return false;
	}
	else {
		return true;
	}
}