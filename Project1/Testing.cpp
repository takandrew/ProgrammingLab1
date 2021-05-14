#include<iostream>
#include"Computing.h"

using namespace std;

// Вывод исходных данных в случае ошибки в тестировании основного алгоритма программы
void CoutingIntersectionResultTesting(rectangle testFirst, rectangle testSecond) {
	cout << "Исходные данные:" << endl;
	cout << "Координаты верхней левой точки первого прямоугольника:" << endl;
	cout << "x = " << testFirst.lt.x << endl << "y = " << testFirst.lt.y << endl;
	cout << "Координаты нижней правой точки первого прямоугольника:" << endl;
	cout << "x = " << testFirst.rb.x << endl << "y = " << testFirst.rb.y << endl;
	cout << "Координаты верхней правой точки первого прямоугольника:" << endl;
	cout << "x = " << testFirst.rt.x << endl << "y = " << testFirst.rt.y << endl;
	cout << "Координаты нижней левой точки первого прямоугольника:" << endl;
	cout << "x = " << testFirst.lb.x << endl << "y = " << testFirst.lb.y << endl;
	cout << "Координаты верхней левой точки второго прямоугольника:" << endl;
	cout << "x = " << testSecond.lt.x << endl << "y = " << testSecond.lt.y << endl;
	cout << "Координаты нижней правой точки второго прямоугольника:" << endl;
	cout << "x = " << testSecond.rb.x << endl << "y = " << testSecond.rb.y << endl;
	cout << "Координаты верхней правой точки второго прямоугольника:" << endl;
	cout << "x = " << testSecond.rt.x << endl << "y = " << testSecond.rt.y << endl;
	cout << "Координаты нижней левой точки второго прямоугольника:" << endl;
	cout << "x = " << testSecond.lb.x << endl << "y = " << testSecond.lb.y << endl;
}

// Тестирование модулей программы
void TestingModules() {
	int countGoodTest = 0; // Счетчик успешно пройденных тестов
	// Тестирование модуля проверки составления прямоугольников
	rectangle testAngleFirstRec, testAngleSecondRec, testAngleThirdRec, testAngleFourthRec, testAngleFifthRec;
	testAngleFirstRec.lt.x = 0.0; testAngleFirstRec.lt.y = 10.0;
	testAngleFirstRec.rt.x = 10.0; testAngleFirstRec.rt.y = 10.0;
	testAngleFirstRec.rb.x = 10.0; testAngleFirstRec.rb.y = 0.0;
	testAngleSecondRec.lt.x = 0; testAngleSecondRec.lt.y = 10;
	testAngleSecondRec.rt.x = 20; testAngleSecondRec.rt.y = 10;
	testAngleSecondRec.rb.x = 10; testAngleSecondRec.rb.y = 0;
	testAngleThirdRec.lt.x = -6; testAngleThirdRec.lt.y = 1;
	testAngleThirdRec.rt.x = -2; testAngleThirdRec.rt.y = 5;
	testAngleThirdRec.rb.x = 3; testAngleThirdRec.rb.y = 0;
	testAngleFourthRec.lt.x = 1.5; testAngleFourthRec.lt.y = 2.7;
	testAngleFourthRec.rt.x = 6.3; testAngleFourthRec.rt.y = 2.7;
	testAngleFourthRec.rb.x = 6.3; testAngleFourthRec.rb.y = -1.4;
	testAngleFifthRec.lt.x = 0; testAngleFifthRec.lt.y = 5;
	testAngleFifthRec.rt.x = 16; testAngleFifthRec.rt.y = 2;
	testAngleFifthRec.rb.x = 16; testAngleFifthRec.rb.y = 0;
	bool testAngleFirst = CheckAngle_textless(testAngleFirstRec);
	bool testAngleSecond = CheckAngle_textless(testAngleSecondRec);
	bool testAngleThird = CheckAngle_textless(testAngleThirdRec);
	bool testAngleFourth = CheckAngle_textless(testAngleFourthRec);
	bool testAngleFifth = CheckAngle_textless(testAngleFifthRec);
	if (testAngleFirst && (!testAngleSecond) && testAngleThird && testAngleFourth && (!testAngleFifth)) {
		countGoodTest++;
	}
	else {
		cout << "Тестирование модуля проверки составления прямоугольников провалилось." << endl;
		if (!testAngleFirst) {
			cout << "Исходные данные:" << endl;
			cout << "Координаты верхней левой точки прямоугольника: " << endl;
			cout << "x = " << testAngleFirstRec.lt.x << endl << "y = " << testAngleFirstRec.lt.y << endl;
			cout << "Координаты нижней правой точки прямоугольника: " << endl;
			cout << "x = " << testAngleFirstRec.rb.x << endl << "y = " << testAngleFirstRec.rb.y << endl;
			cout << "Координаты верхней правой точки прямоугольника: " << endl;
			cout << "x = " << testAngleFirstRec.rt.x << endl << "y = " << testAngleFirstRec.rt.y << endl;
			cout << "Полученный результат: Точки не образуют прямоугольник." << endl;
			cout << "Ожидаемый результат: Точки образуют прямоугольник." << endl;
		}
		if (testAngleSecond) {
			cout << "Исходные данные:" << endl;
			cout << "Координаты верхней левой точки прямоугольника: " << endl;
			cout << "x = " << testAngleSecondRec.lt.x << endl << "y = " << testAngleSecondRec.lt.y << endl;
			cout << "Координаты нижней правой точки прямоугольника: " << endl;
			cout << "x = " << testAngleSecondRec.rb.x << endl << "y = " << testAngleSecondRec.rb.y << endl;
			cout << "Координаты верхней правой точки прямоугольника: " << endl;
			cout << "x = " << testAngleSecondRec.rt.x << endl << "y = " << testAngleSecondRec.rt.y << endl;
			cout << "Полученный результат: Точки образуют прямоугольник." << endl;
			cout << "Ожидаемый результат: Точки не образуют прямоугольник." << endl;
		}
		if (!testAngleThird) {
			cout << "Исходные данные:" << endl;
			cout << "Координаты верхней левой точки прямоугольника: " << endl;
			cout << "x = " << testAngleThirdRec.lt.x << endl << "y = " << testAngleThirdRec.lt.y << endl;
			cout << "Координаты нижней правой точки прямоугольника: " << endl;
			cout << "x = " << testAngleThirdRec.rb.x << endl << "y = " << testAngleThirdRec.rb.y << endl;
			cout << "Координаты верхней правой точки прямоугольника: " << endl;
			cout << "x = " << testAngleThirdRec.rt.x << endl << "y = " << testAngleThirdRec.rt.y << endl;
			cout << "Полученный результат: Точки не образуют прямоугольник." << endl;
			cout << "Ожидаемый результат: Точки образуют прямоугольник." << endl;
		}
		if (!testAngleFourth) {
			cout << "Исходные данные:" << endl;
			cout << "Координаты верхней левой точки прямоугольника: " << endl;
			cout << "x = " << testAngleFourthRec.lt.x << endl << "y = " << testAngleFourthRec.lt.y << endl;
			cout << "Координаты нижней правой точки прямоугольника: " << endl;
			cout << "x = " << testAngleFourthRec.rb.x << endl << "y = " << testAngleFourthRec.rb.y << endl;
			cout << "Координаты верхней правой точки прямоугольника: " << endl;
			cout << "x = " << testAngleFourthRec.rt.x << endl << "y = " << testAngleFourthRec.rt.y << endl;
			cout << "Полученный результат: Точки не образуют прямоугольник." << endl;
			cout << "Ожидаемый результат: Точки образуют прямоугольник." << endl;
		}
		if (testAngleFifth) {
			cout << "Исходные данные:" << endl;
			cout << "Координаты верхней левой точки прямоугольника: " << endl;
			cout << "x = " << testAngleFifthRec.lt.x << endl << "y = " << testAngleFifthRec.lt.y << endl;
			cout << "Координаты нижней правой точки прямоугольника: " << endl;
			cout << "x = " << testAngleFifthRec.rb.x << endl << "y = " << testAngleFifthRec.rb.y << endl;
			cout << "Координаты верхней правой точки прямоугольника: " << endl;
			cout << "x = " << testAngleFifthRec.rt.x << endl << "y = " << testAngleFifthRec.rt.y << endl;
			cout << "Полученный результат: Точки образуют прямоугольник." << endl;
			cout << "Ожидаемый результат: Точки не образуют прямоугольник." << endl;
		}
	}
	// Тестирование модуля проверки пересечения отрезков
	point testFirstA, testFirstB, testFirstC, testFirstD, testSecondA, testSecondB, testSecondC, testSecondD,
		testThirdA, testThirdB, testThirdC, testThirdD, testFourthA, testFourthB, testFourthC, testFourthD,
		testFifthA, testFifthB, testFifthC, testFifthD;
	testFirstA.x = 0.0; testFirstA.y = 0.0; testFirstB.x = 3.0; testFirstB.y = 0.0;
	testFirstC.x = 1.0; testFirstC.y = -1.0; testFirstD.x = 1.0; testFirstD.y = 2.0;
	bool testFirst = Intersection(testFirstA.x, testFirstA.y, testFirstB.x, testFirstB.y,
		testFirstC.x, testFirstC.y, testFirstD.x, testFirstD.y);
	testSecondA.x = 0.0; testSecondA.y = 0.0; testSecondB.x = 3.0; testSecondB.y = 0.0;
	testSecondC.x = 0.0; testSecondC.y = -1.0; testSecondD.x = 3.0; testSecondD.y = -1.0;
	bool testSecond = Intersection(testSecondA.x, testSecondA.y, testSecondB.x, testSecondB.y,
		testSecondC.x, testSecondC.y, testSecondD.x, testSecondD.y);
	testThirdA.x = 5.0; testThirdA.y = 3.0; testThirdB.x = 7.0; testThirdB.y = 7.0;
	testThirdC.x = 6.0; testThirdC.y = 2.0; testThirdD.x = 4.0; testThirdD.y = 4.0;
	bool testThird = Intersection(testThirdA.x, testThirdA.y, testThirdB.x, testThirdB.y,
		testThirdC.x, testThirdC.y, testThirdD.x, testThirdD.y);
	testFourthA.x = -14; testFourthA.y = 15; testFourthB.x = 28; testFourthB.y = 15;
	testFourthC.x = -16; testFourthC.y = -10; testFourthD.x = 34; testFourthD.y = 25;
	bool testFourth = Intersection(testFourthA.x, testFourthA.y, testFourthB.x, testFourthB.y,
		testFourthC.x, testFourthC.y, testFourthD.x, testFourthD.y);
	testFifthA.x = 5; testFifthA.y = 125; testFifthB.x = 163; testFifthB.y = 122;
	testFifthC.x = 3; testFifthC.y = 15; testFifthD.x = 16; testFifthD.y = 25;
	bool testFifth = Intersection(testFifthA.x, testFifthA.y, testFifthB.x, testFifthB.y,
		testFifthC.x, testFifthC.y, testFifthD.x, testFifthD.y);
	if (testFirst && (!testSecond) && testThird && testFourth && (!testFifth)) {
		countGoodTest++;
	}
	else {
		cout << "Тестирование модуля проверки пересечения отрезков провалилось." << endl;
		if (!testFirst) {
			cout << "Исходные данные:" << endl;
			cout << "Начало первого отрезка:" << endl;
			cout << "x = " << testFirstA.x << endl << "y = " << testFirstA.y << endl;
			cout << "Конец первого отрезка:" << endl;
			cout << "x = " << testFirstB.x << endl << "y = " << testFirstB.y << endl;
			cout << "Начало второго отрезка:" << endl;
			cout << "x = " << testFirstC.x << endl << "y = " << testFirstC.y << endl;
			cout << "Конец второго отрезка:" << endl;
			cout << "x = " << testFirstD.x << endl << "y = " << testFirstD.y << endl;
			cout << "Полученный результат: Отрезки не пересекаются." << endl;
			cout << "Ожидаемый результат: Отрезки пересекаются." << endl;
		}
		if (testSecond) {
			cout << "Исходные данные:" << endl;
			cout << "Начало первого отрезка:" << endl;
			cout << "x = " << testSecondA.x << endl << "y = " << testSecondA.y << endl;
			cout << "Конец первого отрезка:" << endl;
			cout << "x = " << testSecondB.x << endl << "y = " << testSecondB.y << endl;
			cout << "Начало второго отрезка:" << endl;
			cout << "x = " << testSecondC.x << endl << "y = " << testSecondC.y << endl;
			cout << "Конец второго отрезка:" << endl;
			cout << "x = " << testSecondD.x << endl << "y = " << testSecondD.y << endl;
			cout << "Полученный результат: Отрезки пересекаются." << endl;
			cout << "Ожидаемый результат: Отрезки не пересекаются." << endl;
		}
		if (!testThird) {
			cout << "Исходные данные:" << endl;
			cout << "Начало первого отрезка:" << endl;
			cout << "x = " << testThirdA.x << endl << "y = " << testThirdA.y << endl;
			cout << "Конец первого отрезка:" << endl;
			cout << "x = " << testThirdB.x << endl << "y = " << testThirdB.y << endl;
			cout << "Начало второго отрезка:" << endl;
			cout << "x = " << testThirdC.x << endl << "y = " << testThirdC.y << endl;
			cout << "Конец второго отрезка:" << endl;
			cout << "x = " << testThirdD.x << endl << "y = " << testThirdD.y << endl;
			cout << "Полученный результат: Отрезки не пересекаются." << endl;
			cout << "Ожидаемый результат: Отрезки пересекаются." << endl;
		}
		if (!testFourth) {
			cout << "Исходные данные:" << endl;
			cout << "Начало первого отрезка:" << endl;
			cout << "x = " << testFourthA.x << endl << "y = " << testFourthA.y << endl;
			cout << "Конец первого отрезка:" << endl;
			cout << "x = " << testFourthB.x << endl << "y = " << testFourthB.y << endl;
			cout << "Начало второго отрезка:" << endl;
			cout << "x = " << testFourthC.x << endl << "y = " << testFourthC.y << endl;
			cout << "Конец второго отрезка:" << endl;
			cout << "x = " << testFourthD.x << endl << "y = " << testFourthD.y << endl;
			cout << "Полученный результат: Отрезки не пересекаются." << endl;
			cout << "Ожидаемый результат: Отрезки пересекаются." << endl;
		}
		if (testFifth) {
			cout << "Исходные данные:" << endl;
			cout << "Начало первого отрезка:" << endl;
			cout << "x = " << testFifthA.x << endl << "y = " << testFifthA.y << endl;
			cout << "Конец первого отрезка:" << endl;
			cout << "x = " << testFifthB.x << endl << "y = " << testFifthB.y << endl;
			cout << "Начало второго отрезка:" << endl;
			cout << "x = " << testFifthC.x << endl << "y = " << testFifthC.y << endl;
			cout << "Конец второго отрезка:" << endl;
			cout << "x = " << testFifthD.x << endl << "y = " << testFifthD.y << endl;
			cout << "Полученный результат: Отрезки пересекаются." << endl;
			cout << "Ожидаемый результат: Отрезки не пересекаются." << endl;
		}
	}
	// Тестирование модуля нахождения общей области двух прямоугольников 
	rectangle testFirstRecFirst, testFirstRecSecond;
	testFirstRecFirst.lt.x = 0; testFirstRecFirst.lt.y = 5;
	testFirstRecFirst.rb.x = 5; testFirstRecFirst.rb.y = 0;
	testFirstRecFirst.rt.x = 5; testFirstRecFirst.rt.y = 5;
	testFirstRecFirst.lb.x = 0; testFirstRecFirst.lb.y = 0;
	testFirstRecSecond.lt.x = 2; testFirstRecSecond.lt.y = 3;
	testFirstRecSecond.rb.x = 7; testFirstRecSecond.rb.y = -1;
	testFirstRecSecond.rt.x = 7; testFirstRecSecond.rt.y = 3;
	testFirstRecSecond.lb.x = 2; testFirstRecSecond.lb.y = -1;
	rectangle testSecondRecFirst, testSecondRecSecond;
	testSecondRecFirst.lt.x = 0; testSecondRecFirst.lt.y = 5;
	testSecondRecFirst.rb.x = 5; testSecondRecFirst.rb.y = 0;
	testSecondRecFirst.rt.x = 5; testSecondRecFirst.rt.y = 5;
	testSecondRecFirst.lb.x = 0; testSecondRecFirst.lb.y = 0;
	testSecondRecSecond.lt.x = 6; testSecondRecSecond.lt.y = 6;
	testSecondRecSecond.rb.x = 10; testSecondRecSecond.rb.y = 0;
	testSecondRecSecond.rt.x = 10; testSecondRecSecond.rt.y = 6;
	testSecondRecSecond.lb.x = 6; testSecondRecSecond.lb.y = 0;
	rectangle testThirdRecFirst, testThirdRecSecond;
	testThirdRecFirst.lt.x = 0; testThirdRecFirst.lt.y = 10;
	testThirdRecFirst.rb.x = 10; testThirdRecFirst.rb.y = 0;
	testThirdRecFirst.rt.x = 10; testThirdRecFirst.rt.y = 10;
	testThirdRecFirst.lb.x = 0; testThirdRecFirst.lb.y = 0;
	testThirdRecSecond.lt.x = 1; testThirdRecSecond.lt.y = 8;
	testThirdRecSecond.rb.x = 8; testThirdRecSecond.rb.y = 1;
	testThirdRecSecond.rt.x = 8; testThirdRecSecond.rt.y = 8;
	testThirdRecSecond.lb.x = 1; testThirdRecSecond.lb.y = 1;
	rectangle testFourthRecFirst, testFourthRecSecond;
	testFourthRecFirst.lt.x = -150; testFourthRecFirst.lt.y = 420;
	testFourthRecFirst.rb.x = 340; testFourthRecFirst.rb.y = -214;
	testFourthRecFirst.rt.x = 340; testFourthRecFirst.rt.y = 420;
	testFourthRecFirst.lb.x = -150; testFourthRecFirst.lb.y = -214;
	testFourthRecSecond.lt.x = 15; testFourthRecSecond.lt.y = 25;
	testFourthRecSecond.rb.x = 16; testFourthRecSecond.rb.y = 24;
	testFourthRecSecond.rt.x = 16; testFourthRecSecond.rt.y = 25;
	testFourthRecSecond.lb.x = 15; testFourthRecSecond.lb.y = 24;
	rectangle testFifthRecFirst, testFifthRecSecond;
	testFifthRecFirst.lt.x = 0.5; testFifthRecFirst.lt.y = 0.6;
	testFifthRecFirst.rb.x = 0.9; testFifthRecFirst.rb.y = 0.2;
	testFifthRecFirst.rt.x = 0.9; testFifthRecFirst.rt.y = 0.6;
	testFifthRecFirst.lb.x = 0.5; testFifthRecFirst.lb.y = 0.2;
	testFifthRecSecond.lt.x = 0; testFifthRecSecond.lt.y = 0.6;
	testFifthRecSecond.rb.x = 0.4; testFifthRecSecond.rb.y = 0.2;
	testFifthRecSecond.rt.x = 0.4; testFifthRecSecond.rt.y = 0.6;
	testFifthRecSecond.lb.x = 0; testFifthRecSecond.lb.y = 0.2;
	bool testFirstRecBoth = Intersection_Result_textless(testFirstRecFirst, testFirstRecSecond);
	bool testSecondRecBoth = Intersection_Result_textless(testSecondRecFirst, testSecondRecSecond);
	bool testThirdRecBoth = Intersection_Result_textless(testThirdRecFirst, testThirdRecSecond);
	bool testFourthRecBoth = Intersection_Result_textless(testFourthRecFirst, testFourthRecFirst);
	bool testFifthRecBoth = Intersection_Result_textless(testFifthRecFirst, testFifthRecSecond);
	if (testFirstRecBoth && (!testSecondRecBoth) && testThirdRecBoth && testFourthRecBoth && (!testFifthRecBoth)) {
		countGoodTest++;
	}
	else {
		cout << "Тестирование модуля нахождения общей области двух прямоугольников провалилось." << endl;
		if (!testFirstRecBoth) {
			CoutingIntersectionResultTesting(testFirstRecFirst, testFirstRecSecond);
			cout << "Полученный результат: Прямоугольники не имеют общей области." << endl;
			cout << "Ожидаемый результат: Прямоугольники имеют общую область." << endl;
		}
		if (testSecondRecBoth) {
			CoutingIntersectionResultTesting(testSecondRecFirst, testSecondRecSecond);
			cout << "Полученный результат: Прямоугольники имеют общую область." << endl;
			cout << "Ожидаемый результат: Прямоугольники не имеют общей области." << endl;
		}
		if (!testThirdRecBoth) {
			CoutingIntersectionResultTesting(testThirdRecFirst, testThirdRecSecond);
			cout << "Полученный результат: Прямоугольники не имеют общей области." << endl;
			cout << "Ожидаемый результат: Прямоугольники имеют общую область." << endl;
		}
		if (!testFourthRecBoth) {
			CoutingIntersectionResultTesting(testFourthRecFirst, testFourthRecSecond);
			cout << "Полученный результат: Прямоугольники не имеют общей области." << endl;
			cout << "Ожидаемый результат: Прямоугольники имеют общую область." << endl;
		}
		if (testFifthRecBoth) {
			CoutingIntersectionResultTesting(testFifthRecFirst, testFifthRecSecond);
			cout << "Полученный результат: Прямоугольники имеют общую область." << endl;
			cout << "Ожидаемый результат: Прямоугольники не имеют общей области." << endl;
		}
	}
	int testSuccess = 3;
	if (countGoodTest == testSuccess) // Проверка количества успешно пройденных тестов
		cout << "Тестирование проведено успешно." << endl;
	else
		cout << "Тестирование провалилось." << endl;
}
