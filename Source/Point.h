// Point.h : Implements the CPoint class
//

#pragma once

#include "stdafx.h"
#include <type_traits>
//#include "Vector.h"
template
	<
	typename T,
	typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type
	>
class CVector;

template
	<
	typename T,
	typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type
	>
class CPoint
{
public:
	CPoint(const T x = 0.0, const T y = 0.0, const T z = 0.0) :
	  m_x(x), m_y(y), m_z(z)
	{
	}

	~CPoint()	{}

private:
	T m_x, m_y, m_z;

public:
	// Print the co-ordinate values
	void Print()
	{
		cout<<"\n Point : " <<m_x <<", " <<m_y <<", " <<m_z <<endl;
	}

	// Get x co-ordinate
	T GetX() const	{ return m_x; }

	// Get y co-ordinate
	T GetY() const	{ return m_y; }

	// Get z co-ordinate
	T GetZ() const	{ return m_z; }

	// Set x co-ordinate
	void SetX(const T x)	{ m_x = x; }

	// Set y co-ordinate
	void SetY(const T y)	{ m_y = y; }

	// Set z co-ordinate
	void SetZ(const T z)	{ m_z = z; }

	// Computes subtraction of two points which creates a vector
	CVector<T> operator - (const CPoint<T> &point)
	{
		// subtraction of two vectors
		// v = pt1 - pt2
		T i = this->m_x - point.m_x;
		T j = this->m_y - point.m_y;
		T k = this->m_z - point.m_z;
		return CVector<T>(i, j, k);
	}

	// Computes addition of two points which creates a new point
	CPoint<T> operator + (const CPoint<T> &point)
	{
		// subtraction of two vectors
		// p = pt1 - pt2
		T x = this->m_x + point.m_x;
		T y = this->m_y + point.m_y;
		T z = this->m_z + point.m_z;
		return CPoint<T>(x, y, z);
	}

	// Computes addition of Vector and Points which creates a new point
	CPoint<T> operator + (const CVector<T> &vector)
	{
		// adding a vector to a point gives new point
		T x = this->m_x + vector.Get_i();
		T y = this->m_y + vector.Get_j();
		T z = this->m_z + vector.Get_k();
		return CPoint<T>(x, y, z);
	}
};