#include <stdio.h>
#include <stdlib.h>

void tampil(int data[], int n);

time_t t1, t2;
long int waktukomputasi;

int main(){
	int i, n = 20000;
	int data[n];
	
	for(i=0; i<n; i++){
		data[i] = rand();
	}
	
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
//		tampil(data, n);
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
