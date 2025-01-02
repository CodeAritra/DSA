#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

 node* createNode(int val){
	struct node* newnode = ( node*)malloc(sizeof( node));
	newnode->data = val;
	newnode->left = newnode->right = NULL;
	return newnode;
}

 node* insert( node* root,int data){
	if(root == NULL)
		root = createNode(data);
	if(data < root->data){
		root->left = insert(root->left,data);
	}
	else  if(data > root->data){
		root->right = insert(root->right,data);
	}
	return root;
}

void inorder( node* root){
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void preorder( node* root){
	if(root == NULL)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder( node* root){
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);	
}

int main(){
	 node* root = NULL;
	int ch,val,x=1;
	while(x){
		printf("\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the value to insert : ");
				scanf("%d",&val);
				root = insert(root,val);
				break;
			case 2:
				printf("Inorder traversal : \n");
				inorder(root);
				break;
			case 3:
				printf("Preorder traversal : \n");
				preorder(root);
				break;
			case 4:
				printf("Postorder traversal : \n");
				postorder(root);
				break;
			default:
				printf("Wrong input");
		}
	}
}