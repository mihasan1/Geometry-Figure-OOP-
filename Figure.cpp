
#include <iostream>
#include <cmath>
#define Pi 3.14159265358979323846

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
	double AB, BC, CD, AD;
	double P;
	double S;
	Quadrangle() {};

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
	double r, R;
	Quadrat(Point A1, Point B1, Point C1, Point D1) : Quadrangle(A1, B1, C1, D1) {};
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
	Paralelogram() {};
	Paralelogram(Point A2, Point B2, Point C2, Point D2) : Quadrangle(A2, B2, C2, D2) {};
	double cosBAD, sinBAD, VecAB, VecAD, Ugol, h, d1, d2, RAD;
	int gr;
	void Height()
	{
		if (AB == CD && BC == AD && AB != AD)
		{
			h = AB * sinBAD;
			cout << "Висота: " << h << endl;
		}
	}
	void Area()
	{
		S = AD * h;
		cout << "S = " << S << endl;
	}
	Point Vector(Point AA, Point BB)
	{
		Point Vec;
		Vec.x = BB.x - AA.x;
		Vec.y = BB.y - AA.y;
		cout << "Координати вектора: \nx = " << Vec.x << "\n y = " << Vec.y << endl;
		return Vec;
	}

	void VectorLenght(Point Vector1, Point Vector2)
	{
		VecAB = sqrt(pow(Vector1.x, 2) + pow(Vector1.y, 2));
		VecAD = sqrt(pow(Vector2.x, 2) + pow(Vector2.y, 2));
		cout << "Довжини векторів. AB = " << VecAB << ", AD = " << VecAD << endl;
	}
	void CCos(Point A, Point B)
	{
		RAD = (A.x * B.x + A.y * B.y) / (VecAD * VecAD);
		sinBAD = sqrt(1 - pow(RAD, 2));
		cout << "RAD = " << RAD << endl;
		cout << "sin Alpha = " << sinBAD << endl;
	}
	void Diagonal()
	{
		d1 = sqrt(pow(AB, 2) + pow(AD, 2) + 2 * AB + AD * RAD);
		d2 = sqrt(pow(AB, 2) + pow(AD, 2) - 2 * AB + AD * RAD);
		cout << "D1 = " << d1 << " D2 = " << d2 << endl;
	}
};

class Rhombus : public Paralelogram
{
public:
	Rhombus(Point A3, Point B3, Point C3, Point D3) : Paralelogram(A3, B3, C3, D3) {};
	void Diagonal()
	{
		d1 = sqrt(pow(C.x - A.x, 2) + pow(C.y - A.y, 2));
		d2 = sqrt(pow(C.x - D.x, 2) + pow(C.y - D.y, 2));
		cout << "D1 = " << d1 << " D2 = " << d2 << endl;
	}
	void Area()
	{
		S =(0.5)*d1*d2;
		cout << "S = " << S << endl;
	}

};

int main()
{
	setlocale(LC_ALL, "RUS");
	Point A1(0, 0), B1(0, 4), C1(4, 4), D1(4, 0);
	Quadrat Q1(A1, B1, C1, D1);
	cout << "Quadrat\n";
	Q1.Print_Quad();
	Q1.Size();
	Q1.Perimeter();
	Q1.Area();
	Q1.rVpis();
	Q1.ROpis();

	Point A2(0, 0), B2(6, 8), C2(24, 8), D2(18, 0), AB, AD;
	Paralelogram P1(A2, B2, C2, D2);
	cout << "\n\nParalelogram\n";
	P1.Print_Quad();
	P1.Size();
	P1.Perimeter();
	AB = P1.Vector(A2, B2);
	AD = P1.Vector(A2, D2);
	P1.VectorLenght(AB, AD);
	P1.CCos(AB, AD);
	P1.Height();
	P1.Area();
	P1.Diagonal();

	Point A3(-6, 0), B3(0, 8), C3(6, 0), D3(0, -8);
	Rhombus R1(A3, B3, C3, D3);
	cout << "\n\nRhombus" << endl;
	R1.Print_Quad();
	R1.Size();
	R1.Perimeter();
	R1.Diagonal();
	R1.Area();
	return 0;
}