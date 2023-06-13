#include "../lib/queue.h"
#include <stdlib.h>
#include <stdio.h>
// Global list-head variable so queue object doesn't get lost
struct _queue_object *front;

int queue_add(void *new_object, queue_object *queue)
{
    if (new_object == NULL || queue == NULL)
    {
        return 1;
    }

    // create new node
    queue_object *new_node = (queue_object *)malloc(sizeof(queue_object));
    new_node->object = new_object;
    new_node->next = NULL;

    // first initilisation of queue node and front
    if (queue->object == NULL)
    {
        *queue = *new_node;
        front = queue;
    }
    else
    {
        // add new nodes to the end of the list
        queue_object *listend = queue;

        while (listend->next != NULL)
        {
            listend = listend->next;
        }

        listend->next = new_node;
    }
    // free(new_node);
    return 0;
}

void *queue_poll(queue_object *queue)
{
    // re-initilizise queue
    // queue = front;
    if (queue == NULL || queue->object == NULL)
    {
        return NULL;
    }

    if (front == NULL)
    {
        return NULL;
    }

    // create temp variable to get and delete the node of the oldest element in the list
    queue_object *temp = NULL;
    void *object = NULL;
    temp = front;
    front = queue->next;
    object = temp->object;

    free(temp);
    if (front != NULL)
    {
        *queue = *front;
    }

    return object;
}

queue_object *new_queue()
{
    // create new queue
    queue_object *objnode = (queue_object *)malloc(sizeof(queue_object));
    objnode->object = NULL;
    objnode->next = NULL;
    return objnode;
}

void free_queue(queue_object *queue)
{

    // queue_object *current = queue;
    while (queue != NULL)
    {
        queue_object *current = queue;
        queue = queue->next;
        if (current->object != NULL)
        {
            free(current);
        }
    }
}

void *queue_peek(queue_object *queue)
{

    if (front == NULL)
    {
        return NULL;
    }

    void *object = queue->object;
    return object;
}
