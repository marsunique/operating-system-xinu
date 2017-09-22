/* gettime.c - gettime */

#include <conf.h>
#include <kernel.h>
#include <date.h>
#include <proc.h>
#include <lab0.h>

extern int getutim(unsigned long *);

/*------------------------------------------------------------------------
 *  gettime  -  get local time in seconds past Jan 1, 1970
 *------------------------------------------------------------------------
 */
SYSCALL	gettime(long *timvar)
{
    /* long	now; */

	/* FIXME -- no getutim */
	unsigned long s_time = ctr1000;
	s_time = ctr1000 - s_time;
	if (start_syscall_trace == 1){
		frequency[currpid][4] += 1;
		exec_time[currpid][4] += s_time;
	}
	return OK;
}
