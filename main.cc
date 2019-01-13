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
#include "hit.h"
#include "lambertian.h"
#include "material.h"
#include "metal.h"
#include "objcollection.h"
#include "ray.h"
#include "sphere.h"
#include "utils.h"
#include "vec3.h"

const Vec3 WHITE = Vec3(1.0, 1.0, 1.0);
const Vec3 BLUE = Vec3(0.2, 0.5, 1.0);


Vec3 color(const Ray& r, const ObjCollection& world, int n) {
    ObjCollection::IndexedHit indexedHit;
    if (world.getHit(r, 0.001, FLT_MAX, indexedHit)) {
	size_t index = indexedHit.first;
	Hit hit = indexedHit.second;
	Ray scattered;
	Vec3 attenuation;
        if (n < 25 && world.getObject(index)->getMaterial()->scatter(r, hit, attenuation, scattered)) {
			return attenuation * color(scattered, world, n+1);
        } else {
          return Vec3(0.0, 0.0, 0.0);
        }
    } else {
        float t = 0.5 * (r.direction().normalized().y() + 1.0);
        Vec3 lerp = (1.0-t) * WHITE + t * BLUE;
        return lerp;
    }
}

void writeImage() {
    int nx = 400;
    int ny = 200;
    int ns = 100;
    // camera position
    Vec3 lower_left(-2.0, -1.0, -1.0);
    Vec3 origin(0.0, 0.0, 0.0);
    Vec3 vx(4.0, 0.0, 0.0);
    Vec3 vy(0.0, 2.0, 0.0);
    Camera cam(lower_left, vx, vy, origin);
    ObjCollection world;
    // material
    Vec3 albedo = Vec3(0.04, 0.4, 0.14);
    Material::Ptr lambertianRed = std::make_shared<Lambertian>(albedo);
    albedo = Vec3(0.99, 0.87, 0.15);
    Material::Ptr lambertianBlue = std::make_shared<Lambertian>(albedo);
    albedo = Vec3(0.8, 0.8, 0.8);
    Material::Ptr metal = std::make_shared<Metal>(albedo);
    // left sphere
    Vec3 center = Vec3(-0.55, 0.0, -1.0);
    float radius = 0.5;
    world.addObject(std::make_shared<Sphere>(metal, center, radius));
    // right sphere
    center = Vec3(0.55, 0.0, -1.0);
    radius = 0.5;
    world.addObject(std::make_shared<Sphere>(lambertianBlue, center, radius));
    // ground sphere
    center = Vec3(0.0, -100.5, -1.0);
    radius = 100.0;
    world.addObject(std::make_shared<Sphere>(lambertianRed, center, radius));
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


