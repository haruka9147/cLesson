#include <stdio.h>
#include <stdlib.h> // exit()
#include <fcntl.h>  // open(), write()

int main(int argc, char *argv[])
{
    // file handlers : read from foo, write to bar
    int fin, fout; /* input and output handlers */
    char buffer[16384];
    int count;

    if ((fin = open(argv[1], O_RDONLY)) < 0)
    {
        perror(argv[1]);
        exit(1);
    }
    if ((fout = open(argv[2], O_WRONLY | O_CREAT, 0644)) < 0)
    {
        perror(argv[2]);
        exit(1);
    }

    while ((count = read(fin, buffer, 16384)) > 0)
    {
        write(fout, buffer, count);
    }
    close(fin);
    close(fout);

    return 0;
}