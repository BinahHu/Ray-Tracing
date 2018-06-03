#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "typdef.h"
#include "color.h"
#include "intsct.h"

extern const double SPEC_POWER;
extern const int MAX_DREFL_DEP;
extern const int MAX_RAYTRACING_DEP;


class Scene;
class Raytracer
{
    public:
        Raytracer(Scene* _scene);
        Color Diffusion(Intsct* intsct);
        Color Reflection(Intsct* intsct, const Ray& V, int dep, bool refracted);
        Color Refraction(Intsct* intsct, const Ray& V, int dep, bool refracted);
        Color Raytrace(const Ray& rO, const Ray& rt, int dep, bool refracted);
    private:
        Scene * scene;
};


#endif
