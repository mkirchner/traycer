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


bool refract(const Vec3& v, const Vec3& n, float nRatio, Vec3& refracted) {
    // nRatio is the ratio of refraction indexes
    Vec3 u = v.normalized();
    float dt = Vec3::dot(u, n);
    float discriminant = 1.0 - nRatio*nRatio * (1.0-dt*dt);
    if (discriminant > 0.0) {
        refracted = nRatio * (u - n*dt) - n*sqrt(discriminant);
        return true;
    }
    return false;
};


float schlick(float cosine, float refractiveIndex) {
    float r0 = (1 - refractiveIndex) / (1 + refractiveIndex);
    r0 *= r0;
    return r0 + (1-r0)*pow(1-cosine, 5);
}
