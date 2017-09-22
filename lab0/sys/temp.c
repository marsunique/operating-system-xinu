#include <conf.h>
#include <kernel.h>
#include <stdio.h>
#include <proc.h>
#include <lab0.h>
int start_syscall_trace = 0;
int frequency[NPROC][27];
unsigned long exec_time[NPROC][27];
char *sys_call_name = {
        "sys_freemem",0
        "sys_chprio",1
        "sys_getpid",2
        "sys_getprio",3
        "sys_gettime",4
        "sys_kill",5
        "sys_receive",6
        "sys_recvclr",7
        "sys_recvtim",8
        "sys_resume",9
        "sys_scount",10
        "sys_sdelete",11
        "sys_send",12
        "sys_setdev",13
        "sys_setnok",14
        "sys_screate",15
        "sys_signal",16
        "sys_signaln",17
        "sys_sleep",18
        "sys_sleep10",19
        "sys_sleep100",20
        "sys_sleep1000",21
        "sys_sreset",22
        "sys_stacktrace",23
        "sys_suspend",24
        "sys_unsleep",25
        "sys_wait",26
};


void syscallsummary_start(){
        start_syscall_trace = 1;
}
void syscallsummary_stop{
        start_syscall_trace = 0;
}
void printsyscallsummary(){
        int i = 0;
        int j = 0;
        int flag = 0;
        kprintf("\nvoid printsyscallsummary()\n");
        for (i = 0; i < NPROC; i++){
                flag = 1;
                for (j = 0; j < 27; j++){
                        if (frequency[i][j] > 0){
                                if (flag == 1){
                                        kprintf("Process [pid: %d]\n", i);
                                        flag = 0;
                                }
                                kprintf("\tSyscall: %s, count: %n, average execution time: %u (ms)\n", sys_call_name[j], frequency[i][j], exec_time[i][j]/frequency[i][j]);
                        }
                }
        }
}

