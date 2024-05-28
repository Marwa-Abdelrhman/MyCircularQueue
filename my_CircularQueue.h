/**
 * @file my_CircularQueue.h
 * @author Marwa Abdelrhman
 * @brief contains declarations of CircularQueue
 * @version 1.0
 * @date 2024-05-24
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef _MY_CIRCULAR_QUEUE_H_
#define _MY_CIRCULAR_QUEUE_H_


#include "Platform_Types.h"

#define NULL (void *) 0

#define CIRCULAR_QUEUE_DEBUG_MODE


typedef struct{

    void ** Q_array;
    uint32  Q_max_size;
    uint32  Q_elements_count;
    sint32  Q_front;
    sint32  Q_rear;
}Queue_t;


typedef enum{
    Q_NOK=0,
    Q_OK,
    Q_NULL_POINTER,
    Q_FULL,
    Q_EMPTY
}Queue_status_t;

/**
  *@brief  create queue object in heap memory
  *@param  queue_obj pointer to the queue created
  *@param  my_size size of elements in the created queue
  *@return check if queue is created with no errors
  */
  Queue_t * Queue_init(Queue_status_t *q_ret,uint32 my_size);
//Queue_status_t Queue_init(Queue_t *queue_obj,uint32 my_size);
/**
  *@brief  add an element at the queue
  *@param  queue_obj pointer to the queue
  *@param  element to be added at the queue with any data type
  *@return check if element is added at the queue with no errors
  */
Queue_status_t Queue_enqueue_element(Queue_t *queue_obj,void *element);
/**
  *@brief  remove an element from the queue
  *@param  queue_obj pointer to the queue
  *@param  element to be removed from the queue with any data type
  *@return check if element is removed from the queue with no errors
  */
Queue_status_t Queue_dequeue_element(Queue_t *queue_obj,void **element);
/**
  *@brief  remove an element from front of the queue
  *@param  queue_obj pointer to the queue
  *@param  element to be removed from front of the queue with any data type
  *@return check if element is removed from front of the queue with no errors
  */
void* Queue_front(Queue_t *queue_obj,Queue_status_t *q_ret);
/**
  *@brief  remove an element from rear of the queue
  *@param  queue_obj pointer to the queue
  *@param  element to be removed from rear of the queue with any data type
  *@return check if element is removed from rear of the queue with no errors
  */
void* Queue_rear(Queue_t *queue_obj,Queue_status_t *q_ret);
/**
  *@brief  get elements count from the queue
  *@param  queue_obj pointer to the queue
  *@param  element_count pointer to number of elements at the queue
  *@return check if element count returns with no errors
  */
Queue_status_t Queue_count(Queue_t *queue_obj,uint32 *elements_count);
/**
  *@brief  destroy queue object from heap memory
  *@param  queue_obj pointer to the queue to be destroyed
  *@return check if queue is destroyed with no errors
  */
Queue_status_t Queue_destroy(Queue_t *queue_obj);
/**
  *@brief  check if queue object is full
  *@param  queue_obj pointer to the queue
  *@return return queue is full
  */
static Queue_status_t Queue_is_full(Queue_t *queue_obj);
/**
  *@brief  check if queue object is empty
  *@param  queue_obj pointer to the queue
  *@return return queue is empty
  */
static Queue_status_t Queue_is_empty(Queue_t *queue_obj);




#endif // _MY_CIRCULAR_QUEUE_H_
