// Vector.h : Implements the CVector class
//

#pragma once

#include "stdafx.h"
#include <math.h>
#include <type_traits>
#include "Point.h"

template
	<
	typename T,
	typename = typename std::enable_if<std::is_floating_point<T>::value, T>::type
	>
class CVector
{
public:
	CVector(const T i = 0.0, const T j = 0.0, const T k = 0.0) :
	  m_i(i), m_j(j), m_k(k)
	{
		ComputeMagnitude();
	}

	~CVector()	{}

private:
	T m_i, m_j, m_k;
	T m_magnitude;

private:
	// Compute the magnitude of the vector.
	void ComputeMagnitude()
	{
		// Magnitude = SquareRoot( i^2 + j^2 + k^2)
		m_magnitude = sqrt( (m_i * m_i) + (m_j * m_j) + (m_k * m_k));
	}

public:
	// Print the vector components
	void Print()
	{
		cout<<"\n Vector : " <<m_i <<" i, " <<m_j <<" j, " <<m_k <<" k" <<endl;
		cout<<"\n Magnitude : " <<m_magnitude <<endl;
	}

	// Get i co-ordinate
	T Get_i() const	{ return m_i; }

	// Get j co-ordinate
	T Get_j() const	{ return m_j; }

	// Get k co-ordinate
	T Get_k() const	{ return m_k; }

	// Return the magnitude
	T Get_Magnitude()	{ return m_magnitude; }

	// Return the unit vector
	CVector<T> Normalize()
	{
		//			       Vector
		// Unit Vector = -----------
		//               | Vector |

		return CVector<T>((m_i / m_magnitude), (m_j / m_magnitude), (m_k / m_magnitude));
	}

	// Validate Zero Vector
	bool IsZero()
	{
		if(m_magnitude)
			return true;
		else
			return false;
	}

	// Set i co-ordinate
	void Set_i(const T i)
	{
		m_i = i;

		// Recompute the magnitude as the i component is changed
		ComputeMagnitude();
	}

	// Set j co-ordinate
	void Set_j(const T j)
	{
		m_j = j;

		// Recompute the magnitude as the j component is changed
		ComputeMagnitude();
	}

	// Set k co-ordinate
	void Set_k(const T k)
	{
		m_k = k;

		// Recompute the magnitude as the k component is changed
		ComputeMagnitude();
	}

	// Computes addition of vectors
	CVector<T> operator + (const CVector<T> &vector)
	{
		// Addition of two vectors

		// V = v1 + v2 = (a1 + a2)i + (b1 + b2)j + (c1 + c2)k

		T i, j, k;
		i = this->m_i + vector.m_i;
		j = this->m_j + vector.m_j;
		k = this->m_k + vector.m_k;

		return CVector<T>(i, j, k);
	}

	// Computes subtraction of vectors
	CVector<T> operator - () const
	{
		// subtraction of two vectors
		// v = - v1

		return CVector<T>(-m_i, -m_j, -m_k);
	}

	// Computes subtraction of vectors
	CVector<T> operator - (const CVector<T> &vector)
	{
		// subtraction of two vectors
		// v = v1 - v2 = v1 + -v2

		return *this + (-vector);
	}

	// Computes cross product of vectors
	CVector<T> operator * (const CVector<T> &vector)
	{
		// Cross product of two vectors

		//               | i  j  k  |
		// V = v1 * v2 = | a1 b1 c1 | = (b1*c2 - c1*b2)i - (a1*c2 - c1*a2)j + (a1*b2 - b1*a2)k;
		//               | a2 b2 c2 |

		T i, j, k;
		i = (this->m_j * vector.m_k) - (this->m_k * vector.m_j);
		j = - ((this->m_i * vector.m_k) - (this->m_k * vector.m_i));
		k = (this->m_i * vector.m_j) - (this->m_j * vector.m_i);

		return CVector<T>(i, j, k);
	}

	// Scalar product
	CVector<T> operator * (T scalarValue)
	{
		T i = m_i * scalarValue;
		T j = m_j * scalarValue;
		T k = m_k * scalarValue;

		return CVector<T>(i, j, k);
	}

	// Dot product
	T dot_product(const CVector<T> &vector)
	{
		return (m_i * vector.m_i) + (m_j * vector.m_j) + (m_k * vector.m_k);
	}

	//// Computes addition of Vector and Points which creates a new point
	CPoint<T> operator + (const CPoint<T> &pt)
	{
		T x = m_i + pt.GetX();
		T y = m_i + pt.GetY();
		T z = m_k + pt.GetZ();
		return CPoint<T> (x, y, z);
	}

	void Negate()
	{
		this->m_i = - this->m_i;
		this->m_j = - this->m_j;
		this->m_k = - this->m_k;
		ComputeMagnitude();
	}
};