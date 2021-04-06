/** @file */
#include "segment-fit.hpp"
#include <algorithm>
#include <iostream>
#include <utility>

Line::Line(long double a, long double b) : a(a), b(b){};
Line::Line() : a(0), b(0){};

Line fitLine(std::vector<Point> &points, int l, int r) {
    int n = r - l + 1;
    long double sxiyi = 0, sxi = 0, syi = 0, sxisq = 0;
    for (int i = l; i <= r; i++) {
        sxiyi += points[i].x * points[i].y;
        sxi += points[i].x;
        syi += points[i].y;
        sxisq += points[i].x * points[i].x;
    }
    long double a = (n * sxiyi - sxi * syi) / (n * sxisq - sxi * sxi);
    long double b = (syi - a * sxi) / n;
    return Line(a, b);
}

long double sq_distance(Point p, Line line) {
    long double pred_y = line.a * p.x + line.b;
    long double diff = p.y - pred_y;
    return diff * diff;
}

long double fit_error(std::vector<Point> &points, Line line, int l, int r) {
    int n = r - l + 1;
    long double error = 0;
    for (int i = l; i <= r; i++) {
        error += sq_distance(points[i], line);
    }
    return error;
}

std::pair<long double,
          std::vector<std::pair<Line, std::pair<long double, long double>>>>
segment_fit(std::vector<Point> points, long double penalty) {
    std::sort(points.begin(), points.end());
    int n = points.size();
    std::vector<std::vector<Line>> pair_lines(n, std::vector<Line>(n, Line()));
    std::vector<std::vector<long double>> pair_errors(
        n, std::vector<long double>(n, 0));
    for (int i = 0; i < n; i++) {
        pair_lines[i][i] = Line(0, points[i].y);
        pair_errors[i][i] = 0;
        for (int j = i + 1; j < n; j++) {
            pair_lines[i][j] = fitLine(points, i, j);
            pair_errors[i][j] = fit_error(points, pair_lines[i][j], i, j);
        }
    }
    std::vector<long double> opt(n, penalty);
    std::vector<long double> parent(n, 0);
    for (int j = 1; j < n; j++) {
        parent[j] = j;
        long double min_cost = __LDBL_MAX__;
        int opt_index = j - 1;
        for (int i = 0; i <= j; i++) {
            long double curr_cost = pair_errors[i][j] + penalty;
            if (i > 0) {
                curr_cost += opt[i - 1];
            }
            if (curr_cost < min_cost) {
                opt_index = i;
                min_cost = curr_cost;
            }
        }
        opt[j] = min_cost;
        parent[j] = opt_index;
    }
    std::vector<std::pair<Line, std::pair<long double, long double>>> segments;
    int st = n - 1;
    while (st >= 0) {
        segments.push_back(
            {pair_lines[parent[st]][st], {points[parent[st]].x, points[st].x}});
        st = parent[st] - 1;
    }
    reverse(segments.begin(), segments.end());
    return {opt[n - 1], segments};
}