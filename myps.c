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
#include "process.h"
#include "structs.h"

#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]){

    
    struct flags flag;
    stat_statm_cmdline_fields fields;
    flag = check_args(argc, argv, flag);
    process(flag, fields);

    return 0;
}