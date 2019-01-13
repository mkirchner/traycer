/*
 * objcollection.cc
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#include "objcollection.h"

bool ObjCollection::getHit(const Ray& r, float tMin, float tMax, Hit& hit) const {
    float t;
    float tBest = tMax;
    bool anyHits = false;
    size_t iBest = 0;
    for (size_t i = 0; i < objs_.size(); ++i) {
        if (objs_[i]->testHit(r, tMin, tBest, &t)) {
            tBest = t;
            iBest = i;
            anyHits = true;
        }
    }
    if (anyHits) {
        hit = objs_[iBest]->getHit(r, tBest);
    }
    return anyHits;
}


