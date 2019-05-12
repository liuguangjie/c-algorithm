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

// 函数定义
Tree* createTree(); // 创建树
Node* createNode(int); //创建节点
void insertNode(Tree*,int);// 插入节点
Node* findNode(Tree*,int);// 查找节点
int deleteNode(Tree*,int); // 删除节点
Node* getSuccessor(Node*); // 中序后续节点
void seqTraverse(Node*); // 前序遍历树
void middleTraverse(Node*);//中序 遍历树
void afterTraverse(Node*);//后序 遍历树
void insertArr(Tree* ,int*, int);// 插入数据 用数组
void threadNode(Tree*,Node*); //  线索二叉树的定义
int main(int t,char* args) 
{
    Tree* tree = createTree();
    // Node* root = createNode(1);
    // Node* left = createNode(2);
    
    // Node* right = createNode(3);
    // root->left = left;



    // root->right = right;
    // tree->root = root;

    // printf("root=%d\n", root->data);
    // printf("left=%d\n", left->data);
    // printf("right=%d\n", right->data);
    // 10 20 5 15 3
    // insertNode(tree,10);
    // printf("%d\n", tree->root->data);
    // insertNode(tree,20);
    // printf("%d\n", tree->root->right->data);
    // insertNode(tree,5);
    // printf("%d\n", tree->root->left->data);

    // insertNode(tree,15);
    // printf("%d\n", tree->root->right->left->data);
    // printf("%p\n", tree->root->right->left);
    // insertNode(tree,3);
    // printf("%d\n", tree->root->left->left->data);

    // Node* find_0 = findNode(tree, 15);
    // printf("找到%p\n", find_0);
    int arr[7] = {30,50, 26, 53,  2, 25, 31};
    //int arr[6] = {10, 20, 15, 3, 4, 90};
    insertArr(tree,arr,7);
    // seqTraverse(tree->root);
    printf("\n");
    middleTraverse(tree->root);
    //threadNode(tree,tree->root);
    // printf("\n");
    // afterTraverse(tree->root);
    deleteNode(tree, 50);
    printf("\n");
    middleTraverse(tree->root);
    printf("\n");
    //Node* find = findNode(tree, 40);
    //printf("%d\n",find->right->data);
    
    return 0;
}
// 函数实现
//创建树
Tree* createTree() {
    Tree* t = (Tree*)malloc(sizeof(Tree));
    t->root=NULL;
    t->pre=NULL;
    return t;
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

//线索二叉树的实现 中序
void threadNode(Tree* tree,Node* node) {
    // 如果为空就停止递归
    if (!node) return;
    // 左边
    threadNode(tree,node->left);

    if (node->left == NULL) {
        node->left=tree->pre;
        node->leftType=1;
    }

    if (tree->pre!=NULL && tree->pre->right == NULL){
        tree->pre->right=node;
        tree->pre->rightType=1;
    }
    tree->pre=node;


    // 右边
    threadNode(tree,node->right);

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
        
    }
}
// 查找节点
Node* findNode(Tree* tree,int data) {

    Node* current = tree->root;

    while (current && current->data != data)
    {
        if (current->data > data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return current;

}

/**用数组初始化树*/
void insertArr(Tree* tree,int* arr, int len) {
    int i;
    for (i=0;i<len;i++) {
        insertNode(tree, arr[i]);
    }
}

// 删除节点 这个有点难
int deleteNode(Tree* tree,int data) {

    //先遍历二叉树 找到树
    Node* parent = tree->root;
    Node* curt = tree->root;
    int isLeft = 1;
    while (curt!=NULL&&curt->data != data)
    {
        parent = curt;
        if (curt->data > data) {
            curt = curt->left;
            isLeft =1;
        } else {
            curt = curt->right;
            isLeft =0;
        }

        if (curt ==NULL) {
            return 0;
        }
    }

    //printf("deleteNode %d\n", parent->data);
    //  1. 删除叶子节点
    if (curt->left == NULL && curt->right==NULL) {
        if (parent == curt) {
            tree->root = NULL;
        } else 
        if(isLeft) {
            parent->left=NULL;
        } else {
            parent->right=NULL; 
        }
    } else if (curt->right == NULL) {
        if (parent == curt) {
            tree->root = curt->left;
        } else
        if (isLeft) {
            parent->left = curt->left;
        } else {
            parent->right = curt->left;
        }
    } else if (curt->left == NULL) {
        if (parent == curt) {
            tree->root = curt->right;
        } else
        if (isLeft) {
            parent->left = curt->right;
        } else {
            parent->right = curt->right;
        }
    } else{
        // 删除有2个节点的情况
        Node* sr = getSuccessor(curt);
        if (parent == curt) {
            tree->root = sr;
        } else if (isLeft) {
            parent->left = sr;
        } else {
            parent->right = sr;
        }
        sr->left = curt->left;
    }
    
    





    return 1;


    // 考虑情况如下
    //  1. 删除叶子节点
    //  2. 删除父节点其中有一个节点
    
    //  3. 删除父节点其中有二个节点

}

Node* getSuccessor(Node* node) {
    Node* successor = node;
    Node* parent = node;
    Node* curt = node->right;

    while (curt!=NULL)
    {
        parent = successor;
        successor = curt;
        curt = curt->left;
    }

    //printf("%d,\n", successor->data);
    if (successor != node->right) {
        parent->left = successor->right;
        successor->right = node->right;
    }
    return successor;
}

/*
50, 15, 20, 2, 40, 25, 56

        50
     15   56  
   2   20
         40
       25    

    
*/
// 前序遍历树
void seqTraverse(Node* node){ 
    if (node) {
        printf("%d ", node->data);
        seqTraverse(node->left); // 前序遍历 左边
        seqTraverse(node->right); // 前序遍历 右边
    }
} 

// 中序遍历树
void middleTraverse(Node* node){ 
    if (node) {
        middleTraverse(node->left); // 中序遍历 左边
        printf("%d ", node->data);
        middleTraverse(node->right); // 中序遍历 右边
    }
} 

// 后序遍历树
void afterTraverse(Node* node){ 
    if (node) {
        afterTraverse(node->left); // 后序遍历 左边
        afterTraverse(node->right); // 后序遍历 右边
        printf("%d ", node->data);
    }
} 

