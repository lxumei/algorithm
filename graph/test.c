#include<stdio.h>

typedef struct test{
	int a[10];
}T;

int main(){
	T t1;
	T t2;
	for(int i=0; i<10; i++){
		t1.a[i] = i;
	}
	t2 = t1;
	for(int i=0; i<10; i++)
		printf("%d ", t2.a[i]);
	return 0;
}
