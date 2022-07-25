﻿// Rational.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

int GreatesCommonDivisor(int a, int b) {
    if (b == 0)
        return a;
    else
        return GreatesCommonDivisor(b, a % b);
};

class Rational {
public:
    Rational() {
        numerator_value = 0;
        denominator_value = 1;
    };
    Rational(int numerator, int denominator) {
        int divisor = GreatesCommonDivisor(numerator, denominator);

        numerator_value = numerator / divisor;
        denominator_value = denominator / divisor;

        if (denominator_value < 0) {
            numerator_value = -numerator_value;
            denominator_value = -denominator_value;
        }
    }

    int Numerator() const {
        return numerator_value;
    }
    int Denominator() const {
        return denominator_value;
    }

private:
    int numerator_value = 0;
    int denominator_value = 1;
};
bool operator == (const Rational& lhs, const  Rational& rhs) {
    return (lhs.Denominator() == rhs.Denominator() &&
        lhs.Numerator() == rhs.Numerator());
};

bool operator < (const Rational& lhs, const  Rational& rhs) {
    return (lhs.Numerator()* rhs.Denominator()) < (rhs.Numerator() * lhs.Denominator()); //return (lhs - rhs).Numerator() < 0;
};
Rational operator + (Rational& lhs, Rational& rhs) {
    return{ lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
        lhs.Denominator() * rhs.Denominator() };
};

Rational operator - (Rational& lhs, Rational& rhs) {
    return{ lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
    lhs.Denominator() * rhs.Denominator() };
};

Rational operator * (Rational& lhs, Rational& rhs) {
    return{ lhs.Numerator() * rhs.Numerator(),
    lhs.Denominator() * rhs.Denominator() };
};

Rational operator / (Rational& lhs, Rational& rhs) {
    return{ lhs.Numerator() * rhs.Denominator(),
    lhs.Denominator() * rhs.Numerator() };
};

ostream& operator << (ostream& rational_output, const Rational& rational) {
    rational_output << rational.Numerator() << "/" << rational.Denominator();
    return rational_output;
};

istream& operator >> (istream& rational_input, Rational& rational) {
    int numerator = 0, decominator = 1;
    char divider;
    rational_input >> numerator >> divider >> decominator;
    if (rational_input && divider == '/')
        rational = { numerator, decominator };
    return rational_input;
};

int main()
{
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "Part 1 OK" << endl;

    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << " " << c.Numerator() << "/" << c.Denominator() << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "Part 2 OK" << endl;
    
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "Part 3 OK" << endl;
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "Part 4 OK" << endl;

    {
        const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "Part 5 OK" << endl;
    return 0;
}
