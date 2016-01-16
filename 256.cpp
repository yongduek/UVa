// UVa 256 Quirksome Squares
/****
 The number 3025 has a remarkable quirk: if you split its decimal representation in two strings of equal
 length (30 and 25) and square the sum of the numbers so obtained, you obtain the original number:
 (30 + 25)2
 = 3025
 The problem is to determine all numbers with this property having a given even number of digits.
 For example, 4-digit numbers run from 0000 to 9999. Note that leading zeroes should be taken into
 account. This means that 0001 which is equal to (00 + 01)2
 is a quirksome number of 4 digits. The
 number of digits may be 2,4,6 or 8. Although maxint is only 32767 and numbers of eight digits are asked
 for, a well-versed programmer can keep his numbers in the range of the integers. However eciency
 should be given a thought.
 Input
 The input of your program is a textle containing numbers of digits (taken from 2,4,6,8), each number
 on a line of its own.
 Output
 The output is a textle consisting of lines containing the quirksome numbers (ordered according to the
 input numbers and for each input number in increasing order).
 Warning: Please note that the number of digits in the output is equal to the number in the corresponding
 input line : leading zeroes may not be suppressed.
 Sample Input
 2
 2
 Sample Output
 00
 01
 81
 00
 01
 81
****/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>

typedef std::pair<int,int>  ii;
typedef std::pair<int,ii>  iii;
typedef std::vector<int>    vi;
typedef std::vector<ii>    vii;
typedef std::vector<iii>  viii;

using namespace std;


void print (viii& p) {
    for (int i=0; i<p.size(); i++)
        printf (" %d  %d-%d\n", p[i].first, p[i].second.first, p[i].second.second);
    printf("---\n");
}

const bool dbg=0;

int main() {
    FILE*fp=stdin;
    if (dbg) {
        fp = fopen ("in-256.txt", "r");
    }
    while (1) {
        int nDigit;
        int ns = fscanf(fp, "%d", &nDigit);
        if (ns<1) return 0;
     
        int digit = nDigit/2;
        char format[256];
        sprintf (format, "%%0%dd%%0%dd\n",digit,digit);
        int lim = (int) (pow (10., digit) + 0.5);
        for (int a=0; a<lim; a++)
            for (int b=0; b<lim; b++) {
                int c = a+b;
                int c2 = c*c;
                int aa = c2/lim;
                int bb = c2%lim;
                if (aa==a && bb==b)
                    printf (format, a, b);
            }
    }
    
    return 0;
}
