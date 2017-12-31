//kompilować z flagą -lm (biblioteka math.h)

#include <stdio.h>
#include <math.h>

int ilePierw(double a, double b, double c){
	double delta = b*b-4*a*c;
	if (delta == 0)
		return 1;
	else if (delta <0)
		return 0;
	else 
		return 2;
}

double obliczx0(double a, double b){
	return -b/(2*a);
}

double obliczx1(double a, double b, double c){
	return (-b-sqrt(b*b-4*a*c))/(2*a);
}

double obliczx2(double a, double b, double c){
	return (-b+sqrt(b*b-4*a*c))/(2*a);
}

int main(){
	double a, b, c;
	printf("Podaj pierwiastki:\n");
	scanf("%lf%lf%lf", &a, &b, &c);
	if (a==0){
		fprintf(stderr, "Funkcja nie jest kwadratowa (a=0)\n");
		return 0;
	}
	switch (ilePierw(a, b, c)){
	case 0:
		printf("Funkcja nie ma pierwiastkow\n");
		return 0;
	case 1:
		printf("Funkcja ma 1 pierwiastek rowny %lf\n",
			obliczx0(a, b));
		return 0;
	case 2:
		printf("Funkcja ma 2 pierwiastki równe %lf i %lf\n",
			obliczx1(a, b, c), obliczx2(a, b, c));
		return 0;
	}
}
