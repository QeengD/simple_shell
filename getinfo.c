#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 1024

void shell_loop() 
{
char input[MAX_INPUT_LENGTH];
int status = 1;
while (status) 
{
printf("Shell> ");
fgets(input, MAX_INPUT_LENGTH, stdin); 
if (strcmp(input, "exit\n") == 0) 
{
status = 0;
} else {
}
}
}
int main() 
{
shell_loop();
return 0;
}
