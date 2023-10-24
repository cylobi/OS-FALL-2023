#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
  if(argc != 3){
    printf(2, "Usage: strdiff string1 string2\n");
    exit();
  }

  char *s1 = argv[1];
  char *s2 = argv[2];
  char result[16];
  int i;

  for(i = 0; i < strlen(s2); i++){
    result[i] = (s1[i] >= s2[i]) ? '0' : '1';
  }
  result[strlen(s2)] = '\0';

  int fd = open("strdiff_result.txt", O_CREATE | O_WRONLY);
  if(fd < 0){
    printf(2, "Error: cannot open file for writing\n");
    exit();
  }

  write(fd, result, 16);
  close(fd);

  exit();
}
