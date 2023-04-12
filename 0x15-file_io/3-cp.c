#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

/**
* main - Copies the content of a file to another file
* @argc: Number of arguments
* @argv: Array of arguments
*
* Return: 0 on success, otherwise 97, 98, 99 or 100
*/
int main(int argc, char **argv)
{
int fd_from, fd_to, read_count, write_count;
char buf[BUF_SIZE];

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);
}

do {
read_count = read(fd_from, buf, BUF_SIZE);
if (read_count == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

write_count = write(fd_to, buf, read_count);
if (write_count == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);
}

} while (read_count > 0);

if (close(fd_from) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
exit(100);
}

if (close(fd_to) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
exit(100);
}

return (0);
}

