#include <iostream>
#include <cmath>

using namespace std;

class Point {
  double x_;
  double y_;

public:

  Point(double x = 0.0, double y = 0.0) {
    x_ = x;
    y_ = y;
  };

  double get_x() {
    return x_;
  }
  void set_x(double x) {
    x_ = x;
  }

  double get_y() {
    return y_;
  }
  void set_y(double y) {
    y_ = y;
  }

  void add(Point other) {
    x_ += other.x_;
    y_ += other.y_;
  }

  void sub(Point other) {
    x_ -= other.x_;
    y_ -= other.y_;
  }

  void print() {
    cout << "(" << x_ << ", " << y_ << ")" << endl;
  }

  double distance(Point other) {
    double d1 = x_ - other.x_;
    double d2 = y_ - other.y_;

    return sqrt(d1 * d1 + d2 * d2);
  }

  Point add(Point p1, Point p2) {
    Point result(p1.get_x(), p1.get_y());
    result.add(p2);

    return result;
  }

  Point sub(Point p1, Point p2) {
    Point result(p1.get_x(), p1.get_y());
    result.sub(p2);

    return result;
  }

  double distance(Point p1, Point p2) {
    return p1.distance(p2);
  }
};

int main() {
  Point p1, p2;

  p1.print();
  p2.print();

  p1.set_x(5.5);
  p1.set_y(5.0);

  p2.set_x(5.3);
  p2.set_y(6.0);

  p1.print();
  p2.print();

  p1.add(p2);
  p2.sub(p1);

  p1.print();
  p2.print();

  double d = p1.distance(p2);

  cout << "Distance: " << d << endl;

  Point p3(1.0,2.0), p4(3.0,4.0);

  Point p5(7.0, 8.0);

  p5.print();

  p5.add(p3);

  p5.print();

  return 0;
}
