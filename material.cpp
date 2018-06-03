#include "material.h"
#include "kit.h"

void Material::Read(str var, ssm& finv)
{
    if(var == "color")  finv >> color;
    if(var == "absorb") finv >> absorb;
    if(var == "refl")   finv >> crefl;
    if(var == "refc")   finv >> crefc;
    if(var == "diff")   finv >> cdiff;
    if(var == "spec")   finv >> cspec;
    if(var == "n")      finv >> N;
    if(var == "texture")
    {
        str file;
        finv >> file;
        texture = new Texture();
        texture->Load(file);
    }
}

using namespace std;

double Material::BRDF(const Ray& I, const Ray& N, const Ray& V)
{
    double coef = 0;
    Vector3 nI = -I.Unit();
    Vector3 nV = V.Unit();
    Vector3 nh = (nV + nI).Unit();
    double d1 = nI.Dot(N);
    double d2 = nV.Dot(nh);
    if (cdiff > EPS && d1 > EPS)
		coef += cdiff * d1;
	if (cspec > EPS && d2 > EPS)
		coef += cspec * PowN(d2, 50);
    return coef;
}
