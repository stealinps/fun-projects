#include <iostream>
#include <string>
struct tree{
	int val;
	tree *right;
	tree *left;
};
class Tree{
	public:
		Tree();
		~Tree();
		void Insert(int Val);
		std::string Search(int Val);
		void Display();
		void Remove(std::string path);
	private:
		tree *root;
		void InsertNode(tree* &root,int Val);
		void SearchTree(tree* root,int Val,std::string *dir);
		void DisplayTree(tree* root);
		void DeleteTree(tree* &root);
};
Tree::Tree(){
	root=NULL;
}
Tree::~Tree(){
	std::cout<<"Deleting the tree \n";
	DeleteTree(root);
}
void Tree::DeleteTree(tree* &root){
	if(root!=NULL){
		DeleteTree((*root).left);
		DeleteTree((*root).right);
		delete root;
		std::cout<<"Node deleted\n";
	}
}
void Tree::Insert(int val){
	InsertNode(root,val);
}
void Tree::InsertNode(tree* &root,int val){
	if(root==NULL){
		root=new tree;
		(*root).val=val;
		(*root).left=NULL;
		(*root).right=NULL;
		return;
	} //insert val only when current node is empty
	if(val==(*root).val) return;
	else if(val<(*root).val) InsertNode((*root).left,val); //go to left
	else InsertNode((*root).right,val); //go to right
}
std::string Tree::Search(int val){
	std::string dir="H";
	SearchTree(root,val,&dir);
	return dir;
}

void Tree::SearchTree(tree* root,int val,std::string *dir){
	if(root==NULL){
		std::cout<<"Value not found\n";
		*dir="Invalid\n";
		return;
	}
	else if(val==(*root).val) {
		std::cout<<"Found\n";
		return;
	}
	else if(val<(*root).val) {
		*dir+="0";
		SearchTree((*root).left,val,dir);}
	else {
		*dir+="1";
		SearchTree((*root).right,val,dir);
	}
	return;
}

void Tree::Remove(std::string path) {
	std::cout << "Removing element along path: " << path << "\n";
	if (root == NULL || path.empty() || path == "Invalid") return;
	tree* parent = NULL;
	tree* curr = root;
	for (size_t i = 0; i < path.length(); i++) {
		if (path[i] == 'H') {
		curr = root;
	} 
	else if (path[i] == '0') {
		if (curr) { 
			parent = curr; curr = (*curr).left; }
	}
	else if (path[i] == '1') {
		if (curr) { 
			parent = curr; curr = (*curr).right; }
	}
}
	if (curr == NULL) {
		std::cout << "Node not found at this path.\n";
		return;
	}
	if (parent == NULL) {
		root = NULL; 
	}
	else if (parent->left == curr) {
	parent->left = NULL;
	}
	else if (parent->right == curr) {
	parent->right = NULL;
	}
	DeleteTree(curr); 
	std::cout << "Element removed successfully.\n";
}

void Tree::Display(){
	std::cout<<"[";
	DisplayTree(root);
	std::cout<<"]\n";
}

void Tree::DisplayTree(tree* root){
	if(root==NULL){
		return;
	}
	else {
		DisplayTree((*root).left);
		std::cout<<(*root).val<<" ";
		DisplayTree((*root).right);
	}

}

int main(){
	std::cout<<"Hello\n";
	Tree A;
	A.Insert(10);
	A.Insert(20);
	A.Insert(5);
	A.Insert(4);
	A.Insert(50);
	A.Display();
	std::cout<<A.Search(4);
	A.Remove(A.Search(4));
	A.Display();
	std::cout<<A.Search(20);
	A.Remove(A.Search(20));
	A.Display();
}
