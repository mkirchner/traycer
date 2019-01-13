/*
 * ray.cc
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#include "ray.h"

Vec3 Ray::operator()(const Float t) const {
    return o_ + t * d_;
}

