//
//  Main.cpp
//  CS 425 Project 3
//
// created by Zixuan Zeng on 11/28/2018

#include <stdlib.h> // standard definitions
#include <math.h>   // math definitions
#include <stdio.h>  // standard I/O
#include <iostream>
#include <fstream>
#include <GL/glut.h>
#include "Light.h"
#include "Point.h"
#include "Surface.h"
#include "Vector.h"
using namespace std;

void display(void) {

}

void reshape(int w, int h) {
	/* set the viewport */
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);  // lower-left corner

	/* Matrix for projection transformation */
	glMatrixMode(GL_PROJECTION);

	/* replaces the current matrix with the identity matrix */
	glLoadIdentity();

	/* Define a 2d orthographic projection matrix */
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);  // left, right, bottom, top
}

int main(int argc, char **argv) {

	ifstream inputFile;
	string test;       //For testing input file only

	/* deal with any GLUT command Line options */
	glutInit(&argc, argv);

	/* create an output window */
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 800);

	/* set the name of the window and try to create it */
	glutCreateWindow("Assignment 3 - Zixuan Zeng");

	inputFile.open("database.txt");    //Handle database file
	if (!inputFile)
	{
		cout << "Unable to open file";
		exit(1);
	}

	cout << inputFile.rdbuf() << endl;     //For testing only
	inputFile.close();

	/* assign the display function */
	glutDisplayFunc(display);

	/* assign the idle function */
	glutIdleFunc(display);

	/* sets the reshape callback for the current window */
	glutReshapeFunc(reshape);

	/* enters the GLUT event processing loop */
	glutMainLoop();

	return (EXIT_SUCCESS);
}