/*
 * main.cc
 * Copyright (C) 2019 Marc Kirchner
 *
 * Distributed under terms of the MIT license.
 */

#include <cfloat>
#include <cstdlib>
#include <iostream>
#include <memory>

#include "camera.h"
#include "objcollection.h"
#include "ray.h"
#include "sphere.h"
#include "vec3.h"

const Vec3 WHITE = Vec3(1.0, 1.0, 1.0);
const Vec3 BLUE = Vec3(0.2, 0.5, 1.0);

Vec3 sample_from_unit_sphere() {
    Vec3 p;
    do {
        p = 2.0 * Vec3(drand48(), drand48(), drand48()) - Vec3(1.0, 1.0, 1.0);
    } while (p.squared_norm() >= 1.0);
    return p;
}

Vec3 color(const Ray& r, const ObjCollection& world, int n) {
    Hit hit;
    if (world.getHit(r, 0.001, FLT_MAX, hit)) {
        Vec3 reflection = hit.p + hit.n + sample_from_unit_sphere();
        if (n > 10) {
          return 0.5*Vec3(hit.n.x()+1, hit.n.y()+1, hit.n.z()+1);
        } else {
            return 0.5*color(Ray(hit.p, reflection-hit.p), world, n+1);
        }
    } else {
        float t = 0.5 * (r.direction().normalized().y() + 1.0);
        Vec3 lerp = (1.0-t) * WHITE + t * BLUE;
        return lerp;
    }
}

void writeImage() {
    int nx = 200;
    int ny = 100;
    int ns = 50;
    // camera position
    Vec3 lower_left(-2.0, -1.0, -1.0);
    Vec3 origin(0.0, 0.0, 0.0);
    Vec3 vx(4.0, 0.0, 0.0);
    Vec3 vy(0.0, 2.0, 0.0);
    Camera cam(lower_left, vx, vy, origin);
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
            Vec3 px(0.0, 0.0, 0.0);
            for (int s = 0; s < ns; ++s) {
                float u = float(x + drand48())/float(nx);
                float v = float(y + drand48())/float(ny);
                Ray r = cam.getRay(u, v); 
                px += color(r, world, 0);
            }
            px = px / ns;
            // approximate gamma correction
            px = Vec3(sqrt(px[0]), sqrt(px[1]), sqrt(px[2]));
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


