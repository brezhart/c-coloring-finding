
// by: @brezhart
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include "bits/stdc++.h"
using namespace std;
// <>------CODE STARTS BELLOW-------<> //
const unsigned int n = 17;
const unsigned int m = 17;
const unsigned int q = 4;
int iter = 0;
vector<vector<unsigned int>> field(q, vector<unsigned int>(m, 0));
clock_t beegin;
void paint() {
    iter++;
    for (int i = 0; i < n; i++) {
        field[0][i] = 0 ;
        field[1][i] = 0 ;
        field[2][i] = 0 ;
        for (int g = 0; g < m; g++) {
            field[rand() % q][i] |= (1 << g);
        }
    }
    for (int j = 0; j < q; j++) {
        for (int i = 0; i < n - 1; i++) {
            for (int g = i + 1; g < n; g++) {
                if (__builtin_popcount(field[j][i] & field[j][g]) >= 2) {
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
    for (int j = 0; j < q; j++) {
        for (int i = 0; i < n; i++) {
            cout << field[j][i] << " ";
        }
        cout << endl;
    }
    clock_t eend = clock();
    double elapsed_secs = double(eend - beegin) / CLOCKS_PER_SEC;
    cout << iter << endl;
    cout << fixed << elapsed_secs << endl;
    cout << iter/elapsed_secs << endl;
    exit(0);
}

signed main() {
    srand(time(NULL));
//    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
//    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    beegin = clock();
    while (true) {
        paint();
//        end = std::chrono::steady_clock::now();
    }
}
