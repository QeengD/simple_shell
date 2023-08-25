#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

int main(void)
{
char command[MAX_COMMAND_LENGTH];
char *args[MAX_ARGS + 1];
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
int num_args = 0;
char *token = strtok(command, " ");
while (token != NULL && num_args < MAX_ARGS)
{
args[num_args++] = token;
token = strtok(NULL, " ");
}
args[num_args] = NULL;
pid_t child_pid = fork();
if (child_pid == -1)
{
perror("fork");
}
else if (child_pid == 0)
{
execvp(args[0], args);
perror("execvp");
exit(EXIT_FAILURE);
}
else
{
waitpid(child_pid, NULL, 0);
}
{
return (EXIT_SUCCESS);
}
