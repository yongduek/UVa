// UVa 11195

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

//
// backtracking version
//

vector< vector<bool> > map;

void backtrack (int col, vector<int>& sol, int& count)
{
    if (col==sol.size())
        { // search is finished.
            ++count;
        }
    else
        {
        // find candidates at the current column
        for (int r=0; r<sol.size(); r++)
            {
            // for each (r, col), check feasibility
            if (map[r][col])
                {
                bool feasible=true;
                for (int c=0; c<col; c++)
                    {
                    // compare (sol[c], c) to (r,col)
                    if (sol[c]==r || (abs(sol[c]-r)==abs(c-col)))
                        { // infeasible
                            feasible=false;
                            break;
                        }
                    }
                if (feasible)
                    {
                    sol[col]=r;
                    backtrack (col+1, sol, count);
                    }
                }
            }
        }
}


int main() // with backtracking (or DFS with pruning)
{
    int nCase=0;
    while (1) {
        FILE *fp = stdin;
        int mapSize;
        fscanf(fp, "%d", &mapSize);
        if (mapSize==0) return 0;
        map.resize(mapSize);
        for (int r=0; r<mapSize; r++) {
            map[r].resize(mapSize);
            char ch[mapSize+1];
            fscanf(fp, "%s", ch);
            for (int c=0; c<mapSize; c++) {
                if (ch[c]=='.') map[r][c]=true;
                else map[r][c]=false;
            }
        }
        
        int count=0;
        vector<int> sol(mapSize);
        
        for (int r=0; r<mapSize; r++) {
            if (map[r][0]) {
                sol[0] = r; // Q is at 0-th column, i-th row
                backtrack (1/* next column number*/, sol/* sol. up to i-th column*/, count);
            }
        }
        
        printf("Case %d: %d\n", ++nCase, count);
    }
    
    return 0;
}
// EOF //