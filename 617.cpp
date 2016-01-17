// UVa 617
/****
 Input
 1
 5.5 40 8 25
 
 3
 10.7 10 2 75
 12.5 12 5 57
 17.93 15 4 67
 
 0
 
 1
 10 1 1 0
 
 1
 10 1 1 1
 
 1
 5.5 40 8 25
 3
 10.7 10 2 75
 12.5 12 5 57
 17.93 15 4 67
 
 4
 1.0 10 1 10
 2.0 10 1 10
 3.0 10 1 10
 4.0 10 1 10
 
 5
 15.1 1 1 1
 10.2 10 20 30
 8.95 30 5 30
 25.0 10 1 10
 50.0 12 2 35
 
 6
 25.0 30 1 95
 10.5 10 10 10
 25.1 10 5 30
 16.7 6 50 2
 98.1 1 1 100
 37.25 15 6 38
 
 
 
 
 
 
 
 output:
 
 Case 1: 30, 32-33, 36-38, 41-45, 48-54, 59-60
 Case 2: No acceptable speeds.
 Case 3: 30-60
 Case 4: 30-60
 Case 5: 30-33, 36-37, 40, 43, 45, 47-48, 50-51, 53-57, 59-60
 Case 6: 30, 32-33, 36-38, 41-45, 48-54, 59-60
 Case 7: No acceptable speeds.
 Case 8: 34, 42, 55-57
 Case 9: 54, 60
 Case 10: No acceptable speeds.

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
        fp = fopen ("in-617.txt", "r");
    }

    int count=0;
    while (1) {
        int N;
        fscanf(fp, "%d", &N);
        if (N<0) return 0;

        double dist[10];
        int G[10],Y[10],R[10];
        for (int i=0; i<N; i++) {
            float d;
            fscanf(fp, "%f", &d);
            dist[i]=d;
            fscanf(fp, "%d%d%d", G+i, Y+i, R+i);
        }
        vi vel;
        for (int v=30; v<=60; v++) {
            bool good=true;
            for (int i=0; i<N; i++) {
                int period = G[i]+Y[i]+R[i];
                int Gtime = G[i]+Y[i];
                double arrivalTime = 3600.*dist[i] / (double)v;
                int q = (int) (arrivalTime / period);
                double signalTime = arrivalTime - q*period;
                if (!(0.<=signalTime && signalTime<=Gtime)) {
                    good = false;
                    break;
                }
            }
            if (good)
                vel.push_back(v);
        }
//        print (vel);
        printf("Case %d: ", ++count);
        if (vel.size()==0)
            printf("No acceptable speeds.\n");
        else {
            for (int i=0; i<vel.size(); ) {
                int s = vel[i];
                int k=1;
                while ((vel[i+k]-s)==k)
                    k++;
                
                if (i!=0) printf(", ");
                if (k==1) printf("%d", s);
                else printf("%d-%d", s, vel[i+k-1]);
                
                i = i + k;
            }
            printf("\n");
        }
    }
    
    return 0;
}

