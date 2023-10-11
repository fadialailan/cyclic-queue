/*

a generic circular queue, that needs the size of the data type to function

*/
#ifndef QUEUE_H
#define QUEUE_H


typedef struct Queue_t
{
    unsigned long size;
    unsigned long length;
    unsigned long item_size;
    unsigned long tail;
    unsigned long head;
    char * data;
} Queue;

/**
 * @brief a constructor for the Queue data type
 * 
 * @param size the size of the queue
 * @param item_size the size of a single item in the queue
 * @return a new Queue
 */
Queue* queueCreate(unsigned long size, unsigned long item_size);

/**
 * @brief the distructor for the Queue data type
 * 
 * @param self self
 */
void queueDestroy(Queue* self);

/**
 * @brief a function to push a new item to the queue
 * 
 * @param self self
 * @param item the item to push
 */
void queuePush(Queue* self, void* item);

/**
 * @brief a function to pop an item from the queue
 * 
 * @param self 
 * @param item 
 * @return 0 for success, 1 for empty queue 
 */
int queuePop(Queue* self, void* item);

/**
 * @brief a function that checks if a
 * 
 * @param self 
 * @return 0 for not empty, 1 for empty
 */
int queueIsEmpty(Queue* self);

/**
 * @brief a function to peek at the item at the top of the queue
 * 
 * @param self 
 * @param item 
 * @return 0 for success, 1 for empty queue 
 */
int queuePeek(Queue* self, void* item);

#endif //QUEUE_H
