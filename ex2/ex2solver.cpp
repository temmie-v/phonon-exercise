/*
 * 2021 Crystal and Phonon - Exercise 2
 * ex2solver.cpp
 */

#define _CRT_SECURE_NO_WARNINGS  // not to mention warnings
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)  // loop: 0 to n-1

ofstream ofs1("./ex2rel.dat");  // for dispersion relation
ofstream ofs2("./ex2ans.dat");  // for motion anime
const double PI = 3.141592653589793;
const double M = 17, m = 11, alpha = 2, a = 3;


double freq_from_wavenumber(const double k, int mode) {  // mode : [1/0]=[O/A]
    double res = alpha * (m + M) / (m * M);
    double dif = alpha * sqrt(pow((m + M) / (m * M), 2) -
                              4 * pow(sin(k * a / 2), 2) / (m * M));
    res += dif * (mode ? 1 : -1);
    return sqrt(res);
}

void dispersion_relation(void) {
    int max_k = 1000 * PI / a;
    rep(i, 2 * max_k + 1) {
        double k = (double)(i - max_k) / 1000;
        ofs1 << k << "," << freq_from_wavenumber(k, 0) << ","
             << freq_from_wavenumber(k, 1) << endl;
    }
}

void motion_anime(const double k) {
    ofs2 << "K = " << k << endl;
    rep(mode, 2) {
        double omega = freq_from_wavenumber(k, mode);
        ofs2 << "  mode:" << (mode ? "TO" : "TA") << endl;
        double ratio = alpha * (1 + cos(k * a)) / (2 * alpha - m * pow(omega, 2));
        // ratio of amplitude (Na / Cl)
        if (ratio == 0) {  // ... k = pi / a
            ratio = (mode ? -1e5 : 1e-5);
            // TO : Na only / TA : Cl only move
        }
        double m_amp, M_amp;
        if (abs(ratio) <= 1) {
            m_amp = 1, M_amp = ratio;
        } else {
            m_amp = 1 / ratio, M_amp = 1;
        }
        rep(t, 25) {
            rep(s, 15) {
                double u = cos(s * k * a - omega * t / 2);
                u *= (s % 2 ? m_amp : M_amp);
                ofs2 << u << (s != 14 ? "," : "");
            }
            ofs2 << endl;
        }
        ofs2 << endl;
    }
}

int main(void) {
    ofs1 << fixed << setprecision(15);
    ofs2 << fixed << setprecision(15);

    dispersion_relation();

    vector<double> K = {0, PI / (4 * a), PI / (2 * a), 3 * PI / (4 * a), PI / a};
    rep(i, K.size()) motion_anime(K.at(i));

    return 0;
}
