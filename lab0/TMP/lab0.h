//Task 1
extern long zfunction(long);

//Task 2
extern void printsegaddress();

//Task 3
extern void printtos();

//Task 4
extern void printprocstks(int);

// Task 5
extern void printsyscallsummary();
extern void syscallsummary_start();
extern void syscallsummary_stop();
extern int start_syscall_trace;
extern int frequency[NPROC][27];
extern unsigned long exec_time[NPROC][27];
extern unsigned long ctr1000;
