#include <stdio.h>
#include <string.h>

char *_strcat(char *dest, char *src)
{
    int dest_len = 0;
    while (dest[dest_len] != '\0') {
        dest_len++;
    }

    int src_len = 0;
    while (src[src_len] != '\0') {
        dest[dest_len + src_len] = src[src_len];
        src_len++;
    }

    dest[dest_len + src_len] = '\0';
    return dest;
}

int main(void)
{
    char s1[98] = "Hello ";
    char s2[] = "World!\n";
    char *ptr;

    printf("%s\n", s1);
    printf("%s", s2);
    ptr = _strcat(s1, s2);
    printf("%s", s1);
    printf("%s", s2);
    printf("%s", ptr);
    return 0;
}

