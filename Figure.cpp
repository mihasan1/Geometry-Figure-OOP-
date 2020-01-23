#include <iostream>
#include <cmath>

using namespace std;

class Point
{
public:
	int x;
	int y;
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int x_, int y_)
	{
		x = x_;
		y = y_;
	}

	void out_Coords()
	{
		cout << "X= " << x << " Y= " << y << endl;;
	}
};

class Quadrangle
{
public:
	Point A, B, C, D;
	float AB, BC, CD, AD;
	float P;
	float S;
	Quadrangle();

	Quadrangle(Point AA, Point BB, Point CC, Point DD)
	{
		A = AA;
		B = BB;
		C = CC;
		D = DD;
	}
	void Print_Quad()
	{
		A.out_Coords();
		B.out_Coords();
		C.out_Coords();
		D.out_Coords();
	}
	void Size()
	{
		AB = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
		BC = sqrt(pow(C.x - B.x, 2) + pow(C.y - B.y, 2));
		CD = sqrt(pow(D.x - C.x, 2) + pow(D.y - C.y, 2));
		AD = sqrt(pow(D.x - A.x, 2) + pow(D.y - A.y, 2));
		cout << "\nAB = " << AB << "\nBC = " << BC << "\nCD = " << CD << "\nAD = " << AD << endl;
	}
	void Perimeter()
	{
		P = AB + BC + CD + AD;
		cout << "\nP = " << P << endl;;
	}
	
};

class Quadrat : public Quadrangle
{
public:
	float r, R;
	Quadrat(Point A1, Point B1, Point C1, Point D1) : Quadrangle(A1,B1,C1,D1) {};
	void Area()
	{
		S = AB * AB;
		cout << "S = " << S << endl;;
	}
	void rVpis()
	{
		r = AB / 2;
		cout << "r = " << r << endl;
	}
	void ROpis()
	{
		R = AB / sqrt(2);
		cout << "R = " << R << endl;
	}
};

class Paralelogram : public Quadrangle
{
public:
	Paralelogram(Point A2, Point B2, Point C2, Point D2) : Quadrangle(A2, B2, C2, D2) {};
	float h;
	void Height()
	{
		Point E(B.x, 0);
		float AE = sqrt(pow(E.x - A.x, 2) + pow(E.y - A.y, 2));
		cout << "AE = " << AE << "сm\n";
		h = sqrt(pow(AB, 2) - pow(AE, 2));
		cout << "h = " << h << endl;
	}
	void Area()
	{
		S = AD * h;
		cout << "S = " << S << endl;
	}

};

int main()
{
	setlocale(LC_ALL, "RUS");
	Point A1(0, 0), B1(0, 4), C1(4, 4), D1(4, 0);
	Quadrat Q1(A1,B1,C1,D1);
	cout << "--- Квадрат ---\n";
	Q1.Print_Quad();
	Q1.Size();
	Q1.Perimeter();
	Q1.Area();
	Q1.rVpis();
	Q1.ROpis();

	Point A2(0, 0), B2(6,8), C2(24, 8), D2(18, 0);
	Paralelogram P1(A2, B2, C2, D2);
	cout << "--- Паралелограм ---\n";
	P1.Print_Quad();
	P1.Size();
	P1.Perimeter();
	P1.Height();
	P1.Area();

	return 0;
}

