#include <iostream>
#include "triangle.h"
#include "pyramid.h"

using namespace std;

void lab1(){
	cout << "������ � �������� " << endl << "������� ���������� ��������� �������: ";
	int n;
	cin >> n;
	triangle* mass = new triangle[n];
	for (int i = 0; i < n; i++) {
		float a, b, ung;
		cout << endl << "mass[" << i << "]" << endl;
		cout << "a= ";
		cin >> a; mass[i].setSideA(a);
		cout << "b= ";
		cin >> b;  mass[i].setSideB(b);
		cout << "����= ";
		cin >> ung; mass[i].setSideAngle(ung);
		cout << "c= " << mass[i].getSideC() << endl;
		cout << "P = " << mass[i].Perimetr() << endl;
		cout << "S = " << mass[i].Area() << endl;
		cout << "���������� ��������� � \t ++mass[i] = " << (++mass[i]).getSideA();
		cout << "\t mass[i] = " << mass[i].getSideA() << endl;
		cout << "���������� ��������� � \t --mass[i] = " << (--mass[i]).getSideA();
		cout << "\t mass[i] = " << mass[i].getSideA() << endl;
		cout << "����������� ��������� � \t mass[i]++ = " << (mass[i]++).getSideA();
		cout << "\t mass[i] = " << mass[i].getSideA() << endl;
		cout << "����������� ��������� � \t mass[i]-- = " << (mass[i]--).getSideA();
		cout << "\t mass[i] = " << mass[i].getSideA() << endl;
	}
	cout << endl << "������ � ������������ �������� " << endl;
	triangle* dynmicObject = new triangle;
	float a, b, ung;
	cout << "a= ";
	cin >> a; (*dynmicObject).setSideA(a);
	cout << "b= ";
	cin >> b; (*dynmicObject).setSideB(b);
	cout << "����= ";
	cin >> ung; (*dynmicObject).setSideAngle(ung);
	cout << "c= " << (*dynmicObject).getSideC() << endl;
	cout << "P = " << (*dynmicObject).Perimetr() << endl;
	cout << "S = " << (*dynmicObject).Area() << endl;

	cout << endl << "������ � ������� �������� " << endl;
	triangle rezTr;
	triangle ** set = new triangle *[2];
	set[0] = mass;
	set[1] = dynmicObject;
	rezTr = (*set[0]) + (*set[1]);
	cout << endl << "��������� �������� ���� ������������� " << endl << " a= " << rezTr.getSideA() << " b= " << rezTr.getSideB() << " ����= " << rezTr.getSideAngle() << " c= " << rezTr.getSideC() << endl;
	rezTr = (*set[0]) * (*set[1]);
	cout << endl << "��������� ��������� ���� ������������� " << endl << " a= " << rezTr.getSideA() << " b= " << rezTr.getSideB() << " ����= " << rezTr.getSideAngle() << " c= " << rezTr.getSideC() << endl;
	delete dynmicObject, rezTr;
	delete[] mass;
	delete[] set;
}

void lab2() {
	cout << "������ � �������� " << endl << "������� ���������� ��������� �������: ";
	int n;
	cin >> n;
	pyramid* mass = new pyramid[n];
	for (int i = 0; i < n; i++) {
		float a, b, ung, height;
		cout << endl << "mass[" << i << "]" << endl<<"���������: "<<endl;
		cout << "a= ";
		cin >> a; mass[i].setSideA(a);
		cout << "b= ";
		cin >> b;  mass[i].setSideB(b);
		cout << "����= ";
		cin >> ung; mass[i].setSideAngle(ung);
		cout << "c= " << mass[i].getSideC() << endl;
		cout << "�������� = " << mass[i].Perimetr() << endl;
		cout << "������� = " << mass[i].Area() << endl;
		cout << "������= ";
		cin >> height;  mass[i].setHeight(height);
		cout << "����� = " << mass[i].Volume() << endl;
	}
	cout << endl << "�������� ������� ���� �������" << endl;
	cout << "�������� [0] - �������� [1] " << endl << mass[0] - mass[1] << endl << endl;

	cout << "�������� ������������ " << endl;
	mass[0] = mass[1];
	mass[0].Show();
	cout << "�������� [0] = �������� [1]" << endl << "������� �: " << mass[0].getSideA() << ", ������� b: " << mass[0].getSideB() << ", ������� c: " << mass[0].getSideC() << ", ������: " << mass[0].getHeight() << ", �����: " << mass[0].Volume() << endl << endl;
}
void lab3() {
	triangle objectTriangle(5, 8, 45);
	pyramid objectPyramid(3, 6, 35, 12);
	triangle* pT = &objectTriangle;
	pyramid* pP = &objectPyramid;
	cout << "�����������" << endl;
	pT->Show();
	cout << endl << endl << "��������" << endl;
	pP->Show();
	pT = &objectPyramid;
	//pP = &objectTriangle;
	cout << endl << endl << "pT = &objectPyramid" << endl;
	pT->Show();

}
int main() {
	setlocale(LC_ALL, "rus");
	lab3();
	return 0;
}
