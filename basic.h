#ifndef BASIC_H
#define BASIC_H

#include "object.h"


class Triangle: public Object
{
    public:
        virtual Intsct* Intersect(const Ray& rO, const Ray& rt);
};

class Rectangle: public Object
{
    public:
        Rectangle();
        virtual void Read(str var, ssm& finv);
        virtual Intsct* Intersect(const Ray& rO, const Ray& rt);
        virtual Color GetColor(const Vector3& P);
        virtual void Init();
        virtual void Show()
        {
            std::cout << "Show rect info:" << std::endl;
            N.Show();
            O.Show();
            Dx.Show();
            Dy.Show();
            std::cout << "R = " << R << std::endl;
            Object::Show();
        }
    private:
        Vector3 N, O, Dx, Dy;
        double R;
};

class Sphere: public Object
{
    public:
        virtual void Read(str var, ssm& finv);
        virtual Intsct* Intersect(const Ray& rO, const Ray& rt);
        virtual Color GetColor(const Vector3& P);
        virtual void Show()
        {
            std::cout << "Show sphere info:" << std::endl;
            O.Show();
            std::cout << "R = " << R << std::endl;
        }
    private:
        Vector3 O;
        double R;
};


#endif
