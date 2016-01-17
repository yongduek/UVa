// UVa 11085 nQueens

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long       ul;
typedef unsigned long long ull;

typedef std::pair<int,int>  ii;
typedef std::pair<int,ii>  iii;
typedef std::vector<int>    vi;
typedef std::vector<ii>    vii;
typedef std::vector<iii>  viii;
typedef vector<std::vector<int> >   vvi;

void print(vi s, string st="") {
    printf("%s", st.c_str());
    for (int i=0; i<s.size(); i++)
        printf ("%d ", s[i]);
    printf("\n");
}

void print (vvi s) {
    for (int i=0; i<s.size(); i++)
        print (s[i], to_string(i)+" : ");
    printf("\n----\n");
}


vvi sol;

void visit (int row, vi rs) {
    rs.push_back(row);
    
    int ccol = (int)rs.size()-1; // column
    // pruning
    // current column number is equal to rs.size()
    for (int c=0; c<ccol; c++) {
        if (rs[c]==row)
            return;// horizontal check
        int d1=rs[c]-row;
        int d2=ccol-c;
        if (abs(d1)==abs(d2))
            return;
    }
    
    if (rs.size()==8) {
        sol.push_back(rs);
        return;
    }
    
    // visit rows of next column
    for (int r=0; r<8; r++)
        visit(r, rs);
}

void nqueen() {
    for (int r=0; r<8; r++) { // row of the first column
        vi rs;
        visit (r, rs);
    }
    //print (sol);
}

int main()
{
    // 1. find all the solution of the problem.
    nqueen();
    
    FILE *fp=stdin;
#ifndef ONLINE_JUDGE
    fp = fopen ("in-11085.txt", "r");
#endif
    // 2. solve the original problem
    while (1) {
        static int tc=0;
        
        int rpos[8];
        for (int i=0; i<8; i++) {
            int n=fscanf (fp, "%d", rpos+i);
            rpos[i]--; // 0-based
            if (n<1) return 0;
        }

        int movemin = 8;
        for (int i=0; i<sol.size(); i++) {
            vi &s = sol[i];
            int move=0;
            for (int k=0; k<8; k++)
                if (s[k]!=rpos[k])
                    move++;
            if (move < movemin)
                movemin=move;
        }
        printf ("Case %d: %d\n", ++tc, movemin);
    }
    return 0;
}