#pragma once
#ifndef __CH_SP_MATH_H__
#define __CH_SP_MATH_H__

#include <cmath>

namespace ChSP
{
	template<typename T>
	class Vec3
	{
	public:
		Vec3() : x(T(0)), y(T(0)), z(T(0)) { }
		Vec3(const T& xx) : x(xx), y(xx), z(xx) { }
		Vec3(const T& xx, const T& yy, const T& zz) : x(xx), y(yy), z(zz) { }

		T dot(const Vec3<T>& v) const { return x * v.x + y * v.y + z * v.z; }
		T length() const { return sqrt(x * x + y * y + z * z); }
		void normalize()
		{
			T len = length();
			if (len > 0)
			{
				T invLen = 1 / len;
				x *= invLen, y *= invLen, z *= invLen;
			}
		}

		Vec3<T> cross(const Vec3<T>& v) const
		{
			return Vec3<T>(
				y * v.z - z * v.y,
				z * v.x - x * v.z,
				x * v.y - y * v.x
				);
		}

		Vec3<T> operator + (const Vec3<T>& v) const { return Vec3<T>(x + v.x, y + v.y, z + v.z); }
		Vec3<T> operator - (const Vec3<T>& v) const { return Vec3<T>(x - v.x, y - v.y, z - v.z); }
		Vec3<T> operator * (const Vec3<T>& v) const { return Vec3<T>(x * v.x, y * v.y, z * v.z); }
		void operator += (const Vec3<T>& v) { x += v.x, y += v.y, z += v.z; }

		T x, y, z;
	};

	template<typename T>
	T dot(const Vec3<T>& a, const Vec3<T>& b) { return a.x * b.x + a.y *b.y + a.z * b.z; }

	template<typename T>
	T length(const Vec3<T>&v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }

	template<typename T>
	void normalize(Vec3<T>& v)
	{
		T len2 = v.x * v.x + v.y * v.y + v.z * v.z;
		if (len2 > 0)
		{
			T invLen = 1 / sqrt(len2);
			v.x *= invLen, v.y *= invLen, v.z *= invLen;
		}
	}

	template<typename T>
	Vec3<T> normalize(const Vec3<T>& v)
	{
		Vec3<T> rv;
		T len3 = v.x * v.x + v.y * v.y + v.z * v.z;
		if (len3 > 0)
		{
			T invLen = 1 / sqrt(len3);
			return Vec3<T>(v.x * invLen, v.y * invLen, v.z*invLen);
		}

		return v;
	}

	template<typename T>
	Vec3<T> cross(const Vec3<T>& a, const Vec3<T>& b)
	{
		return Vec3<T>(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
			);
	}
}

#endif