#include "texture.h"
#include <cmath>

using namespace std;
Color Texture::GetColor(double u, double v)
{
    double U = u * m;
    double V = v * n;
    int U1 = int(floor(U - 0.5 - EPS)), U2 = U1 + 1;
    int V1 = int(floor(V - 0.5 - EPS)), V2 = V1 + 1;
    double cU = 0.5 - U + U2;
    double cV = 0.5 - V + V2;
    if(cU < EPS)cU = 0.0;
    if(cV < EPS)cV = 0.0;
    if(U1 < 0)  U1 = m - 1;
    if(U2 == m) U2 = 0;
    if(V1 < 0)  V1 = m - 1;
    if(V2 == n) V2 = 0;
    Color ret;
    ret = ret + texture->GetColor(U1,V1) * cU * cV;
	ret = ret + texture->GetColor(U1,V2) * cU * (1 - cV);
	ret = ret + texture->GetColor(U2,V1) * (1 - cU) * cV;
	ret = ret + texture->GetColor(U2,V2) * (1 - cU) * (1 - cV);
	return ret;
}

void Texture::Load(str file)
{
    texture = new Bmp();
    texture->Input(file);
    m = texture->m;
    n = texture->n;
}
