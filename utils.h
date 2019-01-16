/*
 * utils.h
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#ifndef UTILS_H
#define UTILS_H

#include "vec3.h"

Vec3 reflect(const Vec3& v, const Vec3& n);
bool refract(const Vec3& v, const Vec3& n, float nRatio, Vec3& refracted);
Vec3 sample_from_unit_sphere();
Vec3 sample_from_xy_unit_disk();
float schlick(float cosine, float refractiveIndex);

#endif /* !UTILS_H */
