/*
 * dielectric.h
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#ifndef DIELECTRIC_H
#define DIELECTRIC_H

#include "hit.h"
#include "material.h"
#include "vec3.h"

class Dielectric : public Material {
    public:
        Dielectric(float refractiveIndex) : Material(), refractiveIndex_(refractiveIndex) {}
        ~Dielectric() {}

        virtual bool scatter(const Ray& r, const Hit& hit, Vec3& attenuation, Ray& scattered) const;

    private:
        float refractiveIndex_;
};


#endif /* !DIELECTRIC_H */
