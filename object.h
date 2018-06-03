#ifndef OBJECT_H
#define OBJECT_H
#include "vector3.h"
#include "intsct.h"
#include "material.h"
#include "typdef.h"
#include "color.h"

class Object
{
	protected:
		Object* next;
		Material* mat;
	public:
		virtual Intsct* Intersect(const Ray& rO, const Ray& rt) = 0;
		virtual void Read(str var, ssm& finv);
		virtual void Init()	{}
		Object()	{next = NULL; mat = new Material();}
		Object* GetNext()	{return next;}
		void SetNext(Object* _next)	{next = _next;}
		void SetMaterial(Material* _mat)	{mat = _mat;}
		Material* GetMaterial()	{return mat;}
		virtual Color GetColor()
		{
			return mat->color;
		}
		virtual Color GetColor(const Vector3& P)
		{
			return mat->color;
		}
		virtual void Show()
		{
			std::cout << "Show obj info:" << std::endl;
			std::cout << "Next = " << next << std::endl;
			std::cout << "Show material info:" << std::endl;
			mat->Show();
		}
};

#endif
