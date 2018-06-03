#include "camera.h"
#include <omp.h>
Camera::Camera(Scene* _scene)
{
	scene = _scene;
	raytracer = new Raytracer(scene);
}

void Camera::Read(str var, ssm& finv)
{
	if(var == "O") 		finv >> O;
	if(var == "sight")	finv >> N;
	if(var == "up")		finv >> U;
	if(var == "f")		finv >> f;
	if(var == "w")		finv >> w;
	if(var == "h")		finv >> h;
	if(var == "psyw")	finv >> psyw;
	if(var == "psyh")	finv >> psyh;
}

void Camera::Init()
{
	//To be continue..
	R = N.Cross(U);
	R = R.Unit();
	Dh = R * psyh / double(h);
	Dw = -(U * psyw / double(w));
	S = N * f - Dh * (double(h-1)/2.0) - Dw * (double(w-1)/2.0) ;
}

Vector3 Camera::Emit(double i, double j)
{
	return S + Dw * i + Dh * j;
}

Bmp* Camera::Shot()
{
	Bmp* ans = new Bmp(w, h);
#pragma omp parallel for
	for(int i = 0; i < w; i++)
		for(int j = 0; j < h; j++)
		{
			Ray rt = Emit(i,j);
			ans->SetColor(i,j, raytracer->Raytrace(O, rt, 1, false));
		}
	return ans;
}
