#include <stdio.h>

extern int etext, edata, end;

void printsegaddress(){
	kprintf("void printsegaddress()\n\n");
	kprintf("Current: etext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x\n", &etext-1, *(&etext-1), &edata-1, *(&edata-1), &end-1, *(&end-1));
	kprintf("Preceding: etext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x\n", &etext-2, *(&etext-2), &edata-2, *(&edata-2), &end-2, *(&end-2));
	kprintf("After: etext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x\n", &etext, etext, &edata, edata, &end, end);

}

