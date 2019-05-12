#include <stdio.h>
#include <stdlib.h>
typedef struct Tree
{
    struct Node* root; //根节点
    
    struct Node* pre; //前一个节点
} Tree;

typedef struct Node
{
    int data;
    struct Node* left; //左子节点
    struct Node* right;// 右子节点
    int leftType;
    int rightType;
    
}Node;
void insertNode(Tree*,int);// 插入节点
Node* createNode(int); //创建节点
// 获取树的高度
int getHeight(Node*);
int max(int,int);

void rightRotate(Tree*,Node*); // 右旋
void leftRotate(Tree*,Node*); // 左旋
//入口
int main() {

    // int arr[6] = {8,9,6,7,5,4};
    //int arr[6] = {2,1,4,3,5,6};
    int arr[6] = {8,9,5,4,6,7};
    Tree* t = (Tree*)malloc(sizeof(Tree));
    t->root=NULL;
    t->pre=NULL;


    int i;
    for (i=0;i<6;i++) {
        insertNode(t, arr[i]);
    }

    printf("%d\n", getHeight(t->root));
    printf("%d\n", t->root->data);

    return 0;
}

int getHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }
    if (node->right == NULL && node->left == NULL) {
        return 1;
    }

    return max(getHeight(node->left), getHeight(node->right)) + 1;
}

int max(int a, int b) {

    return a>b?a:b;
}


// 插入节点
void insertNode(Tree* tree, int data) {
    //如果根节点为NUll
    Node* node = createNode(data);
    if (!tree->root) {
        tree->root = node;
    } else {
        Node* n = tree->root;
        Node* p = NULL;
        while (n!=NULL)
        {
            p = n;
            if (n->data > data) {
                n = n->left;
                if (n == NULL) {
                    p->left = node;
                }
            } else {
                n = n->right;
                if (n == NULL) {
                    p->right = node;
                }
            }
        }

        Node* root = tree->root;
        int lg = getHeight(root->left);
        int rg = getHeight(root->right);
        
        // 右旋
        if (lg-rg >= 2) {
            // 双旋转  没有完成有个问题就是节点传递的问题
            if (root->left != NULL  && getHeight(root->left->left) < getHeight(root->left->right)) {
                leftRotate(tree, root->left); //这块有点问题
                rightRotate(tree,root);
            } else {
                rightRotate(tree,root);
            }
            
        }
        // 左旋
        if (lg-rg <=-2) {
            if (root->right != NULL && getHeight(root->right->right) < getHeight(root->right->left)) {
                rightRotate(tree,root);
                leftRotate(tree,root);
            } else {
                leftRotate(tree,root);
            }
        }

    }
}

// 右旋
void rightRotate(Tree* tree,Node* root) {
    //1.创建一个节点
        Node* r = createNode(root->data);
        //2.
        r->right = root->right;
        
        r->left = root->left->right;
        
        tree->root = root->left;

        tree->root->right = r;
}
// 左旋
void leftRotate(Tree* tree,Node* root){
    Node* l = createNode(root->data);
    l->left = root->left;
    l->right = root->right->left;
    tree->root = root->right;
    tree->root->left = l;
}

//创建节点
Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->left = NULL;
    n->right = NULL;
    n->data = data;
    n->leftType=0;
    n->rightType=0;
    return n;
}