// UVa 927
/****
 http://foxlime.tistory.com/115
 32bit 자료형 / 64bit 자료형의 크기 정리
 자료형    32 bit OS      64bit OS
 int   32 bit (4 Byte)       32 bit
 short 16 bit                16 bit
 long 32 bit                 64 bit
 longlong 64 bit             64 bit
 pointer (*) 32 bit          64 bit
 long double 12 bytes        16 bytes (128 bit)  -- check!
 size_t , ssize_t 32 bit     64 bit
 
 
 Process
 This one gave me a lot of problems. The concept itself was difficult to understand at first. A sequence a_n consists of groups of size d * n. For example, 1 2 2 3 3 3 4 4 4 4… where d = 1 or 1 1 2 2 2 2 3 3 3 3 3 3 4 4 4 4 4 4 4 4… where d = 2. Given this sequence, we’re given a polynomial function and asked to find the value outputted from this function whose input we calculate given an index k and d for the sequence a_n. Therefore, we must pregenerate the a_n sequence and calculate the value of the group the index belongs to. I preprocessed a few thousand values in the sequence a_n where d = 1. The values where d = 2, 3… can be calculated by the formula k / d. I used (k – 1) / d because I shifted to zero index. The most painful part was that I glanced over the bit that said, output is “less or equal than 2^63 – 1”. This is a long long value and must be incorporated in your evaluation function and print statement, or you will certainly get WA.
****/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <sstream>

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

vector<string> split (string str, char delimiter)
{
    vector<string> vs;
    std::stringstream ss(str);
    string tok;
    
    while (getline(ss, tok, delimiter))
        vs.push_back(tok);

    return vs;
}

vector<int> split (string str)
{
    vector<string> vs = split (str, ' ');
    vector<int> vi;
    for (int i=0; i<vs.size(); i++)
        vi.push_back(atoi(vs[i].c_str()));
    return vi;
}

const bool dbg=0;

unsigned long long get_a (int n, vi& c) {
    ull a=0;
    for (int i=0; i<c.size(); i++) {
        ull p=1;
        for (int j=0; j<i; j++)
            p *= n;
        a += (c[i]*p);
    }
    return a;
}

int main() {
    FILE*fp=stdin;
    if (dbg) {
        fp = fopen ("in-927.txt", "r");
    }
    int TC;
    fscanf(fp, "%d", &TC);
    while (--TC >= 0) {
        int degree;
        fscanf (fp, "%d", &degree);
        vi c;
        for (int i=0; i<=degree; i++) {
            int num;
            fscanf(fp, "%d", &num);
            c.push_back(num);
        }
        //        print (c, "c=");
        
        int d, k;
        fscanf(fp, "%d", &d);
        fscanf(fp, "%d", &k);
        //        printf ("d=%d k=%d\n", d, k);
        //vector<ull> seq;
        ull seqSize=0;
        unsigned long a;
        int n=0;
        while (seqSize < k) {
            ++n;
            a = get_a (n, c);
            int m = n * d;
            seqSize += m;
//            while (--m >= 0)
//                seq.push_back(a);
        }
        
        //        print (seq, "seq");
        // output
        printf ("%lu\n", a);
    }
    
    return 0;
}

/****
 // initial version
int main() {
    FILE*fp=stdin;
    if (dbg) {
        fp = fopen ("in-927.txt", "r");
    }
    int TC;
    fscanf(fp, "%d", &TC);
    while (--TC >= 0) {
        int degree;
        fscanf (fp, "%d", &degree);
        vi c;
        for (int i=0; i<=degree; i++) {
            int num;
            fscanf(fp, "%d", &num);
            c.push_back(num);
        }
//        print (c, "c=");
        
        int d, k;
        fscanf(fp, "%d", &d);
        fscanf(fp, "%d", &k);
//        printf ("d=%d k=%d\n", d, k);
        vector<ull> seq;
        int n=0;
        while (seq.size() < k) {
            ++n;
            ull a = get_a (n, c);
            int m = n * d;
            while (--m >= 0)
                seq.push_back(a);
        }
        
//        print (seq, "seq");
        // output
        printf ("%llu\n", seq[k-1]);
    }
    
    return 0;
}
****/