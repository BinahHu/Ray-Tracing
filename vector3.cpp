#include "vector3.h"
#include <cstdlib>
#include <cmath>

Vector3 operator + ( const Vector3& A , const Vector3& B )
{
	return Vector3( A.x + B.x , A.y + B.y , A.z + B.z );
}

Vector3 operator - ( const Vector3& A , const Vector3& B )
{
	return Vector3( A.x - B.x , A.y - B.y , A.z - B.z );
}

Vector3 operator * ( const Vector3& A , const double& k )
{
	return Vector3( A.x * k , A.y * k , A.z * k );
}

Vector3 operator / ( const Vector3& A , const double& k )
{
	return Vector3( A.x / k , A.y / k , A.z / k );
}

Vector3& operator += ( Vector3& A , const Vector3& B )
{
	A = A + B;
	return A;
}

Vector3& operator -= ( Vector3& A , const Vector3& B )
{
	A = A - B;
	return A;
}

Vector3& operator *= ( Vector3& A , const double& k )
{
	A = A * k;
	return A;
}

Vector3& operator += ( Vector3& A , const double& k )
{
	A = A / k;
	return A;
}

Vector3 operator - ( const Vector3& A )
{
	return Vector3( -A.x , -A.y , -A.z );
}

ssm& operator>>(ssm& in, Vector3& v)
{
	in >> v.x >> v.y >> v.z;
	return in;
}

double Vector3::Dot(const Vector3& v) const
{
	return x * v.x + y * v.y + z * v.z;
}

Vector3 Vector3::Cross(const Vector3& v) const
{
	return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

double Vector3::Norm() const
{
	return sqrt(Norm2());
}

double Vector3::Norm2() const
{
	return x * x + y * y + z * z;
}

double Vector3::Dist(const Vector3& v) const
{
	return sqrt(Dist2(v));
}

double Vector3::Dist2(const Vector3& v) const
{
	return (v.x - x) * (v.x - x) + (v.y - y) * (v.y - y) + (v.z - z) * (v.z - z);
}

double Vector3::GetMax() const
{
	return fmax(fabs(x), fmax(fabs(y), fabs(z)));
}

Vector3 Vector3::Regular() const
{
	return Vector3(fmin(x,1.0) ,fmin(y,1.0) ,fmin(z,1.0));
}

Vector3 Vector3::Unit() const
{
	double len = Norm();
	return Vector3(x / len, y / len, z / len);
}
