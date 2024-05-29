/**
 * @file my_CircularQueue.c
 * @author Marwa Abdelrhman
 * @brief contains function definitions of CircularQueue
 * @version 1.0
 * @date 2024-05-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdlib.h>
#include "my_CircularQueue.h"
//#include "C:\mingw64\x86_64-w64-mingw32\include\stdlib.h"

 /**
  *@brief  create queue object in heap memory
  *@param  my_size size of elements in the created queue
  *@param  check if queue is created with no errors
  *@return queue_obj pointer to the queue created
  */
//Queue_status_t Queue_init(Queue_t *queue_obj,uint32 my_size)
Queue_t * Queue_init(Queue_status_t *q_ret,uint32 my_size)
{
    //Queue_status_t q_ret=Q_NOK;

    //*q_ret=Q_NOK;
     Queue_t * queue_obj=(Queue_t *)malloc(sizeof(Queue_t));
    if(NULL== queue_obj)
    {
        *q_ret=Q_NULL_POINTER;
        queue_obj=NULL;
        #ifdef CIRCULAR_QUEUE_DEBUG_MODE
        printf("ERROR: can't initialize the queue due to null pointer.\n");
        #endif // CIRCULAR_QUEUE_DEBUG_MODE
    }
    else
    {
        //queue_obj->Q_array=(void **)malloc((sizeof(void *))*my_size);
        queue_obj->Q_array=(void **)calloc(my_size, sizeof(void *));
        if(NULL ==queue_obj->Q_array)
        {
            *q_ret=Q_NOK;
            queue_obj=NULL;
            #ifdef CIRCULAR_QUEUE_DEBUG_MODE
            printf("ERROR: can't initialize the queue due to null pointer.\n");
            #endif // CIRCULAR_QUEUE_DEBUG_MODE

        }
        else
        {
            queue_obj->Q_elements_count=0;
            queue_obj->Q_front=-1;
            queue_obj->Q_rear=-1;
            queue_obj->Q_max_size=my_size;

            *q_ret=Q_OK;

            #ifdef CIRCULAR_QUEUE_DEBUG_MODE
            printf("Queue initialized successfully.\n");
            #endif // CIRCULAR_QUEUE_DEBUG_MODE

        }



    }
    return queue_obj;

}
/**
  *@brief  add an element at the queue
  *@param  queue_obj pointer to the queue
  *@param  element to be added at the queue with any data type
  *@return check if element is added at the queue with no errors
  */
Queue_status_t Queue_enqueue_element(Queue_t *queue_obj,void *element)
{
    Queue_status_t q_ret=Q_NOK;
    if((NULL== queue_obj)|| (NULL == element))
    {

        q_ret=Q_NULL_POINTER;

        #ifdef CIRCULAR_QUEUE_DEBUG_MODE
        printf("ERROR: null pointer @ Queue_enqueue_element.\n");
        #endif // CIRCULAR_QUEUE_DEBUG_MODE
    }
    else
    {
        if(Q_FULL==Queue_is_full(queue_obj))
        {
            q_ret=Q_FULL;
            #ifdef CIRCULAR_QUEUE_DEBUG_MODE
            printf("can't add element the queue is full.\n");
            #endif // CIRCULAR_QUEUE_DEBUG_MODE
        }
        else
        {
            (queue_obj->Q_rear)++;

            /*circular queue operation*/
            if(queue_obj->Q_rear == queue_obj->Q_max_size)
            {
                queue_obj->Q_rear=0;
            }
            else{/*Nothing */}

            queue_obj->Q_array[queue_obj->Q_rear]=element;

            if(queue_obj->Q_elements_count == 0)
            {
                queue_obj->Q_front=0;
                //queue_obj->Q_rear=0;
                queue_obj->Q_elements_count=1;

            }
            else
            {
                (queue_obj->Q_elements_count)++;
                //printf("queue_obj->Q_elements_count %i\n",queue_obj->Q_elements_count);

            }

            q_ret=Q_OK;

            #ifdef CIRCULAR_QUEUE_DEBUG_MODE
            printf("value %i added to the queue.\n",*(uint32 *)element);
            #endif // CIRCULAR_QUEUE_DEBUG_MODE


        }
    }
    return q_ret;


}
/**
  *@brief  remove an element from the queue
  *@param  queue_obj pointer to the queue
  *@param  element to be removed from the queue with any data type
  *@return check if element is removed from the queue with no errors
  */
Queue_status_t Queue_dequeue_element(Queue_t *queue_obj,void **element)
{
    Queue_status_t q_ret=Q_NOK;
    if((NULL== queue_obj)|| (NULL == element))
    {

        q_ret=Q_NULL_POINTER;

        #ifdef CIRCULAR_QUEUE_DEBUG_MODE
        printf("ERROR: null pointer @ Queue_dequeue_element.\n");
        #endif // CIRCULAR_QUEUE_DEBUG_MODE
    }
    else
    {
        if(Q_EMPTY == Queue_is_empty(queue_obj))
        {
            q_ret=Q_EMPTY;
            #ifdef CIRCULAR_QUEUE_DEBUG_MODE
            printf("can't reomve element the queue is empty.\n");
            #endif // CIRCULAR_QUEUE_DEBUG_MODE
        }
        else
        {
            *element=queue_obj->Q_array[queue_obj->Q_front];
            (queue_obj->Q_front)++;

            /*circular queue operation*/
            if(queue_obj->Q_front == queue_obj->Q_max_size)
            {
                queue_obj->Q_front=0;
            }
            else{/*Nothing */}
            if(queue_obj->Q_elements_count == 1)
            {
                queue_obj->Q_front=-1;
                queue_obj->Q_rear=-1;
            }
            else{/*Nothing */}
           (queue_obj->Q_elements_count)--;

            q_ret=Q_OK;



            #ifdef CIRCULAR_QUEUE_DEBUG_MODE
            //printf("value %i removed from the queue.\n",*(uint32 *)(queue_obj->Q_array[(queue_obj->Q_front)-1]));
            printf("value %i removed from the queue.\n",**(uint32 **)(element));
            #endif // CIRCULAR_QUEUE_DEBUG_MODE*/
        }

    }
    return q_ret;


}
/**
  *@brief  remove an element from front of the queue
  *@param  queue_obj pointer to the queue
  *@param  check if element is removed from front of the queue with no errors
  *@return element to be removed from front of the queue with any data type
  */
void* Queue_front(Queue_t *queue_obj,Queue_status_t *q_ret)
{
    void * element=NULL;
    if((NULL== queue_obj)|| (NULL == q_ret))
    {

        *q_ret=Q_NULL_POINTER;

        #ifdef CIRCULAR_QUEUE_DEBUG_MODE
        printf("ERROR: null pointer @ Queue_front.\n");
        #endif // CIRCULAR_QUEUE_DEBUG_MODE
    }
    else
    {

        if(Q_EMPTY==Queue_is_empty(queue_obj))
        {
            *q_ret=Q_EMPTY;

        }
        else
        {

            element=queue_obj->Q_array[queue_obj->Q_front];
            *q_ret=Q_OK;

            #ifdef CIRCULAR_QUEUE_DEBUG_MODE
            printf("front element at queue is %i .\n",*(uint32 *)element);
            #endif // CIRCULAR_QUEUE_DEBUG_MODE

        }
    }
    return element;


}
/**
  *@brief  remove an element from rear of the queue
  *@param  queue_obj pointer to the queue
  *@param  check if element is removed from rear of the queue with no errors
  *@return element to be removed from rear of the queue with any data type
  */
void* Queue_rear(Queue_t *queue_obj,Queue_status_t *q_ret)
{
    void * element=NULL;
    if((NULL== queue_obj) || (NULL == q_ret))
    {

        *q_ret=Q_NULL_POINTER;

        #ifdef CIRCULAR_QUEUE_DEBUG_MODE
        printf("ERROR: null pointer @ Queue_rear.\n");
        #endif // CIRCULAR_QUEUE_DEBUG_MODE
    }
    else
    {
        if(Q_EMPTY==Queue_is_empty(queue_obj))
        {
            *q_ret=Q_EMPTY;

        }
        else
        {

            element=queue_obj->Q_array[queue_obj->Q_rear];
            *q_ret=Q_OK;

            #ifdef CIRCULAR_QUEUE_DEBUG_MODE
            printf("rear element at queue is %i .\n",*(uint32 *)element);
            #endif // CIRCULAR_QUEUE_DEBUG_MODE

        }
    }
    return element;


}
/**
  *@brief  get elements count from the queue
  *@param  queue_obj pointer to the queue
  *@param  element_count pointer to number of elements at the queue
  *@return check if element count returns with no errors
  */
Queue_status_t Queue_count(Queue_t *queue_obj,uint32 *elements_count)
{
    Queue_status_t q_ret=Q_NOK;
    if(NULL== queue_obj)
    {

        q_ret=Q_NULL_POINTER;

        #ifdef CIRCULAR_QUEUE_DEBUG_MODE
        printf("ERROR: null pointer @ Queue_count.\n");
        #endif // CIRCULAR_QUEUE_DEBUG_MODE
    }
    else
    {
        *elements_count = queue_obj->Q_elements_count;
        q_ret=Q_OK;

        #ifdef CIRCULAR_QUEUE_DEBUG_MODE
        printf("Queue has %i elements.\n",*elements_count);
        #endif // CIRCULAR_QUEUE_DEBUG_MODE
    }
    return q_ret;


}
/**
  *@brief  destroy queue object from heap memory
  *@param  queue_obj pointer to the queue to be destroyed
  *@return check if queue is destroyed with no errors
  */
Queue_status_t Queue_destroy(Queue_t *queue_obj)
{

    Queue_status_t q_ret=Q_NOK;
    if(NULL == queue_obj)
    {

        q_ret=Q_NULL_POINTER;

        #ifdef CIRCULAR_QUEUE_DEBUG_MODE
        printf("ERROR: can't destroy the queue due to null pointer.\n");
        #endif // CIRCULAR_QUEUE_DEBUG_MODE
    }
    else
    {

        free(queue_obj->Q_array);
        free(queue_obj);

        q_ret=Q_OK;

        #ifdef CIRCULAR_QUEUE_DEBUG_MODE
        printf("Queue destroyed successfully.\n");
        #endif // CIRCULAR_QUEUE_DEBUG_MODE
    }
    return q_ret;


}
/**
  *@brief  check if queue object is full
  *@param  queue_obj pointer to the queue
  *@return return queue is full
  */
static Queue_status_t Queue_is_full(Queue_t *queue_obj)
{
    Queue_status_t q_ret=Q_NOK;
    if(queue_obj->Q_elements_count == queue_obj->Q_max_size)
    {
        q_ret=Q_FULL;
    }
    else
    {
        q_ret=Q_EMPTY;
    }
    return q_ret;

}
/**
  *@brief  check if queue object is empty
  *@param  queue_obj pointer to the queue
  *@return return queue is empty
  */
static Queue_status_t Queue_is_empty(Queue_t *queue_obj)
{
    Queue_status_t q_ret=Q_NOK;
    if(queue_obj->Q_elements_count == 0)
    {
        q_ret=Q_EMPTY;
    }
    else
    {
        q_ret=Q_FULL;
    }
    return q_ret;

}

