#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int get_common_length(char *s1, char *s2)
{
    int len = 0;
    while (s1[len] && s2[len] && s1[len] == s2[len])
        len++;
    return len;
}

char *copy_substring(char *src, int len)
{
    char *dest = malloc(len + 1);
    int i = 0;
    while (i < len)
        dest[i++] = *src++;
    dest[len] = '\0';
    return dest;
}

char *find_longest_common(char *s1, char *s2)
{
    char *result = NULL;
    int max_len = 0;
    int current_len;
    char *ptr1 = s1;

    while (*ptr1)
    {
        char *ptr2 = s2;
        while (*ptr2)
        {
            current_len = get_common_length(ptr1, ptr2);
            if (current_len > max_len)
            {
                max_len = current_len;
                free(result);
                result = copy_substring(ptr2, max_len);
            }
            ptr2++;
        }
        ptr1++;
    }
    return result;
}

int find_common_in_all(int argc, char **argv)
{
    if (argc < 3)
        return -1;

    char *common = find_longest_common(argv[1], argv[2]);
    if (!common)
        return -1;

    for (int i = 3; i < argc; i++)
    {
        char *temp = find_longest_common(common, argv[i]);
        free(common);
        common = temp;
        if (!common)
            return -1;
    }

    write(1, common, strlen(common));
    free(common);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc > 2)
        find_common_in_all(argc, argv);
    write(1, "\n", 1);
    return 0;
}
