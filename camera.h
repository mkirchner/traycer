/*
 * camera.h
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"

class Camera {
    public:
        Camera(const Vec3& llc, const Vec3& vx, const Vec3& vy, const Vec3& origin)
            : llc_(llc), vx_(vx), vy_(vy), origin_(origin) {}
        Ray getRay(float u, float v) const;

    private:
        Vec3 llc_, vx_, vy_, origin_;

};

#endif /* !CAMERA_H */
