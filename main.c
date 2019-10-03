#include "queue.h"

int main()
{
    Queue* new_q = queue_create(100);
    enqueue(new_q,"Hello");
    enqueue(new_q,"World");
    printf("%s\n",queue_top(new_q));
    dequeue(new_q);
    printf("%s\n",queue_top(new_q));
    dequeue(new_q);
    printf("%s\n",queue_top(new_q));
    queue_delete(new_q);
    return 0;
}