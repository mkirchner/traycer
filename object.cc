/*
 * object.c
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#include "object.h"

Object::~Object() {
}

Material::Ptr Object::getMaterial() const {
    return material_;
}
