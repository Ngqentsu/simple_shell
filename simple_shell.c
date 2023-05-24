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
int i = 0, argc = 0, j;
char **argv = NULL;
pid_t pid;

while(1)
{
_putchar('$');
_putchar(' ');

if(getline(&cmd, &n, stdin) == -1)
{
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

token = strtok(cmd_cp, delim);
argv = malloc(sizeof(char *) * argc);
if (argv == NULL)
return (0);

while(token != NULL)
{
argv[i] = token;
token = strtok(NULL, delim);
i++;
}
argv[i] = NULL;

for (i = 0; argv[i] != NULL; i++)
{
for (j = 0; argv[i][j] != '\0'; j++)
_putchar(argv[i][j]);
_putchar('\n');
}

if (strcmp(argv[0], "exit") == 0)
{
break;
}

cmd = get_path(argv[0]);

pid = fork();
if (pid == -1)
{
perror("Error ");
exit(EXIT_FAILURE);
}

if (pid == 0)
{
int check = execve(cmd, argv, NULL);
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
