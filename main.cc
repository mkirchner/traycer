/*
 * main.cc
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <memory>
#include <cfloat>
#include "objcollection.h"
#include "ray.h"
#include "sphere.h"
#include "vec3.h"

const Vec3 WHITE = Vec3(1.0, 1.0, 1.0);
const Vec3 BLUE = Vec3(0.2, 0.5, 1.0);

Vec3 color(const Ray& r, const ObjCollection& world) {
    Hit hit;
    if (world.getHit(r, 0.0, FLT_MAX, hit)) {
        // std::cout << "Hit" << std::endl;
        return 0.5*Vec3(hit.n.x()+1, hit.n.y()+1, hit.n.z()+1);
    } else {
        float t = 0.5 * (r.direction().normalized().y() + 1.0);
        Vec3 lerp = (1.0-t) * WHITE + t * BLUE;
        return lerp;
    }
}

void writeImage() {
    int nx = 200;
    int ny = 100;
    // camera position
    Vec3 lower_left(-2.0, -1.0, -1.0);
    Vec3 origin(0.0, 0.0, 0.0);
    Vec3 dx(4.0, 0.0, 0.0);
    Vec3 dy(0.0, 2.0, 0.0);
    ObjCollection world;
    // center sphere
    Vec3 center = Vec3(0.0, 0.0, -1.0);
    float radius = 0.5;
    world.addObject(std::make_shared<Sphere>(center, radius));
    // ground sphere
    center = Vec3(0.0, -100.5, -1.0);
    radius = 100.0;
    world.addObject(std::make_shared<Sphere>(center, radius));
    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
    for (int y = ny-1; y >=0; --y) {
        for (int x = 0; x < nx; ++x) {
            float u = float(x)/float(nx);
            float v = float(y)/float(ny);
            Ray r(origin, lower_left + u*dx + v*dy);
            Vec3 px = color(r, world);
            px *= 255.99;
            std::cout << int(px[0]) << " " << int(px[1]) << " "
                      << int(px[2]) << "\n";
        }
    }
}

int main(int argc, char* argv[]) {
    writeImage();
    return 0;
}


