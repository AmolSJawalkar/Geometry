// GeomUtil.cpp : Defines the entry point for the console application.
//

#pragma once

#include "stdafx.h"
#include <conio.h>
#include "Point.h"
#include "Vector.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CPoint<double> p1(1,1,1);
	CPoint<double> p2(1, 2, 3);
	CVector<double> p= p2 - p1;
	CVector<double> v(2, 2, 2);

	p1 = v + p2;

	p2.Print();

	cout<<"\nPress any key to exit...";
	_getch();

	return 0;
}