/*
 Lotto
 
 In the German Lotto you have to select 6 numbers from the set {1,2,...,49}.
 
 A popular strategy to play Lotto - although it doesn't increase your chance of winning - is to select a subset S containing k (k>6) of these 49 numbers, and then play several games with choosing numbers only from S.
 
 For example, for k=8 and S = 1,2,3,5,8,13,21,34 there are 28 possible games: [1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34].
 
 Your job is to write a program that reads in the number k and the set S and then prints all possible games choosing numbers only from S.
 
 Input Specification
 
 The input file will contain one or more test cases.
 
 Each test case consists of one line containing several integers separated from each other by spaces. The first integer on the line will be the number k (6 < k < 13). Then k integers, specifying the set S, will follow in ascending order.
 
 Input will be terminated by a value of zero (0) for k.
 
 Output Specification
 
 For each test case, print all possible games, each game on one line.
 
 The numbers of each game have to be sorted in ascending order and separated from each other by exactly one space. The games themselves have to be sorted lexicographically, that means sorted by the lowest number first, then by the second lowest and so on, as demonstrated in the sample output below.
 
 The test cases have to be separated from each other by exactly one blank line. Do not put a blank line after the last test case.
 
 Sample Input
 
 7 1 2 3 4 5 6 7
 8 1 2 3 5 8 13 21 34
 0
 Sample Output
 
 1 2 3 4 5 6
 1 2 3 4 5 7
 1 2 3 4 6 7
 1 2 3 5 6 7
 1 2 4 5 6 7
 1 3 4 5 6 7
 2 3 4 5 6 7
 
 1 2 3 5 8 13
 1 2 3 5 8 21
 1 2 3 5 8 34
 1 2 3 5 13 21
 1 2 3 5 13 34
 1 2 3 5 21 34
 1 2 3 8 13 21
 1 2 3 8 13 34
 1 2 3 8 21 34
 1 2 3 13 21 34
 1 2 5 8 13 21
 1 2 5 8 13 34
 1 2 5 8 21 34
 1 2 5 13 21 34
 1 2 8 13 21 34
 1 3 5 8 13 21
 1 3 5 8 13 34
 1 3 5 8 21 34
 1 3 5 13 21 34
 1 3 8 13 21 34
 1 5 8 13 21 34
 2 3 5 8 13 21
 2 3 5 8 13 34
 2 3 5 8 21 34
 2 3 5 13 21 34
 2 3 8 13 21 34
 2 5 8 13 21 34
 3 5 8 13 21 34
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


int main() {
    int count=0;
    while (1) {
        int k;
        cin >> k;
        if (k==0) exit (0);

        ++count;
        
        if (count>1) printf("\n");
     
        vector<int> A(k);
        for (int i=0; i<k; i++)
            cin >> A[i];
        
        
        for (int a1=0; a1<k; a1++)
            for (int a2=0; a2<k; a2++)
                for (int a3=0; a3<k; a3++)
                    for (int a4=0; a4<k; a4++)
                        for (int a5=0; a5<k; a5++)
                            for (int a6=0; a6<k; a6++)
                                if (a1<a2 && a2<a3 && a3<a4 && a4<a5 && a5<a6)
                                    printf ("%d %d %d %d %d %d\n", A[a1], A[a2], A[a3], A[a4], A[a5], A[a6]);
    }
    return 0;
}