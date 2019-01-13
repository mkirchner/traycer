/*
 * utils.h
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#ifndef UTILS_H
#define UTILS_H

#include "vec3.h"

Vec3 sample_from_unit_sphere();
Vec3 reflect(const Vec3& v, const Vec3& n);

#endif /* !UTILS_H */
