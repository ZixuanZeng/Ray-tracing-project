// Created by Zixuan Zeng
// Surface.h
#include <stdlib.h> 
#include <math.h>   
#include <stdio.h>  
#include <vector>
#include <GL/glut.h>
#include "Point.h"

class CoefficientOfPlane
{
public:
	double A, B, C, D;
	CoefficientOfPlane();
};

class DepthBuffer
{
public:
	CoefficientOfPlane* COPlane;
	DepthBuffer();
	CoefficientOfPlane& Value(Point3D&, Point3D&, Point3D&);
	double DepthValue(CoefficientOfPlane&, int, int);
	bool checkInside(Point3D&, Point3D&, Point3D&, int, int);
	bool checkTriangleInside(Point3D&, Point3D&, Point3D&, int, int);
};

class Surface
{
private:
	void writePixel(int, int);
	void drawCirclePoint(int, int, int, int);
	void midpointCircle(int, int, int);
public:
	void drawSphere(Point3D&, int);
	void drawWall();
};
