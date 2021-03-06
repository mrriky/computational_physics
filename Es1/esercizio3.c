#include<stdio.h>
#include<math.h>
#define epsilon 8.8542*pow(10,-12)

//Nuovo commento aggiunto

double rho(double r, double alfa){
	return (alfa*exp(-pow(r,2)/2.0));
}

double rho_sferico(double r, double alfa){
	return (rho(r, alfa)*4*M_PI*pow(r,2));
}


void calc_Q(double *q, double r, double alfa, double dr){
	int i, n=r/dr;
	double integq=0, rr=0;
	for(i=0; i<n; i++){
		*(q+i)=integq+(rho_sferico(rr, alfa)+rho_sferico(rr+dr, alfa))*dr/2;
		integq=*(q+i);
		rr+=dr;
	}
}

void calc_E(double *e, double *q, double r, double dr, double ke){
	int i, n=r/dr;
	double rr=0;
	for(i=0; i<n; i++){
		*(e+i)=ke**(q+i)/(pow(rr,2));
		rr+=dr;
	}
}



int main() {
	double alfa, r, dr=0.0001;
	double ke=1;
	int n;
	//double i;
	printf("dammi alfa: ");
	scanf("%lf", &alfa);
	printf("dammi r: ");
	scanf("%lf", &r);
	n=r/dr;
	double Q[n], E[n];
/*	double *pQ, *pE;
	pQ=&Q[0];
	pE=&E[0];*/
	calc_Q(&Q[0], r, alfa, dr);
	printf("Q[%f] = %f\n", r, Q[n-1]);
	calc_E(&E[0], &Q[0], r, dr, ke);
	printf("E[%f] = %f\n", r, E[n-1]);




/*	for(i=0; i<n; i++){
		printf("%d\t%f\n", i, E[i]);
	}
	printf("E[%f] = %f\n", r, E[n-1]);*/

/*	for(i=0; i<n; i++){
		printf("%d\t%f\n", i, Q[i]);
	}
	printf("Q[%f] = %f\n", r, Q[n-1]);*/

	return 0;
}
