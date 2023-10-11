/*

a generic circular queue, that needs the size of the data type to function

*/
#include <stdlib.h>
#include <string.h>
#include "queue.h"

static void queueResize(Queue* self);

Queue* queueCreate(unsigned long size, unsigned long item_size){
    Queue* self = malloc(sizeof(Queue));
    if (self == NULL) {
        return NULL;
    }
    self->size = size;
    self->length = 0;
    self->item_size = item_size;
    self->tail = 0;
    self->head = 0;
    self->data = malloc(size*item_size);
    return self;
}

void queuePush(Queue* self, void* item) {
    if (self->length == self->size){
        queueResize(self);
    }
    memcpy(self->data+self->item_size*self->head, item, self->item_size);
    self->head = (self->head+1)%self->size;
    self->length += 1;
}

int queuePop(Queue* self, void* item) {
    int result = queuePeek(self, item);
    if (result == 1) {
        return 1;
    }
    self->tail = (self->tail+1)%self->size;
    self->length -= 1;

    return 0;
}

int queuePeek(Queue* self, void* item) {
    if (self->length == 0){
        return 1;
    }
    
    if (item != NULL) {
        memcpy(item, self->data+self->tail*self->item_size, self->item_size);
    }

    return 0;
}

int queueIsEmpty(Queue* self) {
    if (self->length == 0){
        return 1;
    }
    return 0;
}


static void queueResize(Queue* self){
    char* new_data = malloc(self->size*2*self->item_size);
    int new_head;
    for (new_head = 0; new_head<self->size; new_head++) {
        memcpy(new_data+new_head*self->item_size, self->data+self->tail*self->item_size,self->item_size);
        self->tail = (self->tail+1)%self->size;
    }
    self->head = new_head;
    self->tail = 0;
    self->size *= 2;
    free(self->data);
    self->data = new_data;
    
}

void queueDestroy(Queue* self){
    free(self->data);
    free(self);
}

