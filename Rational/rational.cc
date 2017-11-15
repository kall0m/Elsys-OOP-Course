#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int gcd(int number1, int number2) {
	int dividor = number1 < number2 ? number1 : number2;

	while(number1 % dividor != 0 || number2 % dividor != 0) {
		dividor--;
	}

	return dividor;
}

class RationalException {
  string err_msg_;

public:
  RationalException(string message) : err_msg_(message) {}

  string get_err_msg() {
    return err_msg_;
  }
};

class Rational {
    long num_, den_;

    void simple(long n, long d) { // second chance: no arguments
      long dividor = gcd(n, d);

      num_ = n / dividor;
      den_ = d / dividor;
    }
public:
    Rational(long num = 1, long den = 1) {
      if(den == 0) {
			  throw RationalException("Denominator can't be zero!");
		  }

      simple(num, den);
		  //long dividor = gcd(num, den);

      //num_ = (long)(num / dividor);
      //den_ = (long)(den / dividor);
    }

    long get_numerator() const {
        return num_;
    }

    long get_denominator() const {
        return den_;
    }

    Rational& set_numerator(long num) {
      num_ = num;

      return *this;
    }

    Rational& set_denominator(long den) {
      den_ = den;

      return *this;
    }

    Rational& add(const Rational& r) {
        num_ = num_ * r.den_ + den_ * r.num_;
        den_ = den_ * r.den_;

        //long dividor = gcd(num_, den_);

        //num_ = (long)(num_ / dividor);
        //den_ = (long)(den_ / dividor);

        simple(num_, den_);

        return *this;
    }

    Rational& sub(const Rational& r) {
        num_ = num_ * r.den_ - den_ * r.num_;
        den_ = den_ * r.den_;

        simple(num_, den_);

        return *this;
    }

    Rational& operator+=(const Rational& r) {
        add(r);

        return *this;
    }

    Rational& operator-=(const Rational& r) {
        sub(r);

        return *this;
    }

    Rational& mul(const Rational& r) {
        num_ *= r.num_;
        den_ *= r.den_;

        simple(num_, den_);

        return *this;
    }

    Rational& div(const Rational& r) {
        num_ *= r.den_;
        den_ *= r.num_;

        simple(num_, den_);

        return *this;
    }

    Rational& operator*=(const Rational& r) {
        mul(r);

        return *this;
    }

    Rational& operator/=(const Rational& r) {
        div(r);

        return *this;
    }
};

Rational operator+(const Rational& r1, const Rational& r2) {
  Rational result(r1.get_numerator(), r1.get_denominator());
  result.add(r2);

  return result;
}

Rational operator-(const Rational& r1, const Rational& r2) {
  Rational result(r1.get_numerator(), r1.get_denominator());
  result.sub(r2);

  return result;
}

Rational operator*(const Rational& r1, const Rational& r2) {
  Rational result(r1.get_numerator(), r1.get_denominator());
  result.mul(r2);

  return result;
}

Rational operator/(const Rational& r1, const Rational& r2) {
  Rational result(r1.get_numerator(), r1.get_denominator());
  result.div(r2);

  return result;
}

ostream& operator<<(ostream& out, const Rational& r) {
  out << "(" << r.get_numerator() << "/" << r.get_denominator() << ")";

  return out;
}

istream& operator>>(istream& in, Rational& r) {
  long num, den;

  char c;

  in >> c;

  if(c != '(') {
    in.clear(ios_base::badbit);

    return in;
  }

  in >> num >> c;

  if(c != '/') {
    in.clear(ios_base::badbit);

    return in;
  }

  in >> den >> c;

  if(c != ')') {
    in.clear(ios_base::badbit);

    return in;
  }

  if(in.good()) {
    r.set_numerator(num);
    r.set_denominator(den);

    return in;
  }
}

int main() {
    try {
      Rational r4(1,1);

      cin >> r4;
      cout << r4;
    } catch (RationalException rex) {
      cout << rex.get_err_msg() << endl;
    }

    return 0;
}
