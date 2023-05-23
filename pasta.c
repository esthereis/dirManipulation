#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  DIR *dir;               // the directory adress in memory
  struct dirent *dirread; // the directory adress in memory to be readed

  dir = opendir(argv[1]);
  if (dir == NULL)
  {
    printf("Could not read the file\n");
    return 1;
  }

  else
  {
    printf("Opened the file sucessfully!\n");

    while ((dirread = readdir(dir)) != NULL)
    {

      if (strstr(dirread->d_name, ".pdf") != NULL)
      {
        char address[] = "";
        strcpy(address, argv[1]);
        strcat(address, dirread->d_name);

        int isRemoved = remove(address);
        printf("%s: %i\n", address, isRemoved);
      }
    }
  }
  /*
    if (dir == NULL)
    {
      printf("Directory sucessfully cleaned up!\n");
    }*/
  closedir(dir);

  return 0;
}