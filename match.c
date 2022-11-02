//int match(const char *s1, const char *s2)
//{
//    if (*s2 == '*') {
//        return match(s1, s2 + 1) || (*s1 && match(s1 + 1, s2));
//    }
//    if (*s1 != *s2) {
//        return 0;
//    }
//    if (*s1 == '\0') {
//        return 1;
//    }
//    return match(s1 + 1, s2 + 1);
//}

int match(const char *s1, const char *s2)
{
    return (*s2 == '*' && (match(s1, s2 + 1) || (*s1 && match(s1 + 1, s2)))) ||
        (*s1 == *s2 && (*s1 == '\0' || match(s1 + 1, s2 + 1)));
}

#include <stdio.h>
int main(int argc, char *argv[])
{
    if (argc != 3) {
        return 1;
    }
    if (match(argv[1], argv[2])) {
        printf("Match!\n");
    }
    else {
        printf("No match...\n");
    }
    return 0;
}
