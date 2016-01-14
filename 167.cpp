// UVa 167

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


vector< vector<int> > solutions;

void print (vector<int>& s) {
    static int count=1;
    printf("%d> ", count++);
    for (int i=0; i<s.size(); i++)
        printf (" %d", s[i]+1); printf("\n");
}

void backtrack (int col, vector<int>& sol)
{
    if (col==8) { // search is finished.
        solutions.push_back(sol);
    }
    else {
        // find candidates at the current column
        for (int r=0; r<8; r++) {
            // for each (r, col), check feasibility
            bool feasible=true;
            for (int c=0; c<col; c++) {
                // compare (sol[c], c) to (r,col)
                if (sol[c]==r || (abs(sol[c]-r)==abs(c-col))) { // infeasible
                    feasible=false;
                    break;
                }
            }
            if (feasible) {
                sol[col]=r;
                backtrack (col+1, sol);
            }
        }
    }
}

bool dbg=false;
int main() // with backtracking (or DFS with pruning)
{
    solutions.clear();
    
    vector<int> sol(8);
    
    for (int r=0; r<8; r++) {
        sol[0] = r; // Q is at 0-th column, i-th row
        backtrack (1/* next column number*/, sol/* sol. up to i-th column*/);
    }
    
    // ---------------------------------------- //
    
    FILE *fp = stdin;
    int nData;
    fscanf(fp, "%d", &nData);
    if (nData==0) return 0;
    int count=0;
    
    while (--nData>=0) {

        int map[64];
        for (int i=0; i<64; i++)
            fscanf (fp, "%d", &map[i]);

        int maxSum=0;
        for (int i=0; i<solutions.size(); i++) {
            int sum=0;
            for (int k=0; k<solutions[i].size(); k++)
                sum += map[ solutions[i][k] * 8 + k ]; // location is (solutions[i][k], k)
            if (sum > maxSum)
                maxSum = sum;
        }
        
        printf ("%5d\n", maxSum);
    }
    
    return 0;
}
// EOF //