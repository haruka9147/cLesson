#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fd;
    /* file descripter (cursor) */
    fd = open(/* path */ "myfile", /* flag */ O_WRONLY | O_CREAT, /* file permission */ 0644);
    if(fd < 0)
    {
        printf("error number %d\n", errno); // errno -> global
        perror("Something went wrong.");
        exit(1);
    }

    write(fd, "Hello, world!", 14);
    close(fd);
    return 0;
}