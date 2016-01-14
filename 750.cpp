// UVa 750 nQueens

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

/*****
 //
 // Permutation Version
 //
 vector< vector<int> > nQueen_Permutation (const int r0, const int c0)
 {
 vector< vector<int> > sol;
 
 vector<int> row(8);
 for (int i=0; i<row.size(); i++) row[i]=i; // row[i] is the row position at i-th column
 // start search
 do {
 if (row[c0]!=r0) continue; // one queen must be at (r0,c0)
 
 bool ok=true;
 // 1. row[i] is not equal to row[j] for any j \neq i
 // 2. diagonal: (row[i], i) & (row[j],j)
 for (int i=0; i<7; i++) {
 for (int j=i+1; j<8; j++) {
 if (abs(row[i]-row[j])==abs(i-j)) {
 ok=false; // diagonal alignment must not happen
 break;}
 }
 if (!ok) break;
 }
 
 if (ok) {
 sol.push_back(row);
 //            printf ("%d %d - %d solutions.\n", r0, c0, sol.size());
 }
 } while (std::next_permutation(row.begin(), row.end()));
 
 return sol;
 }
 
 int main()
 {
 FILE *fp = stdin;
 int nData;
 fscanf(fp, "%d", &nData);
 if (nData==0) return 0;
 int count=0;
 
 while (--nData>=0) {
 int row, col;
 fscanf (fp, "%d %d", &row, &col);
 row--; // 0-based
 col--;
 
 vector< vector<int> > sol = nQueen_Permutation (row, col);
 
 if (++count>1) printf("\n");
 
 printf("SOLN       COLUMN\n");
 printf(" #      1 2 3 4 5 6 7 8\n");
 printf("\n");
 for (int i=0; i<sol.size(); i++) {
 printf ("%2d     ", i+1);
 for (int k=0; k<sol[i].size(); k++)
 printf (" %d", sol[i][k]+1);
 printf ("\n");
 }
 }
 
 return 0;
 }
 ****/

//
// backtracking version
//

vector< vector<int> > solutions;

void print (vector<int>& s) {
    static int count=1;
    printf("%d> ", count++);
    for (int i=0; i<s.size(); i++)
        printf (" %d", s[i]+1); printf("\n");
}

void backtrack (int col, vector<int>& sol, int r0, int c0)
{
    if (col==8) { // search is finished.
//        print (sol);
        if (sol[c0]==r0)
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
                backtrack (col+1, sol, r0, c0);
            }
        }
    }
}

bool dbg=false;
int main() // with backtracking (or DFS with pruning)
{
    FILE *fp = stdin;
    int nData;
    if (dbg)
        nData=1;
    else {
        fscanf(fp, "%d", &nData);
        if (nData==0) return 0;
    }
    int count=0;
    
    while (--nData>=0) {
        int row, col;
        if (!dbg) fscanf (fp, "%d %d", &row, &col);
        else {
            row=4;
            col=3;
        }
        row--; // 0-based
        col--;
        
        solutions.clear();
        
        vector<int> sol(8);
        
        for (int r=0; r<8; r++) {
            sol[0] = r; // Q is at 0-th column, i-th row
            backtrack (1/* next column number*/, sol/* sol. up to i-th column*/, row, col);
        }
        
        if (solutions.size()>0) {
            if (++count>1) printf("\n");
            
            printf("SOLN       COLUMN\n");
            printf(" #      1 2 3 4 5 6 7 8\n");
            printf("\n");
            for (int i=0; i<solutions.size(); i++) {
                printf ("%2d     ", i+1);
                for (int k=0; k<solutions[i].size(); k++)
                    printf (" %d", solutions[i][k]+1);
                printf ("\n");
            }
        }
    }
    
    return 0;
}
// EOF //