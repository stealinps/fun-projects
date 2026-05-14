#include <iostream>
#include <cstring>
class Stack
{
	public:
	Stack(int StackSize);
	~Stack(); 
	void Push(char Value);
	char Pop();
	char Top();
	void Clear();
	void Display();

	private:
	char *Array;
	int CurrentPosition;
	int MaxCapacity;
};

Stack::Stack(int StackSize)
{
	Array=new char[StackSize];
	MaxCapacity=StackSize;
	CurrentPosition=-1;
}

Stack::~Stack()
{
	delete [] Array;
}

void Stack::Push(char value)
{
	if(CurrentPosition<MaxCapacity-1){
		CurrentPosition=CurrentPosition+1;
		Array[CurrentPosition]=value;
	}
	else
		std::cout<<"Stack Overflow!!\n";
}

char Stack::Pop()
{
	char Result;
	if(CurrentPosition>=0){
		Result=Array[CurrentPosition];
		CurrentPosition--;
		return Result;
	}
	else
	{
		std::cout<<"Stack Underflow\n";
		return -1;
	}
}

char Stack::Top()
{
	if(CurrentPosition>=0)
	{
		int Result=Array[CurrentPosition];
		return Result;
	}
	else
		std::cout<<"Stack Underflow\n";
	return -1;
}
void Stack::Clear()
{
	CurrentPosition=-1;
}
void Stack::Display()
{
	int i;
	std::cout<<"Display of Stack\n";
	for(i=0;i<CurrentPosition+1;i++){
		std::cout<<Array[i]<<std::endl;
	}
}
const int size=99;
int main(){
	Stack A(99);
	char word[size];
	int len;
	std::cout<<"Enter a word up to 99 characters:";
	std::cin>>word;
	int i;
	len = strlen(word);
	for(i=0;i<len;i++){
		A.Push(word[i]);
	}
	for(i=0;i<len;i++){
		std::cout<<A.Pop();
	}
}
