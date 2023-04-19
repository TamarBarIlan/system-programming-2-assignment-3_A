#include "sources/Fraction.hpp"

#include "doctest.h"
#include <stdexcept>
#include "iostream"
#include <stdio.h>

using namespace std;

TEST_CASE("Initialization tests")
{
    CHECK_THROWS(Fraction(1, 0)); // Division by zero
}

TEST_CASE("Comparison tests")
{
    Fraction a(1, 2);
    Fraction b(1, 3);
    Fraction c(2, 4);

    CHECK(a == a); // Reflexive
    CHECK(a == c); // Equivalent fractions
    CHECK(b != c); // Non-equivalent fractions
    CHECK(a < b);  // Less than
    CHECK(b < c);  // Transitive
    CHECK(a <= c); // Less than or equal to
    CHECK(b >= c); // Greater than or equal to
}

TEST_CASE("Arithmetic tests")
{
    Fraction a(1, 2);
    Fraction b(1, 3);

    CHECK((a + b) == Fraction(5, 6)); // Addition
    CHECK((a - b) == Fraction(1, 6)); // Subtraction
    CHECK((a * b) == Fraction(1, 6)); // Multiplication
    CHECK((a / b) == Fraction(3, 2)); // Division
}

TEST_CASE("Reduction tests")
{
    Fraction a(2, 4);
    Fraction b(3, 9);
    Fraction c(7, 21);

    CHECK(a == Fraction(1, 2)); // Simple reduction
    CHECK(b == Fraction(1, 3)); // Reduction with common factor
    CHECK(c == Fraction(1, 3)); // Reduction with larger common factor
}

TEST_CASE("Increment/decrement tests")
{
    Fraction a(1, 2);

    CHECK(++a == Fraction(3, 2)); // Prefix increment
    CHECK(a++ == Fraction(3, 2)); // Postfix increment
    CHECK(a == Fraction(5, 2));   // Result of postfix increment
    CHECK(--a == Fraction(3, 2)); // Prefix decrement
    CHECK(a-- == Fraction(3, 2)); // Postfix decrement
    CHECK(a == Fraction(1, 2));   // Result of postfix decrement
}

TEST_CASE("Input/output tests")
{
    Fraction a(1, 2);
    CHECK_NOTHROW(cout << a << endl);
}
