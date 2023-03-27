#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>
int main(){

    char *filename;
    filename = "/proc/meminfo";
    FILE *fp = fopen(filename, "r");
    char *line;
    size_t len = 0;
    ssize_t nread;
    char *delim;
    while((nread = getline(&line, &len, fp))!= -1){
        char *ret;
        ret = strstr(line, "MemFree");
        if(ret){
            delim = strtok(line, ":");
            delim = strtok(NULL, " ");
            printf("Free Memory %s",delim);
            delim = strtok(NULL, " ");
            printf("%s",delim);

        }

        ret = strstr(line, "Buffers");
        if(ret){
            delim = strtok(line, ":");
            delim = strtok(NULL, " ");
            printf("Buffers: %s", delim);
            delim = strtok(NULL, " ");
            printf("%s\n", delim);
        }
       
    }
    
   
    fclose(fp);
}
