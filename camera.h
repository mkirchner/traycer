/*
 * camera.h
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"
#include "vec3.h"

class Camera {
    public:
        Camera(const Vec3& origin, const Vec3& lookAt, const Vec3& vup,
               float vFov, float aspect, float aperture, float focusDist);
        Ray getRay(float u, float v) const;

    private:
        Vec3 llc_, vx_, vy_, origin_, cz_, cx_, cy_;
        float aperture_;

};

#endif /* !CAMERA_H */
