#include "Vector.h"

/*********These are helper and essential functions to do matrix calculation****/
void subVector(double in1[3], double in2[3], double output[3])
{
	output[0] = in1[0] - in2[0];
	output[1] = in1[1] - in2[1];
	output[2] = in1[2] - in2[2];
}

void crossVector(double x[3], double y[3], double output[3])
{
	output[0] = x[1] * y[2] - y[1] * x[2];
	output[1] = x[2] * y[0] - y[2] * x[0];
	output[2] = x[0] * y[1] - y[0] * x[1];
}
double dotVector(double x[3], double y[3])
{
	return x[0] * y[0] + x[1] * y[1] + x[2] * y[2];
}

void normalizeVector(double input[3])
{
	double length = std::sqrt(input[0] * input[0] + input[1] * input[1] + input[2] * input[2]);
	input[0] = input[0] / length;
	input[1] = input[1] / length;
	input[2] = input[2] / length;
}

void getEyeMatrix(
	double *VRC,
	double *VPN,
	double *VUP,
	double Result[4][4])
{
	double f[3] = { VPN[0],VPN[1],VPN[2] };
	normalizeVector(f);

	double s[3] = {};
	crossVector(f, VUP, s);
	normalizeVector(s);

	double u[3] = {};
	crossVector(s, f, u);
	normalizeVector(u);

	double init_value[4][4] = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1} };

	memcpy((double *)Result, (double *)init_value, 16 * sizeof(double));

	Result[0][0] = s[0];
	Result[1][0] = s[1];
	Result[2][0] = s[2];
	Result[0][1] = u[0];
	Result[1][1] = u[1];
	Result[2][1] = u[2];
	Result[0][2] = -f[0];
	Result[1][2] = -f[1];
	Result[2][2] = -f[2];
	Result[3][0] = -dotVector(s, VRC);
	Result[3][1] = -dotVector(u, VRC);
	Result[3][2] = dotVector(f, VRC);
}

//clipping matrix
void getPerspectiveProjectionMatrix(double fovy, double aspect, double zNear, double zFar, double Result[4][4])
{

	double const tanHalfFovy = tan(fovy / static_cast<double>(2));

	double init_value[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0} };

	memcpy((double *)Result, (double *)init_value, 16 * sizeof(double));


	Result[0][0] = static_cast<double>(1) / (aspect * tanHalfFovy);
	Result[1][1] = static_cast<double>(1) / (tanHalfFovy);
	Result[2][3] = -static_cast<double>(1);

}