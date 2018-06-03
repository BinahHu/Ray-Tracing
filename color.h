#ifndef COLOR_H
#define COLOR_H
#include "typdef.h"

class Color
{
	public:
		float r, g, b;

		Color(float _r = 0.0, float _g = 0.0, float _b = 0.0) : r(_r), g(_g), b(_b) {}
		~Color() {}

		friend Color operator+(const Color&, const Color&);
		friend Color operator-(const Color&, const Color&);
		friend Color operator*(const Color&, const Color&);
		friend Color operator/(const Color&, const Color&);
		friend Color operator*(const Color&, const float&);
		friend Color operator/(const Color&, const float&);
		friend Color& operator+=(Color&, const Color&);
		friend Color& operator-=(Color&, const Color&);
		friend Color& operator*=(Color&, const float&);
		friend Color& operator/=(Color&, const float&);

		float GetMax();
		Color Regular();
		Color Exp();
		bool IsBlack();

		friend ssm& operator>>(ssm&, Color&);
		void Show() const
		{
			std::cout << "Color = [" << r << ", " << g << ", " << b << "]" << std::endl;
		}
};



#endif
