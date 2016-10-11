#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compute(double* a, double* b, double* c, int n);
void test();
void print_matrix(double* x, int n);

int main(int argc, char **argv)
{
	int i;
	unsigned int n;

	
	n = 1000;
	for (i = 1; i < (unsigned) argc; i++) {
		if (strcmp(argv[i], "--n") == 0 ) {
			i++;
			if (i < argc)
				sscanf(argv[i], "%u", &n);
			else {
				fprintf (stderr, "Usage: matrix1/2/3 [-n N]\n");
				return 1;
			}
		} else {
			fprintf (stderr, "Usage: matrix1/2/3 [-n N]\n");
			return 1;
		}

	}

	double x;

	double *a, *b, *c;
	a = malloc(n * n * sizeof(double));
	b = malloc(n * n * sizeof(double));
	c = malloc(n * n * sizeof(double));

	i = 0;
/*	do {
		x = a[i];
		a[i] = 123.456;
		x = a[i];
		i++;
		printf("%6.4f\n", x);
	} while (i < (n * n)); */

	test();
	 
	//compute(a, b, c, n);
	printf("success with a value of %u\n", n);


}

void compute(double* a, double* b, double* c, int n)
{
	
	int i, j, k;
	double sum;

	for(i = 0; i < n; i++){
		
		for(j = 0; j < n; j++){
			sum = 0;
			for(k = 0; k < n; k++){
				sum += a[(i * n) + k] * b[(k * n) + j];
			};
			c[i * n + j] = sum;
		};
	};
}


void test()
{	
	double *x, *y, *z;	

	x = malloc(3 * 3 * sizeof(double));
	y = malloc(3 * 3 * sizeof(double));
	z = malloc(3 * 3 * sizeof(double));

	x[0] = 1.0;
	x[1] = 2.0;
	x[2] = 3.0;

	x[3] = 3.0;
	x[4] = 2.0;
	x[5] = 1.0;

	x[6] = 2.0;
	x[7] = 1.0;
	x[8] = 3.0;

	y[0] = 3.0;
	y[1] = 2.0;
	y[2] = 1.0;

	y[3] = 2.0;
	y[4] = 3.0;
	y[5] = 1.0;

	y[6] = 1.0;
	y[7] = 2.0;
	y[8] = 3.0;
	
	printf("Matrix x:\n");
	print_matrix(x, 3);
	printf("\n\n");

	printf("Matrix y:\n");
	print_matrix(y, 3);
	printf("\n\n");

	compute(x, y, z, 3);
	print_matrix(z, 3);
	printf("\n\n");



}

void print_matrix(double* x, int n)
{
	double a;
	int i, j;
	i = j = 0;
	
	for(i = 0; i < n; i++){

		for(j  = 0; j < n; j++){
			a = x[i * n + j];
			printf("%6.2f\t", a);
		}
		printf("\n");
	}

}
