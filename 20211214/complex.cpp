#include <iostream>
#include <complex>
using namespace std;

int main()
{
    double r1 {3.5};
    double i1 {7.5};
    double r2 {2.5};
    double i2 {4.5};
    complex<double> z1 {r1, i1};
    complex<double> z2 {r2, i2};
    complex<double> z3;
    z3 = z1 * z2;
    cout << "( " << z1.real() << " + " << z1.imag() << " i ) * " <<
            "( " << z2.real() << " + " << z2.imag() << " i ) = " <<
            "( " << z3.real() << " + " << z3.imag() << " i )";
}
