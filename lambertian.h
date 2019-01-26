/*
 * lambertian.h
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "hit.h"
#include "material.h"
#include "vec3.h"

class Lambertian : public Material {
    public:
        Lambertian(const Vec3& albedo) : Material(), albedo_(albedo) {}
        ~Lambertian() {}

        virtual bool scatter(const Ray& r, const Hit& hit, Vec3& attenuation, Ray& scattered) const;

    private:
        Vec3 albedo_;
};

#endif /* !LAMBERTIAN_H */
