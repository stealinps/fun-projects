#include <iostream>
int main(){
	double weight;
	double height;
	double bmi;
	std::string message[]={"Underweight","Normal weight","Overweight","Obesity class I","Obesity class II","Obesity class III"};
	std::string status;
	std::cout<<"height(cm): ";
	std::cin>>height;
	height=height/100;
	std::cout<<"weight(kg): ";
	std::cin>>weight;
	bmi=weight/(height*height);
	std::cout<<"Your BMI is "<<bmi;
	if(bmi<18.5){
		status=message[0];
	}
	else if(bmi<25){
		status=message[1];
	}
	else if(bmi<30){
		status=message[2];
	}
	else if(bmi<35){
		status=message[3];
	}
	else if(bmi<40){
		status=message[4];
	}
	else{
		status=message[5];
	}
	std::cout<<" "<<status;
}
