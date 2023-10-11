# cyclic-queue
a NOT thread safe cyclic queue

# usage example

```
// a queue that can hold 10 int
Queue* new_queue = queueCreate(10, sizeof(int));

// add 5 to the queue
int value = 5;
queuePush(new_queue, &value);

// remove the 5 from the queue
int queue_value;
queuePop(new_queue, &queue_value);

// clean the queue
queueDestroy(new_queue);

```

all functions can be found in the header file `queue.h`
