/* scount.c - scount */

#include <conf.h>
#include <kernel.h>
#include <sem.h>
#include <proc.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  scount  --  return a semaphore count
 *------------------------------------------------------------------------
 */
SYSCALL scount(int sem)
{
	unsigned long s_time = ctr1000;
extern	struct	sentry	semaph[];

	if (isbadsem(sem) || semaph[sem].sstate==SFREE)
		return(SYSERR);
	s_time = ctr1000 - s_time;
	if (start_syscall_trace == 1){
		frequency[currpid][10] += 1;
		exec_time[currpid][10] += s_time;
	}
	return(semaph[sem].semcnt);
}
