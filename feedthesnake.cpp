
#include <iostream>

class Queue{
	public:
		Queue(int QueueSize);
		~Queue();
		void Insert(char Val);
		char Remove();
		char First();
		void Clear();
		void Display();

	private:
		char *Array;
		int Front;
		int Rear;
		int Count;
		int ArraySize;
	};
Queue::Queue(int QueueSize){
	Array=new char[QueueSize];
	ArraySize=QueueSize;
	Front=0;
	Rear=ArraySize-1;
	Count=0;
}
Queue::~Queue(){
	delete []Array;
}
void Queue::Insert(char Val){
	if(Count==ArraySize){
		std::cout<<"Queue is FULL!\n";
		return;
	}
	if(Rear==ArraySize-1)
		Rear=0;
	else
		Rear++;
	Array[Rear]=Val;
	Count++;
}
char Queue::Remove(){
	char Temp;
	if(Count==0){
	std::cout<<"Queue is empty!\n";
		return -1;
	}
	Temp=Array[Front];
	if(Front==ArraySize-1) Front=0;
	else Front++;
	Count--;
	return Temp;
}
char Queue::First(){
	if(Count==0){
		std::cout<<"Queue is empty!\n";
		return -1;
	}
	return Array[Front];
}
void Queue::Clear(){
	Front=0;
	Rear=ArraySize-1;
	Count=0;
}
void Queue::Display(){
    if(Count==0){ std::cout<<"Queue is empty!\n"; return; }
    for(int i=0;i<Count;i++)
        std::cout << Array[(Front+i) % ArraySize] ;
}

int main(){
	std::cout<<"Feed the snake game ";
	Queue snake(999);
	snake.Insert('<');
	char feed='a';
	while(feed!='x'){
		if(feed=='y'){
			snake.Insert('[');
			snake.Insert(']');
			snake.Display();
		}
		else if(feed=='k'){
			std::cout<<"Snake was bombed to death, it gave birth to a new one:";
			snake.Clear();
			snake.Insert('<');
		}
		std::cout<<"\n Enter y to feed/x to exit/k to kill:";
		std::cin>>feed;
	}
}
