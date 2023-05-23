#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
  char *cmd = NULL, *cmd_cp = NULL, *token = NULL;
  char *path, *path_cp, *path_token, *cmd_path = "/bin/pwd";
  size_t n = 0;
  char *delim = " \n", *path_delim = ":";
  int i = 0, argc = 0, cmd_len, dir_len;
  char **argv = NULL;
  struct stat buffer;

  while(1)
    {
      printf("Shell$ ");
         if(getline(&cmd, &n, stdin) == -1)
	   {
	     printf("Exiting....\n");
           return (-1);
	   }
      cmd_cp = strdup(cmd);
      i = 0, argc = 0;
  token = strtok(cmd, delim);

         while (token != NULL)
          {
      token = strtok(NULL, delim);
      argc++;
          }
  argv = malloc(sizeof(char *) * argc);

  token = strtok(cmd_cp, delim);
  while(token)
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

   int check = execve(cmd_path, argv, NULL);
    if (check == -1)
      {
      perror("Error");
      }
    path = getenv("PATH");
    if (path)
      {
	cmd_len = strlen(cmd);
	path_cp = strdup(path);
	path_token = strtok(path_cp, path_delim);

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
            return (-1);
      }
  
             free(cmd), free(cmd_cp), free(argv);
    
          return (-1);
    }
  return (0);
}
