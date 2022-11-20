#include <iostream>
#include <cmath>

using namespace std;

struct Rational {
    long long up = 0, down = 1;
};

inline long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}
void rational_show(long long up, long long down) {
    if (up * down == 0) {
        if(down == 0)cout << "Inf";
        else cout << '0';
        return;
    }
    bool isNeg = ((up < 0 && down > 0) || (up > 0 && down < 0));
    up = abs(up);
    down = abs(down);
    long long k = up / down;
    if(isNeg)cout << "(-";
    if(k != 0) cout << k;
    if(up % down == 0) {
        if(isNeg)cout << ')';
        return;
    }
    if(k != 0)cout << ' ';
    up = up - k * down;
    long long gcd_res = gcd(up, down);
    up /= gcd_res;
    down /= gcd_res;
    cout << up << '/' << down;
    if(isNeg)cout << ')';
}

void rational_plus(const Rational& r1, const Rational& r2) {
    rational_show(r1.up, r1.down);
    cout << " + ";
    rational_show(r2.up, r2.down);
    cout << " = ";
    rational_show(r1.up * r2.down + r2.up * r1.down, r1.down * r2.down);
    cout << endl;
}

void rational_mine(const Rational& r1, const Rational& r2) {
    rational_show(r1.up, r1.down);
    cout << " - ";
    rational_show(r2.up, r2.down);
    cout << " = ";
    rational_show(r1.up * r2.down - r2.up * r1.down, r1.down * r2.down);
    cout << endl;
}

void rational_mul(const Rational& r1, const Rational& r2) {
    rational_show(r1.up, r1.down);
    cout << " * ";
    rational_show(r2.up, r2.down);
    cout << " = ";
    rational_show(r1.up * r2.up, r1.down * r2.down);
    cout << endl;
}

void rational_div(const Rational& r1, const Rational& r2) {
    rational_show(r1.up, r1.down);
    cout << " / ";
    rational_show(r2.up, r2.down);
    cout << " = ";
    rational_show(r1.up * r2.down, r1.down * r2.up);
    cout << endl;
}

int main() {
    char c;
    Rational r1, r2;
    cin >> r1.up >> c >> r1.down >> r2.up >> c >> r2.down;
    rational_plus(r1, r2);
    rational_mine(r1, r2);
    rational_mul(r1, r2);
    rational_div(r1, r2);
    return 0;
}