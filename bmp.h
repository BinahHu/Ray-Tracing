#ifndef BMP_H
#define BMP_H
#include "typdef.h"
#include "color.h"

struct Imgdata
{
    byte r,g,b;
};

class Bmp
{
    public:
        int m, n;
        void Output(str file);
        void Input(str file);
        void SetColor(int i, int j, const Color&c);
        Color GetColor(int i, int j);
        Bmp(int _m = 0, int _n = 0);
        ~Bmp();
    private:
        Imgdata** data;
};

#endif
