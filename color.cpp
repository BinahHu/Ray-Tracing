#include "color.h"
#include <cmath>

Color operator+(const Color& c1, const Color& c2)
{
	return Color(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b);
}

Color operator-(const Color& c1, const Color& c2)
{
	return Color(c1.r - c2.r, c1.g - c2.g, c1.b - c2.b);
}

Color operator*(const Color& c1, const Color& c2)
{
	return Color(c1.r * c2.r, c1.g * c2.g, c1.b * c2.b);
}

Color operator/(const Color& c1, const Color& c2)
{
	return Color(c1.r / c2.r, c1.g / c2.g, c1.b / c2.b);
}

Color operator*(const Color& c, const float& k)
{
	return Color(c.r * k, c.g * k, c.b * k);
}

Color operator/(const Color& c, const float& k)
{
	return Color(c.r / k, c.g / k, c.b / k);
}

Color& operator+=(Color& c1, const Color& c2)
{
	c1 = c1 + c2;
	return c1;
}

Color& operator-=(Color& c1, const Color& c2)
{
	c1 = c1 - c2;
	return c1;
}

Color& operator*=(Color& c, const float& k)
{
	c = c * k;
	return c;
}

Color& operator/=(Color& c, const float& k)
{
	c = c / k;
	return c;
}

bool Color::IsBlack()
{
	if(r > EPS)return false;
	if(g > EPS)return false;
	if(b > EPS)return false;
	return true;
}

float Color::GetMax()
{
	if(r > g)
		return (r > b) ? r : b;
	return (g > b) ? g : b;
}

Color Color::Regular()
{
	return Color(std::min(r, 1.0f), std::min(g, 1.0f), std::min(b, 1.0f));
}

Color Color::Exp()
{
	return Color(std::exp(r),std::exp(g),std::exp(b));
}

ssm& operator>>(ssm& in, Color& c)
{
		in >> c.r >> c.g >> c.b;
		return in;
}
