/*
 * vec3.cc
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#include "vec3.h"

inline std::istream& operator>>(std::istream& is, Vec3& v) {
    is >> v[0] >> v[1] >> v[2];
    return is;
}

inline std::ostream& operator<<(std::ostream& os, const Vec3& v) {
    os << v[0] << " " << v[1] << " " << v[2];
    return os;
}

Vec3& Vec3::operator=(const Vec3& rhs) {
    if (this != &rhs) {
        e_[0] = rhs[0]; e_[1] = rhs[1]; e_[2] = rhs[2];
    }
    return *this;
}


Vec3 operator*(const Float f, const Vec3& v) {
    return Vec3(f*v[0], f*v[1], f*v[2]);
}

Vec3 operator*(const Vec3& v, const Float f) {
    return Vec3(f*v[0], f*v[1], f*v[2]);
}

Vec3 operator*(const Vec3& v, const Vec3& u) {
    // element-wise multiplication
    return Vec3(u[0]*v[0], u[1]*v[1], u[2]*v[2]);
}

Vec3 operator/(const Vec3& v, const Float f) {
    return Vec3(v[0]/f, v[1]/f, v[2]/f);
}



// scalar Vec3::operations
Vec3& Vec3::operator*=(const Float f) {
    e_[0] *= f;
    e_[1] *= f;
    e_[2] *= f;
    return *this;
}


Vec3& Vec3::operator/=(const Float f) {
    e_[0] /= f;
    e_[1] /= f;
    e_[2] /= f;
    return *this;
}


// element-wise Vec3::operations
Vec3 Vec3::operator+(const Vec3& v) const {
    return Vec3(e_[0] + v[0], e_[1] + v[1], e_[2] + v[2]);
}


Vec3 Vec3::operator-(const Vec3& v) const {
    return Vec3(e_[0] - v[0], e_[1] - v[1], e_[2] - v[2]);
}


Vec3& Vec3::operator+=(const Vec3& v) {
    e_[0] += v[0];
    e_[1] += v[1];
    e_[2] += v[2];
    return *this;
}


Vec3& Vec3::operator-=(const Vec3& v) {
    e_[0] -= v[0];
    e_[1] -= v[1];
    e_[2] -= v[2];
    return *this;
}


Vec3& Vec3::operator*=(const Vec3& v) {
    e_[0] *= v[0];
    e_[1] *= v[1];
    e_[2] *= v[2];
    return *this;
}


Vec3& Vec3::operator/=(const Vec3& v) {
    e_[0] /= v[0];
    e_[1] /= v[1];
    e_[2] /= v[2];
    return *this;
}


Float Vec3::norm() const {
    return sqrt(e_[0]*e_[0] + e_[1]*e_[1] + e_[2]*e_[2]);
}

Float Vec3::squared_norm() const {
    return e_[0]*e_[0] + e_[1]*e_[1] + e_[2]*e_[2];
}

void Vec3::normalize() {
    *this /= this->norm();
}

Vec3 Vec3::normalized() const {
    return *this / this->norm();
}

Float Vec3::dot(const Vec3& l, const Vec3& r) {
    return l.e_[0]*r.e_[0] + l.e_[1]*r.e_[1] + l.e_[2]*r.e_[2];
}

Vec3 Vec3::cross(const Vec3& l, const Vec3& r) {
    return Vec3(l.e_[1]*r.e_[2] - l.e_[2]*r.e_[1],
                -l.e_[0]*r.e_[2] - l.e_[2]*r.e_[0],
                l.e_[0]*r.e_[1] - l.e_[1]*r.e_[0]);
}

