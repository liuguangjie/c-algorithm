#include <stdio.h>
#include <malloc.h>


void show(){
    printf("show() ...\n");
}

// 增加元素动态扩容
void add(int ele, struct myarray* my) 
{   
    int i,len = my->length;
    int *newArr = (int*)malloc(sizeof(int) * (len + 1));

    for (i=0;i<len;i++) {
        newArr[i] = my->data[i];
    }
    newArr[len] = ele;
    my->length = my->length+1;
    my->data = newArr;
}


void print(struct myarray* my)
{


}

struct myarray
{
    /* data */
    int length;
    int *data;
    void (*show)();
    void (*add)(int, struct myarray*);
    void (*print)(struct myarray*);
} myarray = {0,NULL,show, add, print};
int main()
{
    struct myarray* my;
    my->show = show;
    printf("%d\n",myarray.length);

    //printf("%d\n", sizeof(int));
    my->show();


    char arr[30];
    int a[0];

    printf("%d\n", sizeof(a) / sizeof(int));

    printf("%d\n", sizeof(arr));

    return 0;
}