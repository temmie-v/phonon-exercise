/*
 * 2021 Crystal and Phonon - Exercise 2
 * ex2detail.cpp
 */

#define _CRT_SECURE_NO_WARNINGS  // not to mention warnings
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)  // loop: 0 to n-1

ofstream ofs("./ex2anime.dat");  // for motion anime
const double PI = 3.141592653589793;
const double M = 17, m = 11, alpha = 2, a = 3;


double freq_from_wavenumber(const double k, int mode) {  // mode : [1/0]=[O/A]
    double res = alpha * (m + M) / (m * M);
    double dif = alpha * sqrt(pow((m + M) / (m * M), 2) -
                              4 * pow(sin(k * a / 2), 2) / (m * M));
    res += dif * (mode ? 1 : -1);
    return sqrt(res);
}

void motion_anime(void) {
    rep(t, 1000) {
        rep(kn, 5){
            double k = kn * PI / (4 * a);
            rep(mode, 2) {
                double omega = freq_from_wavenumber(k, mode);
                double ratio =
                    alpha * (1 + cos(k * a)) / (2 * alpha - m * pow(omega, 2));
                if (ratio == 0) ratio = (mode ? -1e5 : 1e-5);
                double m_amp, M_amp;
                if (abs(ratio) <= 1) {
                    m_amp = 1, M_amp = ratio;
                } else {
                    m_amp = 1 / ratio, M_amp = 1;
                }
                rep(s, 15) {
                    double u = cos(s * k * a - omega * t / 20);
                    u *= (s % 2 ? m_amp : M_amp);
                    ofs << u << ",";
                }
            }
        }
        ofs << endl;
    }
}

int main(void) {
    ofs << fixed << setprecision(15);
    motion_anime();
    return 0;
}
