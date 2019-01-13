/*
 * lambertian.cc
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#include "lambertian.h"
#include "utils.h"

bool Lambertian::scatter(const Ray& r,
                         const Hit& hit,
                         Vec3& attenuation,
                         Ray& scattered) const {
        Vec3 reflected  = hit.p + hit.n + sample_from_unit_sphere();
        scattered = Ray(hit.p, reflected-hit.p);
        attenuation = albedo_;
        return true;
}


