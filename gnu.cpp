#include <iostream>

void gnu(int n){
	if(n==1){
		std::cout<<"GNU Not Unix ";
	}
	else {
		gnu(n-1);
		std::cout<<"Not Unix ";
	}
}

int main(){
	std::cout<<"Enter recursion number ";
	int num;
	std::cin>>num;
	std::cout<<"GNU stands for ";
	gnu(num);
}
