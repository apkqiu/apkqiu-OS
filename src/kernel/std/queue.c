#include "std/queue.h"
#include <stddef.h>
#include "string.h"

void queue_init(Queue *q, void *buffer, uint32_t capacity, uint32_t item_size)
{
    q->buffer = (uint8_t *)buffer;
    q->head = 0;
    q->tail = 0;
    q->capacity = capacity;
    q->item_size = item_size;
}
bool queue_enqueue(Queue *q, const void *data)
{
    if (queue_full(q))
        return false;

    uint8_t *dst = q->buffer + (q->tail * q->item_size);
    memcpy(dst, (const uint8_t *)data, q->item_size);

    q->tail = (q->tail + 1) % q->capacity;
    return true;
}

bool queue_dequeue(Queue *q, void *out)
{
    if (queue_empty(q))
        return false;

    uint8_t *src = q->buffer + (q->head * q->item_size);
    memcpy((uint8_t *)out, src, q->item_size);

    q->head = (q->head + 1) % q->capacity;
    return true;
}

uint32_t queue_count(const Queue *q)
{
    if (q->tail >= q->head)
    {
        return q->tail - q->head;
    }
    else
    {
        return q->capacity - (q->head - q->tail);
    }
}

bool queue_empty(const Queue *q)
{
    return q->head == q->tail;
}

bool queue_full(const Queue *q)
{
    return ((q->tail + 1) % q->capacity) == q->head;
}