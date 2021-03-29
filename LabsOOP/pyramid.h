#pragma once
#include "triangle.h"
using namespace std;

class pyramid : public triangle
{
private: 
	float height;
public:
	pyramid(): triangle() {
		height = 7; sideC = SearchSideC();
	}
	pyramid(float a, float b, float ung, float h) : triangle(a, b, ung) {
		height = h; sideC = SearchSideC();
	}
	float getHeight() { return height; };
	void setHeight(float h) { height = h; };
	
	float Volume() {
		return (Area()*height) / 3;
	}
	virtual void Show() {
		cout << " a= " << this->sideA << "; b= " << this->sideB << "; Угол= " << this->angle << "; c= " << this->sideC <<  "; Площадь= " << this->Area() << "; Периметр= " << this->Perimetr() << "; h= " << this->height << "; Объём= " << this->Volume();
	}
	float friend operator - (pyramid ob1, pyramid ob2) { return abs(ob1.Volume() - ob2.Volume()); }
	pyramid & operator = (const pyramid& ob) { sideA = ob.sideA; sideB = ob.sideB; angle = ob.angle; sideC = ob.sideC; height = ob.height; return*this; }

};

