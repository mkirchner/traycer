/*
 * material.h
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#ifndef MATERIAL_H
#define MATERIAL_H

#include "hit.h"
#include "ray.h"
#include "vec3.h"

class Material {
    public:
        typedef std::shared_ptr<Material> Ptr;
        virtual ~Material() = 0;
        virtual bool scatter(const Ray& r, const Hit& hit, Vec3& attenuation, Ray& scattered) const = 0;
};


#endif /* !MATERIAL_H */
