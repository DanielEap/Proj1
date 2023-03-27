#ifndef STRUCTS_H
#define STRUCTS_H


typedef struct{
    char proc_state;
    unsigned int proc_utime;
    unsigned int proc_stime;
    int proc_virtual_mem_size;
    char cmdline[4096];
} stat_statm_cmdline_fields;

struct flags{
    int flag_p;
    int flag_s;
    int flag_U;
    int flag_S; 
    int flag_v;
    int flag_c;
    char pid[1000];
};


#endif