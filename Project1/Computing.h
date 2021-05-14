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

double NumInDouble(); // ������� �������� ������������ ����� ��� ���������� ���� double
int NumInInt(); // ������� �������� ������������ ����� ��� ���������� ���� int
bool CheckAngle(rectangle rec); // �������, ����������� �������� ������ 
                                     //�� ����������� �������������� �� ���
bool CheckAngle_textless(rectangle rec); // �������, ����������� ��������
                                                            //������ �� ����������� �������������� �� ��� ��� ������������
bool Intersection(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy); // �������,
                                                                  //����������� ����������� �������� �� ������ �����
bool Intersection_Result(rectangle firstRec, rectangle secondRec); // �������, ����������� �������
                                                             //����� ������� � ���� ���������������
bool Intersection_Result_textless(rectangle firstRec, rectangle secondRec); // �������, ����������� �������
                                                            //����� ������� � ���� ��������������� ��� ������������