#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 4096

void check_files(char *source, char *dest);

/**
* @brief Main function that implements the file copy operation.
*
* This function takes two file names as command line arguments - a source file
* and a destination file - and copies the contents of the source file to the
* destination file.
*
* @param argc Number of command line arguments.
* @param argv Array of strings representing the command line arguments.
* @return Returns 0 on successful execution.
*/

int main(int argc, char *argv[])
{
// Function body

int input_fd, output_fd, read_size, write_size;
char buffer[BUFFER_SIZE];

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
exit(97);
}

check_files(argv[1], argv[2]);

input_fd = open(argv[1], O_RDONLY);
if (input_fd == -1) {
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
if (output_fd == -1) {
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);
}

while ((read_size = read(input_fd, buffer, BUFFER_SIZE)) > 0)
{
write_size = write(output_fd, buffer, read_size);
if (write_size != read_size)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);
}
}

close(input_fd);
close(output_fd);
return 0;
}

void check_files(char *source, char *dest)
{
int source_fd, dest_fd;
struct stat source_stat, dest_stat;

if (strcmp(source, dest) == 0)
{
dprintf(STDERR_FILENO, "Error: Source and destination files are the same\n");
exit(100);
}

source_fd = open(source, O_RDONLY);
if (source_fd == -1) {
dprintf(STDERR_FILENO, "Error: Can't open file %s\n", source);
exit(98);
}

dest_fd = open(dest, O_RDONLY);
if (dest_fd != -1)
{
fstat(source_fd, &source_stat);
fstat(dest_fd, &dest_stat);

if (source_stat.st_ino == dest_stat.st_ino)
{
dprintf(STDERR_FILENO, "Error: Source and destination files are the same\n");
exit(100);
}
}

close(source_fd);
close(dest_fd);
}

