#ifndef MATRIX_LIB
#define MATRIX_LIB
	
//Method Defines
int det2x2(int mat[2][2]);
int det3x3(int mat[3][3]);
int det4x4(int mat[4][4], int kof);
int det5x5(int *mat, int kof);

//Implementations
int det2x2(int mat[2][2]){
	return (mat[0][0]*mat[1][1]) - (mat[0][1]*mat[1][0]);
}

int det3x3(int mat[3][3]){
	int det = 0, u = 0, d = 0, rd = 0, ru = 0;
	int size, i;
	for(i = 0; i < 3; i++){
		u = mat[0][i];
		d = mat[2][i];
		printf("\n%i", mat[0][i]);
		if(i + 1 < 3){
			u *= mat[1][i+1];
			d *= mat[1][i+1];
			printf("*%i", mat[1][i+1]);
		}else{
			u *= mat[1][i-2];
			d *= mat[1][i-2];
			printf("*%i", mat[1][i-2]);
		}
		
		if(i + 2 < 3){
			u *= mat[2][i+2];
			d *= mat[0][i+2];
			printf("*%i\n", mat[2][i+1]);
		}else{
			u *= mat[2][i-1];
			d *= mat[0][i-1];
			printf("*%i\n", mat[2][i-1]);
		}
		ru += u;
		rd += d;
	}
	det = ru - rd;
	printf("3x3Det : %i\n", det);
	return det;
}

int det4x4(int mat[4][4], int kof){
	int i, j, x, inc = 0, inc2 = 0, det = 0;
	int mat3x3[4][3][3];
	int sdet[4];
	for(x = 0; x < 4; x++){
	printf("\n===========\n");
	inc = 0;
		for(i = 0; i < 4; i++){
		sdet[x] = mat[kof][x];
		inc2 = 0;
			if(i == kof) continue;
			for(j = 0; j < 4; j++){
				if(j == x) continue;
				mat3x3[x][inc][inc2] = mat[i][j];
				printf("%i ", mat3x3[x][inc][inc2]);
				inc2++;
			}
			printf("\n");
			inc++;
		}
	}
	for(i = 0; i < 4; i++){
		det += (sdet[i]*det3x3(mat3x3[i]));
	}
	return det;
}

int det5x5(int *mat, int kof){
	int i, j, x, inc = 0, inc2 = 0, det = 0;
	int mat4x4[5][4][4];
	int sdet[5];
	for(x = 0; x < 5; x++){
	printf("\n===========\n");
	inc = 0;
		for(i = 0; i < 5; i++){
		sdet[x] = *(mat+((kof*5)+x));
		inc2 = 0;
			if(i == kof) continue;
			for(j = 0; j < 5; j++){
				if(j == x) continue;
				mat4x4[x][inc][inc2] = *(mat+((i*5)+j));
				printf("%i ", mat4x4[x][inc][inc2]);
				inc2++;
			}
			printf("\n");
			inc++;
		}
	}
	for(i = 0; i < 5; i++){
		det += (sdet[i]*det4x4(mat4x4[i], kof));
	}
	return det;
}


#endif
