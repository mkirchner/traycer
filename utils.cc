/*
 * utils.cc
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#include "utils.h"

Vec3 sample_from_unit_sphere() {
    // Sample from the unit cube and reject until we find a point
    // inside the sphere.
    Vec3 p;
    do {
        p = 2.0 * Vec3(drand48(), drand48(), drand48()) - Vec3(1.0, 1.0, 1.0);
    } while (p.squared_norm() >= 1.0);
    return p;
}


Vec3 reflect(const Vec3& v, const Vec3& n) {
    return v - 2*Vec3::dot(v, n)*n;
}
