/* Minimum Vertex Cover Dunamic Programming Implementation */
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	int vertex_cover;
	struct node* left;
	struct node* right;
};
typedef struct node Node;

Node* getNode(int info)
{
	Node* create = (Node* )malloc(sizeof(Node));
	create->left = NULL;
	create->right = NULL;
	create->data = info;
	create->vertex_cover = 0;
	return create;
}

int vcover(Node* root)
{
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL)
		return 0;

	if(root->vertex_cover != 0)
	{
		return root->vertex_cover;
	}

	//size including root element
	int r_in = 1 + vcover(root->left) + vcover(root->right);

	//size excluding root eleemnet
	int r_out = 0;
	if(root->left)
		r_out += 1 + vcover(root->left->left) + vcover(root->left->right);
	if(root->right)
		r_out += 1 + vcover(root->right->right) + vcover(root->right->left);

	root->vertex_cover = min(r_out, r_in);
	return min(r_out, r_in);
}
int main()
{
	Node* root                =	getNode(20);
	root->left                = getNode(8);
    root->left->left          = getNode(4);
    root->left->right         = getNode(12);
    root->left->right->left   = getNode(10);
    root->left->right->right  = getNode(14);
    root->right               = getNode(22);
    root->right->right        = getNode(25);
    cout<<"Minimum Vertex Cover : "<<vcover(root)<<endl;
	return 0;
}