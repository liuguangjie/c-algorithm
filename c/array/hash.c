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

typedef struct HashTable
{
    Student stus[UINT_MAX];

    
} HashTable;

int hashCode(Student*);
void put(HashTable* h, Student* s);
Student* get(HashTable* h, Student* s);
int main() {
    Student s0 = {16,3,"tom"};
    Student s1 = {17,11,"ken"};
    Student s2 = {18,23,"jruy"};
    Student s3 = {19,24,"liu"};
    Student s4 = {20,9,"jie"};
    HashTable t= {(Student*)malloc(sizeof(Student)*UINT_MAX)};
    
    put(&t,&s0);
    put(&t,&s1);
    put(&t,&s2);
    put(&t,&s3);
    put(&t,&s4);

    
    printf("%d\n",t.stus[hashCode(&s4)].count);

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
    h->stus[hashCode(s)] = *s;
}

// Student* get(HashTable* h, int age) {
//     return &h->stus[age];
// }

Student* get(HashTable* h, Student* s) {

    return &h->stus[hashCode(s)];
}