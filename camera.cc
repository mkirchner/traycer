/*
 * camera.cc
 * Copyright (C) 2019 marc <marc@k2.local>
 *
 * Distributed under terms of the MIT license.
 */

#include "camera.h"
#include "utils.h"

Camera::Camera(const Vec3& origin, const Vec3& lookAt, const Vec3& vup,
               float vFov, float aspect, float aperture, float focusDist) {
    Vec3 cx, cy, cz;
    float theta = vFov * M_PI / 180;
    float half_height = tan(theta/2);
    float half_width = aspect * half_height;
    origin_ = origin;
    aperture_ = aperture;
    cz_ = (origin_ - lookAt).normalized();
    cx_ = Vec3::cross(vup, cz_).normalized();
    cy_ = Vec3::cross(cz_, cx_);
    llc_ = origin_ - half_width * focusDist * cx_
	           - half_height * focusDist * cy_
		   - focusDist * cz_;
    vx_ = 2 * half_width * focusDist * cx_;
    vy_ = 2 * half_height * focusDist * cy_;
}

Ray Camera::getRay(float u, float v) const {
    Vec3 rnd = aperture_ / 2 * sample_from_xy_unit_disk();
    Vec3 offset (rnd.x() * u, rnd.y() * v, 0.0);
    return Ray(origin_ + offset, llc_ + u*vx_ + v*vy_ - origin_ - offset);
}
