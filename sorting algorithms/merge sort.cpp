#include<iostream>
using namespace std;
void merge(int A[],int p, int q, int r){
	int n1=q-p+1;
	int n2=r-q;
	int L[n1+1];
	int R[n2+1];
	for(int i=0;i<n1;i++){
		L[i]=A[p+i];
	}
	for(int j=0;j<n2;j++){
		R[j]=A[q+j+1];
	}
	int inf=10000000;
	L[n1]=inf;
	R[n1]=inf;
	int i=0;
	int j=0;
	for(int k=p;k<=r;k++){
		if(L[i]<=R[j]){
			A[k]=L[i];
			i=i+1;
		} else {
			A[k]=R[j];
			j=j+1;
		}
	}
	
}
void mergesort(int A[], int p, int r){
	if(p<r){
		int q=(p+r)/2;
		mergesort(A,p,q);
		mergesort(A,q+1,r);
		merge(A,p,q,r);
	}
	
}
int main(){
	int n;
	cout<<"Enter the no. of digits -> ";
	cin>>n;
	int a[n];
	cout<<"Enter the nos."<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int p=0;
	int q=3;
	int r=n-1;
	mergesort(a,p,r);
	for(int m=0;m<=r;m++){
		cout<<a[m]<<" ";
	}
	cout<<endl;
}
