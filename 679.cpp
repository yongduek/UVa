// UVa 679 : TLE

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

const bool dbg=false;

/******************
int main() {
    int TC;
    FILE*fp=stdin;
    fscanf(fp, "%d", &TC);
    while (--TC >= 0) {
        int D, I;
        fscanf(fp, "%d %d", &D, &I);
        if (D==-1) return 0;
        
        int nodeSize = (1<<D) - 1; //2^D - 1
        vector<bool> fbt(1+nodeSize,false); // index>=1 will be used.
    
        int number;
        for (int i=0; i<I; i++) {
            number = 1;
            for (int depth=1; depth < D; depth++) {
                number = number << 1;
                if (fbt[number]==false) {
                    fbt[number]=true;
                }
                else {
                    fbt[number]=false;
                    number += 1;
                }
            }
        }
        printf ("%d\n", number);
    }
    
    return 0;
}
********************/

/*******************
int main() {
    int TC;
    FILE*fp=stdin;
    fscanf(fp, "%d", &TC);
    while (--TC >= 0) {
        int D, I;
        fscanf(fp, "%d %d", &D, &I);
        if (D==-1) return 0;
        
        int nodeSize = (1<<D) - 1; //2^D - 1
        std::bitset<1100000> fbt; // index>=1 will be used.
        
        int number;
        for (int i=0; i<I; i++) {
            number = 1;
            for (int depth=1; depth < D; depth++) {
                number = number << 1;
                if (fbt[number]) {
                    fbt[number]=true;
                }
                else {
                    fbt[number]=false;
                    number += 1;
                }
            }
        }
        printf ("%d\n", number);
    }
    
    return 0;
}
************************/

void binarySearch(int depth, int num, int& leaf) {
    if (depth==0) return;
    if (num%2==0) { // even -> right
        binarySearch(--depth, num/2, leaf=leaf*2+1);
    }
    else { // left
        binarySearch(--depth, num/2+1, leaf=leaf*2);
    }
}
int main() {
    int TC;
    FILE*fp=stdin;
    fscanf(fp, "%d", &TC);
    while (--TC >= 0) {
        int D, I;
        fscanf(fp, "%d %d", &D, &I);
        if (D==-1) return 0;

        int leaf = 1;
        
        binarySearch (--D, I, leaf);
        
        printf ("%d\n", leaf);
    }
    
    return 0;
}
