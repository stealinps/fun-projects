#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
int main(){
	srand(time(NULL));
	int dif;
	std::cout<<"Please enter difficulty ";
	std::cin>>dif;
	dif=std::pow(10,dif);
	int n=std::rand()%dif;
	int m=-1;
	int attempt=0;
	std::cout<<"Please enter 0=<guesses<"<<dif<<" :";
	std::cin>>m;
	attempt++;
	std::cout<<"Attempt :"<<attempt<<std::endl;

	while(m!=n){
		if(m>n){
			std::cout<<"Guess is bigger than the value \n";
		}
		else{
			std::cout<<"Guess is smaller than the value \n";
		}
		std::cout<<"Please enter guesses :";
		std::cin>>m;
		attempt++;
		std::cout<<"Attempt :"<<attempt<<std::endl;
	}
	std::cout<<"\nYou are correct!!!\n";
}
