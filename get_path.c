#include "simpleshell.h"

/**
 * get_path - Find the path of the argument
 * @cmd: command
 * Return: Always 0 (Success)
 */
char *get_path(char *cmd)
{
char *cmd_cp = NULL, *token = NULL;
char *path, *path_cp, *path_token, *cmd_path = "/bin/pwd";
char *path_delim = ":";
int  argc = 0, cmd_len, dir_len;
char **argv = NULL;
struct stat buffer;

path = getenv("PATH");

if (path != NULL)
{
path_cp = strdup(path);
path_token = strtok(path_cp, path_delim);
cmd_len = strlen(cmd);

while(path_token != NULL)
{
dir_len = strlen(path_token);
cmd_path = malloc(cmd_len + dir_len + 2);
strcpy(cmd_path, path_token);
strcat(cmd_path, "/");
strcat(cmd_path, cmd);
strcat(cmd_path, "\0");

if (stat(cmd_path, &buffer) == 0)
{
free(path_cp);
free(cmd);
free(cmd_cp);
free(argv);
return (0);
}
else
free(cmd_path);
path_token = strtok(NULL, path_delim);
}

free(path_cp);

if (stat(cmd, &buffer) == 0)
{
free(cmd);
free(cmd_cp);
free(argv);
return (0);
}

free(cmd);
free(cmd_cp);
free(argv);
return (0);
}

return (0);
}
