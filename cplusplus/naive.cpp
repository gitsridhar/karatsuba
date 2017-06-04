//
//  main.cpp
//  Recursion
//
//  Created by Sridhar Venkat on 5/22/17.
//  Copyright © 2017 Sridhar Venkat. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void synchronize_length(string &x, string &y) {
    long long xlen = x.size();
    long long ylen = y.size();

    if (xlen < ylen) {
        for (long long i=0; i<ylen-xlen; i++)
            x = "0" + x;
    } else {
        for (long long i=0; i<xlen-ylen; i++)
            y = "0" + y;
    }

    return;
}

string addstringnumber(string &x, string &y) {

    synchronize_length(x, y);

    string result(x.size()+1, '0');

    char carry = 0;

    std::transform(x.rbegin(), x.rend(), y.rbegin(), result.rbegin(),
                   [&carry]( char x, char y) {
                       char z = (x-'0')+(y-'0') + carry;
                       if (z>9) {
                           carry = 1;
                           z -= 10;
                       } else {
                           carry = 0;
                       }
                       return z+'0';
                   });
    result[0] = carry + '0';

    long long n = result.find_first_not_of("0");
    if (n != string::npos) {
        result = result.substr(n);
    }

    return result;
}

long long karatsuba(string x, string y) {

    synchronize_length(x, y);

    if (x.size() == 0) return 0;

    if (x.size() == 1 && y.size() == 1) {
        long xx = (x[0]-'0')*(y[0]-'0');
        return (xx);
    }

    long long n = x.size() / 2;
    long long m = x.size() - n;

    string xleft = x.substr(0, n);
    string xright = x.substr(n, x.size()-n);

    string yleft = y.substr(0, n);
    string yright = y.substr(n, y.size()-n);

    long long part1 = karatsuba(xleft, yleft);

    long long part2 = karatsuba(xright, yright);

    string leftadd = addstringnumber(xleft, xright);
    string rightadd = addstringnumber(yleft, yright);

    long long part3 = karatsuba(leftadd, rightadd);

    long long one = part1 * pow(10, 2*m);
    long long two = (part3 - part1 - part2) * pow(10, m);
    long long three = part2;

    return one + two + three;
}

int main(int argc, const char * argv[]) {

    // Segmentation fault...
    //cout << karatsuba("3141592653589793238462643383279502884197169399375105820974944592", "2718281828459045235360287471352662497757247093699959574966967627") << endl;

    // correct answer
    cout << karatsuba("1234", "5678") << endl;
    cout << karatsuba("1234567890", "1234567890") << endl;

    // not correct due to long long limitation
    cout << karatsuba("123456789012345", "123456789012345") << endl;

    return 0;
}
