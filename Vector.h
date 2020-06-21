// Created by Zixuan Zeng
// Vector.h

#include <stdlib.h> 
#include <math.h>   
#include <stdio.h>  
#include <vector>
#include <GL/glut.h>

//vector help function
void subVector(double in1[3], double in2[3], double output[3]);
void crossVector(double x[3], double y[3], double output[3]);
double dotVector(double x[3], double y[3]);
void normalizeVector(double input[3]);

//view matrix
void getEyeMatrix(
	double * VRC,
	double * VPN,
	double * VUP,
	double Result[4][4]);

//clipping and projection matrix
void getPerspectiveProjectionMatrix(double fovy, double aspect, double zNear, double zFar, double Result[4][4]);
