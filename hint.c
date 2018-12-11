#include "hint.h"
#include "stdlib.h"

static char* sol;
static int l;

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void init(char* _s,int _l){
	sol = _s;
	l = _l;
}

void getHint(char* hinta, char* hintb){
	int a = rand()%l;
	int b;
	do{
		b = rand()%l;
	}while(b == a);
	if(a > b){
		swap(&a, &b);
	}
	*hinta = sol[a];
	*hintb = sol[b];
}