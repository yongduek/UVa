//
//  Created by Yongduek Seo on 2018. 3. 2..
//  yndk@sogang.ac.kr
//

/*
 UVa 12455 - Bars
 4
 25
 4
 10 12 5 7
 925
 10
 45 15 120 500 235 58 6 12 175 70
 120
 5
 25 25 25 25 25
 0
 2
 13 567

 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bar[20];

int main(int argc, const char * argv[]) {

    int ntests; cin >> ntests;
    
    while (ntests-- > 0) {
        int len;
        cin >> len;
        int p;
        cin >> p;
        for (int i=0; i < p; i++)
            cin >> bar[i];
        
        bool found = false;
        for (int i = 0; i < (1<<p); i++) // every combination
            {
            int sum = 0;
            for (int s = 0; s < p; s++)
                if (i & (1<<s)) // if this bar is chosen
                    sum += bar[s];
            if (sum == len)
                {
                found = true;
                break;
                }
            }
        
        cout << (found ? "YES" : "NO") << endl;
    }

    return 0;
}
