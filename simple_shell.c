#include "simpleshell.h"

/**
 * main - entry
 * 
 * Return: 0 Always (Success)
 */

int main(void)
{
char *cmd = NULL, *cmd_cp = NULL, *token = NULL, *delim = " \n";
size_t n = 0;
int i = 0, argc = 0;
char **argv = NULL;
pid_t pid;

while(1)
{
_putchar('$');
_putchar(' ');

if(getline(&cmd, &n, stdin) == -1)
{
printf("Exiting...\n");
break;
}

cmd_cp = strdup(cmd);
i = 0, argc = 0;
token = strtok(cmd, delim);

while(token != NULL)
{
token = strtok(NULL, delim);
argc++;
}

argv = malloc(sizeof(char *) * argc);
token = strtok(cmd_cp, delim);

while(token != NULL)
{
argv[i] = token;
token = strtok(NULL, delim);
i++;
}
argv[i] = NULL;

for (i = 0; argv[i] != NULL; i++)
{
printf("%s\n", argv[i]);
}

if (strcmp(argv[0], "exit") == 0)
{
printf("Exiting...\n");
break;
}

pid = fork();
if (pid == -1)
return (-1);

if (pid == 0)
{
int check = execve(argv[0], argv, NULL);
if (check == -1)
perror("Error");
}
else
{
wait(NULL);
}
}

free(cmd), free(cmd_cp), free(argv);

return (0);
}
