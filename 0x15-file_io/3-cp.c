#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int open_file(char *file_name, int mode, mode_t permission);
void copy_file(int fd_from, int fd_to, char *file_name_from, char *file_name_to);
void close_file(int fd, char *file_name);

/**
* main - Copies the content of a file to another file
* @argc: Number of arguments
* @argv: Array of arguments
* Return: 0 on success, otherwise 97, 98, 99 or 100
*/
int main(int argc, char **argv)
{
int fd_from, fd_to;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

fd_from = open_file(argv[1], O_RDONLY, 0);
fd_to = open_file(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

copy_file(fd_from, fd_to, argv[1], argv[2]);

close_file(fd_from, argv[1]);
close_file(fd_to, argv[2]);

return (0);
}

/**
* open_file - opens a file
* @file_name: name of file to open
* @mode: mode to open file
* @permission: permission to open file
* Return: file descriptor of opened file
*/
int open_file(char *file_name, int mode, mode_t permission)
{
int fd = open(file_name, mode, permission);

if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_name);
exit(98);
}

return (fd);
}

/**
* copy_file - copies content of one file to another file
* @fd_from: file descriptor of file to copy from
* @fd_to: file descriptor of file to copy to
* @file_name_from: name of file to copy from
* @file_name_to: name of file to copy to
*/
void copy_file(int fd_from, int fd_to, char *file_name_from, char *file_name_to)
{
ssize_t read_count, write_count;
char buf[BUF_SIZE];

do {
read_count = read(fd_from, buf, BUF_SIZE);
if (read_count == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_name_from);
exit(98);
}

write_count = write(fd_to, buf, read_count);
if (write_count == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_name_to);
exit(99);
}

} while (read_count > 0);
}

/**
* close_file - closes a file
* @fd: file descriptor of file to close
* @file_name: name of file to close
*/
void close_file(int fd, char *file_name)
{
int close_status = close(fd);

if (close_status == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

