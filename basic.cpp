#include "basic.h"
#include <cmath>


Intsct* Triangle::Intersect(const Ray& rO, const Ray& rt)
{
    //To be continue...
    return NULL;
}



Rectangle::Rectangle() : Object()
{

}
void Rectangle::Read(str var, ssm& finv)
{
    if      ( var == "N" ) finv >> N;
	else if ( var == "R" ) finv >> R;
    else if ( var == "O" ) finv >> O;
	else if ( var == "Dx" ) finv >> Dx;
	else if ( var == "Dy" ) finv >> Dy;
    else
        Object::Read(var, finv);
}

void Rectangle::Init()
{
    N = N.Unit();
}

Intsct* Rectangle::Intersect(const Ray& rO, const Ray& rt)
{
    Intsct* intsct = NULL;
	Vector3 Rt = rt.Unit();

    double d = N.Dot(Rt);
	if (fabs(d) < EPS) return intsct;

    double l = (N * R - rO).Dot(N) / d;
	if (l < EPS) return intsct;

    Vector3 Pos = rO + Rt * l;
	double u = (Pos - O).Dot(Dx) / Dx.Norm2();
	double v = (Pos - O).Dot(Dy) / Dy.Norm2();
    if(!(0 <= u && u <= 1 && 0 <= v && v <= 1)) return intsct;

    intsct = new Intsct();

    intsct->dep = l;
	intsct->P = Pos;
	intsct->N = (d < 0) ? N : -N;
    intsct->I = Rt;
    intsct->SetObj(this);
	return intsct;
}

Color Rectangle::GetColor(const Vector3& P)
{
    if(!mat->texture)return mat->color;
    double u = (P - O).Dot(Dx) / Dx.Norm2();
    double v = (P - O).Dot(Dy) / Dy.Norm2();
    return mat->texture->GetColor(u,v);
}


void Sphere::Read(str var, ssm& finv)
{
    if     (var == "O")  finv >> O;
    else if(var == "R")  finv >> R;
    else
        Object::Read(var, finv);
}

Intsct* Sphere::Intersect(const Ray& rO, const Ray& rt)
{
    Intsct* intsct = NULL;
    Vector3 l = O - rO;
    Vector3 Rt = rt.Unit();
    double tp = l.Dot(Rt);
    double l2 = l.Norm2();
    double R2 = R * R;

    bool outflag = (l2 - R2 > EPS);
    if((outflag || fabs(l2 - R2) < EPS) && tp < EPS)return intsct;
    double d2 = l2 - tp * tp;
    if(d2 - R2 > EPS)return intsct;
    double t = sqrt(R2 - d2);
    intsct = new Intsct();
    intsct->dep = outflag ? tp - t : tp + t;
    intsct->P = rO + Rt * intsct->dep;
    intsct->N = (intsct->P - O).Unit();
    if(!outflag)    intsct->N = - intsct->N;
    intsct->I = Rt;
    intsct->SetObj(this);
    return intsct;
}

Color Sphere::GetColor(const Vector3& P)
{
    if(!mat->texture)   return mat->color;

    Vector3 dir = (P - O).Unit();
    double u = acos(dir.Dot(Vector3(0,0,1))) / PI;
    double v = acos(dir.Dot(Vector3(1,0,0))) / (2 * PI);
    if(dir.y < -EPS)v = 1 - v;
    return mat->texture->GetColor(u,v);
}
