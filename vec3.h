/*
 * vec3.h
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

#define Float float

class Vec3 {
  public:
    Vec3() {}
    Vec3(Float e0, Float e1, Float e2) { e_[0] = e0; e_[1] = e1; e_[2] = e2; }
    Vec3(const Vec3& v) { e_[0] = v[0]; e_[1] = v[1]; e_[2] = v[2]; }
    Vec3& operator=(const Vec3& rhs);

    inline Float x() const { return e_[0]; }
    inline Float y() const { return e_[1]; }
    inline Float z() const { return e_[2]; }
    inline Float r() const { return e_[0]; }
    inline Float g() const { return e_[1]; }
    inline Float b() const { return e_[2]; }

    inline const Vec3& operator+() const { return *this; }
    inline Vec3 operator-() const { return Vec3(-e_[0], -e_[1], -e_[2]); }
    inline Float operator[](const size_t i) const { return e_[i]; }
    inline Float& operator[](const size_t i) { return e_[i]; }

    // scalar operations
    Vec3& operator*=(const Float f);
    Vec3& operator/=(const Float f);
    // element-wise operations
    Vec3 operator+(const Vec3& v) const;
    Vec3 operator-(const Vec3& v) const;
    Vec3& operator+=(const Vec3& v);
    Vec3& operator-=(const Vec3& v);
    Vec3& operator*=(const Vec3& v);
    Vec3& operator/=(const Vec3& v);

    Float norm() const;
    Float squared_norm() const;
    void normalize();
    Vec3 normalized() const;

    static Float dot(const Vec3& lhs, const Vec3& rhs);
    static Vec3 cross(const Vec3& lhs, const Vec3& rhs);

  private:
    float e_[3];
};

Vec3 operator*(Float f, const Vec3& v);
Vec3 operator*(const Vec3& v, Float f);
Vec3 operator*(const Vec3& v, const Vec3& u);
Vec3 operator/(const Vec3& v, Float f);


#endif /* !VEC3_H */
