//
//  Created by Yongduek Seo on 2018. 3. 19.
//  yndk@sogang.ac.kr
//

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm> // next_permutation()

using namespace std;

int main(int argc, const char * argv[]) {
    
    int npeople, nconst;
    
    do {
        cin >> npeople >> nconst ;
        if (npeople == 0 && nconst == 0) break;

        vector< tuple<int, int, int> > constraints;
        
        for (int i = 0; i < nconst; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            constraints.push_back (make_tuple(a,b,c));
        }
        
        int count = 0;
        int p[8] = {0,1,2,3,4,5,6,7};
        do {
            bool failed = false;
            for (int i = 0; i < nconst; i++) {
                int dist = abs(p[get<0>(constraints[i])] - p[get<1>(constraints[i])]);
                if (get<2>(constraints[i]) > 0 && dist <= get<2>(constraints[i])) // positive constraint
                    continue;
                else if (get<2>(constraints[i]) < 0 && dist >= -get<2>(constraints[i]))
                    continue;
                else {
                    failed = true;
                }
            }
            if (failed == false)
                count ++; // one more case
        } while (next_permutation(p, p + npeople));
        cout << count << endl;
    } while (1);
    
    return 0;
}
