/*
 * object.h
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "ray.h"
#include "vec3.h"

struct Hit {
    float t;  // ray coefficient
    Vec3 p;  // point
    Vec3 n;  // normal
};


class Object {
    public:
        virtual ~Object() = 0;
        virtual bool testHit(const Ray& r, float tMin, float tMax, float* t) = 0;
        virtual Hit getHit(const Ray& r, float t) = 0;
};

#endif /* !OBJECT_H */
