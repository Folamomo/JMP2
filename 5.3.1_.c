#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Matrix {
	int x, y;
	double **data;
};

struct Matrix* init(int x, int y){
	struct Matrix *new = (struct Matrix*)malloc(sizeof(struct Matrix));
	new->x=x;
	new->y=y;
	new->data = (double **)malloc(sizeof(double*)*x);
	for (int i = 0; i<x; i++){
		new->data[i] = (double*)malloc(sizeof(double)*y);
	}
	return new;
}
double max (struct Matrix* matrix){
	double maximum=matrix->data[0][0];
	
	for (int i=0;i<matrix->x;i++){
		for(int j=0; j<matrix->y;j++){
			if (maximum<matrix->data[i][j])
				maximum=matrix->data[i][j];
		}
	}
	return maximum;
}

double min (struct Matrix* matrix){
	double minimum=matrix->data[0][0];

	for (int i=0;i<matrix->x;i++){
		for(int j=0; j<matrix->y;j++){
			if (minimum>matrix->data[i][j])
				minimum=matrix->data[i][j];
		}
	}
	return minimum;
}
int calculateWidth(struct Matrix* matrix){
	int width=3;
	int longest=(int)max(matrix);
	int longestNegative=(int)min(matrix);
	if (longest+longestNegative<0)
		longest=-longestNegative;

	while (longest>1){
		longest/=10;
		width ++;
	}
	
	int precision=2;
	width+=precision;
	return width;
}

void print (struct Matrix* matrix){
	int width=calculateWidth(matrix);
	for (int i=0;i<matrix->x;i++){
		printf("|");
		for(int j=0; j<matrix->y;j++)
			printf("%*.*lf", width, 2, matrix->data[i][j]);
		printf("|\n");
	}
}

int main(){
	struct Matrix* macierz1 = init(10, 10);
	macierz1->data[1][2]=500;
	print(macierz1);
	return 0;
}
