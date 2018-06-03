#include "kit.h"
#include "basic.h"
#include "bezier.h"
#include "camera.h"
#include "color.h"
#include "light.h"
#include <fstream>
#include <cmath>
#include <cstdlib>

void LoadFile(Scene* scene, str file)
{
	std::ifstream fin(file);
	str obj;
	while(fin >> obj)
	{
		str data, type;
		Object* new_obj = NULL;
		Light* new_light = NULL;

		if(obj == "obj")
		{
			fin >> type;
			if(type == "tir")	new_obj = new Triangle();
			if(type == "rect")	new_obj = new Rectangle();
			if(type == "sphe")	new_obj = new Sphere();
			if(type == "bezier")new_obj = new Bezier();
			if(new_obj)	scene->AddObj(new_obj);
		}
		else if(obj == "light")
		{
			fin >> type;
			if(type == "point")	new_light = new PointLight();
			if(type == "line")	new_light = new LineLight();
			if(type == "area")	new_light = new AreaLight();
			if(new_light)	scene->AddLight(new_light);
		}
		else if(obj == "camera" || obj == "background");
		else continue;

		fin.ignore(2333, '\n');
		while(getline(fin, data, '\n'))
		{
			ssm finv(data);
			str var;
			finv >> var;
			if(var == "end")
			{
				if(obj == "obj")		new_obj->Init();
				if(obj == "light")		new_light->Init();
				if(obj == "camera")		scene->CameraInit();
				break;
			}
			if(obj == "camera")					scene->CameraRead(var, finv);
			if(obj == "background")				scene->SetBackground(var, finv);
			if(obj == "obj" && new_obj)			new_obj->Read(var, finv);
			if(obj == "light" && new_light)		new_light->Read(var, finv);
		}
	}
}

Vector3 ReflDir(const Ray& I, const Ray& N)
{
	double l = fabs(N.Dot(I)) / N.Norm();
	return I + N.Unit() * (2 * l);
}

Vector3 RefrDir(const Ray& I, const Ray& N, double n, bool& valid)
{
	Vector3 rN = -(N.Unit());
	Vector3 uI = I.Unit();
	Vector3 p = uI - rN * uI.Dot(rN);
	double l = p.Norm();
	if(n < l + EPS)
	{
		valid = false;
		return p;
	}
	l = sqrt(n * n - l * l);
	valid = true;
	return rN * l  + p;
}

inline double ran()
{
	return double(rand() % RAND_MAX) / RAND_MAX;
}

void GenXY(const Ray& N, Ray& X , Ray& Y)
{
	if(fabs(N.x) > EPS)
	{
		X.z = 0.0;
		X.y = 1.0;
		X.x = - N.y / N. x;
	}
	else if(fabs(N.y) > EPS)
	{
		X.z = 0.0;
		X.x = 1.0;
		X.y = -N.x / N.y;
	}
	else
	{
		X.y = 0.0;
		X.x = 1.0;
		X.z = -N.x / N.z;
	}
	Y = N.Cross(X);
}

Vector3 DiffDir(const Ray& N, const Ray& X, const Ray& Y, int dir)
{
	srand((unsigned int)time(NULL));
	int dx = (dir % 2) * 2 - 1;
	int dy = (dir / 2) * 2 - 1;
	return N * ran() + X * ran() * dx + Y * ran() * dy;
}

double PowN(double s, int N)
{
    double ans = 1.0;
    for(int i = 0; i < N; i++)
        ans *= s;
    return ans;
}
