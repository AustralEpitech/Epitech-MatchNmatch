int nmatch(const char *s1, const char *s2)
{
    int res = 0;

    if (*s2 == '*') {
        res += nmatch(s1, s2 + 1);
        if (*s1)
            res += nmatch(s1 + 1, s2);
    }
    if (*s1 != *s2) {
        return res;
    }
    if (*s1 == '\0') {
        return res + 1;
    }
    return nmatch(s1 + 1, s2 + 1);
}

#include <stdio.h>
int main(int argc, char *argv[])
{
    if (argc != 3) {
        return 1;
    }
    printf("occurences found: %d\n", nmatch(argv[1], argv[2]));
    return 0;
}
