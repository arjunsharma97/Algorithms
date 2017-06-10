#include<iostream>
using namespace std;
int partition (int A[], int p, int r){
	int x=A[r];
	int temp;
	int i=p-1;
	for(int j=p;j<r;j++){
		if(A[j]>=x){
			i=i+1;
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
		}
	}
	temp=A[i+1];
	A[i+1]=A[r];
	A[r]=temp;
	return i+1;
}
int* quicksort(int A[],int p,int r){
	if(p<r){
		int q=partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
	return A;
	
}
int main(){
	int n;
	int res;
	cout<<"Enter the no. of digits -> ";
	cin>>n;
	int a[n];
	cout<<"Enter the nos."<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int p=0;
	int r=n-1;
	int *c;
	c=quicksort(a,p,r);
	for(int m=0;m<=r;m++){
		cout<<c[m]<<" ";
	}
	cout<<endl;
}
