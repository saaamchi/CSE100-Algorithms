#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
using namespace std; 

class Tree {
	struct Node {
		
		Node* lChild;
		Node* rChild;
		Node* parent;
		int value;

	};
	
	public:
		Tree();

		//void Print(Node * binaryTree, int key);
		void Insert(Node * binaryTree, int key);

		void Delete(Node * binaryTree, int key);
		
		void printPost(Node *current);
		
		void printInorder(Node *current);
		
		void printPreorder(Node *current);
		
		Node* getRoot();


	private: 

		Node* root;

		Node *Min(Node *current);
		
		Node *Max(Node *current);
		
		Node *Search(Node* head, int val);
		
		Node *Successor(Node *current);

		void Transplant(Node *u, Node *v);
		
/*
		//setters and getters for the different aspects of the tree
		void setRoot(int root){
			this->root = root;
		}

		int getRoot(){
			return root;
		}
		void setParent(int parent){
			this->parent = parent;
		}
		int getParent(){
			return parent;
		}

		void setRight(int right){
			this->rightChild = right;

		}
		int getRight(){
			return rightChild;
		}

		void setLeft(int left){
			this->leftChild = left;

		}

		int getLeft(){
			return leftChild;
		}
		*/
};

Tree::Tree(){
	this->root = NULL; // initialize root to NULL
}

Tree::Node *Tree::Min(Node *x){
	Node* temp = x;
	while(temp != x){
		temp = temp->lChild;
	}
	return temp;
}

Tree::Node *Tree:: Max(Node *x){
	while(x->rChild != NULL){
		x = x->rChild;
	}
return x;
}

Tree::Node* Tree::Successor(Node *x){
	Node * y;
	if (x->rChild ==NULL)
	{
		return Min(x->rChild);
	}
	y = x-> parent;
	while(y !=NULL && x == y->rChild){
		x=y;
		y=y->parent;
	}
	return y;
}
void Tree::printInorder (Node* x){
	if (x != NULL){
		printInorder(x->lChild);
		cout<< x->value<<endl;
		printInorder(x->rChild);
	}
}

void Tree::printPost (Node* x){
	if (x != NULL){
		printPost(x->lChild);
		printPost(x->rChild);
		cout<< x->value<<endl;
	}
}

void Tree::printPreorder(Node* x){
	if (x != NULL){
		cout<< x->value<<endl;
		printPreorder(x->lChild);
		
		printPreorder(x->rChild);
	}
}

void Tree::Transplant(Node *u, Node*v){
	if(v != NULL){
		v->parent = u->parent;
	}
	if(u->parent == NULL){
		this->root = v;
	}
	else if (u == u->parent->lChild) {
		u->parent->lChild = v;
	}

	else {
		u->parent->rChild = v;
	}	

	
 }
//pg294 of book 
void Tree::Insert (Node * binaryTree, int key){
	// trailing pointer y as the parent on x
	Node *x = this->root;
	Node *y = NULL;

	Node *z = new Node;
	x = root;
	z->lChild = NULL;
	z->rChild= NULL;
	z->parent = NULL;
	z->value = key;
	

	while(x != NULL){
		y = x;
		if (z->value < x->value){
			x = x-> lChild;
		}
		else{
			x = x-> rChild;
		} 
	}
	z->parent = y;
	 if(y==NULL)

	 	root = z;

	 else if (key < y->value)
	 	y->lChild = z;
	 
	 else y->rChild = z;
}

//pg 298 of book 
void Tree::Delete(Node* binaryTree, int key){
	Node* z = Search(this->root, key);

	if(z != NULL){
		if(z->lChild == NULL){
			Transplant(z, z->rChild);
		}
		else if (z->rChild == NULL){
			Transplant(z, z->lChild);
		}
		else {
			Node *y = Min(z->rChild);
			if(y->parent != z){
				Transplant(y, y->rChild);
				y->rChild = z->rChild;
				y->rChild->parent = y;
			}
			Transplant(z,y);
			y->lChild = z->lChild;
			//y->left = z->lChild;
			y->lChild->parent = y;
		}	
	}
}

Tree::Node* Tree::getRoot() {
	return this->root;
}
//used for the delete function 
Tree::Node* Tree::Search(Node* head, int val) {
	if(head == NULL || head->value == val) {
		return head;
	}
	if(val < head->value)
		return Search(head->lChild, val);
	else 
		return Search(head->rChild, val);
}






int main(){
	int key = 0;

	char action [6];
	cin>> action;

	//cin >> command;

	Tree* binaryTree = new Tree();

//strcmp works better than the other ways that were used in past labs 
while(strcmp(action, "e") != 0)
{
	if(strcmp(action, "i") == 0){
		cin >> key;
		binaryTree->Insert(binaryTree->getRoot(),key);
	}
	if (strcmp(action, "d") == 0){
		cin >> key;
		binaryTree->Delete(binaryTree->getRoot(),key);
	}
	if(strcmp(action, "pre") == 0){
		binaryTree->printPreorder(binaryTree->getRoot());
		cout << "++++++++++++++++++++" << endl;

	}
	if (strcmp(action, "post") == 0){
		binaryTree->printPost(binaryTree->getRoot());
		cout << "++++++++++++++++++++" << endl;
	}

	if(strcmp(action, "in") == 0)
	{
		binaryTree->printInorder(binaryTree->getRoot());
		cout << "++++++++++++++++++++" << endl;
	}
	if (strcmp(action, "e") == 0){
		break;
	}

	cin >> action;
}
	return 0;
}

/*
	// Make a class called binaryTree that makes the tree
	Tree* binaryTree = new Tree();

	while(key != "in"){
		cin >> key;

		if(key == "i"){
			cin >> num;
			binaryTree->Insert(binaryTree->getRoot(),num);
		}

		if(key == "d"){
			//cin >> num;
			binaryTree->Delete(binaryTree->getRoot(),key);

		}
		if(key == "pre"){
			//cin >> num;
			binaryTree->printPreorder(binaryTree->getRoot());
		}

		if(key == "post"){
			//cin >> num;
			binaryTree->printPost(binaryTree->getRoot());
		}
		if(key == "in"){
			binaryTree->printInorder(binaryTree->getRoot());
		}
	}
	*/
	
//return 0;
	

