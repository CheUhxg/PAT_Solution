#include <iostream>

using namespace std;

struct Rational {
    long up = 0, down = 1;
};

char c;
Rational r1, r2;

inline long gcd(long a, long b) {
    return b > 0?gcd(b, a%b) : a;
}

void rational_show(Rational& res, char op) {
    if(r1.up < 0)cout << '(';
    cout << r1.up;
    if(r1.up != 0 && r1.down > 1)cout << '/' << r1.down;
    if(r1.up < 0)cout << ')';
    cout << ' ' << op << ' ';
    if(r2.up < 0)cout << '(';
    cout << r2.up;
    if(r2.up != 0 && r2.down > 1)cout << '/' << r2.down;
    if(r2.up < 0)cout << ')';
    cout << " = ";
    if(res.down == 0)cout << "Inf";
    else {
        bool neg = res.up < 0;
        res.up = abs(res.up);
        long k = res.up / res.down;
        res.up %= res.down;
        if(neg)cout << "(-";
        if(k > 0) {
            cout << k;
            if(res.up != 0)cout << ' ' << res.up;
        } else cout << res.up;
        if(res.up != 0 && res.down > 1)cout << '/' << res.down;
        if(neg)cout << ')';
    }
    cout << endl;
}

void rational_plus() {
    Rational res;
    if(r1.up != 0 && r2.up != 0) {
        // TODO:maybe out of range
        res.up = r1.up * r2.down + r2.up * r1.down;
        res.down = r1.down * r2.down;
        long gcd_res = gcd(abs(res.up), abs(res.down));
        res.up /= gcd_res;
        res.down /= gcd_res;
    } else if(r1.up == 0) res = r2;
    else res = r1;
    rational_show(res, '+');
}

void rational_mine() {
    Rational res;
    if(r1.up != 0 && r2.up != 0) {
        // TODO:maybe out of range
        res.up = r1.up * r2.down - r2.up * r1.down;
        res.down = r1.down * r2.down;
        long gcd_res = gcd(abs(res.up), abs(res.down));
        res.up /= gcd_res;
        res.down /= gcd_res;
    } else if(r1.up == 0) {
        res = r2;
        res.up *= -1;
    } else res = r1;
    rational_show(res, '-');
}

void rational_mul() {
    Rational res;
    if(r1.up != 0 && r2.up != 0) {
        // TODO:maybe out of range
        res.up = r1.up * r2.up;
        res.down = r1.down * r2.down;
        long gcd_res = gcd(abs(res.up), abs(res.down));
        res.up /= gcd_res;
        res.down /= gcd_res;
    }
    rational_show(res, '*');
}

void rational_div() {
    Rational res;
    if(r2.up == 0) {
        res.down = 0;
    } else if(r1.up != 0 && r2.up != 0) {
        // TODO:maybe out of range
        res.up = r1.up * r2.down;
        res.down = r1.down * r2.up;
        if(res.down < 0) {
            res.up *= -1;
            res.down *= -1;
        }
        long gcd_res = gcd(abs(res.up), abs(res.down));
        res.up /= gcd_res;
        res.down /= gcd_res;
    }
    rational_show(res, '/');
}

int main() {
    cin >> r1.up >> c >> r1.down >> r2.up >> c >> r2.down;
    long gcd1 = gcd(abs(r1.up), abs(r1.down)), gcd2 = gcd(abs(r2.up),abs(r2.down));
    r1.up /= gcd1;
    r1.down /= gcd1;
    r2.up /= gcd2;
    r2.down /= gcd2;
    rational_plus();
    rational_mine();
    rational_mul();
    rational_div();
}