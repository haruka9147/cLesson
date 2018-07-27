#include <stdio.h>
#include <unistd.h>
#include <string.h>

// FILE *fp = fopen("/Users/kitadaharuka/.g.conf", "r");
#define N 256
void help()
{
    //printf("g name    　: go to name dir.\n");
    printf("g ls      　: list all directions registered.\n");
    printf("g add name　: add current dir as name to the list.\n");
    printf("g rm name 　: remove name dir from the list.\n");
}
void move(char bookmark[])
{
    FILE *fp;
    char line[N];
    char name[N];
    char dir[N];
    int isExist = 0;
    fp = fopen("/Users/kitadaharuka/.g.conf", "r");

    if(fp == NULL)
    {
        perror("can not open file");
        exit(1);
    }
    while(fgets(line, N, fp) != NULL) {
        sscanf(line, "%s %s", name, dir);
        if(strcmp(bookmark, name) == 0)
        {
            isExist = 1;
            if(chdir(dir) == 0)
            {
                printf("move to %s\n", dir);
                break;
            }
            else
            {
                perror("can not to move directory\n");
                exit(1);
            }
        }
    }
    fclose(fp);
    if(!isExist)
    {
        printf("g: %s: not found\n", bookmark);
        exit(1);
    }
    
}
void ls()
{
    FILE *fp;
    char line[N];
    char name[N];
    char dir[N];
    fp = fopen("/Users/kitadaharuka/.g.conf", "r");
    if(fp == NULL)
    {
        perror("can not open file");
        exit(1);
    }
    while(fgets(line, N, fp) != NULL) {
        sscanf(line, "%s %s", name, dir);
        printf("%s -> %s\n", name, dir);
    }
   fclose(fp);
}

void add(char bookmark[])
{
    FILE *fp, *r_fp;
    char line[N];
    char name[N];
    char dir[N];
    int isExist = 0;
    r_fp = fopen("/Users/kitadaharuka/.g.conf", "r");
    char cwd[N];

    if(r_fp == NULL)
    {
        perror("can not open file");
        exit(1);
    }

    //printf("add %s", name);

    if(getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("getcwd() error");
        exit(1);
    }
    else
    {
        while(fgets(line, N, r_fp) != NULL) {
            sscanf(line, "%s %s", name, dir);
            if(strcmp(bookmark, name) == 0)
            {
                
                isExist = 1;
            }
        }

        fclose(r_fp);

        if(isExist == 1)
        {
            printf("name already used.\n");
        }
        else
        {
            fp = fopen("/Users/kitadaharuka/.g.conf", "a");
            fprintf(fp, "%s %s\n", bookmark, cwd);
        }
        fclose(fp);
    }
}

void rm(char bookmark[])
{
    FILE *fp, *w_fp, *temp, *r_temp;
    fp = fopen("/Users/kitadaharuka/.g.conf", "r");
    temp = fopen("/Users/kitadaharuka/temp.txt", "w");

    char line[N];
    char name[N];
    char dir[N];

    if(fp == NULL)
    {
        perror("can not open file");
        exit(1);
    }

    if(temp == NULL)
    {
        perror("can not open file");
        exit(1);
    }

    while(fgets(line, N, fp) != NULL) {
        sscanf(line, "%s %s", name, dir);
        if(strcmp(bookmark, name) != 0)
        {
            //printf("Not found!\n");
            fprintf(temp, "%s %s\n", name, dir);
        }
    }

    fclose(fp);
    fclose(temp);

    w_fp = fopen("/Users/kitadaharuka/.g.conf", "w");
    r_temp = fopen("/Users/kitadaharuka/temp.txt", "r");

    if(w_fp == NULL)
    {
        perror("can not open file");
        exit(1);
    }

    if(r_temp == NULL)
    {
        perror("can not open file");
        exit(1);
    }

    while(fgets(line, N, r_temp) != NULL) {
        sscanf(line, "%s %s", name, dir);
        fprintf(w_fp, "%s %s\n", name, dir);
    }

    fclose(w_fp);
    fclose(r_temp);

    if(remove("/Users/kitadaharuka/temp.txt") != 0)
    {
        perror("Cannot delete.\n");
        exit(1);
    }
}

int main(int argc, char *argv[])
{
    /* Example code */
    // TODO: Command line argument check!
    if(argc > 2)
    {
        if (strcmp(argv[1], "rm") == 0)
        {
            rm(argv[2]);
        }
        if (strcmp(argv[1], "add") == 0)
        {
            add(argv[2]);
        }
    }
    else if(argc > 1)
    {
        if (strcmp(argv[1], "help") == 0)
        {
            help();
        }
        else if (strcmp(argv[1], "ls") == 0)
        {
            ls();
        }
        else
        {
            move(argv[1]);
        }
    }
    else
    {
        help();
    }
    
    return 0;
}