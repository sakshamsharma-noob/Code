#include <bits/stdc++.h>
using namesapce std;

int jos(int n, int k){
	if(n==1)
		return 0;
	return (jos(n-1,k)+k)%n;
}

int main(){
	jos(5,3);	
	return 0;
}