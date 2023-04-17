#ifndef FRACTION_HPP
#define FRACTION_HPP
namespace ariel
{
}
using namespace ariel;
#include <iostream>
#include <cmath>

class Fraction {
private:
    int numerator, denominator;

public:
    // Constructor
    Fraction(int num, int den);

    // Getters
    int getNumerator() const;
    int getDenominator() const;

    // Overloaded operators
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;
    bool operator==(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;
    Fraction operator++();
    Fraction operator++(int);
    Fraction operator--();
    Fraction operator--(int);

    // Friends
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
    friend std::istream& operator>>(std::istream& is, Fraction& frac);

private:
    // Private method to reduce the fraction
    void reduce();
};

#endif
