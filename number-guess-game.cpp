#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

int aiAttempt(int lastAttempt,bool bigger,int upper, int lower){
	int mid;
	if(!bigger){
		mid=(upper+lastAttempt)/2;
	}
	else{
		mid=(lastAttempt+lower)/2;
	}
	if(mid <= lower) mid = lower + 1;
	if(mid >= upper) mid = upper - 1;
	return mid;
}

int main(){
	srand(time(NULL));
	int dif;
	std::cout<<"Please enter difficulty>0 ";
	std::cin>>dif;
	if(dif<0) return 0;
	dif=std::pow(10,dif);
	int n=std::rand()%dif;


	int attempt=1;
	int m=dif/2;
	int upper=dif;
		int lower=0;
		while(m!=n){	
			bool bigger;
			if(m > n) {upper = m; bigger=true;}
			else {lower = m; bigger=false;}
			m=aiAttempt(m,bigger,upper,lower);
			++attempt;
			std::cout<<"AI attempt:"<<attempt<<"\n";
	}
	int aiattempt=attempt;

	m=-1;
	attempt=0;
	upper=dif;
	lower=0;
	std::cout<<"Upper:"<<upper<<" Lower:"<<lower<<"\n";
	std::cout<<"Please enter guess:";
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
		std::cout<<"----------------------------------------\n";
		if(m > n) upper = m;
		else lower = m;
		std::cout<<"Upper:"<<upper<<" Lower:"<<lower<<"\n";
		std::cout<<"Please enter guesses :";
		std::cin>>m;
		attempt++;
		std::cout<<"Attempt :"<<attempt<<std::endl;
	}
	std::cout<<"\nYou are correct!!!\n";
	
	if(aiattempt<attempt) std::cout<<"\nAI win!";
	else if(aiattempt>attempt) std::cout<<"\nYou win!";
	else std::cout<<"\nTie!";

}
