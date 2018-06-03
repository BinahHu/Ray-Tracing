#ifndef MATERIAL_H
#define MATERIAL_H

#include "typdef.h"
#include "color.h"
#include "vector3.h"
#include "texture.h"

class Material
{
    public:
        Material()  {texture = NULL;}
        void Read(str var, ssm& finv);

        Color color, absorb;
        Texture* texture;
        double crefl, crefc, cdiff, cspec, N;
        double BRDF(const Ray& I, const Ray& N, const Ray& V);
        void Show()
        {
            std::cout << "Show Material info:" << std::endl;
            std::cout << "crefl = " << crefl << std::endl;
            std::cout << "crefc = " << crefc << std::endl;
            std::cout << "cdiff = " << cdiff << std::endl;
            std::cout << "cspec = " << cspec << std::endl;
            std::cout << "N = " << N << std::endl;
            if(texture) std::cout << "Has textture" << std::endl;
            else    std::cout << "No texture" << std::endl;
            color.Show();
            absorb.Show();
        }
};


#endif
