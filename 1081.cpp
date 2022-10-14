#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Rational {
    long int numerator, denominator;
};

long int gcd(long int a, long int b) {
    return b > 0 ? gcd(b, a % b) : a;
}

long int lcm(long int a, long int b) {
    return a / gcd(a, b) * b;
}

int main() {
    int n; cin >> n;
    long int d = 1, sum = 0, integer;
    char c;
    vector<Rational>rationals(n);
    for(int i = 0; i < n; ++i) {
        cin >> rationals[i].numerator >> c >> rationals[i].denominator;
        d = lcm(d, rationals[i].denominator);
    }
    for(const Rational& r : rationals) {
        sum += r.numerator * (d / r.denominator);
    }
    integer = sum / d;
    if(integer > 0) {
        cout << integer << ' ';
    }
    sum %= d;
    if(sum > 0) {
        integer = gcd(sum, d);
        cout << sum / integer << '/' << d / integer << endl;
    }
    else if(integer == 0) {
        cout << 0 << endl;
    }
}