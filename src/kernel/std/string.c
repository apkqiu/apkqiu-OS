#include "string.h"
#include <stddef.h>
/* ---------- 内存操作函数 ---------- */
#undef memchr
void *memchr(const void *str, int c, size_t n) {
    const unsigned char *p = (const unsigned char *)str;
    unsigned char uc = (unsigned char)c;
    for (size_t i = 0; i < n; ++i) {
        if (p[i] == uc)
            return (void *)(p + i);
    }
    return NULL;
}

int memcmp(const void *str1, const void *str2, size_t n) {
    const unsigned char *p1 = (const unsigned char *)str1;
    const unsigned char *p2 = (const unsigned char *)str2;
    for (size_t i = 0; i < n; ++i) {
        if (p1[i] != p2[i])
            return (p1[i] < p2[i]) ? -1 : 1;
    }
    return 0;
}

void *memcpy(void *dest, const void *src, size_t n) {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    for (size_t i = 0; i < n; ++i)
        d[i] = s[i];
    return dest;
}

void *memmove(void *dest, const void *src, size_t n) {
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    if (d < s) {
        for (size_t i = 0; i < n; ++i)
            d[i] = s[i];
    } else if (d > s) {
        for (size_t i = n; i > 0; --i)
            d[i-1] = s[i-1];
    }
    return dest;
}

void *memset(void *str, int c, size_t n) {
    unsigned char *p = (unsigned char *)str;
    unsigned char uc = (unsigned char)c;
    for (size_t i = 0; i < n; ++i)
        p[i] = uc;
    return str;
}

/* ---------- 字符串操作函数 ---------- */

char *strcat(char *dest, const char *src) {
    char *d = dest;
    while (*d) ++d;
    while (*src)
        *d++ = *src++;
    *d = '\0';
    return dest;
}

char *strncat(char *dest, const char *src, size_t n) {
    char *d = dest;
    while (*d) ++d;
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; ++i)
        d[i] = src[i];
    d[i] = '\0';
    return dest;
}
#undef strchr
char *strchr(const char *str, int c) {
    unsigned char uc = (unsigned char)c;
    while (*str) {
        if ((unsigned char)*str == uc)
            return (char *)str;
        ++str;
    }
    if (uc == '\0')
        return (char *)str;
    return NULL;
}

int strcmp(const char *str1, const char *str2) {
    while (*str1 && *str2 && (*str1 == *str2)) {
        ++str1;
        ++str2;
    }
    return (unsigned char)*str1 - (unsigned char)*str2;
}

int strncmp(const char *str1, const char *str2, size_t n) {
    size_t i;
    for (i = 0; i < n; ++i) {
        if (str1[i] == '\0' || str2[i] == '\0' || str1[i] != str2[i])
            return (unsigned char)str1[i] - (unsigned char)str2[i];
    }
    return 0;
}

int strcoll(const char *str1, const char *str2) {
    /* 简单实现：等同于 strcmp */
    return strcmp(str1, str2);
}

char *strcpy(char *dest, const char *src) {
    char *d = dest;
    while (*src)
        *d++ = *src++;
    *d = '\0';
    return dest;
}

char *strncpy(char *dest, const char *src, size_t n) {
    char *d = dest;
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; ++i)
        d[i] = src[i];
    for (; i < n; ++i)
        d[i] = '\0';
    return dest;
}

size_t strcspn(const char *str1, const char *str2) {
    size_t count = 0;
    while (str1[count]) {
        const char *p = str2;
        int found = 0;
        while (*p) {
            if (str1[count] == *p) {
                found = 1;
                break;
            }
            ++p;
        }
        if (found) break;
        ++count;
    }
    return count;
}

char *strerror(int errnum) {
    static const char *unknown = "Unknown error";
    static const char *messages[] = {
        "Success",
        "Operation not permitted",
        "No such file or directory",
        "No such process",
        "Interrupted system call",
        "Input/output error"
    };
    if (errnum >= 0 && errnum < (int)(sizeof(messages)/sizeof(messages[0])))
        return (char *)messages[errnum];
    return (char *)unknown;
}

size_t strlen(const char *str) {
    size_t len = 0;
    while (*str++) ++len;
    return len;
}
#undef strpbrk
char *strpbrk(const char *str1, const char *str2) {
    while (*str1) {
        const char *p = str2;
        while (*p) {
            if (*str1 == *p)
                return (char *)str1;
            ++p;
        }
        ++str1;
    }
    return NULL;
}
#undef strrchr
char *strrchr(const char *str, int c) {
    unsigned char uc = (unsigned char)c;
    const char *last = NULL;
    while (*str) {
        if ((unsigned char)*str == uc)
            last = str;
        ++str;
    }
    if (uc == '\0')
        return (char *)str;   /* 指向末尾空字符 */
    return (char *)last;
}

size_t strspn(const char *str1, const char *str2) {
    size_t count = 0;
    while (str1[count]) {
        const char *p = str2;
        int found = 0;
        while (*p) {
            if (str1[count] == *p) {
                found = 1;
                break;
            }
            ++p;
        }
        if (!found) break;
        ++count;
    }
    return count;
}
#undef strstr
char *strstr(const char *haystack, const char *needle) {
    if (*needle == '\0')
        return (char *)haystack;
    const char *h = haystack;
    while (*h) {
        const char *ht = h;
        const char *nt = needle;
        while (*ht && *nt && (*ht == *nt)) {
            ++ht;
            ++nt;
        }
        if (*nt == '\0')
            return (char *)h;
        ++h;
    }
    return NULL;
}

/* ---------- strtok 静态状态 ---------- */
static char *strtok_next = NULL;

char *strtok(char *str, const char *delim) {
    char *token_start;
    if (str != NULL)
        token_start = str;
    else
        token_start = strtok_next;

    if (token_start == NULL)
        return NULL;

    /* 跳过前导分隔符 */
    while (*token_start && strchr(delim, *token_start) != NULL)
        ++token_start;

    if (*token_start == '\0') {
        strtok_next = NULL;
        return NULL;
    }

    char *token_end = token_start;
    while (*token_end && strchr(delim, *token_end) == NULL)
        ++token_end;

    if (*token_end == '\0')
        strtok_next = NULL;
    else {
        *token_end = '\0';
        strtok_next = token_end + 1;
    }
    return token_start;
}

/* ---------- strxfrm ---------- */
size_t strxfrm(char *dest, const char *src, size_t n) {
    size_t len = strlen(src);
    if (n > 0) {
        size_t copy_len = (len < n) ? len : n - 1;  /* 保留一个字节给 '\0' */
        for (size_t i = 0; i < copy_len; ++i)
            dest[i] = src[i];
        dest[copy_len] = '\0';
    }
    return len;
}