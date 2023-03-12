#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int check_num(char *str);

int main(int argc, char *argv[])
{
if (argc < 2) {
printf("Usage: %s <number>\n", argv[0]);
return 1;
}

if (check_num(argv[1])) {
printf("%s is a valid number\n", argv[1]);
} else {
printf("%s is not a valid number\n", argv[1]);
}

return 0;
}

int check_num(char *str)
{
unsigned int count = 0;

while (count < strlen(str)) {
if (!isdigit(str[count])) {
return 0;
}

count++;
}

return 1;
}

