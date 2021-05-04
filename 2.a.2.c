#include <stdio.h>
#include <stdlib.h>

void tampil(int data[], int n);

int ascDesc = 1;
int orderBy = 2;
int C = 0, M = 0, S = 0;

int main(){
	int n = 10;
	int data[] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
//	int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	int data[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	
	printf("\n");
	printf("%-25s", "Data awal array"); printf(": ");
	tampil(data, n);
	printf("\n");
	bubble(data, n);
	printf("\n");
	printf("%-25s", "Data terurut array"); printf(": ");
	tampil(data, n);
	
	printf("%-25s", "Data C"); printf(": %d\n", C);
	printf("%-25s", "Data M"); printf(": %d\n", M);
	printf("%-25s", "Data S"); printf(": %d\n", S);
}

int bubble(int data[], int n){
	
	int i, j, kondisi = 0, flag = 1, akhir = n-2;

	for(i=0; i<=n-2; i++){
		flag = 0;
		for(j=0; j<=akhir; j++){
			C++;
			if(data[j] > data[j+1]){
				M = M + 3;
				S++;
				tukar(&data[j], &data[j+1]);
				flag = 1;
			}
//			if(akhir == j)
//				break;
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
