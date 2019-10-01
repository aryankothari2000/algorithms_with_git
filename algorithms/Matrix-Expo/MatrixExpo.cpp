#include<iostream>
#include<cstring>

using namespace std;

void mulMatrix(int a[][20],int b[][20],int n){
	int c[20][20];
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			c[i][j]=0;
			for(int k=0;k<n;++k){
				c[i][j]+=(a[i][k]*b[k][j]);
			}
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)
			a[i][j]=c[i][j];
	}
}

void MatExpo(int a[][20],int n,int p){
	int res[20][20];
	memset(res,0,sizeof res);
	for (int i = 0; i < n; ++i)
	{
		res[i][i]=1;
	}

	while(p>0){
		if(p&1)
			mulMatrix(res,a,n);
		mulMatrix(a,a,n);
		p>>=1;
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)
			a[i][j]=res[i][j];
	}
}

int32_t main(){
	int a[20][20],n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)
			cin>>a[i][j];
	}
	MatExpo(a,n,m);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)
			cout<<a[i][j]<<" ";
		cout<<'\n';
	}
	// cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
	return 0;
}