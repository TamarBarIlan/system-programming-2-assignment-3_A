#include <iostream>
#include <cmath>
#include <iomanip>
#include "Fraction.hpp"

Fraction ::Fraction(int num, int den) : numerator(num), denominator(den)
{
    numerator = num;
    denominator = den;
    reduce();
}

Fraction ::Fraction(float num)
{
    numerator = 1;
    denominator = 1;
    reduce();
}

// Getters
int Fraction ::getNumerator() const { return numerator; }
int Fraction ::getDenominator() const { return denominator; }

// Overloaded operators
Fraction operator+(const Fraction &frac1, const Fraction &frac2)
{
    return Fraction(1,1);
}
Fraction operator-(const Fraction &frac1, const Fraction &frac2)
{
    return Fraction(1,1);
}
Fraction operator*(const Fraction &frac1, const Fraction &frac2){
    return Fraction(1,1);
}
Fraction operator/(const Fraction &frac1, const Fraction &frac2)
{
    return Fraction(1,1);
}
bool operator==(const Fraction &frac1, const Fraction &frac2)
{
    return true;
}
bool operator<(const Fraction &frac1, const Fraction &frac2)
{
    return true;
}
bool operator>(const Fraction &frac1, const Fraction &frac2)
{
    return true;
}
bool operator<=(const Fraction &frac1, const Fraction &frac2)
{
    return true;
}
bool operator>=(const Fraction &frac1, const Fraction &frac2)
{
    return true;
}

Fraction Fraction ::operator++()
{
    numerator += denominator;
    reduce();
    return *this;
}

Fraction Fraction ::operator++(int)
{
    Fraction temp(numerator, denominator);
    numerator += denominator;
    reduce();
    return temp;
}

Fraction Fraction ::operator--()
{
    numerator -= denominator;
    reduce();
    return *this;
}

Fraction Fraction ::operator--(int)
{
    Fraction temp(numerator, denominator);
    numerator -= denominator;
    reduce();
    return temp;
}

std::ostream &operator<<(std::ostream &os, const Fraction &frac)
{
    os << frac.numerator << "/" << frac.denominator;
    return os;
}

std::istream &operator>>(std::istream &is, Fraction &frac)
{
    // int num, den;
    // is >> num >> den;
    // frac = Fraction(num, den);
    return is;
}

// Private method to reduce the fraction
void Fraction ::reduce()
{
    // int gcd = std::gcd(numerator, denominator);
    // numerator /= gcd;
    // denominator /= gcd;

    // // Make sure denominator is positive
    // if (denominator < 0)
    // {
    //     numerator *= -1;
    //     denominator *= -1;
    // }
}

int gcd(int n, int m)
{
    // int gcd, remainder;

    // while (n != 0)
    // {
    //     remainder = m % n;
    //     m = n;
    //     n = remainder;
    // }

    // gcd = m;

    // return gcd;
    return 1;
}
