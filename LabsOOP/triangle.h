#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

class triangle
{
protected:
	float sideA;
	float sideB;
	float sideC;
	float angle;
public:
	triangle() {
		sideA = 1;
		sideB = 1;
		angle = 90;
		sideC = SearchSideC();
	}
	triangle(float a, float b, float ung) {
		sideA = a;
		sideB = b;
		angle = ung;
		sideC = SearchSideC();
	}
	float getSideA() { return sideA; };
	void setSideA(float a) {
		sideA = a; sideC = SearchSideC();
	};

	float getSideB() { return sideB; };
	void setSideB(float B) { sideB = B; sideC = SearchSideC(); };

	float getSideC() { return sideC; };

	float getSideAngle() { return angle; };
	void setSideAngle(float ung) { angle = ung; };

	float SearchSideC() {
		return sqrt((sideB * sideB) + (sideA * sideA) - (2 * sideB * sideA * (cos((angle * M_PI) / 180))));
	}
	float Perimetr() {
		return sideA + sideB + sideC;
	}
	float Area() {
		return (sideA * sideB * (sin((angle * M_PI) / 180))) / 2;
	}

	triangle operator + (triangle ob) { return triangle(sideA + ob.sideA, sideB + ob.sideB, (angle + ob.angle) / 2); }
	triangle operator * (triangle ob) { return triangle(sideA * ob.sideA, sideB * ob.sideB, (angle + ob.angle) / 2); }
	triangle operator ++() { ++sideA; sideC = SearchSideC();  return *this; }
	triangle friend operator--(triangle& ob) { --ob.sideA; ob.sideC = ob.SearchSideC();  return ob; }
	triangle operator ++(int) { triangle tmp = *this; sideA++; sideC = SearchSideC();  return tmp; }
	triangle friend operator--(triangle& ob, int) {
		triangle tmp = ob; ob.sideA--; ob.sideC = ob.SearchSideC();
		return tmp;
	}
	virtual void Show() {
		cout << " a= " << this->sideA << "; b= " << this->sideB << "; Угол= " << this->angle << "; c= " << this->sideC << "; Площадь= " << this->Area() << "; Периметр= " << this->Perimetr();
	}
};

