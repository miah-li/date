#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main()
{
        int fd,temp;
        char buff[100];
        while(1)
        {
                fd = open("/sys/bus/w1/devices/28-0119395ebf91/w1_slave", O_RDONLY);
                char *string1=buff;
                char *string2="t=";
                read(fd,buff,sizeof(buff));
                printf("%s\n",buff);
                char *a=strstr(string1, string2);
                printf("a:%s\n",a);
                temp = atoi(a+2);                                                               
                printf("temp:%d.%dC\n",temp/1000,temp%1000/100);
                sleep(1);
                close(fd);
        }
        return 0;
}

