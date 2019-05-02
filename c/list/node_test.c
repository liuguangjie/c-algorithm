#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* node;
    /* data */
} Node;

void addNode(Node* next, Node* root) {
    Node* curt = root;
    while (curt->node != NULL)
    {
        //printf("%p \n", curt);
        curt = curt->node;
    }
    //printf("add-> %d \n", curt->data);
    curt->node = next;
}

void print(Node* node) {
    Node* curt = node;
    while (curt->node != NULL)
    {
        curt = curt->node;
        printf("%d,", curt->data);
        //free(curt);
        /* code */
    }
    printf("\n\b");
    //printf("\b");
    //printf("");
}

void removeFirst(Node* root) {
    Node* next = root->node;
    if (next->node != NULL) {
        root->node = next->node;

    } else {
        root->node = NULL;
    }
    //free(next);
    
}

void deleteNode(Node* node, Node* root) {
    Node* curt = root;
    Node* pre = root;
    //printf("%d\n", root->data);
    while (curt->node != NULL && curt->data != node->data)
    {   
        pre = curt;
        curt = curt->node;

        if (curt->node == NULL) {
            printf("没有找到元素");
            break;
        }
    }
    // 实现删除
    pre->node = curt->node;

    
}

int main()
{
    
    Node root = {0,NULL};
    int i;
    for ( i = 0; i < 6; i++)
    { 
        Node *n = (Node*)malloc(sizeof(Node)); //{rand() >> 20,NULL};
        n->data = i + 1;
        addNode(n, &root);
    }
    print(&root);
    Node *node = (Node*)malloc(sizeof(Node)); //{rand() >> 20,NULL};
    node->data = 3;
    deleteNode(node, &root);
    print(&root);
    removeFirst(&root);
    print(&root);
    removeFirst(&root);
    print(&root);
    return 0;
}