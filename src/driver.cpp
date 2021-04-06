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

    auto start = high_resolution_clock::now();
    int n;
    long double c;
    fin >> n >> c;
    vector<Point> points(n);
    for (Point &pt : points) {
        fin >> pt.x;
        fin >> pt.y;
    }

    pair<long double, vector<pair<Line, pair<long double, long double>>>> ans =
        segment_fit(points, c);
    fout << ans.first << "\n";
    cout << "Error: " << ans.first << "\n";
    fout << ans.second.size() << "\n";
    for (auto it : ans.second) {
        fout << it.first.a << " " << it.first.b << " " << it.second.first << " "
             << it.second.second << "\n";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time Taken: " << duration.count() / 1000.0 << " ms\n";

    return 0;
}