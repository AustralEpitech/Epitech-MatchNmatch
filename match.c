int match(const char *s1, const char *s2)
{
    return (*s2 == '*' && (match(s1, s2 + 1) || (*s1 && match(s1 + 1, s2)))) ||
        (*s1 == *s2 && (!*s1 || match(s1 + 1, s2 + 1)));
}
