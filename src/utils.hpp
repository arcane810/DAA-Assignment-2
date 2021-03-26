/** @file */

#pragma once

/**
 * A Class for a point in 2-D Space
 */
class Point {
  public:
    /// The x coordinate of the point
    long double x;
    /// The y coordinate of the point
    long double y;

    /**
     * Constructor. Initializes the coordinates to the passed parameters
     *
     * @param x The x coordinate
     * @param y The y coordinate
     */
    Point(long double x, long double y);

    /**
     * Default Constructor
     */
    Point();
    /**
     * Operator overloading for comparing two points
     */
    bool operator<(Point p2);
};