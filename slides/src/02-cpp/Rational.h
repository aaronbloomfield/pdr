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

    // return string representation of (this)
    void print() ;

    // return (this * b)
    Rational times(Rational b);

    // return (this + b)
    Rational plus(Rational b);

    // return (1 / this)
    Rational reciprocal();

    // return (this / b)
    Rational divides(Rational b);

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
