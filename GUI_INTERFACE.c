#include "TYPES.h"										/*include types of variables*/
#include "GUI_INTERFACE.h"								/*gui interface file*/
#include "BACKEND_INTERFACE.h"									/*backend interfface file*/
#include <stdio.h>										/*standard input output liberary*/
u32 Gui_u8Status ;										/*global public variable for current status*/
u32 Gui_u8StatusPrevious ;								/*global public variable for previous status*/
extern checks GUI_EnuGuiTask(void)						/*Gui public function for gui task*/
{
	checks local_EnuStatus =notok;						/*local variable with type checks to return status of the functin ok or notok*/
	if(Gui_u8Status == GUI_SYESTEM_MAIN_MENU)			/* the main page*/
	{
		printf("*********************\n");
		printf("Main menu page\n");
		printf("admin mode press(1)\n");
		printf("user mode press(2)\n");
		printf("close mode press(3)\n");
		Gui_u8Status = GUI_SYESTEM_MAIN_MENU;			/*this status will be sent to the bcak end to dp some operation*/
		checks local_EnuStatus =ok;						/*make status ok*/
	}
	else if(Gui_u8Status == GUI_ADMIN_ENTER_PASSWORD)	/*this the page will appear if you select the admin mode and ask you o enter the password*/
	{
		printf("*********************\n");
		printf("admin enter password page\n");
		printf("please enter your password\n");
		Gui_u8Status = GUI_ADMIN_ENTER_PASSWORD;
		checks local_EnuStatus =ok;						/*make status ok*/
	}
	else if(Gui_u8Status == GUI_WRONG )					/*wrong page status that will apper at any wrong step the  user does*/
	{
		printf("*********************\n");
		printf("wrong\n");
		printf("please enter any number to return to the previous page or 11 to still into current page");
		Gui_u8Status = GUI_WRONG ;
		checks local_EnuStatus =ok;						/*make status ok*/
	}
	else if(Gui_u8Status == GUI_ADMIN_MAIN_MENU )		/*admin main menu for the options of admin*/
	{
		printf("*********************\n");
		printf("admin main menu page\n");
		printf("add new user press(1)\n");
		printf("edit user press(2)\n");
		printf("add new slot press(3)\n");
		printf("delete slot press(4)\n");
		printf("main menu press(5)\n");
		Gui_u8Status = GUI_ADMIN_MAIN_MENU ;
		checks local_EnuStatus =ok;						/*make status ok*/
	}
	else if(Gui_u8Status == GUI_ADMIN_NEW_USER)			/*add new user*/
	{
		printf("*********************\n");
		printf("add new user page\n");
		printf("please enter your id\n");
		printf("please enter your name\n");
		printf("please enter your age\n");
		printf("please enter your gender\n");
		Gui_u8Status = GUI_ADMIN_NEW_USER;
		checks local_EnuStatus =ok;						/*make status ok*/
		
	}
	else if(Gui_u8Status == GUI_ADMIN_EDIT_USER)		/*edit data of user*/
	{
		printf("*********************\n");
		printf("edit user page\n");
		printf("please enter your id\n");
		printf("please enter your new name\n");
		printf("please enter your new age\n");
		printf("please enter your new gender\n");
		Gui_u8Status = GUI_ADMIN_EDIT_USER;
		checks local_EnuStatus =ok;						/*make status ok*/
	}
	else if(Gui_u8Status == GUI_ADMIN_NEW_SLOT)			/*reserve new slot time*/
	{
		printf("*********************\n");
		printf("ADD Slot page\n");
		printf("please enter your id\n");
		printf("please enter your slot\n");
		Gui_u8Status = GUI_ADMIN_NEW_SLOT;
		checks local_EnuStatus =ok;						/*make status ok*/
	}
	else if(Gui_u8Status == GUI_ADMIN_DELET_SLOT)		/*to delete slot*/
	{
		printf("*********************\n");
		printf("Edit Slot page\n");
		printf("please enter your slot\n");
		Gui_u8Status == GUI_ADMIN_DELET_SLOT;
		checks local_EnuStatus =ok;						/*make status ok*/
	}
	else if(Gui_u8Status == GUI_USER_ENTER_ID_check)	/*user enter id page*/
	{
		printf("*********************\n");
		printf("user enter id page\n");
		printf("please enter your id\n");
		Gui_u8Status = GUI_USER_ENTER_ID_check;
		checks local_EnuStatus =ok;						/*make status ok*/
	}
	else if(Gui_u8Status == GUI_USER_MAIN_MENU )		/*main opions of user page*/
	{
		printf("*********************\n");
		printf("user main menu page\n");
		printf("print your information press (1)\n");
		printf("print reservations press (2)\n");
		printf("return to main menu (3)\n");
		Gui_u8Status = GUI_USER_MAIN_MENU;
		checks local_EnuStatus =ok;						/*make status ok*/
	}
	else if(Gui_u8Status  == GUI_USER_PRINT_DATA )		/*print information of user page*/
	{
		printf("*********************\n");
		printf("user information page\n");
		printf("your id is %d\n",GUI_EnuScan_g.id);
		printf("your name issssss %s\n",GUI_EnuScan_g.name);
		printf("your age is %d\n",GUI_EnuScan_g.age);
		printf("your gender is %c\n",GUI_EnuScan_g.gender);
		if(GUI_EnuScan_time_g.id == 0 )			
		{
			printf("no reservaton\n");
		}
		else 
		{
			printf("your reservation is %d\n",GUI_EnuScan_time_g.time);
		}
		Gui_u8Status  = GUI_USER_PRINT_DATA;
		checks local_EnuStatus =ok;						/*make status ok*/
	}
	else if(Gui_u8Status  == GUI_USER_PRINT_RESERVATIONS_1)/*print time slots part1 page*/
	{
		
		printf("*********************\n");
		printf("RESERVATIONS information page\n");
		Gui_u8Status  = GUI_USER_PRINT_RESERVATIONS_1;
		checks local_EnuStatus =ok;/*make status ok*/	
	}
	else if(Gui_u8Status  == GUI_USER_PRINT_RESERVATIONS_2)/*print time slots part2 page*/
	{
		if(GUI_EnuScan_time_g.id != 0 )						/*check for reserved slots*/
		{
			printf("SLOT NUMBER %d is reserved\n",GUI_EnuScan_time_g.time);
			Gui_u8Status  = GUI_USER_PRINT_RESERVATIONS_1;
		}
		else												/*empty time slots*/
		{
			printf("SLOT NUMBER %d is empty\n",GUI_EnuScan_time_g.time);
			Gui_u8Status  = GUI_USER_PRINT_RESERVATIONS_1;
		}
		checks local_EnuStatus =ok;							/*make status ok*/
	}	
}