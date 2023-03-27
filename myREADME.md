Week 1:

Proc files to use are:
    /proc/[pid] for the -p option, use collection of proc/tty and /proc/cmdline to help display the information
    /proc/[pid]/stat for -s option, looking at the third field; state %c
    /proc/[pid]/stat for -U option, looking at the 14 field; utime %lu
    /proc/[pid]/stat for -S option, looking at the 15 field; stime %lu
    /proc/[pid]/stat for -v option, looking at the 23 field; vsize %lu
        could also use /proc/[pid]/smaps and use the "VmFlags"
        /proc/[pid]/status, seemingly more detailed version of /stat, gives a bunch of values for different datas about VM
        could also look deeper into the directory /proc/sys/vm, for all things memory management
        /prov/vmstat seems most promising giving multiple statistics
    /proc/[pid]/cmdline or proc/cmdline for -c option

parsing:
    parsing through the /stat file seems fairly easy as being able to just iterate through all the different fields and capture the specific field that is needed. refer constantly to the man pages to check all the output details of each cat call of the proc files.

for warmup:
    using opening tools to choose between; open, fopen, or maybe popen. Use on /proc/cpuinfo and /proc/meminfo in read mode in order to get the all of the information found in those files and then parse through them until the stat needed is found.

Week 2:completed warmup activity using fopen for the proc file, get line to scan through every single entry. used strstr to check for specifically the entries we want. tokenized to get a better string formating. repeated steps for both of them. created make file. worked on processs id list.