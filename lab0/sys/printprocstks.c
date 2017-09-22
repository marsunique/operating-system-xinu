#include <conf.h>
#include <kernel.h>
#include <stdio.h>
#include <proc.h>
static unsigned long *esp;
void printprocstks(int priority){
	kprintf("\nvoid printprocstks(int priority)\n");
	struct pentry *procptr = &proctab;
	int i;
	for (i = 0; i < NPROC; i++){
		if (procptr != NULL && procptr->pprio > priority){
			kprintf("Process\t[%s]\n", procptr->pname);
			kprintf("\tpid: %d\n", i);
			kprintf("\tpriority: %d\n", procptr->pprio);
			kprintf("\tbase: 0x%08x\n", (int) procptr->pbase);
			kprintf("\tlimit: 0x%08x\n",(int) procptr->plimit);
			kprintf("\tlen: %d\n", procptr->pstklen);
			if (procptr->pstate == PRCURR){
				asm("movl %esp, esp");
				kprintf("\tpointer: 0x %08x\n", *esp);
			}
			else
				kprintf("\tpointer: 0x %08x\n", procptr->pesp);
		}
		procptr += 1;
	}


}
