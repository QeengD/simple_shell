#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

int main(void)
{
char command[MAX_COMMAND_LENGTH];
char prompt[] = "#cisfun$ ";
while (1)
{
printf("%s", prompt);
if (fgets(command, sizeof(command), stdin) == NULL)
{
printf("\n");
break;
}
size_t command_length = strlen(command);
if (command_length > 0 && command[command_length - 1] == '\n')
{
command[command_length - 1] = '\0';
}
if (strcmp(command, "exit") == 0)
{
break;
}
pid_t child_pid = fork();
if (child_pid == -1)
{
perror("fork");
}
else if (child_pid == 0)
{
execlp(command, command, (char *)NULL);
perror("execlp");
exit(EXIT_FAILURE);
}
else
{
waitpid(child_pid, NULL, 0);
}
}
return (EXIT_SUCCESS);
}
