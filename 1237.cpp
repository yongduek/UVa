// UVa 1237
/****
 Input
 The input begins with a line containing an integer T (T 10) , the number of test cases follow. Each case
 begins with the size of the database D (D < 10000) . The next each of D lines contains M , L and H (0 < L < H
 < 1000000) which are the name of the maker (contains no whitespace and will never exceeds 20 characters),
 the car's lowest price the maker ever made, and the car's highest price the maker ever made respectively. Then
 there is the number of query Q (Q < 1000) . follows. Each of the next Q lines contains an integer P (0 < P <
 1000000) , the query price.
 Output
 Output for each query should be one line containing the name of the maker, or the string ``UNDETERMINED"
 (without quotes) if there is no maker or more than one maker that satisfies the query. You should separate
 output for different case by one empty line.
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

struct Car {
    int lp, hp;
    string name;
    
    Car (int l, int h, char n[]) : lp(l), hp(h), name(n) {}
    
    void print () {
        printf ("%s  %d  %d\n", name.c_str(), lp, hp);
    }
    
    friend bool operator<(const Car& a, const Car& b)
    { return (a.lp==b.lp? (a.hp<b.hp) : (a.lp < b.lp)); }
};

void print (vector<Car>& c) {
    for (int i=0; i<c.size(); i++)
        c[i].print();
}

int main() {
    FILE*fp=stdin;
    if (dbg) {
        fp = fopen ("in-1237.txt", "r");
    }
    int TC;
    fscanf(fp, "%d", &TC);
    while (--TC >= 0) {
        int N;
        fscanf(fp, "%d", &N); // num of cars
        
        vector<Car> cars;
        for (int i=0; i<N; i++) {
            char name[32];
            int lp, hp;
            fscanf(fp, "%s%d%d", name, &lp, &hp);
            
            cars.push_back (Car(lp, hp, name));
        }
        
//        sort (cars.begin(), cars.end());
//        print(cars);
        
        int nq;
        fscanf(fp, "%d", &nq);
        
        /***
        for (int i=0; i<nq; i++) {
            int p;
            fscanf (fp, "%d", &p);
            int id=-1;
            for (int k=0; k<N; k++) {
                if (cars[k].lp<=p && p<=cars[k].hp) {
                    if (id < 0) {
                        id = k;
                    }
                    else {
                        id = -1;
                        break;
                    }
                }
            }
            if (id < 0)
                printf ("UNDETERMINED\n");
            else
                printf("%s\n", cars[id].name.c_str());
        }
        ***/
        /***/
        while (--nq >= 0) {
            int p; // price
            fscanf (fp, "%d", &p);
            // linear search
            vector<Car> sr;
            for (vector<Car>::iterator it=cars.begin();
                 it != cars.end(); ++it) {
                if (it->lp <= p && p<=it->hp)
                    sr.push_back(*it);
            }
            if (sr.size()==1)
                printf ("%s\n", sr[0].name.c_str());
            else // (sr.size()>1 || sr.empty())
                printf ("UNDETERMINED\n");
        }
        /***/
        if (TC > 0) printf("\n");
    }
    
    return 0;
}

