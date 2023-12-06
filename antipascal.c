#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int factorial(int x);
//int checkPascal(int x[][][]);
void makePascal(int n, int x, int z[][n][factorial(n)]);

int main() {
  
  setlocale(LC_ALL, "Turkish");
  
  int num;
  printf("Lütfen bir sayı giriniz: ");
  scanf("%d", &num);
  
  int n=num;
  int max_value=(n*(n+1))/2;
  
  int antp[n][n];
  int allArrs[n][n][factorial(n)];
  
  int i;
  int values[max_value];
  
  for (i=0; i<max_value; i++) {
	  values[i] = i+1;
  }
  
  makePascal(n, factorial(n), allArrs);
  
  int j;
  int k;
  int l;
  int facn = factorial(n);
  
  for (l=0; l<facn; l++) {
	  printf("%d. Antipascal Üçgeni \n", l+1);
	  for (j=0; j<n; j++) {
		  for (k=0; k<j+1; k++) {
			  printf("%d ", (int)allArrs[j][k][l]);
		  }
		  printf("\n");
	  }
  }
  
  system("pause");
  return 0;
} 

int factorial(int x) {
	int i;
	int j=1;
	for (i=x; i>0; i--) {
		j *= i;
	}
	return j;
}

void makePascal(int n, int x, int z[][n][factorial(n)]) { // x tekrarlama, z butun antipascal ucgenleri, n sabit.
	int i, j, k;
	double random;
	int gauss=n*(n+1)/2;
	int put;
	for (i=0; i<x; i++) {
		for (j=0; j<n; j++) {
			for (k=0; k<j+1; k++) {
			    random = (double)((rand()%(gauss+1))+1);
				put = (int)random;
				z[j][k][i]= put;
				int m, f;
				for (m=0; m<n; m++) {
					for (f=0; f<m+1; f++) {
						while ((z[j][k][i] == (int)z[m][f][i] && !(m==j && f==k)) || z[j][k][i] > gauss) {
						    random = (double)((rand()%(gauss+1))+1);
							put = (int)random;
							z[j][k][i]= put;
						}
					}
				}
			}
		}
		if (i>0) {
			int counter, p, r;
			int s = 0;
			for (p=0; p<n; p++) {
				for (r=0; r<p+1; r++) {
					while (s<i) {
						if (z[p][r][i]==z[p][r][i-s+1]) {
							counter++;
						}
						s++;
					}
				}
			}
			if (counter/s == n*(n+1)/2) {
				i=0;
			}
		}
	}
}
