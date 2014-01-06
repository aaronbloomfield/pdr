// File Rational.java

/* Fall 2007 CS 216 NOTES on Handout:
 *
 * MCO:  See notes scattered in comments throughout this file
 *
 * 		For now, use the comments as a guideline for the conversion to C++
 *		Explanation the following concepts will become clearer in the next class:
 *			- pointers
 *			- when to use "new" and "this"
 *
 *	NOTE 0: For now, remove all instances of "new" and "this"
 *
 *	C++ REMINDERS:
 *
 *		1) For Input/Output:
 *
 *			#include <iostream>
 *			using namespace std;
 *
 *		2) To print to screen:  cout << varname1 << " " << endl;
 *			(endl means "end of line" or newline)
 *
 *		3) C++ signature for main (must not be in any class):
 *			int main()
 *
 *		4) C++ class syntax reminders:
 *
 *		// Instead of modifying each member function,
 *		// just a section for each in the class
 *		public:
 *		private:
 *
 */

public class Rational {
    private int num;   // the numerator
    private int den;   // the denominator

    // create and initialize a new Rational object
    public Rational(int numerator, int denominator) {
        if (denominator == 0) {
            System.out.println("Denominator is zero");
        }
        int g = gcd(numerator, denominator);
        num = numerator   / g;
        den = denominator / g;
    }

    // return string representation of (this)
    public void print() {
        if (den == 1) {
            // MCO: NOTE 1
            // For conversion to C++
            // use the following
            // cout << num << "" << endl;
            // We'll talk about C++ operator overloading later for
            // operators such as the '+' symbol soon
            System.out.println(num + "");
        } else {
            System.out.println(num + "/" + den);
        }
    }

    // return (this * b)
    public Rational times(Rational b) {
        // MCO: NOTE 2
        // More explanation on this next class, for now
        // remove "new" and "this" for conversion to C++
        // Do this for all "new" and "this" for the Rational class
        // for this exercise
        return new Rational(this.num * b.num, this.den * b.den);
    }


    // return (this + b)
    public Rational plus(Rational b) {
        int numerator   = (this.num * b.den) + (this.den * b.num);
        int denominator = this.den * b.den;
        return new Rational(numerator, denominator);
    }

    // return (1 / this)
    public Rational reciprocal() {
        return new Rational(den, num);
    }

    // return (this / b)
    public Rational divides(Rational b) {
        return this.times(b.reciprocal());
    }

    /*************************************************************************
     *  Helper functions
     *************************************************************************/

    // return gcd(m, n)
    private int gcd(int m, int n) {
        if (0 == n)
            return m;
        else
            return gcd(n, m % n);
    }

    /*************************************************************************
     *  Test client
     *************************************************************************/

    public static void main(String[] args) {
        Rational x, y, z;

        // 1/2 + 1/3 = 5/6
        x = new Rational(1, 2);
        y = new Rational(1, 3);
        z = x.plus(y);
        z.print();

        // 8/9 + 1/9 = 1
        x = new Rational(8, 9);
        y = new Rational(1, 9);
        z = x.plus(y);
        z.print();

        //  4/17 * 7/3 = 28/51
        x = new Rational(4, 17);
        y = new Rational(7,  3);
        z = x.times(y);
        z.print();

        // 0/6 = 0
        x = new Rational(0, 6);
        x.print();
    }

}