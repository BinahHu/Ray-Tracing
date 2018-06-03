#ifndef CAMERA_H
#define CAMERA_H

#include "typdef.h"
#include "vector3.h"
#include "bmp.h"
#include "raytracer.h"

class Scene;
class Camera
{
	public:
		Camera(Scene* _scene);
		void Read(str var, ssm& finv);
		void Init();
		void Show()
		{
			std::cout << "Show camera info:" << std::endl;
			O.Show();
			N.Show();
			U.Show();
			std::cout << "w = " << w << " h = " << h << std::endl;
			std::cout << "psyh = " << psyh << " psyw = " << psyw << " f = " << f << std::endl;
		}

		Vector3 Emit(double i, double j);
		Bmp* Shot();
	private:
		Scene* scene;
		Raytracer* raytracer;
		Vector3 O, N, U, S, R, Dh, Dw;
		int w, h;
		double psyh, psyw, f;

};


#endif
