/*
 * material.cc
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#include "material.h"


Material::~Material() {
}

Vec3 Material::emit(float u, float v, const Vec3& p) const {
    return Vec3(0.0, 0.0, 0.0);
}
