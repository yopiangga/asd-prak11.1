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
	shell(data, n);
	printf("\n");
	printf("%-25s", "Data terurut array"); printf(": ");
	tampil(data, n);
}

int shell(int data[], int n){
	
	int i, j, y,  kondisi = 0, flag;
	int key;
	
	for(y=n/2; y>=1; y=y/2){
		flag = 1;
		while(flag == 1){
			flag = 0; 
			for(i=0; i<n-y; i++){			
				if(data[i] > data[i+y]){
					tukar(&data[i], &data[i+y]);
					flag = 1;
				}
			}
		}
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
