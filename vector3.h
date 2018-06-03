#ifndef VECTOR3_H
#define VECTOR3_H
#include <cstddef>
#include "typdef.h"


class Vector3
{
	public:

		double x, y, z;
		Vector3(double _x = 0.0, double _y = 0.0, double _z = 0.0) : x(_x), y(_y), z(_z) {}
		~Vector3() {}

		friend Vector3 operator+(const Vector3& , const Vector3& );
		friend Vector3 operator-(const Vector3& , const Vector3& );
		friend Vector3 operator*(const Vector3& , const double& );
		friend Vector3 operator/(const Vector3& , const double& );
		friend Vector3& operator+=(Vector3&, const Vector3&);
		friend Vector3& operator-=(Vector3&, const Vector3&);
		friend Vector3& operator*=(Vector3&, const double&);
		friend Vector3& operator/=(Vector3&, const double&);
		friend Vector3 operator-(const Vector3&);

		friend ssm& operator>>(ssm&, Vector3&);
		double Dot(const Vector3&) const;
		Vector3 Cross(const Vector3&) const;
		double Norm() const;
		double Norm2() const;
		double Dist(const Vector3&) const;
		double Dist2(const Vector3&) const;
		double GetMax()	const;

		Vector3 Regular() const;
		Vector3 Unit() const;
		void Show() const
		{
			std::cout << "Vector3 = [" << x << ", " << y << ", " << z << "]" << std::endl;
		}
};

#endif
