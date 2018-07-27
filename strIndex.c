#include <stdio.h>

// int strrindex(char s[], char t)
// {
//     int i;
//     int index = -1;

//     for(i = 0; s[i] != '\0'; i++)
//     {
//         if(s[i] == t)
//         {
//             index = i;
//         }
//     }

//     return index;
// }

// int main()
// {
//     char s[] = "applele";
//     char t = 'l';

//     printf("answer: %d\n", strrindex(s, t));
// }

int strrindex(char s[], char t[])
{
    int i, j, k;
    int index = -1;
    int flag = 0;

    for(i = k = 0; s[i] != '\0'; i++)
    {
        flag = 0;
        if(s[i] == t[0])
        {
            for(j = 1; t[j] != '\0'; j++)
            {
                k++;
                if(s[k] != t[j])
                {
                    flag = 1;
                }
                
            }
            if(flag == 0)
            {
                index = i;
            }
        }
        k = i;
        k++;
    }
    
    return index;
}

int main()
{
    char s[] = "applele";
    char t[] = "la";

    printf("answer: %d\n", strrindex(s, t));
}