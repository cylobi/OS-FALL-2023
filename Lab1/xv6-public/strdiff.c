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

  for(i = 0; i < 15; i++){
    char c1 = (i < strlen(s1)) ? s1[i] : 'z' + 1;
    char c2 = (i < strlen(s2)) ? s2[i] : 'z' + 1;
    result[i] = (c1 >= c2) ? '0' : '1';
  }
  result[15] = '\0';

  int fd = open("strdiff_result.txt", O_CREATE | O_WRONLY);
  if(fd < 0){
    printf(2, "Error: cannot open file for writing\n");
    exit();
  }

  write(fd, result, 16);
  close(fd);

  exit();
}
