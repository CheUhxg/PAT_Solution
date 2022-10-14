#include <iostream>
#include <vector>

using namespace std;

struct Rational {
    long int numerator = 0, denominator = 1;
};

long int gcd(long int a, long int b) {
    return b > 0 ? gcd(b, a % b) : a;
}

long int lcm(long int a, long int b) {
    return a / gcd(a, b) * b;
}

int main() {
    int n; cin >> n;
    Rational sum;
    char c;
    for(int i = 0; i < n; ++i) {
        Rational now;
        cin >> now.numerator >> c >> now.denominator;
        long int d = lcm(sum.denominator, now.denominator);
        sum.numerator *= d / sum.denominator;
        sum.numerator += now.numerator * (d / now.denominator);
        sum.denominator = d;
        d = gcd(abs(sum.numerator), sum.denominator);
        sum.numerator /= d;
        sum.denominator /= d;
    }
    long int integer = sum.numerator / sum.denominator;
    sum.numerator %= sum.denominator;
    if(integer != 0) {
        cout << integer;
        if(sum.numerator != 0) cout << ' ';
    }
    if(sum.numerator != 0) {
        integer = gcd(abs(sum.numerator + sum.denominator), sum.denominator);
        cout << sum.numerator / integer << '/' << sum.denominator / integer << endl;
    }
    else if(integer == 0) {
        cout << 0 << endl;
    }
}