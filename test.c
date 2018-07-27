// int main(int argc, char *argv[])
// {
//     // file handlers : read from foo, write to bar
//     int fd, fout, rc; /* input and output handlers */
//     char buffer[16384];
//     int count;

//     //printf("read: %s\n", argv[1]);

//     fd = open(argv[1], O_RDONLY);
//     if(fd == -1)
//     {
//         perror(argv[1]);
//         exit(1);
//     }
//     rc = read(fd, buffer, 100);
//     if(rc == -1)
//     {
//         perror(argv[0]);
//         exit(1);
//     }
//     else
//     {
//         buffer[rc] = '\0';
//         printf("read: %s\n", buffer);
//     }
//     // while ((count = read(fin, buffer, 16384)) > 0)
//     // {
//     //     write(fout, buffer, count);
//     // }
//     close(fd);

//     return 0;
// }