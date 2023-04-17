#include <iostream>
#include <cmath>
#include <iomanip>
#include "Fraction.hpp"

Fraction :: Fraction(int num, int den)
{
    numerator = num;
    denominator = den;
    reduce();
}

// Getters
int Fraction :: getNumerator() const { return numerator; }
int Fraction :: getDenominator() const { return denominator; }

// Overloaded operators
Fraction Fraction :: operator+(const Fraction &other) const
{
    int num = numerator * other.denominator + denominator * other.numerator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction :: operator-(const Fraction &other) const
{
    int num = numerator * other.denominator - denominator * other.numerator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction :: operator*(const Fraction &other) const
{
    int num = numerator * other.numerator;
    int den = denominator * other.denominator;
    return Fraction(num, den);
}

Fraction Fraction :: operator/(const Fraction &other) const
{
    int num = numerator * other.denominator;
    int den = denominator * other.numerator;
    return Fraction(num, den);
}

bool Fraction :: operator==(const Fraction &other) const
{
    return (numerator == other.numerator && denominator == other.denominator);
}

bool Fraction :: operator<(const Fraction &other) const
{
    return (numerator * other.denominator < other.numerator * denominator);
}

bool Fraction :: operator>(const Fraction &other) const
{
    return (numerator * other.denominator > other.numerator * denominator);
}

bool Fraction :: operator<=(const Fraction &other) const
{
    return (numerator * other.denominator <= other.numerator * denominator);
}

bool Fraction :: operator>=(const Fraction &other) const
{
    return (numerator * other.denominator >= other.numerator * denominator);
}

Fraction Fraction :: operator++()
{
    numerator += denominator;
    reduce();
    return *this;
}

Fraction Fraction :: operator++(int)
{
    Fraction temp(numerator, denominator);
    numerator += denominator;
    reduce();
    return temp;
}

Fraction Fraction :: operator--()
{
    numerator -= denominator;
    reduce();
    return *this;
}

Fraction Fraction :: operator--(int)
{
    Fraction temp(numerator, denominator);
    numerator -= denominator;
    reduce();
    return temp;
}

friend std::ostream &operator<<(std::ostream &os, const Fraction &frac)
{
    os << frac.numerator << "/" << frac.denominator;
    return os;
}

friend std::istream &operator>>(std::istream &is, Fraction &frac)
{
    int num, den;
    is >> num >> den;
    frac = Fraction(num, den);
    return is;
}

// Private method to reduce the fraction
void Fraction :: reduce()
{
    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;

    // Make sure denominator is positive
    if (denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }
}
