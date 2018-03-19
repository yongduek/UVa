// yndk@sogang.ac.kr

#include <iostream>
#include <set>
using namespace std;

int main(int argc, const char * argv[]) {
    int testcase;
    cin >> testcase;
    while (testcase-- > 0) {
        int a, b, c;
        cin >> a >> b >> c;
    
        // x * y * z = b
        set<int> fset;
        for (int i = 1; i*i < b; i++)
            if (b % i == 0) {
                fset.insert (i), fset.insert (-i), fset.insert (b/i), fset.insert(-b/i);
            }
        

        int s[3];
        bool found = false;
        for (auto it = fset.cbegin(); it != fset.cend(); ++it)
            for (auto jt = fset.cbegin(); jt != fset.cend(); ++jt)
                if (*it != *jt) {
                    int x = *it;
                    int y = *jt;
                    int z = a - x - y; // first constraint: x + y + z = c
                    if (x != z && y != z && fset.find(z) != fset.end()) {
                        if (x*x + y*y + z*z == c) {
                            if (found) {
                                if (x < s[0]) { s[0] = x, s[1] = y, s[2] = z; }
                                else if (x == s[0] && y < s[1])
                                    { s[0] = x, s[1] = y, s[2] = z; }
                            }
                            else {
                                found = true;
                                s[0] = x, s[1] = y, s[2] = z;
                            }
                        }
                    }
                }
        
        if (found)
            printf ("%d %d %d\n", s[0], s[1], s[2]);
        else
            printf ("No solution.\n");
    }
    
    return 0;
}
