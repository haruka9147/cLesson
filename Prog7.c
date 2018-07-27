#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid arguements: use ./Hello en\n");
        exit(1);
    }
    if (strcmp(argv[1], "en") == 0)
    {
        printf("%s: Hello\n", argv[1]);
    }
    else if (strcmp(argv[1], "jp") == 0)
    {
        printf("%s: Konnichiwa\n", argv[1]);
    }
    else if (strcmp(argv[1], "es") == 0)
    {
        printf("%s: Hola\n", argv[1]);
    }
    else if (strcmp(argv[1], "ch") == 0)
    {
        printf("%s: Nihao\n", argv[1]);
    }
    else
    {
        printf("%s: Hi\n", argv[1]);
    }
    return 0;
}