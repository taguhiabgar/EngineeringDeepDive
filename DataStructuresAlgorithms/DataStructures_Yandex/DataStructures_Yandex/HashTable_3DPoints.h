//
//  HashTable_3DPoints.hpp
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 16.01.25.
//

#ifndef HashTable_3DPoints_hpp
#define HashTable_3DPoints_hpp

#include <stdio.h>

class Point3D {
public:
    int x;
    int y;
    int z;
    
    Point3D(int x, int y, int z);
};

int hashPoint3D(const Point3D& point);

bool operator==(const Point3D& a, const Point3D& b);

#endif /* HashTable_3DPoints_hpp */
