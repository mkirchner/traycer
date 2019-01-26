/*
 * diffuselight.h
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#ifndef DIFFUSELIGHT_H
#define DIFFUSELIGHT_H

#include "material.h"

class DiffuseLight : public Material {
    public:
        DiffuseLight(const Vec3& color) : Material(), color_(color) {}
	~DiffuseLight() {}
        virtual bool scatter(const Ray& r, const Hit& hit, Vec3& attenuation, Ray& scattered) const;
        virtual Vec3 emit(float u, float v, const Vec3& p) const;

    private:
        Vec3 color_;
};


#endif /* !DIFFUSELIGHT_H */
