#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define UINT_MAX 100

typedef struct Student
{
    int age;
    int count;
    char* key;
    
}Student;
typedef struct Linked
{
    struct Node* root;
}Linked;

typedef struct Node
{  
    struct Student stu;
    struct Node* next;

} Node;

typedef struct HashTable
{
    Linked stus[UINT_MAX];

    
} HashTable;

int hashCode(Student*);
void put(HashTable* h, Student* s);
Student* get(HashTable* h, Student* s);
Node* createNode(Student* stu) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->stu = *stu;
    n->next = NULL;
    return n;
}

void insert(Linked* k, Student* s) {
    Node* node = createNode(s);
    Node* root = k->root;
    if (root==NULL) {
        k->root = node;
    } else {
        Node* next = root->next;
        node->next = next;
        k->root = node;
    }
}
int main() {
    
    Student s0 = {16,3,"ken"};
    //insert(k,&s0);
    Student s1 = {17,11,"ken"};
    //insert(k,&s1);
    Student s2 = {18,23,"jruy"};
    //insert(k,&s2);
    Student s3 = {19,24,"liu"};
    //insert(k,&s3);
    Student s4 = {20,9,"jie"};
    //insert(k,&s4);
    HashTable t = {(Linked*)malloc(sizeof(Linked)*UINT_MAX)};
    put(&t,&s0);
    put(&t,&s1);
    put(&t,&s2);
    put(&t,&s3);
    put(&t,&s4);
    printf("%d\n",get(&t,&s0)->count);
    Student* sout = get(&t,&s3);
    printf("%d\n", sout->count);
    return 0;
}
int hashCode(Student* s) {
    char* key = s->key;
    // 获取字符长度
    int len = strlen(key), i,hashval=0,pow27=1;
    
    for (i=len-1;i>=0;i--) {
        int letter = key[i] - 97;
        hashval=letter*pow27;
        pow27 = pow27*27;
    }
    return hashval % 100;
    //return s->age;
}
void put(HashTable* h, Student* s) {
    Linked* k = (Linked*) malloc(sizeof(Linked));
    insert(k,s);
    h->stus[hashCode(s)] = *k;
}
// Student* get(HashTable* h, int age) {
//     return &h->stus[age];
// }
Student* get(HashTable* h, Student* s) {

    return &h->stus[hashCode(s)].root->stu;
}