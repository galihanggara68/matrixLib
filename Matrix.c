#include <stdio.h>
#include "2.1/matrixlib.h"

int main(){
	int mat[2][2] = {
	{2, 5},
	{1, 4},
	};
	int mat2[3][3] = {
		{1, 5, 3},
		{0, -4, 2},
		{2, 1, 1},
	};
	int mat3[4][4] = {
		{3, 1, 5, 3},
		{-7, 0, -4, 2},
		{0, 2, 1, 1},
		{0, 0, 1, 1},
	};
	int mat4[5][5] = {
		{1, 3, 1, 5, 3},
		{-2, 7, 0, -4, 2},
		{0, 0, 1, 0, 1},
		{0, 0, 2, 1, 1},
		{0, 0, 0, 1, 1}
	};
	int *pMat = mat4;
	//printf("%i", *(pMat+(4*5)+4));
	//int *pMat = mat2;
	//printf("%i", *(pMat+4));
	//printf("%i", det2x2(mat));
	//printf("\n%i", det3x3(mat2));
	//printf("Det 4x4 : %i", det4x4(mat3, 2));
	//printf("%d", -4)
	printf("Det 5x5 : %i", det5x5(mat4, 4));
	return 0;
}
