#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>
int main(){

    char *filename;
    filename = "/proc/cpuinfo";
    FILE *fp = fopen(filename, "r");
    char *line;
    size_t len = 0;
    ssize_t nread;
    char *delim;
    while((nread = getline(&line, &len, fp))!= -1){
        char *ret;
        ret = strstr(line, "processor");
        if(ret){
            //keeps tokenizing to meet the string formatting of the proc file
            delim = strtok(line, ":");
            delim = strtok(NULL, ":");
            char num = delim[1];
            delim[2] = 32;
            //gets rid of \n 
            printf("processor%s",delim);
        }

        // fwrite(line, nread, 1, stdout);

        
        ret = strstr(line, "cache size");
        if(ret){
            delim = strtok(line, ":");
            delim = strtok(NULL, ":");
            printf("with a cache size of%s\n", delim);
        }
       
    }

   
    fclose(fp);
}
