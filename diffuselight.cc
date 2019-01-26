/*
 * diffuselight.cc
 * Copyright (C) 2019 marc <marc@k2.local>
 *
 * Distributed under terms of the MIT license.
 */

#include "diffuselight.h"


bool DiffuseLight::scatter(const Ray& r, const Hit& hit, Vec3& attenuation, Ray& scattered) const {
    return false;
}


Vec3 DiffuseLight::emit(float u, float v, const Vec3& p) const {
    return color_;
}

