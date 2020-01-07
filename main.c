#include<stdio.h>
#include "TYPES.h"
#include "GUI_INTERFACE.h"
#include "BACKEND_INTERFACE.h"
int main(void)
{
	int i ;
	Backend_EnuBackendTask_init();
	while(1)
	{
	GUI_EnuGuiTask();
	if(Backend_EnuBackendTask()==notok)
	{
		return 0   ;
	}
	}
	
	
	
}

