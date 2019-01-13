/*
 * objcollection.h
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#ifndef OBJCOLLECTION_H
#define OBJCOLLECTION_H

#include <vector>
#include <memory>
#include <utility>  // for std::pair

#include "hit.h"
#include "object.h"
#include "ray.h"

class ObjCollection {
    public:
        typedef std::shared_ptr<Object> ObjectPtr;
        typedef std::pair<size_t, Hit> IndexedHit;
        bool getHit(const Ray& r, float tMin, float tMax, IndexedHit& hit) const;
        void addObject(ObjectPtr obj) {objs_.push_back(obj);}
        ObjectPtr getObject(const size_t i) const {return objs_[i];}

    private:
        std::vector<ObjectPtr> objs_;
};

#endif /* !OBJCOLLECTION_H */
