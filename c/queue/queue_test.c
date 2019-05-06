
/*****************************************************
Author：Simon_Kly    Version:0.1    Date: 20170520
Description: 动态栈
Mail: degaullekong@gmail.com
Funcion List: 
*****************************************************/

#include <stdio.h>
#include <stdlib.h>

enum ret_result {EMPTY_OK = 100, EMPTY_NO, ENTER_OK, ENTER_NO, OUT_OK, OUT_NO};

typedef struct node//链结构
{
    int data;
    struct node *next;
}Node, *Link;

typedef struct que//队列结构
{
    Link front;//出队口
}Queue;

/*判断malloc是否正确执行*/
void is_malloc_ok(void *queue)
{
    if (queue == NULL)
    {
        printf("malloc error!\n");
        exit(-1);
    }
}

/*创建队列*/
void create_queue(Queue ** queue)
{
    *queue = (Queue *)malloc(sizeof(Queue));
    is_malloc_ok(*queue);
    
    (*queue)->front = (Link)malloc(sizeof(Node));//为头结点分配空间
    is_malloc_ok((*queue)->front);

}

/*初始化队列*/
void init_queue(Queue *queue)
{
    queue->front->next = NULL;//头结点
}

/*创建入队元素*/
void create_node(Link * new_node)
{
    *new_node = (Link)malloc(sizeof(Node));
    is_malloc_ok(*new_node);
    (*new_node)->next = NULL;
}

/*入队*/
void enter_queue(Queue *queue, Link new_node)
{
    Link p = NULL;
    
    p = queue->front;

    while (p->next != NULL)
    {
        p = p->next;
    }
    new_node->next = NULL;
    p->next = new_node;
}

/*判断队空*/
int is_queue_empty(Queue *queue)
{
    if (queue->front->next == NULL)
    {
        return EMPTY_OK;
    }
    return EMPTY_NO;
}
/*出队*/
int out_queue(Queue *queue)
{
    Link p = NULL;
    int data;

    if (queue == NULL)
    {
        printf("queue is not exist!\n");
        return OUT_NO;
    }

    if (EMPTY_OK == is_queue_empty(queue))
    {
        return OUT_NO;
    }
    
    p = queue->front->next;
    queue->front->next = p->next;
    data = p->data;

    free(p);

    return data;
}

/*销毁队列*/
void release_queue(Queue ** queue)
{
    Link p = NULL;
    
    if (*queue == NULL)//如队列不存在
    {
        printf("queue is not exist!\n");
        return ;
    }

    p = (*queue)->front->next;

    while ((*queue)->front->next != NULL)
    {
        (*queue)->front->next = p->next;
        free(p);
        p = (*queue)->front->next;
    }
    free((*queue)->front);
    free((*queue));
    *queue = NULL;
}

int main()
{
    int i = 0;
    int ret;
    Queue *queue = NULL;
    Link new_node = NULL;
    
    create_queue(&queue);
    
    init_queue(queue);

    for (i = 0; i < 10; i++)
    {
        create_node(&new_node);

        new_node->data = i + 1;
        enter_queue(queue, new_node);//相当于链表中尾插
    }
    printf("第一次入队完成\n");

    for (i = 0; i < 10; i++)
    {
        ret = out_queue(queue);

        if (ret == EMPTY_OK)
        {
            break;
        }
        printf("%d ", ret);
    }
    printf("\n");
    printf("第一次出队完成，共10个元素\n");

    for (i = 0; i < 10; i++)
    {
        create_node(&new_node);
        new_node->data = i + 20;
        enter_queue(queue, new_node);
    }
    printf("第二次入队完成，共10个元素\n");

    for (i = 0; i < 10; i++)
    {
        ret = out_queue(queue);

        if (ret == EMPTY_OK)
        {
            break;
        }
        printf("%d ", ret);
    }
    printf("\n");
    printf("第二次出队完成，共10个元素\n");

    release_queue(&queue);
    out_queue(queue);

    return 0;
}