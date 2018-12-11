#include "hint.h"
#include "stdlib.h"
typedef struct Node{
	char c;
	struct Node* next;
} Node;

void hack(char* ans, int size){
	int num = size;
	Node* hist[26];
	int i;
	char a,b;
	for(i = 0; i < 26; i++){
		hist[i] = 0;
	}
	while(num > 1){
		getHint(&a,&b);
		Node** curr = &hist[a-'a'];
		int count = 0;
		while(*curr != 0){
			count++;
			if((*curr)->c == b){
				break;
			}
			curr = &(*curr)->next;
		}
		if(*curr == 0){
			*curr = (Node*) malloc(sizeof(Node));
			(*curr)->c = b;
			count++;
		}
		if(count == num - 1){
			ans[size - 1 - count] = a;
			num--;
		}
	}
	ans[size-1] = hist[ans[size-2]-'a']->c;
}