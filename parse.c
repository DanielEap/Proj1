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

stat_statm_cmdline_fields parse(struct flags flag, stat_statm_cmdline_fields fields){
    int n;
    struct stat buffer;
    char path[4096];

    strcpy(path,"/proc/");
    strcat(path, flag.pid);
    
    if((n = stat(path, &buffer)) == -1){
        perror("stat");
        exit(EXIT_FAILURE);
    }
    
    
    
    strcat(path,"/stat");
    FILE *fp = fopen(path, "r");
    
    char unused[4096];
    fscanf(fp, "%s %s %c %s %s %s %s %s %s %s %s %s %s %u %u ", flag.pid, unused, &fields.proc_state,
        unused, unused, unused, unused, unused, unused, unused, unused, unused, unused,
        &fields.proc_utime, &fields.proc_stime);

    
   
    strcpy(path,"/proc/");
    strcat(path, flag.pid);
    strcat(path, "/statm");
    fp = fopen(path, "r");
    fscanf(fp, "%u", &fields.proc_virtual_mem_size);


    strcpy(path,"/proc/");
    strcat(path, flag.pid);
    strcat(path, "/cmdline");
    fp = fopen(path, "r");
    fscanf(fp, "%s", fields.cmdline);
    
    
    return fields;
        
}