//
//  ConvexHull.hpp
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 30.01.25.
//

#ifndef ConvexHull_h
#define ConvexHull_h

#include <stdio.h>
#include <vector>

class Point {
public:
    double x;
    double y;
};

double distance(const Point& a, const Point& b);

std::vector<Point> GrahamScan(const std::vector<Point>& points);
std::vector<Point> ConvexHullDivideAndConquer(const std::vector<Point>& points);
std::vector<Point> QuickHull(const std::vector<Point>& points);


#endif /* ConvexHull_h */
