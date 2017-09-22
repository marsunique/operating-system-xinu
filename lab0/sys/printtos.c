#include <stdio.h>
static unsigned long *ebp;
static unsigned long *esp;
void printtos(){
	asm("movl %ebp, ebp");
	kprintf("\nvoid printtos()\n");
	kprintf("Before[0x%08x]: 0x%08x\n", (ebp+2), *(ebp+2));
	kprintf("After [0x%08x]: 0x%08x\n", ebp, *ebp);

	asm("movl %esp, esp");
	int i;
	for(i=3; i>=0; i--){
		kprintf("\telement[0x%08x]: 0x%08x\n", (esp+i), *(esp+i));
	}
	

}
