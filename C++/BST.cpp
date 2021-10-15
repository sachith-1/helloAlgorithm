#include<iostream>
#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct Node{
	Node* left;
	Node* right;
	int data;
};

Node* addNewNode(int x){
Node* temp = new Node();
temp -> data = x;
temp -> left = temp -> right = NULL;
return temp;
}

//Insertion
Node* Insert( Node* root,int x){
if(root==NULL){
	root = addNewNode(x);
}
else{
	if(x<=root->data){
		root -> left = Insert(root->left,x);
}
	if(x>=root->data){
	
	root -> right = Insert(root -> right,x);
}
}
return root;
}

//Searching
bool search(Node* root,int x){
	if(root==NULL){
		return false;
	}
	else if(x == root->data){
		return true;
	}
	else if(x<root->data){
		return search(root->left,x);
	}
	else if(x>root->data){
		return search(root->right,x);
	}
}

//Finding Maximum Value
int findMax(Node* root){
	if(root->right==NULL){
		return root->data;
	}
	return findMax(root->right);
}

//Finding Minimum Value
int findMin(Node* root){
	if(root->left==NULL){
		return root->data;
	}
	return findMin(root->left);
}

//Finding height of the BST
int findHeight(Node* root){
	if(root==NULL){
		return -1;
	}
	int lh = findHeight(root->left);
	int rh = findHeight(root->right);
	return max(lh,rh)+1;
}

//Pre-Order Traversal
void preOrderTraversal(Node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

//In-order Traversal
void inOrderTraversal(Node* root){
	if(root==NULL){
		return;
	}
	inOrderTraversal(root->left);
	cout<<root->data<<" ";
	inOrderTraversal(root->right);
}

//Post-Order Traversal
void postOrderTraversal(Node* root){
	if(root==NULL){
		return;
	}
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout<<root->data<<" ";
}

//Level Order Traversal
void levelOrderTraversal(Node* root){
	queue<Node*> q;
	q.push(root);
	while(q.size()!=0){
		cout<<q.front()->data<<" ";
		if(q.front()->left){
			q.push(q.front()->left);
		}
		if(q.front()->right){
			q.push(q.front()->right);
		}
		q.pop();
	}
}

//Utility Function
bool isUtil(Node* root,int maxValue,int minValue){
	if(root==NULL){
		return true;
	}
	if(root->data<=maxValue && root->data>minValue
	&& isUtil(root->left,root->data,minValue)&& isUtil(root->right,maxValue,root->data)){
		return true;
	}
	else{
		return false;
	}

}
//Checking whether a Binary tree is a BST
bool isBST(Node* root){
	return isUtil(root,INT_MAX,INT_MIN);
}

//Deleting a Node
Node* Delete(Node* root,int x){
	if(root==NULL) {
		return root;
	}
	else if(x<root->data){ 
		root->left = Delete(root->left,x);
	}
	else if(x>root->data) {
		root->right = Delete(root->right,x);
	}
	else{
		//case 1 (if it is a leaf node)
		if(root->left==NULL && root->right==NULL){
			delete(root);
			root=NULL;
		}
		//case 2 (if node has only one subtree)
		else if(root->left==NULL){
			Node* temp=root;
			root=root->right;
			delete(temp);
		}
		else if(root->right==NULL){
			Node* temp = root;
			root=root->left;
			delete(temp);
		}

		//case 3 if node has two subtrees
		else{
			int data = findMin(root->right);
			root->data = data;
			root->right = Delete(root->right,data);
		}
	}
	return root;
}

//Driver Code
int main(){
	Node* root=NULL;
	root = Insert(root,10);
	root = Insert(root,15);
	root = Insert(root,5);
	root = Insert(root,20);
	root = Insert(root,17);
	root = Insert(root,12);
	root = Insert(root,25);
	cout<<search(root,10)<<endl;
	cout<<search(root,25)<<endl;
	cout<<"Min : "<<findMin(root)<<endl;
	cout<<"Max : "<<findMax(root)<<endl;
	cout<<"Height : "<<findHeight(root)<<endl;
	cout<<"pre-order : ";
	preOrderTraversal(root);
	cout<<endl;
	cout<<"in-order : ";
	inOrderTraversal(root);
	cout<<endl;
	cout<<"post-order : ";
	postOrderTraversal(root);
	cout<<endl;
	cout<<"level order : ";
	levelOrderTraversal(root);
	cout<<endl;
	cout<<"isBST : ";
	cout<<isBST(root)<<endl;
	cout<<"Delete a node : ";
	root = Delete(root,15);
	inOrderTraversal(root);
}
