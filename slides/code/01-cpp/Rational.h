// File Rational.h

#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {

public:
    // default constructor
    Rational();

    // destructor
    ~Rational();

    // create and initialize a new Rational object
    Rational(int numerator, int denominator);

    // print string representation of (this) to cout
    void print() const;

    // return (this * b)
    Rational times(Rational b) const;

    // return (this + b)
    Rational plus(Rational b) const;

    // return (1 / this)
    Rational reciprocal() const;

    // return (this / b)
    Rational divides(Rational b) const;

private:
    int num;   // the numerator
    int den;   // the denominator

    /*************************************************************************
    *  Helper functions
    *************************************************************************/
    // return gcd(m, n)
    int gcd(int m, int n);

};

#endif
