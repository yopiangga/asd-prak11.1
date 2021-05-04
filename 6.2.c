#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 20000

void tampil(int data[]);
void menu(int data[]);
void alokasi(int data2[], int n);

int ascDesc = 0;
int orderBy = 0;

int n;
int pilihan;

time_t t1, t2;
long int waktukomputasi;

int main(){
	int data[MAX], data2[MAX];
	
	printf("%-25s", "Jumlah data "); printf(": ");
	scanf("%d", &n);
	fflush(stdin);
	
	srand(time(NULL));
	alokasi(data2, n);
	
	tampil(data2);
	
	do {
		copyData(data2, data);
		menu(data);
	} while(pilihan != 5);
	
}

void menu(int data[]){
	printf("========================\n");
	printf(" MENU METODE SORTING\n");
	printf("========================\n");
	printf("1. Insertion Sort\n");
	printf("2. Selection Sort\n");
	printf("3. Bubble Sort\n");
	printf("4. Shell Sort\n");
	printf("5. Keluar\n");
	printf("%-25s", "Pilih Menu"); printf(": ");
	scanf("%d", &pilihan);
	fflush(stdin);
	
	if(pilihan == 5)
		exit(0);
		
	modeUrut();
		
	switch(pilihan){
		case 1:
			time(&t1);
			insertion(data);
			time(&t2);
			waktukomputasi= difftime(t2,t1);
			break;
		case 2:
			time(&t1);
			selection(data);
			time(&t2);
			waktukomputasi= difftime(t2,t1);
			break;
		case 3:
			time(&t1);
			bubble(data);
			time(&t2);
			waktukomputasi= difftime(t2,t1);
			break;
		case 4:
			time(&t1);
			shell(data);
			time(&t2);
			waktukomputasi= difftime(t2,t1);
			break;
	}
	
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

int copyData(int data2[], int data[]){
	int i;
	
	for(i=0; i<n; i++)
		data[i] = data2[i];
}

void alokasi(int data2[], int n){
	int i;
	
	for(i=0; i<n; i++){
		data2[i] = rand()/1000;
	}
}

int insertion(int data[]){
	
	int i, j, kondisi = 0;
	int key;
	
	for(i=1; i<n; i++){
		key = data[i];
		j = i - 1;
		while(j >= 0){
			if(ascDesc == 1)
				kondisi = data[j] > key;	
			else if(ascDesc == 2)
				kondisi = data[j] < key;
				
			if(kondisi){
				data[j+1] = data[j];
				j = j - 1;
			} else {
				break;	
			}
		}
		data[j+1] = key;
	}
}

int selection(int data[]){
	
	int i,j, x, kondisi = 0;
    for(i=0; i<n-1; i++){
        x = i;
        for(j = i+1; j<n; j++){
        	if(ascDesc == 1)
				kondisi = data[j] < data[x];	
			else if(ascDesc == 2)
				kondisi = data[j] > data[x];

        	if(kondisi){
        		x = j;
			}
		}
        tukar(&data[i], &data[x]);
    }
	
}

int bubble(int data[]){
	
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
	}
}

int shell(int data[]){
	
	int i, j, y,  kondisi = 0, flag;
	int key;
	
	for(y=n/2; y>=1; y=y/2){
		flag = 1;
		while(flag == 1){
			flag = 0; 
			for(i=0; i<n-y; i++){
				if(ascDesc == 1)
					kondisi = data[i] > data[i+y];
				else if(ascDesc == 2)
					kondisi = data[i] < data[i+y];
					
				if(kondisi){
					tukar(&data[i], &data[i+y]);
					flag = 1;
				}
			}
		}
	}
}

int tukar(int *a, int *b){
	int temp;
	
    temp = *a;
    *a = *b;
    *b = temp;
}

void tampil(int data[]){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}
