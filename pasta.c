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
      char *fileName = dirread->d_name;
      if (strstr(fileName, ".pdf") != NULL)
      {
        char *adress = strcat(argv[1], fileName);
        int isRemoved = remove(adress);
        printf("%s: %i\n", adress, isRemoved);
        closedir(dir);
      }
        }
  }

  return 0;
}