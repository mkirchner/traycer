/*
 * camera.cc
 * Copyright (C) 2019 marc <marc@k2.local>
 *
 * Distributed under terms of the MIT license.
 */

#include "camera.h"


Camera::Camera(const Vec3& origin, const Vec3& lookAt, const Vec3& vup,
               float vFov, float aspect) {
    Vec3 cx, cy, cz;
    float theta = vFov * M_PI / 180;
    float half_height = tan(theta/2);
    float half_width = aspect * half_height;
    origin_ = origin;
    cz = (origin_ - lookAt).normalized();
    cx = Vec3::cross(vup, cz).normalized();
    cy = Vec3::cross(cz, cx);
    llc_ = origin_ - half_width * cx - half_height * cy - cz;
    vx_ = 2 * half_width * cx;
    vy_ = 2 * half_height * cy;
}

Ray Camera::getRay(float u, float v) const {
    return Ray(origin_, llc_ + u*vx_ + v*vy_ - origin_);
}
