#include "Point.h"

Point3D::Point3D()
{
	x = 0;
	y = 0;
	z = 0;
}

Point3D::Point3D(double xCoordinate, double yCoordinate, double zCoordinate)
{
	x = xCoordinate;
	y = yCoordinate;
	z = zCoordinate;
}

Point3D::Point3D(const Point3D& point)
{
	x = point.x;
	y = point.y;
	z = point.z;
}

// Organize every vertex of polygon here!