#include <stdio.h>
#include <string.h>
#define CORNER 1000

int getLine(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1; ++i)
    {
        c = getchar();
        if (c == EOF) // ctrl D or C
        {
            break;
        }
        if (c == '\n')
        {
            break;
        }
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int lower(int ch)
{
  if(ch >= 'A' && ch <= 'Z')
  {
    return ch + 'a' - 'A';
  } else 
  {
    return ch;
  }
}

int htoi(char s[])
{
    int result = 0;
    for(int i = 0; s[i] != '\0'; i++)
    {
        result = result * 16;
        if(s[i] >= '0' && s[i] <= '9')
        {
            result += s[i] - '0';
        }
        if(s[i] >= 'A' && s[i] <= 'F')
        {
            result += s[i] - 'A';
        }
    }
    return result;
}

// void squeeze(char s[], int c)
// {
//   int i, j;
  
//   for(i = j = 0; s[i] != '\0'; i++)
//   {
//     if(s[i] != c)
//     {
//       s[j++] = s[i];
//     }
//   }
//   s[j] = '\0';
// }

void squeeze(char s[], char t[])
{
    int i, j, k;
    int check = 0;

    for(i = j = 0; s[i] != '\0'; i++) 
    {
        check = 0;
        for(k = 0; t[k] != '\0'; k++) // AP, AP, AP
        {
            if(s[i] == t[k])
            {
                check = 1;
            }
        }
        if(!check)
        {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}

int any(char s[], char t[])
{
    int i, j, k;

    for(i = 0; s[i] != '\0'; i++)
    {
        for(k = 0; t[k] != '\0'; k++)
        {
            if(s[i] == t[k])
            {
                return i;
            }
        }
    }

    return -1;

}

void strCat(char s[], char t[])
{
  int i, j;
  
  i = j = 0;
  while(s[i] != '\0') /* find end of s */
    i++;
  while((s[i++] = t[j++]) != '\0') /* copy t */
    ;
}

int main()
{
    printf("%lu\n", strlen("aaa"));
    printf("%d\n", CORNER);
    printf("%c\n", lower('B'));
    printf("%d\n", htoi("11"));

    char s[] = "Apple";
    char t[] = "Ap";
    // squeeze
    squeeze(s, t);
    
    // concat
    //strCat(s, t);
    printf("%s\n", s);

    printf("%d\n", any(s,t));
    return 0;
}