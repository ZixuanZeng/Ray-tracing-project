// Created by Zixuan Zeng
// Surface.cpp
#include "Surface.h"

CoefficientOfPlane::CoefficientOfPlane()
{
	A = B = C = D = 0;
}

DepthBuffer::DepthBuffer()
{
	COPlane = new CoefficientOfPlane();
}

CoefficientOfPlane& DepthBuffer::Value(Point3D& p1, Point3D& p2, Point3D& p3)
{
	CoefficientOfPlane* cop = new CoefficientOfPlane();
	cop->A = (p2.z - p3.z) * (p1.y - p2.y) - (p1.z - p2.z) * (p2.y - p3.y);
	cop->B = (p2.x - p3.x) * (p1.z - p2.z) - (p1.x - p2.x) * (p2.z - p3.z);
	cop->C = (p2.y - p3.y) * (p1.x - p2.x) - (p1.y - p2.y) * (p2.x - p3.x);
	cop->D = -p1.x * (p2.y * p3.z - p2.z * p3.y) + p1.y * (p2.x * p3.z - p2.z * p3.x) - p1.z * (p2.x * p3.y - p2.y * p3.x);
	return *cop;
}

double DepthBuffer::DepthValue(CoefficientOfPlane& surface, int x, int y)
{
	double z = 0;
	if (surface.B != 0)
	{
		z = (-surface.A * x - surface.C * y - surface.D) / surface.B;
		return z;
	}
}

bool DepthBuffer::checkInside(Point3D& point1, Point3D& point2, Point3D& point3, int x, int y)
{
	float fxyC, fxy;
	fxyC = point3.y * (point2.x - point1.x) - point3.x * (point2.y - point1.y) + point1.x * (point2.y - point1.y) - point1.y * (point2.x - point1.x);
	fxy = y * (point2.x - point1.x) - x * (point2.y - point1.y) + point1.x * (point2.y - point1.y) - point1.y * (point2.x - point1.x);
	if (((fxyC <= 0) && (fxy <= 0)) || ((fxyC >= 0) && (fxy >= 0)))
		return true;
	else
		return false;
}
//Subroutine to check any point(x,y) inside the triangle
bool DepthBuffer::checkTriangleInside(Point3D& pt1, Point3D& pt2, Point3D& pt3, int x, int y)
{

	bool check = checkInside(pt1, pt2, pt3, x, y) && checkInside(pt2, pt3, pt1, x, y) && checkInside(pt3, pt1, pt2, x, y);
	if (check == true) return true;
	else return false;
}

/****This function is to genreate each pixel needed for drawing lines*******/
void Surface::writePixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd;
}

//Helper function for the following function
void Surface::drawCirclePoint(int xc, int yc, int x, int y) {
	writePixel(xc + x, yc + y);
	writePixel(xc - x, yc + y);
	writePixel(xc + x, yc - y);
	writePixel(xc - x, yc - y);
	writePixel(xc + y, yc + x);
	writePixel(xc - y, yc + x);
	writePixel(xc + y, yc - x);
	writePixel(xc - y, yc - x);
}

//Bresenham’s circle drawing algorithm
void Surface::midpointCircle(int x1, int y1, int radius) {
	int x = 0;
	int y = radius;
	int d = 1 - radius;
	int deltaE = 3;
	int deltaSE = -2 * radius + 5;
	while (y >= x)
	{
		drawCirclePoint(x1, y1, x, y);
		x++;

		if (d > 0)
		{                          /*Select SE*/
			y--;
			d += deltaSE;
			deltaE += 2;
			deltaSE += 4;
		}
		else
		{                          /*Select E*/
			d += deltaE;
			deltaE += 2;
			deltaSE += 2;
		}
		drawCirclePoint(x1, y1, x, y);
		glEnd();
	}
}

/**This method should use both mid-point circle drawing and depth-buffer algorithms****/
void Surface::drawSphere(Point3D& center, int radius) {
	midpointCircle(center.x, center.y, radius);
	//there should be a method to use hidden surface algorithm to determine which part of polygon should be visible

}