#ifndef LIGHT_H
#define LIGHT_H
#include "typdef.h"
#include "vector3.h"
#include "intsct.h"
#include "camera.h"
#include "color.h"
#include <vector>

extern const double SampleArea;

class Light
{
    protected:
        Light* next;
        Color color;
        int max_photon;
    public:
        std::vector<Vector3> v;
        virtual LightIntsct* Intersect(const Ray& r, const Ray& rt) = 0;
        virtual void Read(str var, ssm& finv);
        virtual void Init() {}
        Light()     {next = NULL;}
        Light* GetNext()   {return next;}
        void SetNext(Light* _next)  {next = _next;}
        Color GetColor()    {return color;}
        virtual void Show()
		{
			std::cout << "Show light info:" << std::endl;
			std::cout << "Next = " << next << std::endl;
            std::cout << "max_photon = " << max_photon << std::endl;
		}
};

class PointLight: public Light
{
    public:
        virtual LightIntsct* Intersect(const Ray& r, const Ray& rt);
        void Read(str var, ssm& finv);
        void Init();
    private:
        Vector3 O;
};

class LineLight: public Light
{
    public:
        virtual LightIntsct* Intersect(const Ray& r, const Ray& rt);
};

class AreaLight: public Light
{
    public:
        virtual LightIntsct* Intersect(const Ray& r, const Ray& rt);
        void Read(str var, ssm& finv);
        void Init();
    private:
        Vector3 N, O, Dx, Dy;
        double R;
};

#endif
