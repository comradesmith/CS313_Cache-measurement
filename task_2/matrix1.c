#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compute(double* a, double* b, double* c, int n);

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
	do {
		x = a[i];
		a[i] = 123.456;
		x = a[i];
		i++;
		printf("%6.4f\n", x);
	} while (i < (n * n));
	 
	compute(a, b, c, n);
	printf("success with a value of %u\n", n);


}

void compute(double* a, double* b, double* c, int n)
{
	printf("%6.2f %6.2f %6.2f \n", a[00], b[0], c[0]);
	
	int i, j, k;

	for(i = 0; i < n; i++){
		
		for(j = 0; j < n; j++){
	
			for(k = 0; k < n; k++){
				#TODO assign this somewhere
				a[(i * n) + j] + b[(k * n) + j];
			
			};
			
			
		};
		
		
	};


}
