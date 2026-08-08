#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    void *buffer;    // 底层存储指针（由调用者分配）
    volatile uint32_t head;      // 读指针（出队位置）
    volatile uint32_t tail;      // 写指针（入队位置）
    uint32_t capacity;  // 最大元素个数（非字节数）
    uint32_t item_size; // 每个元素的大小（字节）
} Queue;

// 初始化队列（必须提供外部缓冲区）
void queue_init(Queue *q, void *buffer, uint32_t capacity, uint32_t item_size);

// 入队：拷贝数据到队列尾部（失败返回 false）
bool queue_enqueue(Queue *q, const void *data);

// 出队：拷贝数据到外部指针（失败返回 false）
bool queue_dequeue(Queue *q, void *out);

// 获取当前元素个数
uint32_t queue_count(const Queue *q);

// 判断是否为空/满
bool queue_empty(const Queue *q);
bool queue_full(const Queue *q);