/*
 * camera.cc
 * Copyright (C) 2019 marc <marc@k2.local>
 *
 * Distributed under terms of the MIT license.
 */

#include "camera.h"


Ray Camera::getRay(float u, float v) const {
    return Ray(origin_, llc_ + u*vx_ + v*vy_);
}
