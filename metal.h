/*
 * metal.h
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#ifndef METAL_H
#define METAL_H

#include "hit.h"
#include "material.h"
#include "vec3.h"

class Metal : public Material {
    public:
        Metal(const Vec3& albedo) : albedo_(albedo) {}
        ~Metal() {}

        virtual bool scatter(const Ray& r, const Hit& hit, Vec3& attenuation, Ray& scattered) const;

    private:
        Vec3 albedo_;
};

#endif /* !METAL_H */
