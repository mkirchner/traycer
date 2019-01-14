/*
 * metal.cc
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#include "metal.h"
#include "utils.h"


bool Metal::scatter(const Ray& r,
                    const Hit& hit,
                    Vec3& attenuation,
                    Ray& scattered) const {

        Vec3 reflected  = reflect(r.direction().normalized(), hit.n);
        scattered = Ray(hit.p, reflected + fuzz_ * sample_from_unit_sphere());
        attenuation = albedo_;
        return (Vec3::dot(scattered.direction(), hit.n) > 0.0);
}

