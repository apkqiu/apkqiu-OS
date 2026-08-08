#include "safe_string.h"
#include <stdint-gcc.h>
#include "string.h"

static inline char check_overflow(size_t a, size_t b)
{
    return a > SIZE_MAX - b;
}

static inline void add_requirement(SafeString *s, size_t count)
{
    if (check_overflow(s->required, count))
    {
        s->flags |= SFLAG_OVERFLOW; // s->required不反应实际情况
    }
    s->required += count; // 保持追踪，即使已经损坏，此时表示长度模2^64
}

static inline size_t max_allowed(SafeString *s, size_t count)
{
    if (s->flags & SFLAG_OVERSIZE || s->capacity <= s->length) // 无剩余空间（包括留给'\0'）
        return 0;
    size_t available = s->capacity - s->length - 1; // 可写入字符数（不含'\0'）
    if (available >= count)
        return count;
    return available;
}

void new_safe_string(SafeString *s, char *buffer, size_t capacity, size_t length)
{
    s->raw = buffer;
    s->capacity = capacity;
    s->length = length;
    s->required = length;
    s->flags = 0;
}

void new_count_only_string(SafeString *s){
    s->raw = NULL;
    s->capacity = 0;
    s->length = 0;
    s->required = 0;
    s->flags = SFLAG_OVERSIZE;
}

void append_char(SafeString *s, const char c)
{
    add_requirement(s, 1);
    if (max_allowed(s, 1) == 0)
    {
        s->flags |= SFLAG_OVERSIZE;
        return;
    }
    s->raw[s->length++] = c;
}
void append_string(SafeString *s, const char *t, size_t count)
{
    add_requirement(s, count);
    size_t t_count = max_allowed(s, count);
    if (t_count != count)
        s->flags |= SFLAG_OVERSIZE;
    if (t_count == 0)
        return;
    memcpy(s->raw + s->length, t, t_count);
    s->length += t_count;
}
void close_string(SafeString *s)
{
    if (s->capacity > 0)
    {
        if (s->length < s->capacity)
        {
            s->raw[s->length] = '\0';
        }
        else
        {
            s->raw[s->capacity - 1] = '\0';
            s->length = s->capacity - 1;
        }
    }
}