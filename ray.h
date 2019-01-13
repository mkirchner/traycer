/*
 * ray.h
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#ifndef RAY_H
#define RAY_H

#include "vec3.h"



class Ray {
  public:
    Ray() {}
    Ray(const Vec3& origin, const Vec3& direction) : o_(origin), d_(direction) {}
    inline const Vec3& origin() const { return o_; }
    inline const Vec3& direction() const { return d_; }
    Vec3 operator()(const Float t) const;

  private:
    Vec3 o_, d_;
};

#endif /* !RAY_H */
