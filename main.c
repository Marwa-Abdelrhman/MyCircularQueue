#include <stdio.h>
#include <stdlib.h>
#include "my_CircularQueue.h"
#include"Platform_Types.h"


Queue_t *q1;
Queue_status_t ret=Q_NOK;
uint32 s=5;
uint32  n1=11,n2=22,n3=33,n4=44,n5=55;
void * r;

uint32 x=0;

int main()
{
    uint32* rem_ele;
    q1= Queue_init(&ret,s);


    ret=Queue_enqueue_element(q1,&n1);
    ret=Queue_enqueue_element(q1,&n2);
    ret=Queue_enqueue_element(q1,&n3);
    ret=Queue_enqueue_element(q1,&n4);
    ret=Queue_enqueue_element(q1,&n5);
    ret=Queue_enqueue_element(q1,&n5);
    ret=Queue_enqueue_element(q1,&n5);
    ret=Queue_enqueue_element(q1,&n5);


    ret=Queue_dequeue_element(q1,&rem_ele);
    printf("rem_ele is %i\n",*((uint32*)rem_ele));


    ret=Queue_dequeue_element(q1,&rem_ele);
    printf("rem_ele is %i\n",*((uint32*)rem_ele));


    r=Queue_rear(q1,&ret);
    printf("rear is %d\n",*(uint32*)r);

    r=Queue_front(q1,&ret);
    printf("front is %d\n",*(uint32*)r);


    ret=Queue_count(q1,&x);
    printf("status is %i\n",ret);
    ret=Queue_destroy(q1);
    return 0;
}
