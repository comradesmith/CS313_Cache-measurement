/* do not add other includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

double getTime(){
	struct timeval t;
	double sec, msec;
	
	while (gettimeofday(&t, NULL) != 0);
	sec = t.tv_sec;
	msec = t.tv_usec;
	
	sec = sec + msec/1000000.0;
	
	return sec;
}
 
/* for task 1 only */
void usage(void)
{
	fprintf(stderr, "Usage: cachetest1/2 [--repetitions M] [--array_size N]\n");
	exit(1);
}

int main (int argc, char *argv[])
{
	double t1, t2; 
	
	/* variables for task 1 */
	unsigned int M = 1000;
	unsigned int N = 256*1024; 
	unsigned int i;
	
	/* declare variables; examples, adjust for task */
	int *a;
	//double	a[100];
 
	
	/* parameter parsing task 1 */
	for(i=1; i<(unsigned)argc; i++) {
		if (strcmp(argv[i], "--repetitions") == 0) {
			i++;
			if (i < argc)
				sscanf(argv[i], "%u", &M);
			else
				usage();
		} else if (strcmp(argv[i], "--array_size") == 0) {
			i++;
			if (i < argc)
				sscanf(argv[i], "%u", &N);
			else
				usage();
		} else usage();
	}

		
	/* allocate memory for arrays; examples, adjust for task */
	a = malloc (N * sizeof(int));

	/* initialise arrray elements */
	
	int x, y, bx, by;
	int j;

	int b[N];
	
	unsigned int sum;

	for(i = 0; i < N; i++) {
		a[i] = b[i] = i;
	}	


	t1 = getTime();
	/* code to be measured goes here */
	/***************************************/

	for(i = 0; i < M; i++){
	/* for M repetitions */
		sum = 0;	
		for(j = 0; j < N; j++) {
			sum += a[b[j]];
		}
	}


	/***************************************/
	t2 = getTime(); 
	
	/* output; examples, adjust for task */
	printf("time:\t%6.4f secs\n",(t2 - t1));
	//printf("time:\t%6.f ns\n", (t2 - t1) * 1000000000);
	printf("sum: \t%u\n", sum);


	/* free memory; examples, adjust for task */
	//free(a);

	return 0;  
}
