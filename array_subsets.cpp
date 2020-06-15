#include<iostream>
using namespace std;

int subset(int input[],int l,int output[][20]){
	
	if( l==0 )
	{
	output[0][0]=1;
	return 1;	
	}	
	int size = subset(input+1,l-1,output);
	int i,j;
	for(i=1;i<size;i++)
	{
		for(j=1;j<=output[i][0];j++)
		output[i+size][j+1]=output[i][j];
		output[i+size][0]=output[i][0]+1;
		output[i+size][1]=input[0];
	}
	output[size][0]=1;
	output[size][1]=input[0];
	return 2*size;
}

int main(){
 int input[20],length, output[1000][20];
  cout<<"Input array length : "<<endl;
  cin >> length;
  cout<<"Input array elements : "<<endl;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);
	cout<<"Possible Array subsets with their size are : \n";
  for( int i = 0; i < size; i++) { 
	for( int j = 0; j <= output[i][0]; j++)  
		cout << output[i][j] << " ";
    
    cout << endl;
}
	return 0;
}
