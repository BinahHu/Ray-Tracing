#ifndef KIT_H
#define KIT_H
#include "scene.h"
#include "bmp.h"
#include "typdef.h"

void LoadFile(Scene* scene, str file);
Vector3 ReflDir(const Ray& I, const Ray& N);
Vector3 RefrDir(const Ray& I, const Ray& N, double n, bool& valid);
Vector3 DiffDir(const Ray& N, const Ray& X, const Ray& Y, int dir);
double PowN(double s, int N);
void GenXY(const Ray& N, Ray& X, Ray& Y);
#endif
