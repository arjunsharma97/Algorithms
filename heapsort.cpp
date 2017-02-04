#include<iostream>
using namespace std;
void maxheapify(int A[],int i,int size){
	int l=2*i+1;
	int r=2*i+2;
	int largest;
	if(l<size && A[l]>A[i]){
		largest = l;
	} else {
		largest = i;
	}
	if(r<size && A[r]>A[largest]){
		largest = r;
	}
	if(largest!=i){
		int temp;
		temp=A[largest];
		A[largest]=A[i];
		A[i]=temp;
		maxheapify(A,largest,size);
		
	}
	for(int i=0;i<size;i++){
		cout<<A[i]<<" ";
	}
}
void buildmaxheap(int A[],int size){
	for(int i=0;i<size/2;i++){
		maxheapify(A,(size/2)-i-1,size);
	}
}
void heapsort(int A[],int size){
	buildmaxheap(A,size);	
	for(int i=size-1;i>=0;i--){
		int temp=0;
		temp=A[0];
		A[0]=A[i];
		A[i]=temp;

		maxheapify(A,0,i);
	}
	
}
int main(){
	int n;
	cout<<"Enter the size of the array -> ";
	cin>>n;
	int A[n];
	cout<<"Enter the nos."<<endl;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	heapsort(A,n);
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
}
