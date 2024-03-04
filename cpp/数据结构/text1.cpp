#include<iostream>
using namespace std;

int main(){
	int n;
	int i,j;
	int num=1;
	
	cin>>n;
 
	int a[n][n];
	int start=0,end=n-1;
	int k=n;
 
	while(num<=k*k){
			for(j=start;j<n;j++){
				a[start][j]=num;
				num++;
			}					
			for(i=start+1;i<n;i++){	
				a[i][end]=num;
				num++;
			}		
			for(j=end-1;j>=start;j--){
				a[end][j]=num;	
				num++;
			}
			for(i=end-1;i>=start+1;i--){
				a[i][start]=num;
				num++;
			}
		start++;end--;n--; 	
		}
 
 
	for (i=0;i<k;i++){
		for(j=0;j<k;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

