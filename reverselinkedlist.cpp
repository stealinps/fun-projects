#include <iostream>
#include <String>

struct linkedlist {
	char val;
	int index;
	linkedlist *next;
};
using list=linkedlist*; //renaming linkedlist* to list abstracting away the * (bad practice) however for this because i lazy to write alot i do it

class LIST{
	public:
		LIST();
		~LIST();
		void Display(); //to display duh
		void Search(char val); //searching through the nodes without mutating the list
		void Insert(char val); //insert at the head/front
		void Remove(char val); //remove the value specified might need to use search algorithm
	private:
		list head; //each linkedlist need to store the address of the first item
};

LIST::LIST(){
	head=NULL; //create a node that point to null indicating the end of the list
}

LIST::~LIST(){
	list temp;
	while(head){ //while current node exist
		temp=(*head).next; //save the address of the next node
		delete head; //delete current node
		head=temp; //change current node to the next node
	}
}

void LIST::Display(){
	list temp=head; //create a new temp node with the address of head
	while(temp){ //if temp exist, if head=null then it no longer exist, look at destructor
		std::cout<<(*temp).val; //print
		temp=(*temp).next; //move temp to next node
	}
}

void LIST::Search(char val){
	list temp=head;
	while(temp){
		if((*temp).val==val) std::cout<<(*temp).index;
		temp=(*temp).next;
	} //search the whole list>if val detected>print the location/index
}

void LIST::Insert(char val){
	list temp=new linkedlist; // allocate more memory to the list
	(*temp).val=val; // assign value of the temp
	(*temp).next=head; // put temp at the "left" of the list
	head=temp; //change head to the temp
	list temp2=head;
	for(int i=0;temp2;i++){
		(*temp2).index=i;
		temp2=(*temp2).next;
	} //reassigning the index
}

void LIST::Remove(char val){
	list Curr=head;
	list Prev=NULL;
	while(Curr){
		if((*Curr).val==val){
			if(Prev==NULL)
				head=(*Curr).next; //move head to 2nd node then delete the first node
			else
				(*Prev).next=(*Curr).next; //assign next pointer of previous node to the next node bypassing current
			delete Curr;
			return;
	}
	else{
		Prev=Curr;
		Curr=(*Curr).next; //traversing
	}
	}
}
int main(){
	std::cout<<"Reversing a word:";
	std::string word;
	std::cin>>word;
	LIST word2reverse;
	for(int i=0;i<word.length();i++){
		word2reverse.Insert(word[i]);
	}
	word2reverse.Display();
}
