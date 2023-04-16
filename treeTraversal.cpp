#include<iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct node {
	int data;
	struct node *left, *right;
};
struct node* newNode(int item)
{
	struct node* temp= (struct node*)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d->", root->data);
		inorder(root->right);
	}
}
void preorder(struct node* root){
	if(root!=NULL){
		cout<<root->data<<"->";
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node* root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<"->";
	}
}
struct node* insert(struct node* node, int data)
{
	if (node == NULL)
		return newNode(data);

	if (data < node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);

	return node;
}

int main()
{
	struct node* root = NULL;
	int x,y,z=0,t;
	cout<<"Enter Root Node Value-:";
	cin>>t;
	root = insert(root, t);
	while(z!=9){
		cout<<"........................Tree Traversal Program..................................\n1.Insertion\n2.Display Before Traversal\n3.Inorder Traversal\n4.PreOrder Traversal\n5.PostOrder Traversal\n9.Exit\nEnter Your Choice-:";
		cin>>z;
		switch(z){
			case 1:
				cout<<"Enter Data-:";
				cin>>x;
				insert(root, x);
				break;
				case 2:
					break;
					case 3:
						inorder(root);
						break;
						case 4:
							preorder(root);
							break;
							case 5:
								postorder(root);
								break;
						case 9:
							exit(0);
							break;
							default:
								cout<<"\nYour Choice Is wrong....Please Enter Right Choice....\n";
								break;
						
				
		}
    } 

	return 0;
}