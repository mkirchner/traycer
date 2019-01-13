/*
 * hit.h
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#ifndef HIT_H
#define HIT_H

#include "vec3.h"

struct Hit {
    float t;  // ray coefficient
    Vec3 p;  // point
    Vec3 n;  // normal
};

#endif /* !HIT_H */
