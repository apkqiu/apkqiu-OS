#include <stddef.h>
enum StringFlag{
    SFLAG_OVERSIZE = 1,
    SFLAG_OVERFLOW = 2,
};
typedef struct SafeString
{
    size_t length, capacity, required;
    enum StringFlag flags;
    char *raw;
} SafeString;