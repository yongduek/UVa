/**
 Division
 Write a program that finds and displays all pairs of 5-digit numbers that between them use the digits 0 through 9 once each, such that the first number divided by the second is equal to an integer N, where  $2
 \le N \le 79$. That is,
 
 
 abcde / fghij = N
 
 where each letter represents a different digit. The first digit of one of the numerals is allowed to be zero.
 
 Input
 
 Each line of the input file consists of a valid integer N. An input of zero is to terminate the program.
 Output
 
 Your program have to display ALL qualifying pairs of numerals, sorted by increasing numerator (and, of course, denominator).
 
 Your output should be in the following general form:
 
 
 xxxxx / xxxxx = N
 
 xxxxx / xxxxx = N
 
 .
 
 .
 
 
 In case there are no pairs of numerals satisfying the condition, you must write ``There are no solutions for N.". Separate the output for two different values of N by a blank line.
 
 Sample Input
 
 61
 62
 0
 
 Sample Output
 
 There are no solutions for 61.
 
 79546 / 01283 = 62
 94736 / 01528 = 62
 
 
 Miguel Revilla 
 2000-08-31
 **/

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <array> // c++11

using namespace std;

int main(){
    int count=0;
    while (1) {
        int N=62;
        cin >> N;
        if (N==0) exit (0);
        
        count ++;
        
        if (count > 1) printf ("\n");
        
        vector< pair<int,int> > sol;
        
        for (int de=1234; de<98765; de++)
        {
            int nu = N * de;
            if (nu > 98765) continue;
            
            if (de == 1283) {
                int a=1;
            }
            
            // now check if de & nu have every of {0,1,2,...,9}
            bool mask[10]={false};
            if (de<10000) mask[0]=true;

            int num = nu;
            while (num != 0) {
                int r = num % 10;
                mask[r] = true;
                num /= 10;
            }
            int den = de;
            while (den != 0) {
                int r = den % 10;
                mask[r] = true;
                den /= 10;
            }
            bool r = true;
            for (int i=0; i<10; i++)
                r &= mask[i];
            if (r) {// 10 numbers used.
//                cout << "true " << endl;
                sol.push_back(pair<int,int>(nu,de));
            }
        }
        
        if (sol.empty())
            cout << "There are no solutions for " << N << ".\n";
        else
            for (int i=0; i<sol.size(); i++)
                printf ("%05d / %05d = %d\n", sol[i].first, sol[i].second, N);
        
        sol.clear();
    }
    return 0;
}
