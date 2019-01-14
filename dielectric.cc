/*
 * dielectric.cc
 * Copyright (C) 2019 marc <marc@k2.local>
 *
 * Distributed under terms of the MIT license.
 */

#include "dielectric.h"
#include "utils.h"

bool Dielectric::scatter(const Ray& r,
                         const Hit& hit,
                         Vec3& attenuation,
                         Ray& scattered) const {

    Vec3 nOut;
    float nRatio;
    float cosine;
    // inside or outside?
    if (Vec3::dot(r.direction(), hit.n) > 0.0) {
        nOut = -hit.n;
        nRatio = refractiveIndex_;
        cosine = refractiveIndex_ * Vec3::dot(r.direction(), hit.n) / r.direction().norm();
    } else {
        nOut = hit.n;
        nRatio = 1.0 / refractiveIndex_;
        cosine = -Vec3::dot(r.direction(), hit.n) / r.direction().norm();
    }
    // refract or reflect?
    Vec3 refracted;
    if (refract(r.direction(), nOut, nRatio, refracted)) {
        float p = schlick(cosine, refractiveIndex_);
        if (drand48() < p) {
            Vec3 reflected = reflect(r.direction(), hit.n);
            scattered = Ray(hit.p, reflected);
        } else {
            scattered = Ray(hit.p, refracted);
        }
    } else {
        Vec3 reflected = reflect(r.direction(), hit.n);
        scattered = Ray(hit.p, reflected);
    }
    // Absorb some blue
    attenuation = Vec3(1.0, 1.0, 1.0);
    return true;
}



