#include <iostream>
#include "triangle.h"
#include "pyramid.h"

using namespace std;

void lab1(){
	cout << "Работа с массивом " << endl << "Введите количество элементов массива: ";
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
		cout << "Угол= ";
		cin >> ung; mass[i].setSideAngle(ung);
		cout << "c= " << mass[i].getSideC() << endl;
		cout << "P = " << mass[i].Perimetr() << endl;
		cout << "S = " << mass[i].Area() << endl;
		cout << "Префиксный инкремент а \t ++mass[i] = " << (++mass[i]).getSideA();
		cout << "\t mass[i] = " << mass[i].getSideA() << endl;
		cout << "Префиксный декремент а \t --mass[i] = " << (--mass[i]).getSideA();
		cout << "\t mass[i] = " << mass[i].getSideA() << endl;
		cout << "Постфиксный инкремент а \t mass[i]++ = " << (mass[i]++).getSideA();
		cout << "\t mass[i] = " << mass[i].getSideA() << endl;
		cout << "Постфиксный декремент а \t mass[i]-- = " << (mass[i]--).getSideA();
		cout << "\t mass[i] = " << mass[i].getSideA() << endl;
	}
	cout << endl << "Работа с динамическим объектом " << endl;
	triangle* dynmicObject = new triangle;
	float a, b, ung;
	cout << "a= ";
	cin >> a; (*dynmicObject).setSideA(a);
	cout << "b= ";
	cin >> b; (*dynmicObject).setSideB(b);
	cout << "Угол= ";
	cin >> ung; (*dynmicObject).setSideAngle(ung);
	cout << "c= " << (*dynmicObject).getSideC() << endl;
	cout << "P = " << (*dynmicObject).Perimetr() << endl;
	cout << "S = " << (*dynmicObject).Area() << endl;

	cout << endl << "Работа с набором объектов " << endl;
	triangle rezTr;
	triangle ** set = new triangle *[2];
	set[0] = mass;
	set[1] = dynmicObject;
	rezTr = (*set[0]) + (*set[1]);
	cout << endl << "Результат сложения двух треугольников " << endl << " a= " << rezTr.getSideA() << " b= " << rezTr.getSideB() << " Угол= " << rezTr.getSideAngle() << " c= " << rezTr.getSideC() << endl;
	rezTr = (*set[0]) * (*set[1]);
	cout << endl << "Результат умножения двух треугольников " << endl << " a= " << rezTr.getSideA() << " b= " << rezTr.getSideB() << " Угол= " << rezTr.getSideAngle() << " c= " << rezTr.getSideC() << endl;
	delete dynmicObject, rezTr;
	delete[] mass;
	delete[] set;
}

void lab2() {
	cout << "Работа с массивом " << endl << "Введите количество элементов массива: ";
	int n;
	cin >> n;
	pyramid* mass = new pyramid[n];
	for (int i = 0; i < n; i++) {
		float a, b, ung, height;
		cout << endl << "mass[" << i << "]" << endl<<"Основание: "<<endl;
		cout << "a= ";
		cin >> a; mass[i].setSideA(a);
		cout << "b= ";
		cin >> b;  mass[i].setSideB(b);
		cout << "Угол= ";
		cin >> ung; mass[i].setSideAngle(ung);
		cout << "c= " << mass[i].getSideC() << endl;
		cout << "Периметр = " << mass[i].Perimetr() << endl;
		cout << "Площадь = " << mass[i].Area() << endl;
		cout << "Высота= ";
		cin >> height;  mass[i].setHeight(height);
		cout << "Объём = " << mass[i].Volume() << endl;
	}
	cout << endl << "Разность объёмов двух пирамид" << endl;
	cout << "Пирамида [0] - Пирамида [1] " << endl << mass[0] - mass[1] << endl << endl;

	cout << "Операция присваивания " << endl;
	mass[0] = mass[1];
	mass[0].Show();
	cout << "Пирамида [0] = Пирамида [1]" << endl << "Сторона а: " << mass[0].getSideA() << ", сторона b: " << mass[0].getSideB() << ", сторона c: " << mass[0].getSideC() << ", высота: " << mass[0].getHeight() << ", объём: " << mass[0].Volume() << endl << endl;
}
void lab3() {
	triangle objectTriangle(5, 8, 45);
	pyramid objectPyramid(3, 6, 35, 12);
	triangle* pT = &objectTriangle;
	pyramid* pP = &objectPyramid;
	cout << "Треугольник" << endl;
	pT->Show();
	cout << endl << endl << "Пирамида" << endl;
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
