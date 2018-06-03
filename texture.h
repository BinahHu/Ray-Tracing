#ifndef TEXTURE_H
#define TEXTURE_H
#include "bmp.h"
#include "color.h"
#include "typdef.h"

class Texture
{
    public:
        Bmp* texture;
        int m, n;
        Texture()   {texture = NULL;}
        ~Texture()  {if(texture)delete texture;}
        bool IsNull()   {return (texture == NULL);}
        Color GetColor(double u, double v);
        void Load(str file);
};


#endif
