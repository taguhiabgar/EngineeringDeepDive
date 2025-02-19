//
//  ConvexHull.cpp
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 30.01.25.
//

#include "ConvexHull.h"
#include <cmath>
#include <algorithm>

Point MiddlePoint(const std::vector<Point>& points) {
    Point p;
    p.x = 0;
    p.y = 0;
    for (const Point& point : points) {
        p.x += point.x / points.size();
        p.y += point.y / points.size();
    }
    return p;
}

std::vector<Point> GrahamScan(const std::vector<Point>& points) {
    std::vector<Point> convexHull;
    Point middle = MiddlePoint(points);
    convexHull = points;
//    std::sort(convexHull.begin(), convexHull.end(), [&middle](const Point& a, const Point& b) {
//        double tgA = a.y / (a.x)
//    });
    
    return convexHull;
}


std::vector<Point> ConvexHullDivideAndConquer(const std::vector<Point>& points);


std::vector<Point> QuickHull(const std::vector<Point>& points);

