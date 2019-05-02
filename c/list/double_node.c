#include <stdio.h>
#include <stdlib.h>

typedef struct double_node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

void add(Node* next, Node* root) {

    Node* c = root;

    while (c->next != root)
    {
        c = c->next;
    }

    c->next = next;
    
    next->prev = c;

    next->next = root;

}

int main()
{

    Node *n = (Node*)malloc(sizeof(Node)); //{rand() >> 20,NULL};
    n->data = 99;
    n->next = n;
    n->prev = n;

    Node* prev = n->prev;
    Node* next = n->next;
    printf("prev=%d,next=%d\n", prev->data, next->data);
    printf("this=%p\n", n);

    printf("%d\n", n == prev);
    return 0;
}