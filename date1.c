#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
int main()
{
        int fd,temp,b;
        char buff[100],a[100];
        while(1)
        {
                fd = open("/sys/bus/w1/devices/28-0119395ebf91/w1_slave", O_RDONLY);
                char *string="t=";
                read(fd,buff,sizeof(buff));           
                printf("123%s\n",buff);
                for(int i=0;i<sizeof(buff);i++)
                {
                        if(buff[i]==*string&&buff[i+1]==*(string+1))
                        {
                                printf("a:%s\n",&buff[i]);
                                b=i;
                                break;
                        }
                temp = atoi(buff+2+b);
                }
                printf("%s\n",buff+b);
                printf("temp:%d.%dC\n",temp/1000,temp%1000/100);                                
                sleep(1);
                close(fd);                                                              
	}
        return 0;
}
