// UVa 105
/****
 Note: Given (L, H, R), the skyline=H for [L, R)
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

struct building {
    int l, h, r;
    building(int ll, int hh, int rr) : l(ll), h(hh), r(rr) {}
};

int main() {
    FILE*fp=stdin;
    if (dbg) {
        fp = fopen ("in-105.txt", "r");
    }
    
    vector<building> bs;
    int l, h, r;
    while (fscanf(fp, "%d%d%d", &l, &h, &r)==3)
        bs.push_back(building(l, h, r));
    
    int buflen = bs[bs.size()-1].r - bs[0].l + 1 + 1;
    vi skyline(buflen,0);
    for (int i=0; i<bs.size(); i++)
        for (int k=bs[i].l; k<bs[i].r; k++) {
            int sid = k-bs[0].l;
            if (skyline[sid] < bs[i].h)
                skyline[sid] = bs[i].h;
        }

//    print (skyline, "skyline");

    vector<building> bline;
    
    int x = 0;
    while (x<skyline.size()) {
        if (x==0 || skyline[x]!=skyline[x-1])
            bline.push_back(building(x+bs[0].l, skyline[x], 0));
        x++;
    }
    for (int i=0; i<bline.size(); i++) {
        printf("%d %d", bline[i].l, bline[i].h);
        if (i<bline.size()-1) printf(" ");
    }
    printf("\n");
    return 0;
}

