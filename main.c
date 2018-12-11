#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "hint.h"
#include "hack.h"

int main(int argc, char* argv[]){
	int size;
	int iterations;
	int iteration = 0;
	if(argc == 1){
		size = 6;
		iterations = 100;
	}else if(argc == 2){
		size = atoi(argv[1]);
		iterations = 100;
	}else if(argc == 3){
		size = atoi(argv[1]);
		iterations = atoi(argv[2]);
	}else{
		printf("Format:\n%s [size of password] [# of iterations]", argv[0]);
		return 0;
	}
	struct timespec start, end;
	long int total = 0;
	srand(time(NULL));
	char sol[size];
	char ans[size];
	int i,j;
	i = 0;
	while(iteration < iterations){
		while(i < size){
			char t = 'a' + rand()%26;
			for(j = 0; j < i; j++){
				if(sol[j] == t){
					break;
				}
			}
			if(j == i){
				sol[i] = t;
				i++;
			}
		}
		init(sol,size);
		int correct = 0;
		clock_gettime(CLOCK_MONOTONIC_RAW, &start);
		while(!correct){
			hack(ans,size);
			for(i = 0; i < size; i++){
				if(ans[i] != sol[i]){
					break;
				}
			}	
			if(i == size){
				correct = 1;
			}
		}
		clock_gettime(CLOCK_MONOTONIC_RAW, &end);
		total += (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;
		iteration++;
	}
	printf("You have successfully cracked %d passwords in %ld microseconds",iterations, total);
	return 0;
}