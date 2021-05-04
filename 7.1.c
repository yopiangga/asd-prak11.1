#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 20000

void alokasi(int data2[], int n);
void tampil(int data[], int n);

int main(){
	int n = 10;
	
	int data[n];
	
	
	int i, j;
	 
	srand(time(NULL));
	
	for(i=0; i<10; i++){
		alokasi(data, n);
		tampil(data, n);
	}
}

void alokasi(int data2[], int n){
	int i;
	
	for(i=0; i<n; i++){
		data2[i] = rand()/1000;
	}
}

void tampil(int data[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}
