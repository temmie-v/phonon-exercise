/*
 * 2021 Crystal and Phonon - Exercise 1
 * solver.cpp
 */

#define _CRT_SECURE_NO_WARNINGS  // not to mention warnings
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)  // loop: 0 to n-1

ofstream ofs("./ex1ans.dat"); // output
const double PI = 3.141592653589793;

void writeline(const vector<double> a) {
    int n = a.size();
    rep(i, n - 1) ofs << fixed << setprecision(15) << a.at(i) << ",";
    ofs << fixed << setprecision(15) << a.at(n - 1) << endl;
}

void solve(const double k) {
    rep(n, 25) {
        double wt = n * PI / 12;
        vector<double> u;
        rep(s, 13) u.push_back(cosl((s - 6) * k - wt));
        writeline(u);
    }
}

int main(void) {
    vector<double> K = {0, PI / 3, PI / 2, PI};
    rep(i, K.size()) {
        ofs << "K = " << fixed << setprecision(15) << K.at(i) << endl;
        solve(K.at(i));
        ofs << endl;
    }
    return 0;
}
