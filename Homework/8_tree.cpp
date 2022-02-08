#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	node*left,*right;
};

typedef node*tree;

void init(tree &root){
	root=NULL;
}

node*createNode(int x){
	node*p=new node;
	if(p==NULL) exit(1);
	p->data=x;
	p->left=p->right=NULL;
	return p;
}

void insertNode(tree &root,int x){
	if(root){
		if(root->data==x) return;
		else if(x<root->data) insertNode(root->left,x);
			else insertNode(root->right,x);
	}else{
		node*p=createNode(x);
		root=p;
	}
}

void createTree(tree &root){
	int n,x;
	printf("nhap n= ");scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Nhap x= ");scanf("%d",&x);
		insertNode(root,x);
	}
}

void preOrder(tree t){
	if(t){
		printf("%5d",t->data);
		preOrder(t->left);
		preOrder(t->right);
	}
}

void inOrder(tree t){
	if(t){
		inOrder(t->left);
		printf("%5d",t->data);
		inOrder(t->right);
	}
}

void postOrder(tree t){
	if(t){
		postOrder(t->left);
		postOrder(t->right);
		printf("%5d",t->data);
	}
}

int countLeaf(tree root){
	if(root==NULL) return 0;
	if(root->left==NULL&&root->right==NULL) return 1;
	else return(countLeaf(root->left)+countLeaf(root->right));
}

int height(tree root){
	if(root == NULL) return 0;
	int maxh = 0;
	node*p = root->left;
	while(p != NULL){
		int h = height(p);
		if(h > maxh) maxh = h;
		p=p->right;
	}
	return maxh + 1;
}

int countNode(tree root){
	if(root==NULL) return 0;
	else return (countNode(root->left)+countNode(root->right))+1;
}

tree isLeftChild (tree root){
    if(root!=NULL) return root->left;
    else return NULL;
}

tree isRightChild (tree root){
    if(root!=NULL) return root->right;
    else return NULL;
}

int countRight(tree root){
	if(root==NULL) return 0;
	else return (isRightChild(root)!=NULL?1:0 ) + countRight(isLeftChild(root)) + countRight(isRightChild(root));
}

int main()
{
//	      5
//	  3        6
//	2   4        8
// 1           
	tree root;
	init(root);
	printf("Nhap cay:\n");
	createTree(root);
	printf("Chieu cao cua cay: %d\n",height(root));
	printf("So node la: %d\n",countLeaf(root));
	printf("So node trong: %d\n",countNode(root)-countLeaf(root)-1);
	printf("So con ben phai: %d\n",countRight(root));
	

return 0;
}
