// Created by Zixuan Zeng
// Point.h
#include <stdlib.h> 
#include <math.h>   
#include <stdio.h>  
#include <vector>
#include <GL/glut.h>
#include "Vector.h"

#ifndef Point3D_HEADER
#define Point3D_HEADER

/* This class do ray tracing and position of each point w.r.t vrp*/

class Point3D
{
public:
	double x, y, z;
	Point3D();
	Point3D(double, double, double);
	Point3D(const Point3D&);
};

#endif // !Point3D