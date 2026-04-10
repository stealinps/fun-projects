#include <iostream>
int fib(int n);
int main(){
	int n;
	std::cout<<"Please enter term ";
	std::cin>>n;
	n=fib(n);
	std::cout<<n;
}
int fib(int n) {
	int sum=0;
	int j=0;
        int f[n+1];
        if (n == 1 || n == 0) return n;
        f[0] = 0;
        f[1] = 1; 
        for (int i=2; i<=n; i++) {
            f[i] = f[i-1] + f[i-2];
        }
	for(int i=n-1;i>=0&&j<2;i--){
		if(f[i]%2==0&&n>5){
			sum=sum+f[i];
			j++;
		}
	}
	if(n<=5)
		sum=2;
	return sum;
    }
