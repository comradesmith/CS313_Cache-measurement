#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

void compute(double* a, double* b, double* c, int n);
double getTime();
void test();
void print_matrix(double* x, int n);

int main(int argc, char **argv)
{
	int i;
	unsigned int n, m;
	double t1, t2;
	
	n = 1000;
	m = 1;
	for (i = 1; i < (unsigned) argc; i++) {
		if (strcmp(argv[i], "--n") == 0 ) {
			i++;
			if (i < argc)
				sscanf(argv[i], "%u", &n);
			else {
				fprintf (stderr, "Usage: matrix1/2/3 [-n N]\n");
				return 1;
			}
		} else if (strcmp(argv[i], "--repetitions") == 0) {
			i++;
			if (i < argc)
				sscanf(argv[i], "%u", &m);
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
	
//	test();

	srand(0xC0FFEE);
	for(i = 0; i < n * n; i++){
		a[i] = b[i]  = (double)(rand() % 255);
	}

	print_matrix(a, n);
	printf("\n");
	print_matrix(b, n);
	printf("\n");

	t1 = getTime();
	/*  BEGIN TIMER  */

	for(i =0; i < m; i++){
		compute(a, b, c, n);
	}
	/* END TIMER */
	t2 = getTime();

	print_matrix(c, n);
	printf("success with a value of %u\n", n);


	printf("time:\t%6.4f secs\n",(t2 - t1));
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

double getTime(){
	struct timeval t;
	double sec, msec;
	
	while (gettimeofday(&t, NULL) != 0);
	sec = t.tv_sec;
	msec = t.tv_usec;
	
	sec = sec + msec/1000000.0;
	
	return sec;
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
