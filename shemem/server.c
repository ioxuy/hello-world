#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
 char buf[10];
 char *ptr;
  
 int main()
 {
       int fd;
       fd = shm_open("region", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
       if (fd<0) {
	                  printf("error open region\n");
	                  return 0;
	   }
	   ftruncate(fd, 10);
	   ptr = mmap(NULL, 10, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	   if (ptr  == MAP_FAILED) {
	            printf("error map\n");
	            return 0;
	   }
      *ptr = 0x12;
      memset(ptr + 1, 0xaa, 9);
       return 0;
  }
