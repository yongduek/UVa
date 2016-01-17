// UVa 1260 sales
/****
 ****/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <sstream>

typedef unsigned long       ul;
typedef unsigned long long ull;

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

void print (vi& p, string s="") {
    if (!s.empty())
        printf ("%s\n", s.c_str());
    for (int i=0; i<p.size(); i++)
        printf ("[%d] %d\n", i, p[i]);
    printf(" ;\n");
}


const bool dbg=0;


int main() {
    FILE*fp=stdin;
    if (dbg) {
        fp = fopen ("in-1260.txt", "r");
    }

    int TC;
    fscanf (fp, "%d", &TC);
    while (--TC >= 0) {
        int n;
        fscanf(fp, "%d", &n);
        int a[1001];
        for (int i=0; i<n; i++)
            fscanf (fp, "%d", a+i);
        
        int b[1001]={0};
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++)
                if (a[j]<=a[i])
                    b[i]++;
        }
        int sum = 0;
        for (int i=1; i<n; i++)
            sum += b[i];
        printf ("%d\n", sum);
    }
    
    return 0;
}

