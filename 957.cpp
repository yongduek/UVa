// UVa 957 Popes
/****
 Input

 The input will contain several test cases, each of them as described below. Consecutive 
 test cases are separated by a single blank line. 
 The first line of the input contains a positive integer Y , the number of years of the period we are
 interested in. The second line contains another positive integer, the number of Popes, P. Each of
 the remaining P lines contains the year of election of a Pope, in chronological order. We know that
 P ≤ 100000 and also that the last year L in the file is such L ≤ 1000000, and that Y ≤ L.

Output

 For each test case, write to the output contains a single line with three integers, separated by spaces: 
 the largest number of Popes in a Y -year period, the year of election of the first Pope in that period and
 the year of election of the last Pope in the period.
****/
#include <iostream>
#include <cstdio>
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
        fp = fopen ("in-957.txt", "r");
    }
    while (1) {
        int Y, P;
        int ns = fscanf(fp, "%d", &Y);
        if (ns<1) return 0;
        
        fscanf(fp, "%d", &P); // num of popes
        //static int eYear[100010];
        int eYear[P+10];
        for (int i=0; i<P; i++)
            fscanf(fp, "%d", eYear+i);
        
        viii nPopes;
        
        iii maxP; maxP.first=0;
        for (int i=0; i<P; i++) {
            int sY = eYear[i];
            int eY = eYear[i] + Y - 1;
            int count=0;
            int y=i;
            while (eYear[y]<=eY && y<P) {
                y++;
                count++;
            }
            
            if (maxP.first < count) maxP.first = count;
            
            iii d;
            d.first = count;
            d.second.first = sY;
            d.second.second = eYear[y-1];
            nPopes.push_back(d);
        }
        
        std::sort(nPopes.begin(), nPopes.end());

        if (dbg) print (nPopes);

//        iii p = nPopes[nPopes.size()-1]; // largest number
//        for (int k=nPopes.size()-2; k>=0; k--)
//            if (p.first==nPopes[k].first)
//                p = nPopes[k];
//            else
//                break;
        
        viii::iterator p = std::upper_bound(nPopes.begin(), nPopes.end(), maxP);
        printf ("%d %d %d\n", p->first, p->second.first, p->second.second);
//        printf ("%d %d %d\n", p->first, *p.second.first, *p.second.second);
//
    }
    
    return 0;
}
