#pragma once
class Vector {
public:
	Vector();
	Vector(double x, double y);

	Vector add(Vector);
	Vector sub(Vector);

	Vector multiply(Vector);
	Vector divide(Vector);

	Vector rotate(double);
	Vector rotate(double, Vector);

	double getX();
	double getY();

	void print();

private:
	double x;
	double y;
};

