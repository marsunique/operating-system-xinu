#include <conf.h>
#include <kernel.h>
#include <stdio.h>
#include <proc.h>
#include <lab0.h>
int start_syscall_trace = 0;
int frequency[NPROC][27];
unsigned long exec_time[NPROC][27];
char *sys_call_name[] = {
        "sys_freemem",
        "sys_chprio",
        "sys_getpid",
        "sys_getprio",
        "sys_gettime",
        "sys_kill",
        "sys_receive",
        "sys_recvclr",
        "sys_recvtim",
        "sys_resume",
        "sys_scount",
        "sys_sdelete",
        "sys_send",
        "sys_setdev",
        "sys_setnok",
        "sys_screate",
        "sys_signal",
        "sys_signaln",
        "sys_sleep",
        "sys_sleep10",
        "sys_sleep100",
        "sys_sleep1000",
        "sys_sreset",
        "sys_stacktrace",
        "sys_suspend",
        "sys_unsleep",
        "sys_wait"
};


void syscallsummary_start(){
	start_syscall_trace = 1;
}
void syscallsummary_stop(){
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
				kprintf("\tSyscall: %s, count: %d, average execution time: %u (ms)\n", sys_call_name[j], frequency[i][j], exec_time[i][j]/frequency[i][j]);
			}
		}
	}
}
