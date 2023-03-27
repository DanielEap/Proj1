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
#include "options.h"
#define TRUE 1



struct flags check_args(int argc, char *argv[], struct flags flag){
    // struct flags flag_pass =;
    int opt;
    int arg_i = 1;

    extern int optind; //gives the position of the argument not starting after argv[0]
    int is_num;
    //checks for the available options
    while((opt = getopt(argc, argv, "psUSvc")) != -1) 
    { 
        //printf("option: %d, is_num: %d\n", optind, is_num);
        arg_i++;
        switch(opt) 
        { 
            
            // once functions are built, after each case, call the appropriate function 
            case 'p':
                if(optind == argc){
                    printf("no pid was entered");
                    exit(EXIT_FAILURE);
                }
                //checks if the following thing after p is a number/pid, then can work through
                if((is_num = digits(argv[optind])) == 1){
                  
                    //if(kill(num, 0) == 0 ){
                        strcpy(flag.pid,argv[optind]);
                        flag.flag_p = TRUE;
                        //printf("%s is valid PID", argv[optind]);
                    // }else{
  
                    //     printf("not valid pid");
                    //     exit(EXIT_FAILURE);
                    // }   
                    //++ in order to skip over the number so getopt doesnt freak out
                    optind++;
                }else{
                    perror("no pid was entered");
                    exit(-1);
                }

               
                break; 

            //all of the other cases, when functions built, call them 
            case 's': 
                flag.flag_s = TRUE;
                break; 
            case 'U': 
                flag.flag_U = TRUE;
                break; 
            case 'S': 
                flag.flag_S = TRUE;
                break; 
            case 'v': 
                flag.flag_v = TRUE;
                break; 
            case 'c': 
                flag.flag_c = TRUE;
                break; 
            default:
                printf("Invalid option");
                exit(EXIT_FAILURE);
        } 
    } 
    return flag;
}
int digits(const char *s){
    while (*s) {
        if (isdigit(*s++) == 0){
            return 0;
        }
    }

    return 1;
}