#include< iostream>
using namespace std;
class Shape {


public:


	Shape() {

	}

	//pure virtual function area()
	virtual  double area() = 0;

	~Shape() {

	}
};

class Circle {
	double radius;
public:

	Circle(double  r) {
		radius = r;
	}


	double area() {

		return 3.1416 * radius * radius;
	}


};


class  Rectangle {

	double length;
	double width;

public:

	Rectangle(double l, double w) {
		length = l;
		width = w;
	}

	double area() {
		return length * width;
		return 0;
	}

	template < class T  >
	void display (T obj) {

		cout << "Area : " << obj.area() << endl;
	}


};



int  main() {

	Circle c(5);
	Rectangle r(4, 6);

	r.display(c);
	r.display(r);

	return 0;
}


