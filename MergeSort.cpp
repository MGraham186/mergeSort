

#include <iostream>
using namespace std;
#include <cmath>
#include <math.h>
void displayArray(int x[], int n);
void merge(int A[], int l, int m, int r);
void mergeSort(int A[], int p, int r);


int main() {
	//int x[] = {5,3,2,5,1,6,3,6,2,3,5,5123,1,3,989,1,1,5,2,3,3,15,1,13,123,5123,512,3512,36,1236,1236,123,12351};
	int x[] = {5,3,2,5,1,6,3,6,2,3,5,5123,1,3,989,1,1,5,2,3,3,15,1,13,123,5123,512,3512,36,1236,1236,123,12351,4};
	//int x[] = {1,3,5,2,4};
	int n = sizeof(x)/sizeof(x[0])-1;
	mergeSort(x,0,n);
	displayArray(x,n+1);
}

void displayArray(int x[], int n){
	for(int i = 0; i<n ; i++)
		cout<<x[i]<<" ";
	cout<<endl;
}
void mergeSort(int A[], int p, int r){
	if(p<r){
		int q = (p+r)/2;
		mergeSort(A,p,q);
		mergeSort(A,q+1,r);
		merge(A,p,q,r);
	}
}


void merge(int A[], int p, int q, int r){

	int n1 = q-p+1; int n2 = r-q;

	int L[n1], R[n2];

	for(int i = 0; i<n1; i++)
		L[i] = A[p+i];

	for(int i = 0; i<n2; i++)
		R[i] = A[q+i+1];

	int i = 0, j=0, k = p;

	while(i < n1 and j < n2){

		if(L[i]<=R[j]){
			A[k] = L[i]; i++; k++;
		}else{
			A[k] = R[j]; j++; k++;
		}

	}
	while(i < n1){
		A[k] = L[i];i++; k++;
	}
	while(j < n2){
		A[k] = R[j]; j++; k++;
	}

}
