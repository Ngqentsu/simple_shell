#include "simpleshell.h"

/**
 * get_path - Find the path of the argument
 * @cmd: command
 * Return: Path of the string
 */
char *get_path(char *cmd)
{
char *path = getenv("PATH");
char *path_token, *cmd_path;
char *path_delim = ":";
int  cmd_len, dir_len;
struct stat buffer;

if (path != NULL)
{
path_token = strtok(path, path_delim);
cmd_len = strlen(cmd);

while(path_token != NULL)
{
dir_len = strlen(path_token);
cmd_path = malloc(cmd_len + dir_len + 2);
strcpy(cmd_path, path_token);
strcat(cmd_path, "/");
strcat(cmd_path, cmd);

if (stat(cmd_path, &buffer) == 0)
{
return cmd_path;
}
else
free(cmd_path);
path_token = strtok(NULL, path_delim);
}
}
return (NULL);
}
