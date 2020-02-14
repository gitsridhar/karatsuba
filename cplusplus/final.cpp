#include <iostream>
#include <algorithm>

using namespace std;

void makeEqualLength(string &x, string &y) {
    long len1 = x.size();
    long len2 = y.size();

    if (len1 < len2) {
        for(long i=0; i<len2 - len1; i++) {
            x = '0' + x;
        }
    } else if (len1 > len2){
        for(long i=0; i<len1 - len2; i++) {
            y = '0' + y;
        }
    }
    return;
}

bool big(string x, string y) {
    long i;
    for (i=0; i<x.size(); i++) {
        if (x[i] == y[i])
            continue;
        else
            return (x[i] > y[i]);
    }
    return true;
}

string addstringnumbers(string x, string y) {
    if(x == "0" && y == "0") return "0";
    makeEqualLength(x, y);

    string result(x.size()+1, '0');

    char carry = 0;

    std::transform(x.rbegin(), x.rend(), y.rbegin(), result.rbegin(),
                   [&carry]( char x, char y) {
                       char sum = (x-'0')+(y-'0') + carry;
                       if (sum > 9) {
                           carry = 1;
                           sum -= 10;
                       } else {
                           carry = 0;
                       }
                       return sum + '0';
                   });
    result[0] = carry + '0';

    long n = result.find_first_not_of("0");
    if (n != string::npos)
        result = result.substr(n);

    return result;
}

string subtractstringnumbers(string x, string y) {

    if (x == "0" && y == "0") return "0";

    makeEqualLength(x, y);

    string result(x.size(), '0');

    if (big(y, x))
        swap(x, y);

    short borrow = 0;

    std::transform(x.rbegin(), x.rend(), y.rbegin(), result.rbegin(),
                   [&borrow](char x, char y) {
                       short d = 0;
                       short xx = x - '0';
                       short yy = y - '0';

                       if (borrow) {
                           xx = xx - 1;
                           if ( xx < yy) {
                               xx = 10 + xx;
                               borrow = 1;
                           } else {
                               borrow = 0;
                           }
                       }
                       d = xx - yy;
                       if (d < 0) {
                           d = 10 + xx - yy;
                           borrow = 1;
                       }
                       d = d + '0';
                       return d;
                   });

    long n = result.find_first_not_of("0");
    if (n != string::npos)
        result = result.substr(n);

    return result;
}

string karatsuba(string x, string y) {

    if (x == "0") return "0";
    makeEqualLength(x, y);

    string result;

    if (x.size() == 1 && y.size() == 1) {
        short value = ((x[0]-'0')*(y[0]-'0'));
        return to_string(value);
    }

    long n = x.size() / 2;
    long m = x.size() - n;

    string a = x.substr(0, n);
    string b = x.substr(n, x.size());

    string c = y.substr(0, n);
    string d = y.substr(n, y.size());

    string parta = karatsuba(a, c);
    string partb = karatsuba(b, d);
    string left = addstringnumbers(a, b);
    string right = addstringnumbers(c, d);
    string partc = karatsuba(left, right);

    string secondpart;

    secondpart = subtractstringnumbers(subtractstringnumbers(partc,parta), partb);

    for(int i=0; i<2*m; i++)
        parta += "0";

    for(int i=0; i<m; i++)
        secondpart += "0";

    string re = addstringnumbers(parta, addstringnumbers(secondpart, partb));
    return re;
}

int main(int argc, const char * argv[]) {

    cout << karatsuba("3141592653589793238462643383279502884197169399375105820974944592","2718281828459045235360287471352662497757247093699959574966967627") << endl;

    cout << "This is Travis Generated Makefile based File" << endl;
    for (;;);
    return 0;
}
