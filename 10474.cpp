// UVa 10474

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

const bool dbg=0;



//
// binary search for the lower bound: {1,2,2,3,3,3}, it must find 4 for query=3
//
int searchQ (vector<int>& ns, int l, int u, int q)
{
    int b;
    while (l!=u) {
        b = (l+u)/2;
        if (ns[b] >= q)
            u = b;
        else
            l = b+1;
    }
    
    if (q == ns[l])
        return l;
    else
        return -1;
}

int main() {
    FILE*fp=stdin;
    if (dbg) {
        fp = fopen ("in-10474.txt", "r");
    }
    while (1) {
        static int count=0;
        int N, Q;
        fscanf(fp, "%d %d", &N, &Q);
        if (N==0 && Q==0) return 0;
        ++count;
        printf ("CASE# %d:\n", count);
        
        vector<int> marbles(N);
        for (int i=0; i<N; i++)
            fscanf(fp, "%d", &marbles[i]);
        
        std::sort(marbles.begin(), marbles.end());
        
        for (int i=0; i<Q; i++) {
            int query;
            fscanf(fp, "%d", &query);
            // now try to find the query in the array
            int p = searchQ (marbles, 0, N-1, query);
            if (p<0)
                printf ("%d not found\n", query);
            else
                printf ("%d found at %d\n", query, p+1);
        }
    }
    
    return 0;
}

/**
 //
 // sort & linear search from the beginning.
 //
int main() {
    FILE*fp=stdin;
    if (dbg) {
        fp = fopen ("in-10474.txt", "r");
    }
    while (1) {
        static int count=0;
        int N, Q;
        fscanf(fp, "%d %d", &N, &Q);
        if (N==0 && Q==0) return 0;
        ++count;
        printf ("CASE# %d:\n", count);
        
        vector<int> marbles(N);
        for (int i=0; i<N; i++)
            fscanf(fp, "%d", &marbles[i]);
        
        std::sort(marbles.begin(), marbles.end());
        
        for (int i=0; i<Q; i++) {
            int query;
            fscanf(fp, "%d", &query);
            // now try to find the query in the array
            if (query > marbles[N-1]) {
                printf ("%d not found\n", query);
                continue;
            }
            bool notFound=true;
            for (int j=0; j<N; j++)
                if (query==marbles[j]) {
                    printf ("%d found at %d\n", query, j+1);
                    notFound=false;
                    break;
                }
            if (notFound)
                printf ("%d not found\n", query);
        }
    }
    
    return 0;
}
****/