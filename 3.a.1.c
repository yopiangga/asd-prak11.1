#include <stdio.h>
#include <stdlib.h>

void tampil(int data[], int n);

int ascDesc = 1;
int orderBy = 2;

int main(){
	int i, n = 10;
	int data[n];
	
	for(i=0; i<n; i++){
		data[i] = rand()/1000;
	}
	
	printf("\n");
	printf("%-25s", "Data awal array"); printf(": ");
	tampil(data, n);
	printf("\n");
	bubble(data, n);
	printf("\n");
	printf("%-25s", "Data terurut array"); printf(": ");
	tampil(data, n);
}

int bubble(int data[], int n){
	
	int i, j, kondisi = 0, flag = 1;

	for(i=0; i<n-1; i++){
		flag = 0;
		for(j=0; j<n-i-1; j++){
			if(data[j] > data[j+1]){
				tukar(&data[j], &data[j+1]);
				flag = 1;
			}
		}
		if(flag == 0)
			break; 
		tampil(data, n);
	}
}

int tukar(int *a, int *b){
	int temp;
	
    temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(int data[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}
