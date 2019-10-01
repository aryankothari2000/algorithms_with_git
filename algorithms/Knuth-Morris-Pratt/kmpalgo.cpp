//KMP Algo
#include<iostream>
#include<string>
using namespace std;

int main(){
	string s,str;
	cin>>s>>str;
	long sz=s.length(),cnt=0;
	long a[sz];
	a[0]=0;
	long l=0,r=1;
	while(r<sz){
		if(s[l]==s[r]){
			a[r++]=++l;
			
		}
		else if(l==0){
			a[r++]=l;
		}
		else
			l=a[l-1];
	}
	l=0;r=0;
	while(l<str.length()){
		if(str[l]==s[r]){
			l++;r++;
		}
		if(r==sz){
			cnt++;
			r=a[r-1];
		}
		else if(l<str.length() && str[l]!=s[r]){
			if(r==0)
				l++;
			else
				r=a[r-1];
		}
	}
	cout<<cnt;
	// cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
	return 0;
}