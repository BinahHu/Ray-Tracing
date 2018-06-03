#include "light.h"
#include <cmath>
#include <cstdlib>

inline double ran()
{
	return double(rand() % RAND_MAX) / RAND_MAX;
}

const double SampleArea = 10000.0;

void Light::Read(str var, ssm& finv)
{
    if(var == "max_photon") finv >> max_photon;
    if(var == "color")      finv >> color;
}

LightIntsct* PointLight::Intersect(const Ray& rO, const Ray& rt)    {return NULL;}

void PointLight::Read(str var, ssm& finv)
{
    if(var == "O")  finv >> O;
    else
        Light::Read(var, finv);
}
void PointLight::Init()
{
    v.push_back(O);
}


LightIntsct* LineLight::Intersect(const Ray& rO, const Ray& rt)     {return NULL;}

LightIntsct* AreaLight::Intersect(const Ray& rO, const Ray& rt)
{
    LightIntsct* lintsct = NULL;
	Vector3 Rt = rt.Unit();

    double d = N.Dot(Rt);
	if (fabs(d) < EPS) return lintsct;

    double l = (N * R - rO).Dot(N) / d;
	if (l < EPS) return lintsct;

    Vector3 Pos = rO + Rt * l;
	double u = (Pos - O).Dot(Dx) / Dx.Norm2();
	double v = (Pos - O).Dot(Dy) / Dy.Norm2();
    if(!(0 <= u && u <= 1 && 0 <= v && v <= 1)) return lintsct;

    lintsct = new LightIntsct();

    lintsct->dep = l;
	lintsct->P = Pos;
	lintsct->N = (d < 0) ? N : -N;
    lintsct->I = Rt;
    lintsct->SetLight(this);
	return lintsct;
}

void AreaLight::Init()
{
	int maxsamp  = int(sqrt((Dx.GetMax() * Dy.GetMax()) / SampleArea));
	for(int i = 0; i < maxsamp; i++)
        for(int j = 0; j < maxsamp; j++)
            v.push_back(O + Dx * ((double(i) + ran()) / double(maxsamp)) + Dy * ((double(j) + ran()) / double(maxsamp)));
    if(maxsamp <= 0)
        v.push_back(O + Dx / 2 + Dy / 2);
}

void AreaLight::Read(str var, ssm& finv)
{
    if      ( var == "N" ) finv >> N;
	else if ( var == "R" ) finv >> R;
    else if ( var == "O" ) finv >> O;
	else if ( var == "Dx" ) finv >> Dx;
	else if ( var == "Dy" ) finv >> Dy;
    else
        Light::Read(var, finv);
}
