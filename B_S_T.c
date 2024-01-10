//*--Binary Search Tree--*//
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define NULL 0
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root ;
struct node *element;
 
void creat_tree();
int insert(int );
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void mirror_image(struct node *);
struct node *del_node(struct node * , int);
struct node *search(struct node * , int); 
struct node *del_tree(struct node *);

struct node *min_element(struct node *);
struct node *max_element(struct node *);

int total_node(struct node *);
int total_internalnode(struct node *);
int total_extarnalnode(struct node *);
int height(struct node *);
//int total_oddnode(struct node * , int);   ////////check i??t//
//int total_evennode(struct node * , int); //////////check ??it///////

void display(int);

void main()
{
    int ch,n,x;
    struct node *ptr;
    creat_tree();
    while(1)
    {
        printf("\nEnter\n1 for insert\n2 for preorder\n3 for inorder\n4 for postorder\n5 for mirrror image\n6 for delete element\n7 for search element\n8 for find snallesrt element\n9 for find largest element\n10 for total nodes\n11 for total no of internal nodes\n12 for total no of extrenal nodes\n13 for height of the tree\n14 for count total no.of and even elements in a BST\n15 for delete the whole tree\n and others for quit:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the element to be inserted:");
                    scanf("%d",&n);
                    x = insert(n);
                    if(x=1)
                       printf("\nElement %d is inserted",n);
                    else
                       printf("\nInserton not done");
                    break;
            case 2: if(root!=NULL)
                    {
                        printf("The preorder elements are:\n");
                        display(1);
                    }
                    else
                    {
                        printf("\nBST is empty.Nothing to display");
                    }
                    break;
            case 3: if(root!=NULL)
                    {
                        printf("The inorder elements are:\n");
                        display(2);
                    }
                    else
                    {
                        printf("\nBST is empty.Nothing to display");
                    }
                    break;
            case 4: if(root!=NULL)
                    {
                        printf("The postorder elements are:\n");
                        display(3);
                    }
                    else
                    {
                        printf("\nBST is empty.Nothing to display");
                    }
                    break;
            case 5: if(root!=NULL)
                    {
                        printf("The Mirror imaage of BST for show choose which traversal we want its mirror image:\n");
                        mirror_image(root);
                    }
                    else
                    {
                        printf("\nBST is empty.Nothing to display");
                    }
                    break;
            case 6: printf("Enter the element to be deleted");
                    scanf("%d",&n);
                    root = del_node(root , n);
                    if(root == NULL)
                    {
                       printf("%d is not avaliable.",n);
                    }
                    else
                    {
                       printf("%d is deleted",n);
                    }
                    break;
            case 7: printf("Enter the element to be searched:");
                    scanf("%d",&n);
                    if(root!=NULL)
                    {
                        printf("\n%d is found.",search(root , n)->data);
                    }
                    else
                    {
                        printf("There is no node or Data not found");
                    }                   
                    break;
            case 8: if(root!=NULL)
                    {
                        printf("\n%d is the smallest element.",min_element(root)->data);   
                    }
                    else
                    {
                        printf("There is no node the tree is empty:");
                    }
                    break;
            case 9: if(root!=NULL)
                    {
                        printf("\n%d is the largest element.",max_element(root)->data);   
                    }
                    else
                    {
                        printf("There is no node the tree is empty:");
                    }
                    break;
            case 10: if(root!=NULL)
                    {
                        printf("\nTotal no. of nodes:%d",total_node(root));   
                    }
                    else
                    {
                        printf("There is no node the tree is empty:");
                    }
                    break;
            case 11: if(root!=NULL)
                    {
                        printf("\nTotal no. of internal nodes:%d",total_internalnode(root));   
                    }
                    else
                    {
                        printf("There is no node the tree is empty:");
                    }
                    break;
            case 12: if(root!=NULL)
                    {
                        printf("\nTotal no. of external nodes:%d",total_extarnalnode(root));   
                    }
                    else
                    {
                        printf("There is no node the tree is empty:");
                    }
                    break;
            case 13: if(root!=NULL)
                    {
                        printf("\nHeight of the BST:%d",height(root));   
                    }
                    else
                    {
                        printf("There is no node the tree is empty:");
                    }
                    break;
            /*case 14: if(root!=NULL)
                    {
                            printf("\nNo of odd nodes:%d",total_oddnode(root,0));
                            printf("\nNo of even nodes:%d",total_evennode(root,0));      
                    }
                    else
                    {
                        printf("There is no node the tree is empty:");
                    }
                    break;*/
            case 15: if(root!=NULL)
                    {
                        root = del_tree(root);  
                        root = NULL; 
                        printf("Now there is no node the BST is empty.");
                    }
                    else
                    {
                        printf("There is no node the tree is empty:");
                    }
                    break; 
            default: exit(0);
            
        }
    }
 }
 
/***********/

void creat_tree()
{
    root = NULL;
}
/***********/
int insert(int x)
{
    struct node *new,*prev,*curr;
    new = (struct node *)malloc(sizeof(struct node));
    if(new == NULL)
    {
        printf("\nMemory not available");
        return 0;
    }
    new->data = x;
    new->left = new->right = NULL;
    if(root == NULL)
    {
        root = new;
        return 1;
    }
    prev = NULL;

    curr = root; //loop in/itilization
    while(curr!=NULL)
    {
        prev = curr;
        if(new->data < curr->data)
        {
            curr = curr->left; // upation of loop and traverse in left
        }
        else
        {
            curr = curr->right; // updation of loop and traverse in right
        }
    }
    if(new->data < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
    return 1;
}

/************/

void display(int x)
{
    if(x==1)
       preorder(root);
    else if(x==2)
       inorder(root);
    else
       postorder(root);
    
}

/***********/

void preorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
       printf("%d  ",ptr->data);
       preorder(ptr->left);
       preorder(ptr->right);
    }
}

/************/

void inorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        printf("%d  ",ptr->data);
        inorder(ptr->right);
    }
}

/************/

void postorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d  ",ptr->data);
    }
}

/************/

void mirror_image(struct node *ptr)
{
    if(ptr!=NULL)
    {
        struct node *p;
        mirror_image(ptr->left);
        //printf("%d ",ptr->data);
        mirror_image(ptr->right);
        p = ptr->left;
        ptr->left = ptr->right;
        ptr->right = p;
    }
}

/************/

struct node *del_node(struct node *root , int val)
{
    struct node *isucc;
    if (root == NULL)
    {
        printf("\nThetre is no node:");
        return root;
    }

    if(val < root->data)
    {
        root->left = del_node(root->left , val);
        return root;
    }
    else if(val > root->data)
    {
        root->right = del_node(root->right , val);
        return root;
    }
    // We reach here when root is the node//
    // to be deleted.//
    if (root->left == NULL) // If one of the children is empty//
    {
        isucc = root->right;
        free(root);
        return isucc;
    }
    else if (root->right == NULL)
    {
        isucc = root->left;
        free(root);
        return isucc;
    }
    // If both children exist//
    else
    {
        struct node *successor_parent = root;
        // Find successor//
        struct node *succ = root->left;
        while(succ->left!=NULL)
        {
            successor_parent = succ;
            succ = succ->left;
        }

        /**-- Delete successor.  Since successor
         is always left child of its parent
         we can safely make successor's right
         right child as left of its parent.
         If there is no succ, then assign
         succ->right to succParent->right--*/

        if (successor_parent != root)
            successor_parent->left = succ->right;
        else
            successor_parent->right = succ->right;
        
        root->data = succ->data;  // Copy Successor Data to root//
        free(succ);
        return root;
    }

}

/***********/

struct node *search(struct node *root , int val)   //??need check for if data not found part//
{
    /*if (root == NULL)
    {
        printf("\nThetre is no node:");
        return root;
    }*/
   
    if(val == root->data)
    {
        //printf("%d is found:",val);
        return root;
    }
    else if(val < root->data)
    {
        return search(root->left , val);
    }
    else if(val > root->data)
    {
        return search(root->right , val);
    }
    else
    {
        return root;
    }
} 

/************/

struct node *min_element(struct node *root)
{
    if(root == NULL || root->left == NULL)
    {
        return root;
    }
    return min_element(root->left);
}

/***********/

struct node *max_element(struct node *root)
{
    if(root == NULL || root->right == NULL)
    {
        return root;
    }
    return max_element(root->right);
}

/************/

int total_node(struct node *root)   
{
    if(root == NULL)
    {
        return 0;
    }
    return (total_node(root->left) + total_node(root->right) + 1);
} 

/*************/

int total_internalnode(struct node *root)  ///?? check??//
{
    if(root == NULL)
    {
        return 0;
    }
    return (1+total_node(root->left) + total_node(root->right));
}

/*************/

int total_extarnalnode(struct node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return (total_extarnalnode(root->left) + total_extarnalnode(root->right));
    } 
}

/************/

int height(struct node *root)
{
    int left_height,right_height;
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        left_height = height(root->left);
        right_height = height(root->right);
        if(left_height > right_height)
           return (left_height+1);
        else
           return (right_height+1);
    }
}

/************

int total_oddnode(struct node *root , int odd)
{
    if(root->data%2!=0)
    {
        return odd++;
    }
    return total_oddnode(root->left , odd);
    return total_oddnode(root->right , odd);
}

/************

int total_evennode(struct node *root , int even)
{
    if(root->data%2==0)
    {
        return even++;
    }
    return total_evennode(root->left , even);
    return total_evennode(root->right , even);
}

************/

struct node *del_tree(struct node *root)
{
    if(root!=NULL)
    {
        del_tree(root->left);
        del_tree(root->right);
        free(root);
    }
}