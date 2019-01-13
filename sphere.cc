/*
 * sphere.cc
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#include "sphere.h"

bool Sphere::testHit(const Ray& r, float tMin, float tMax, float* t) {
    Vec3 CO = r.origin() - center_;
    // std::cout << CO[0] << ", " << CO[1] << ", " << CO[2] << std::endl;
    float a = Vec3::dot(r.direction(), r.direction());
    float b = 2 * Vec3::dot(CO, r.direction());
    float c = Vec3::dot(CO, CO) - radius_*radius_;
    float d = b*b - 4*a*c;
    // std::cout << d << std::endl;
    if (d > 0) {
        float sqrtd = sqrt(d);
        float root = 0.5 * (-b - sqrtd) / a;
        if (tMin <= root && root < tMax) {
            *t = root;
            return true;
        }
        root = 0.5 * (-b + sqrtd) / a;
        if (tMin <= root && root < tMax) {
            *t = root;
            return true;
        }
    }
    return false;
}

Hit Sphere::getHit(const Ray& r, float t) {
    Hit h;
    h.t = t;
    h.p = r(t);
    h.n = (h.p - center_) / radius_;
    return h;
}



