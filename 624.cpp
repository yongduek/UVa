// UVa 1260 sales
/****
 input
 1
 2
 3
 4
 5
 6
 7
 5 3 1 3 4
 10 4 9 8 4 2
 20 4 10 5 7 4
 90 8 10 23 1 2 3 4 5 7
 45 8 4 10 44 43 12 9 8 2
 100 20 1 2 3 99 4 5 30 16 73 28 19 2 29 4 30 5 10 64 7 11
 20 1 1
 output
 1
 2
 3
 4
 5
 6
 7
 1 4 sum:5
 8 2 sum:10
 10 5 4 sum:19
 10 23 1 2 3 4 5 7 sum:55
 4 10 12 9 8 2 sum:45
 1 2 3 4 5 30 16 2 4 5 10 7 11 sum:100
 1 sum:1
 ****/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <queue>
#include <deque>

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

void print (std::queue<int> q) {
    for (int i=0; i<q.size(); i++) {
        printf (" %d", q.front());
        q.pop();
    }
    printf(" :::\n");
}

void print (std::deque<int> q) {
    printf(" (");
    for (int i=0; i<q.size(); i++) {
        printf (" %d", q[i]);
    }
    printf(");\n");
}


/****
int stepinto=0;
std::deque<int> q;
void tryNext (int ti, int len,
             const int nSongs, const int tracks[], const int limit,
             int& maxLen,
             deque<int>& maxq)
{
    if (ti == nSongs) {
        // at a leaf, update maxLen
        if (len > maxLen) { // record
            maxLen = len;
            maxq = q;
//            printf("maxq: "); print(maxq);
        }
//        printf("f-");
//        print(q);
    }
    
    for (int i=ti; i<nSongs; i++) {
//        for (int k=0; k<stepinto; k++) printf("\t");
//        printf("i=%d; ", i);
        int len2 = len + tracks[i];
        if (len2 <= limit) {
            q.push_back(tracks[i]);
//            print(q);
            stepinto++;
            tryNext (i+1, len2, nSongs, tracks, limit, maxLen, maxq);
            --stepinto;
            q.pop_back();
        }
        else {
            if (len > maxLen) {
                maxLen = len;
                maxq = q;
//                printf("maxq: "); print(maxq);
            }
//            printf("--"); print(q);
        }
    }
}

int main() {
    FILE*fp=stdin;
    if (dbg) {
        fp = fopen ("in-624.txt", "r");
    }

    int limit, nSongs;
    while (fscanf(fp,"%d%d", &limit, &nSongs)==2) {
        int tracks[nSongs];
        for (int i=0; i<nSongs; i++)
            fscanf(fp, "%d", tracks+i);
        
        // now search max
        int maxLength = 0;
        std::deque<int> maxq;

        tryNext (0, 0, nSongs, tracks, limit, maxLength, maxq);
        
//        print(maxq);
        while (!maxq.empty()) {
            printf("%d ", maxq.front());
            maxq.pop_front();
        }
        printf("sum:%d\n", maxLength);
    }
    
    return 0;
}
****/


/*********/
int maxLength = 0;
std::deque<int> maxq;

int limit, nSongs;
vector<int> tracks;

void dfs (deque<int> choices, int n_choice, int length)
{
    // visit the node of n_choice
    length += tracks[n_choice];
    choices.push_back(tracks[n_choice]);
    if (length>maxLength
        || (length==maxLength && maxq.size()<choices.size())) {
        maxLength = length;
        maxq = choices;
    }
    
    for (int i=n_choice+1; i<tracks.size(); i++)
        if (length + tracks[i] <= limit)
            dfs (choices, i, length);
}

int main() {
    FILE*fp=stdin;
    if (dbg) {
        fp = fopen ("in-624.txt", "r");
    }
    
    while (fscanf(fp,"%d%d", &limit, &nSongs)==2) {
        tracks.clear();
        for (int i=0; i<nSongs; i++) {
            int trk;
            fscanf(fp, "%d", &trk);
            tracks.push_back(trk);
        }
        
        maxLength=0;
        maxq.clear();
        
        // now search max
        deque<int> choice;
        for (int i=0; i<nSongs; i++)
            dfs (choice, i, 0);

        for (int i=0; i<maxq.size(); i++)
            printf ("%d ", maxq[i]);
        printf("sum:%d\n", maxLength);
    }
    
    return 0;
}

/************/
/*******************
int main() {
    FILE*fp=stdin;
    if (dbg) {
        fp = fopen ("in-624.txt", "r");
    }
    
    int limit, nSongs;
    vector<int> tracks;

    while (fscanf(fp,"%d%d", &limit, &nSongs)==2) {
        
        tracks.clear();
        for (int i=0; i<nSongs; i++) {
            int trk;
            fscanf(fp, "%d", &trk);
            tracks.push_back(trk);
        }
        
        int maxLength=0;
        int maxNTracks=0;
        int maxSel=0;
        
        int ncombi = 1<<nSongs; // total combination

//        printf ("----\nnSongs=%d  ncomb = %d\n", nSongs, ncombi);
//        for (int i=0; i<nSongs; i++)
//            printf("%d ", tracks[i]);
//        printf("\n");
        
        // now search max
        for (int i=0; i<ncombi; i++) {
            // for each combination
            int ntracks=0;
            int sum = 0;
            int flag = true;
            for (int ns=0; flag && ns<nSongs; ns++) {
                int mask = 1<<ns;
                if (i & mask) {
                    if (sum + tracks[ns] <= limit)
                        sum += tracks[ns], ntracks++;
                    else
                        flag = false;
                }
            }
            if (sum > maxLength ||
                ((sum==maxLength) && (ntracks>maxNTracks))) {
                maxNTracks = ntracks;
                maxLength = sum;
                maxSel = i;
            }
        }
        
        for (int ns=0; ns<nSongs; ns++) {
            int mask = 1<<ns;
            if (maxSel & mask)
                printf ("%d ", tracks[ns]);
        }
        printf("sum:%d\n", maxLength);
    }
    
    return 0;
}
***********/