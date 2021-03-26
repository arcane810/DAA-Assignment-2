/** @file */

#include "utils.hpp"
#include <vector>

/**
 * A Class to store the line of form y = ax + b
 */
class Line {
  public:
    /// x coefficient
    long double a;
    /// constant
    long double b;
    /**
     * Constructor. Initializes the coefficients to the passed parameters
     *
     * @param a The x coefficient
     * @param b The constant
     */
    Line(long double a, long double b);

    /**
     * Default Constructor
     */
    Line();
};

/**
 * A function which takes in a vector of points and returns the segments of best
 * fit for it.
 */
std::pair<long double, std::vector<Line>> segment_fit(std::vector<Point> points,
                                                      long double penalty);