// Kompiluje się z flagą -lm 

#include <stdio.h>
#include <math.h>

void kwadrat(){
	double a=0;
	printf("Podaj długość boku:\n");
	scanf("%lf", &a);
	if (a<0){
		fprintf(stderr,"Długości boków nie mogą być ujemne");
		return;
	}
	printf("Pole wynosi: %lf\n", a*a);
	printf("Obwód wynosi: %lf\n", 4*a);
}

void prostokat(){
	double a=0, b=0;
	printf("Podaj długości boków:\n");
	scanf("%lf%lf", &a, &b);
	if (a<0||b<0){
		fprintf(stderr,"Długości boków nie mogą być ujemne");
		return;
	}
	printf("Pole wynosi: %lf\n", a*b);
	printf("Obwód wynosi: %lf\n", 2*(a+b));

}

void kolo (){
	double a=0;
	printf("Podaj długość promienia:\n");
	scanf("%lf", &a);
	if (a<0){
		fprintf(stderr,"Długość promienia nie może być ujemna");
		return;
	}
	printf("Pole wynosi: %lf\n", a*a*M_PI);
	printf("Obwód wynosi: %lf\n", 2*a*M_PI);
}

void trojkat(){
	double a=0, b=0, c=0;
	printf("Podaj długości boków:\n");
	scanf("%lf%lf%lf", &a, &b, &c);
	if (a<0||b<0||c<0){
		fprintf(stderr,"Długości boków nie mogą być ujemne");
		return;
	}
	if (a+b<c||b+c<a||a+c<b){
		fprintf(stderr, "Taki trójkąt nie istnieje");
		return;
	}
	printf("Pole wynosi: %lf\n", sqrt((a+b+c)*(a+b-c)*(a-b+c)*(b+c-a))/4);
	printf("Obwód wynosi: %lf\n", a+b+c);
}

void wielokat_foremny(){
	int n=0;
	double a=0;
	printf("Podaj ilość boków i długość 1 boku:\n");
	scanf("%d%lf", &n, &a);
	if (a<0||n<3){
		fprintf(stderr,"Taka figura nie istnieje");
		return;
	}
	printf("Pole wynosi: %lf\n", 0.25*n*a*a*tan(M_PI/n));
	printf("Obwód wynosi: %lf\n", n*a);
}


int main(){
	int figura;
	printf(	"Wybierz figurę:\n"
		"1. Kwadrat\n"
		"2. Prostokąt\n"
 		"3. Koło\n"
		"4. Trójkąt\n"
 		"5. Wielokąt foremny\n");
	scanf("%d", &figura);
	switch (figura){
	case 1:
		kwadrat();
	break;
	case 2:
		prostokat();
	break;
	case 3:
		kolo();
	break;
	case 4:
		trojkat();
	break;
	case 5:
		wielokat_foremny();
	break;
	}
	return 0;
}
