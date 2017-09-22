/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
SYSCALL getpid()
{
	unsigned long s_time = ctr1000;
	s_time = ctr1000 - s_time;
	if (start_syscall_trace == 1){
		frequency[currpid][2] += 1;
		exec_time[currpid][2] += s_time;
	}
	return(currpid);
}
