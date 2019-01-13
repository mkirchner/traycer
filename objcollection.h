/*
 * objcollection.h
 * Copyright (C) 2019 marc <marc@k2.local>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef OBJCOLLECTION_H
#define OBJCOLLECTION_H

#include <vector>
#include <memory>

#include "object.h"
#include "ray.h"

class ObjCollection {
    public:
        bool getHit(const Ray& r, float tMin, float tMax, Hit& hit) const;
        void addObject(std::shared_ptr<Object> obj) {objs_.push_back(obj);}

    private:
        std::vector<std::shared_ptr<Object> > objs_;
};

#endif /* !OBJCOLLECTION_H */
