#include "fraction.h"


static int gcd(int a, int b) {
								int
																r;

								if (a < 0)
																a = -a;
								if (b < 0)
																b = -b;

								while (b != 0) {
																r = a % b;
																a = b;
																b = r;
								}
								return a;
}

Fraction::Fraction(int n, int d) {
								int
																g;

								if (n < 0) {
																n = -n;
																d = -d;
								}

								g = gcd(n,d);
								n /= g;
								d /= g;

								num = n;
								den = d;
}

Fraction::~Fraction(void) {
}

Fraction Fraction::operator=(Fraction rhs) {
								num= rhs.num;
								den = rhs.den;

								return rhs;
}

Fraction Fraction::operator+(Fraction rhs) {
								int
																s,
																t;

								s = num* rhs.den + den * rhs.num;
								t = den * rhs.den;

								return Fraction(s,t);
}

Fraction Fraction::operator-(Fraction rhs) {
								int s,t;

								s = num* rhs.den - den * rhs.num;
								t = den * rhs.den;

								return Fraction(s,t);
}

Fraction Fraction::operator*(Fraction rhs) {
								int
																s,
																t;

								s = num* rhs.num;
								t = den * rhs.den;

								return Fraction(s,t);
}

Fraction Fraction::operator/(Fraction rhs) {
								int
																s,
																t;

								s = num* rhs.den;
								t = den * rhs.num;

								return Fraction(s,t);
}


bool Fraction::operator==(Fraction rhs) {

								return num == rhs.num && den == rhs.den;
}

bool Fraction::operator!=(Fraction rhs) {

								return num != rhs.num && den != rhs.den;
}

bool Fraction::operator<=(Fraction rhs) {

								if (den * rhs.den >= 0)
																return num * rhs.den <= den * rhs.num;
								else
																return num * rhs.den >= den * rhs.num;
}

bool Fraction::operator>=(Fraction rhs) {

								if (den * rhs.den >= 0)
																return num * rhs.den >= den * rhs.num;
								else
																return num * rhs.den <= den * rhs.num;
}

bool Fraction::operator<(Fraction rhs) {

								if (den * rhs.den >= 0)
																return num * rhs.den < den * rhs.num;
								else
																return num * rhs.den > den * rhs.num;
}

bool Fraction::operator>(Fraction rhs) {

								if (den * rhs.den >= 0)
																return num * rhs.den > den * rhs.num;
								else
																return num * rhs.den < den * rhs.num;
}

std::istream &operator>>(std::istream &is,Fraction &f) {
								int
																n,d;
								char
																slash;

								is >> n >> slash >> d;

								f = Fraction(n,d);
								return is;
}

std::ostream &operator<<(std::ostream &os, Fraction &f) {

								os << f.num << " / " << f.den;

								return os;
}


//~Fraction(void);

//Fraction &operator=(Fraction &rhs);

//Fraction operator+(Fraction rhs);
//Fraction operator-(Fraction rhs);
//Fraction operator*(Fraction rhs);
//Fraction operator/(Fraction rhs);

//bool operator==(Fraction rhs):
//bool operator!=(Fraction rhs):
//bool operator<=(Fraction rhs):
//bool operator>=(Fraction rhs):
//bool operator<(Fraction rhs):
//bool operator>(Fraction rhs):

//friend istream &operator>>(istream &, Fraction &);
//friend ostream &operator<<(ostream &, Fraction &);
