#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

} Node;

Node* createNode(int); //创建节点
void init(Node*[8],int*,int); // 初始化

int main()
{
    int arr[8] = {3,7,8,29,5,11,23,14};

    Node *p[8] = {};
    int len = 8;
    
    init(p,arr,len);

    while (len>1)
    {   
        len-=2;


        //Node *ptr[] = (Node*)malloc(sizeof(Node)*len);
    }
    

    printf("%d",p[0]->data);

    return 0;
}

Node* createNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void init(Node *p[],int* arr,int len) {
    int i,j;
    // 排序
    for(i=0;i<len;i++) {
        int k = i;
        j=i+1;
        for(;j<len;j++) {
            if(arr[j]>arr[k]) {
                k = j;
            }
        }
        int t = arr[i];
        arr[i] = arr[k];
        arr[k] = t;
    }
    //赋值
    for(i=0;i<len;i++) {
        p[i] = createNode(arr[i]);
    }

}