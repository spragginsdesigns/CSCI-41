#include <iostream>
#include <string>
#include <algorithm>
#include <string_view>
#include <cmath>
using namespace std;

class Fraction {
  public:
    // constructor
    Fraction(int numerator, int denominator);

    // question (a)
    Fraction& operator=(const Fraction& other);

    // question (b)
    friend ostream& operator<<(ostream& os, const Fraction& frac);

  private:
    int numerator;
    int denominator;
};

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

// question (c)
Fraction& Fraction::operator=(const Fraction& other) {
    if (this != &other) {
        numerator = other.numerator;
        denominator = other.denominator;
    }
    return *this;
}

// question (d)
ostream& operator<<(ostream& os, const Fraction& frac) {
    // Convert numerator and denominator to strings to determine their lengths
    string numStr = to_string(abs(frac.numerator));
    string denStr = to_string(abs(frac.denominator));

    // Determine the maximum length between numerator and denominator
    size_t maxLen = max(numStr.length(), denStr.length());

    // Use a string_view for dashes
    static constexpr string_view dashes = "--------------------"; // Adjust length as needed

    // Output the numerator, dashes, and denominator
    os << numStr << '\n';
    os << dashes.substr(0, maxLen) << '\n';
    os << denStr;

    return os; // Return the output stream to allow chaining
}