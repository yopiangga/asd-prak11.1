#include <stdio.h>
#include <stdlib.h>

void tampil(int data[], int n);

int ascDesc = 1;
int orderBy = 2;
int C = 0, M = 0, S = 0;

int main(){
	int n = 10;
//	int data[] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
//	int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int data[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	
	printf("\n");
	printf("%-25s", "Data awal array"); printf(": ");
	tampil(data, n);
	printf("\n");
	shell(data, n);
	printf("\n");
	printf("%-25s", "Data terurut array"); printf(": ");
	tampil(data, n);
	
	printf("%-25s", "Data C"); printf(": %d\n", C);
	printf("%-25s", "Data M"); printf(": %d\n", M);
	printf("%-25s", "Data S"); printf(": %d\n", S);
}

int shell(int data[], int n){
	
	int i, j, jarak,  kondisi = 0, flag;
	int key;
	
	for(jarak=n/2; jarak>=1; jarak=jarak/2){
		flag = 1;
		while(flag == 1){
			flag = 0; 
			for(i=0; i<n-jarak; i++){
				C++;		
				if(data[i] > data[i+jarak]){
					M = M + 3;
					S++;
					tukar(&data[i], &data[i+jarak]);
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
