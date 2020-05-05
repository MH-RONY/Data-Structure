#include<stdio.h>
typedef struct node Node;

struct node{
int data;
Node *left;
Node *right;
};

Node *create_node(int item)
{
    Node *new_node=(Node *) malloc(sizeof(Node));
    if(new_node==NULL)
    {
        printf("Error!");
        exit(1);
    }
    new_node->data=item;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

void add_left_child(Node *parent,Node *child)
{
    parent->left=child;
}
void add_right_child(Node *parent,Node *child)
{
    parent->right=child;
}

Node *create_tree()
{
    Node *two=create_node(2);
    Node *seven=create_node(7);
    Node *nine=create_node(9);
    add_left_child(two,seven);
    add_right_child(two,nine);

    Node *one=create_node(1);
    Node *six=create_node(6);
    add_left_child(seven,one);
    add_right_child(seven,six);

    Node *five=create_node(5);
    Node *ten=create_node(10);
    add_left_child(six,five);
    add_right_child(six,ten);

    Node *eight=create_node(8);
    add_left_child(nine,NULL);
    add_right_child(nine,eight);

    Node *three=create_node(3);
    Node *four=create_node(4);
    add_left_child(eight,three);
    add_right_child(eight,four);

    return two;  //two node is the root node of this tree.

}

void pre_order(Node *node) //here we pass root node ,root,left,right
{
    printf("%d ",node->data);
    if(node->left !=NULL)
    {
        pre_order(node->left);
    }
    if(node->right !=NULL)
    {
        pre_order(node->right);
    }
}

void post_order(Node *node)  //left,right,root
{
    if(node->left!=NULL)
    {
        post_order(node->left);
    }
    if(node->right!=NULL)
    {
        post_order(node->right);
    }
    printf("%d ",node->data);
}

void in_order(Node *node) //left,root,right
{
    if(node->left!=NULL)
    {
        in_order(node->left);
    }
    printf("%d ",node->data);
    if(node->right!=NULL)
    {
        in_order(node->right);
    }
}

int main()
{
    Node *root;
    root=create_tree();
    pre_order(root);
    printf("\n");
    post_order(root);
    printf("\n");
    in_order(root);
    printf("\n");
    return 0;
}

