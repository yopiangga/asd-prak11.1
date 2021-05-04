#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 20000

void tampil(int data[], int n);

time_t t1, t2;
long int waktukomputasi;

int ascDesc = 0;

int main(){
	int i, n;
	int data[MAX];
	
	printf("%-25s", "Jumlah data "); printf(": ");
	scanf("%d", &n);
	fflush(stdin);
	
	for(i=0; i<n; i++){
		data[i] = rand();
	}
	
	modeUrut();
	
	printf("\n");
	printf("%-25s", "Data awal array"); printf(": ");
	tampil(data, n);
	printf("\n");
	
	time(&t1);
	bubble(data, n);

	time(&t2);
	waktukomputasi= difftime(t2,t1);
	
	printf("\n");
	printf("%-25s", "Data terurut array"); printf(": ");
	tampil(data, n);
	
	printf("\n");
	printf("%-25s", "Waktu Komputasi"); printf(": %d\n\n", waktukomputasi);
}

int modeUrut(){
	printf("========================\n");
	printf(" MENU MODE SORTING\n");
	printf("========================\n");
	printf("1. Ascending\n");
	printf("2. Descending\n");
	printf("%-25s", "Pilih Menu"); printf(": ");
	scanf("%d", &ascDesc);
	fflush(stdin);
}

int bubble(int data[], int n){
	
	int i, j, kondisi = 0, flag = 1, akhir = n-2;

	for(i=0; i<=n-2; i++){
		flag = 0;
		for(j=0; j<=n-2; j++){
			if(ascDesc == 1)
				kondisi = data[j] > data[j+1];
			else if(ascDesc == 2)
				kondisi = data[j] < data[j+1];
			
			if(kondisi){
				tukar(&data[j], &data[j+1]);
				flag = 1;
			}

			if(akhir == j)
				break;
		}
		if(flag == 0)
			break;
		akhir--; 
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
