#include<stdio.h>
#include<stdlib.h>
typedef struct node Node;

struct node{
Node *parent;
Node *left;
Node *right;
int data;
};

Node *create_node(int item)
{
    Node *new_node=(Node *) malloc(sizeof(Node));
    if(new_node==NULL)
    {
        printf("Error!\n");
        exit(1);
    }

    new_node->data=item;
    new_node->parent=NULL;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void add_left_child(Node *parent2,Node *child)
{
    if(child==NULL)
    {
        parent2->left=child;
    }
    else
    {
        parent2->left=child;
        child->parent=parent2;
    }

}

void add_right_child(Node *parent2,Node *child)
{
    if(child==NULL)
    {
        parent2->right=child;
    }
    else
    {
        parent2->right=child;
        child->parent=parent2;
    }

}

Node *insert_node(Node *root,Node *inserting_node)
{
    if(root==NULL)
    {
        root=inserting_node;
        return root;
    }
    Node *parent_node,*current_node;
    parent_node=NULL;
    current_node=root;
    while(current_node!=NULL)
    {
        parent_node=current_node;
        if(inserting_node->data < current_node->data)
            current_node=current_node->left;
        else
            current_node=current_node->right;
    }
    if(inserting_node->data < parent_node->data)
        add_left_child(parent_node,inserting_node);
    else
        add_right_child(parent_node,inserting_node);

    return root;
}

Node *bst_transpalent(Node *root,Node *transper_node,Node *successor_node)
{
    if(transper_node==root)
    {
        successor_node->parent=NULL;
        root=successor_node;
    }
    else if(transper_node == transper_node->parent->left)
        add_left_child(transper_node->parent,successor_node);
    else
        add_right_child(transper_node->parent,successor_node);

    return root;
}

Node *bst_successor_node(Node *deleting_node)
{
    Node *successor_node;
    successor_node=deleting_node;
    while(deleting_node->left!=NULL)
    {
        successor_node=deleting_node->left;
        deleting_node=deleting_node->left;
    }
    return successor_node;
}

Node *bst_delete(Node *root,Node *deleting_node)
{
    Node *successor_node;
    if(deleting_node->left==NULL)
        root=bst_transpalent(root,deleting_node,deleting_node->right);
    else if(deleting_node->right==NULL)
        root=bst_transpalent(root,deleting_node,deleting_node->left);
    else
    {
        successor_node=bst_successor_node(deleting_node->right);
        if(successor_node->parent!=deleting_node)
        {
            root=bst_transpalent(root,successor_node,successor_node->right);
            add_right_child(successor_node,deleting_node->right);
        }

        root=bst_transpalent(root,deleting_node,successor_node);
        add_left_child(successor_node,deleting_node->left);
    }
    free(deleting_node);
    return root;

}

void in_order(Node *node)
{
    if(node->left!=NULL)
        in_order(node->left);

    printf("%d ",node->data);

    if(node->right!=NULL)
        in_order(node->right);
}

int main()
{
    Node *fourty_four=create_node(44);
    Node *thirty_three=create_node(33);
    Node *fifty=create_node(50);
    Node *Seveteen=create_node(17);
    Node *thirty_six=create_node(36);
    Node *thirty_four=create_node(34);
    Node *thirty_nine=create_node(39);
    Node *thirty_five=create_node(35);
    Node *fourty_six=create_node(46);
    Node *fifty_six=create_node(56);
    Node *fourty_seven=create_node(47);
    Node *fifty_three=create_node(53);
    Node *fifty_nine=create_node(59);
    Node *fourty_eight=create_node(48);

    Node *root;

    root=insert_node(NULL,fourty_four);
    root=insert_node(root,thirty_three);
    root=insert_node(root,fifty);
    root=insert_node(root,Seveteen);
    root=insert_node(root,thirty_six);
    root=insert_node(root,thirty_four);
    root=insert_node(root,thirty_nine);
    root=insert_node(root,thirty_five);
    root=insert_node(root,fourty_six);
    root=insert_node(root,fifty_six);
    root=insert_node(root,fourty_seven);
    root=insert_node(root,fifty_three);
    root=insert_node(root,fifty_nine);
    root=insert_node(root,fourty_eight);

    root=bst_delete(root,fifty);
    root=bst_delete(root,fourty_four);
    root=bst_delete(root,fifty_three);

    in_order(root);
    return 0;
}
