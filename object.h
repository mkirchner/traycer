/*
 * object.h
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "hit.h"
#include "material.h"
#include "ray.h"
#include "vec3.h"

class Object {
    public:
        Object(Material::Ptr material) : material_(material) {}
        virtual ~Object() = 0;
        Material::Ptr getMaterial() const;
        virtual bool testHit(const Ray& r, float tMin, float tMax, float* t) = 0;
        virtual Hit getHit(const Ray& r, float t) = 0;

    private:
        Material::Ptr material_;
};

#endif /* !OBJECT_H */
