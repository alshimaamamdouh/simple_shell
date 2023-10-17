#include "shell.h"
/**
 *non_intractive_mode - deal with non interactive mode
 *
 *@filename: file name
*/
void non_intractive_mode(const char *filename)
{
int fd;
ssize_t read_result;
char line[4096];
fd = open(filename, O_RDONLY);
if (fd == -1)
{
perror("Error opening file");
exit(1); }
while ((read_result = read(fd, line, sizeof(line))) > 0)
write(STDOUT_FILENO, line, read_result);
close(fd);

}
