traycer
=======

My own ray tracing implementation, based on Peter Shirley's [Ray Tracing in One
Weekend][shirley] book. No C++11 features, just clean code.

Build & run
-----------

        $ make && ./traycer > test.ppm && open test.ppm

Examples
--------

### Metal

![Metal example](https://github.com/mkirchner/traycer/blob/master/examples/metal.png)

### Dielectric (glass)

![Dielectric example](https://github.com/mkirchner/traycer/blob/master/examples/dielectric.png)

[shirley]: https://github.com/petershirley/raytracinginoneweekend
