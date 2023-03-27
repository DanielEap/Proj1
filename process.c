#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <ctype.h>
#include <pwd.h>
#include "parse.h"
#include "options.h"
#include "structs.h"

#define TRUE 1
#define FALSE 0

void process(struct flags flag, stat_statm_cmdline_fields fields){
    struct stat buffer;

    DIR *dir;
    struct dirent *entry;
    
    if((dir = opendir("/proc")) == NULL){
        perror("opendir");
        exit(EXIT_FAILURE);
    }
    if(flag.flag_p == TRUE){
        fields = parse(flag,fields);
        printf("%s: ", flag.pid);
        if(flag.flag_s == TRUE){
            printf("%c ", fields.proc_state);
        }
        if(flag.flag_S == TRUE){
            printf("stime = %u ", fields.proc_stime);
        }
        if(flag.flag_U != TRUE){
            printf("utime = %u ",fields.proc_utime);
        }
        if(flag.flag_v == TRUE){
            printf("size = %u ", fields.proc_virtual_mem_size);
        }
        if(flag.flag_c != TRUE){
            printf("[%s] ",fields.cmdline);
        }
        puts("");
    }
    else{
        while(((entry = readdir(dir)) != NULL)){
            if(entry->d_name[0] == '0'|| entry->d_name[0] == '1'|| entry->d_name[0] == '2'|| 
            entry->d_name[0] == '3'|| entry->d_name[0] == '4'|| entry->d_name[0] == '5'||
            entry->d_name[0] == '6'|| entry->d_name[0] == '7'|| entry->d_name[0] == '8'||
            entry->d_name[0] == '9'){
                char path[4096];
                strcpy(flag.pid, entry->d_name);
                fields = parse(flag,fields);
                strcpy(path, "/proc/");
                strcat(path, entry->d_name);
            
                DIR* direct;
                if((direct = opendir(path)) == NULL){
                    perror("opendir");
                }
                pid_t uid = getuid();
                stat(path, &buffer);
                //printf("uid: %d\n", buffer.st_uid);
                if(uid == buffer.st_uid){
                    printf("%s: ", flag.pid);
                    if(flag.flag_s == TRUE){
                        printf("%c ", fields.proc_state);
                    }
                    if(flag.flag_S == TRUE){
                        printf("stime = %u ", fields.proc_stime);
                    }
                    if(flag.flag_U != TRUE){
                        printf("utime = %u ",fields.proc_utime);
                    }
                    if(flag.flag_v == TRUE){
                        printf("size = %u ", fields.proc_virtual_mem_size);
                    }
                    if(flag.flag_c != TRUE){
                        printf("[%s] ",fields.cmdline);
                    }
                    puts("");
                }
                
            }
        }
    }
}
