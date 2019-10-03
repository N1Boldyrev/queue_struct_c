#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define TRUE 1
#define FALSE 0

typedef struct
{
    size_t queue_size;
    size_t current_elem;
    size_t data_len;
    char** data;
}Queue;

Queue* queue_create(size_t);
void queue_delete(Queue*);
int queue_is_empty(Queue*);
void enqueue(Queue*, char*);
int dequeue(Queue*);
char* queue_top(Queue*);

Queue* queue_create(size_t data_len)
{
    Queue* new_queue = (Queue*)malloc(sizeof(Queue));
    new_queue->current_elem = 0;
    new_queue->queue_size = 0;
    new_queue->data_len = data_len;
    return new_queue;
}

void queue_delete(Queue* queue)
{
    for(size_t i = 0; i < queue->queue_size; i++)
        free(queue->data[i]);
    free(queue->data);
    free(queue);
}

int queue_is_empty(Queue* queue)
{
    if(queue->data == NULL)
        return 1;
    else return 0;
}

void enqueue(Queue* queue, char* input_data)
{
    queue->queue_size++;
    if(queue_is_empty(queue)==TRUE)
    {
        queue->data = (char**)malloc(sizeof(char*) * queue->queue_size);
        queue->data[0] = (char*)malloc(sizeof(char*) * queue->data_len);
        for(size_t i = 0; i < queue->data_len && i < strlen(input_data); i++)
            queue->data[0][i] = input_data[i];
    }
    else if(queue_is_empty(queue) == FALSE)
    {
        queue->current_elem++;
        queue->data = (char**)realloc(queue->data,sizeof(char*) * queue->queue_size);
        for(size_t i = queue->current_elem; i < queue->queue_size; i++)
            queue->data[i] = (char*)malloc(sizeof(char*) * queue->data_len);
        for(size_t i = 0; i < queue->data_len && i < strlen(input_data); i++)
            queue->data[queue->current_elem][i] = input_data[i];
        
        //Swap elements
        
        char* temp = queue->data[queue->current_elem - 1];
        queue->data[queue->current_elem - 1] = queue->data[queue->current_elem];
        queue->data[queue->current_elem] = temp;
    }
}

int dequeue(Queue* queue)
{
    if(queue_is_empty(queue) == FALSE)
    {
    free(queue->data[queue->current_elem]);
    queue->current_elem--;
    queue->queue_size--;
    queue->data = realloc(queue->data,sizeof(char*) * queue->queue_size);
    return 1;
    }
    else return 0;
}

char* queue_top(Queue* queue)
{
    if(queue_is_empty(queue) == TRUE)
        return "[QUEUE IS EMPTY]";
    else
    {
        return queue->data[queue->current_elem];
    }
}