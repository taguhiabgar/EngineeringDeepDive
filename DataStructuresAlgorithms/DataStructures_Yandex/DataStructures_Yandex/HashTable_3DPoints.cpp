//
//  HashTable_3DPoints.cpp
//  DataStructures_Yandex
//
//  Created by Taguhi Abgar on 16.01.25.
//

#include "HashTable_3DPoints.h"

Point3D::Point3D(int x, int y, int z) : x(x), y(y), z(z) {
    
}

int hashPoint3D(const Point3D& point) {
    return point.x * 929 + point.y * 401 + point.z * 137;
}
