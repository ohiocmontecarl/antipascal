#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int getRandom(int x);
int minArr(int x, int y[], int z);
void delElement(int x, int y[], int z);

int main() {
  
  setlocale(LC_ALL, "Turkish");
  
  int num;
  printf("Lütfen bir sayı giriniz: ");
  scanf("%d", &num);
  
  int n=num;
  int max_value=(n*(n+1))/2;
  
  int antp[n][n];
  //int false_antp[n][n][max_value];
  
  int i;
  int values[max_value];
  
  for (i=0; i<max_value; i++) {
	  values[i] = i+1;
  }
  
  int value_size= sizeof(values)/sizeof(values[0]);
  
  int a;
  int b;
  for (a=n; a>0; a--) {
	  for (b=a; b>0; b--){
		  antp[a][b]= getRandom(max_value);
		  while (minArr(antp[a][b], values, value_size) == 1) {
			  antp[a][b]= getRandom(max_value);
		  }
		  delElement(antp[a][b], values, value_size);
	  }
  }
  
  int j;
  int k;
  for (j=0; j<n; j++) {
	  for (k=0; k<=j; k++) {
		  printf("%d", antp[j][k]);
	  }
	  printf("\n");
  }
  
  system("pause");
  return 0;
} 

int getRandom(int x) {
	int y = rand();
	if (y>x || y==0) {
		return x;
	}
	return y;
}

int minArr(int x, int y[], int z) {
	int i;
	for (i=z-1; i>=0; i--) {
		if (y[i]==x) {
			return 1;
		}
	}
	return 0;
}

void delElement(int x, int y[], int z) {
	int i;
	for (i=z-1; i>=0; i--) {
		if (y[i]==x) {
			y[i]=0;
		}
	}
}