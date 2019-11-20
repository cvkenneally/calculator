#ifndef _FRACTION_H
#define _FRACTION_H

#include <iostream>

class Fraction {
public:
Fraction(int n=0, int d=1);
~Fraction(void);

Fraction operator=(Fraction rhs);
Fraction operator+(Fraction rhs);
Fraction operator-(Fraction rhs);
Fraction operator*(Fraction rhs);
Fraction operator/(Fraction rhs);

bool operator==(Fraction rhs);
bool operator!=(Fraction rhs);
bool operator<=(Fraction rhs);
bool operator>=(Fraction rhs);
bool operator<(Fraction rhs);
bool operator>(Fraction rhs);

friend std::istream &operator>>(std::istream &, Fraction &);
friend std::ostream &operator<<(std::ostream &, Fraction &);

private:
int
								num,
								den;

};
#endif
