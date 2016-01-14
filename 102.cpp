// UVa 102

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const bool dbg=false;

int main() {
    FILE *fp=stdin;
    while (1) {
        int b[9]; // bottles in 3 bins.
        for (int i=0; i<9; i++) {
            int n=fscanf(fp, "%d", b+i);
            if (n<1 || feof(fp)) return 0;
        }
        
        vector<int> moves;
        vector<int> bin(3);
        bin[0]=0, bin[1]=1; bin[2]=2; // bin[k] represents the color = {B=0, G=1, C=2}
        string str("BGC");

        int minMove=1<<30;
        vector<int> minBin(3);
        string minStr;

        do {
            if (dbg) printf ("%d %d %d\n", bin[0], bin[1], bin[2]);
            int sum = 0; // total bottles moved.
            // bin[] = {a,b,c}, then bin[0] will have bottles whose id%3==a, bin[1] id%3==b, bin[2] id%3==c
            for (int i=0; i<9; i++) { // for each bottle
                int bottleColor = i%3;
                int bottleBinId = i/3;
                // Now, put this bottle to a bin of the same color.
                // So, choose the bin of the color
                int bin_id;
                for (int k=0; k<3; k++) { // find the bin for bottle i = (bottleColor, org_bin)
                    if (bottleColor == bin[k]) {
                        bin_id = k;
                        break;
                    }
                }
                if (bin_id != bottleBinId)
                    sum += b[i];
            }
            string s;  for (int k=0; k<3; k++) s.push_back(str[bin[k]]);
            if ( (sum < minMove )
                || (sum==minMove && (minStr.empty() || s < minStr)) ) {
                    minMove = sum;
                    minBin = bin;
                    minStr = s;
            }
            moves.push_back(sum);
            if (dbg) printf ("%lu : %s %d : min=(%s %d)\n", moves.size(), s.c_str(), sum, minStr.c_str(), minMove);
        } while (std::next_permutation(bin.begin(), bin.end()));
        
        printf("%s %d\n", minStr.c_str(), minMove);
        
        if (dbg) {
            sort (moves.begin(), moves.end());
            for (int i=0; i<moves.size(); i++)
                printf ("%d  ", moves[i]);
            printf("\n-------------\n");
        }
    }
    
    return 0;
}