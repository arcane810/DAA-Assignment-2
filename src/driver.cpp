#include "segment-fit.hpp"
#include <chrono>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std::chrono;
using namespace std;

int main(int argc, char *argv[]) {
    ifstream fin(argv[1]);
    string ofile = string(argv[1]) + ".out";
    ofstream fout(ofile);
    int n;
    long double c;
    fin >> n >> c;
    vector<Point> points(n);
    for (Point &pt : points) {
        fin >> pt.x;
        fin >> pt.y;
    }

    pair<long double, vector<Line>> ans = segment_fit(points, c);
    fout << ans.first << "\n";
    fout << ans.second.size() << "\n";
    for (Line l : ans.second) {
        fout << l.a << " " << l.b << "\n";
    }

    return 0;
}