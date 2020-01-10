#include<stdio.h>/*include standard input output*/
#include<stdlib.h>/*include standard liberary*/
#include "TYPES.h"/*include user standard types*/ 
#include "BACKEND_INTERFACE.h"/*include global public declrations of backend*/
#include "BACKEND_PRIVATE.h"/*include private declrations of backend*/
#include "GUI_INTERFACE.h"/*include public glbal declrations of GUI*/
#include "BACKEND_CONFIGURATION.h"/*incude private declrations*/
PATEINT_T1 * clinic_head_t1 = NULL ;/*global variable as ahead of information list*/
PATEINT_T2 * clinic_head_t2 = NULL ;/*global variable as ahead of time list*/
PATEINT_T1 GUI_EnuScan_g;/*glopal variable for accesing information list*/
PATEINT_T2 GUI_EnuScan_time_g;/*glopal variable for accesing time list*/
static PATEINT_T2 * clinic__t2_PRINT= NULL ;/*glopal  pinter variable for accesing time list*/
extern checks Backend_EnuBackendTask(void)/*BACK END TASK*/
{
	checks local_Enu_Status  = notok;/*intial task with notok*/
	u32 local_u32_scan;/*;local variable to scan integer data*/
	u32 local_u32_main_node;/*local variable to have the main node of the gui*/
	static PATEINT_T1 local_EnuScan;/*local variable of type struct to information list*/
	PATEINT_T2 local_EnuScan_time;/*local variable of type struct to time list*/
	static u8 local_u8Countrr ; /*counter*/
	if(Gui_u8Status == GUI_SYESTEM_MAIN_MENU)/*main menu backend*/
	{
		local_u32_main_node = GUI_SYESTEM_MAIN_MENU ;/*main node -> main menu*/
		private_EnuGetDatatSringToInteger(&local_u32_scan);	
		if(local_u32_scan == BACKEND_ADMIN)/*admin mode*/
		{
			Gui_u8Status = GUI_ADMIN_ENTER_PASSWORD;/*switch to enter password page*/
			local_Enu_Status  = ok;/*make status ok*/
		}
		else if(local_u32_scan == BACKEND_USER)/*user mode*/
		{
			Gui_u8Status = GUI_USER_ENTER_ID_check;/*switch to id page*/
			local_Enu_Status  = ok;/*make status ok*/
			
		}
		else if(local_u32_scan == BACKEND_CLOSE)/*close mode*/
		{
			local_Enu_Status  = notok;/*make status not ok */
		}
		else/*wrong status*/
		{
			Gui_u8StatusPrevious = Gui_u8Status ;
			Gui_u8Status = GUI_WRONG ;
			local_Enu_Status  = ok;
		}
		
	}
	else if(Gui_u8Status == GUI_WRONG )/*wrong status BACKEND*/
	{
		private_EnuGetDatatSringToInteger(&local_u32_scan);
		if(local_u32_scan == BACKEND_WRONG_HANDLING)/*check for continue in the sam path */
		{
			Gui_u8Status = Gui_u8StatusPrevious  ;
			local_Enu_Status  = ok;
		}
		else/*returning to the main mode of the current path*/
		{
			Gui_u8Status = local_u32_main_node;
			local_Enu_Status  = ok;
		}	
	}
	else if(Gui_u8Status == GUI_ADMIN_ENTER_PASSWORD)/*backend of admin password page*/
	{
		local_u32_main_node = GUI_SYESTEM_MAIN_MENU ;/*main node main menu*/
		private_EnuGetDatatSringToInteger(&local_u32_scan);	/*scan password*/
		if(local_u32_scan == BACKEND_PASSWORD)/*password correct*/
		{
			local_Enu_Status  = ok;
			
			Gui_u8Status = GUI_ADMIN_MAIN_MENU;
				local_u8Countrr = BACKEND_ZERO ;
		}
		else /*password not correct*/
		{
			local_u8Countrr++;
			if(local_u8Countrr>BACKEND_TWO)
			{
				local_Enu_Status  = notok;
			}
			else
			{
			Gui_u8StatusPrevious = Gui_u8Status ;
			Gui_u8Status = GUI_WRONG ;
			local_Enu_Status  = ok;
			}	
		}
	}
	else if(Gui_u8Status == GUI_ADMIN_MAIN_MENU)/*admin main menu Backend*/
	{
		local_u32_main_node = GUI_ADMIN_MAIN_MENU ;/*main node admin main menu*/
		private_EnuGetDatatSringToInteger(&local_u32_scan);/*scan option*/
		if(local_u32_scan ==  BACKEND_ONE)/*add new customer option*/
		{
			Gui_u8Status = GUI_ADMIN_NEW_USER ;
		}
		else if(local_u32_scan ==  BACKEND_TWO)/*edit customer option*/
		{
			Gui_u8Status = GUI_ADMIN_EDIT_USER ;
		}
		else if(local_u32_scan ==  BACKEND_THREE)/*add new time slot option*/
		{
			Gui_u8Status = GUI_ADMIN_NEW_SLOT ;
		}
		else if(local_u32_scan ==  BACKEND_FOUR)/*delete slot time*/
		{
			Gui_u8Status = GUI_ADMIN_DELET_SLOT  ;
		}
		else if(local_u32_scan ==  BACKEND_FIVE)/*return to system main menu*/
		{
			Gui_u8Status = GUI_SYESTEM_MAIN_MENU  ;
		}
		else
		{
			Gui_u8StatusPrevious = Gui_u8Status ;
			Gui_u8Status = GUI_WRONG ;	
		}
		local_Enu_Status  = ok;/*make the status ok*/
	}
	else if (Gui_u8Status == GUI_ADMIN_NEW_USER)/*add new user back end*/
	{
		private_EnuGetDatatSringToInteger(&local_EnuScan.id);
		scanf(" %s",local_EnuScan.name);
		private_EnuGetDatatSringToInteger(&local_EnuScan.age);
		scanf("  %c",&local_EnuScan.gender);
		if(clininc_EnuGetNode(BACKEND_INFORMATION_LIST,local_EnuScan.id,BACKEND_INFORMATION_SEARCHBY_ID)==ok)/*check id i ino data base or ont*/
		{
			Gui_u8StatusPrevious = Gui_u8Status ;
			Gui_u8Status = GUI_WRONG ;	
		}
		else/*not into data base*/
		{
			clininc_EnuCreateNode(&local_EnuScan,BACKEND_INFORMATION_LIST);
			Gui_u8Status = GUI_ADMIN_MAIN_MENU ;
		}
			
		local_Enu_Status  = ok;/*make the status ok*/
	}
	
	else if (Gui_u8Status == GUI_ADMIN_EDIT_USER)/*edit user backend*/
	{
		private_EnuGetDatatSringToInteger(&local_EnuScan.id);
		private_EnuGetDatatSringToInteger(&local_EnuScan.age);
		scanf("%s",local_EnuScan.name);
		scanf(" %c",&local_EnuScan.gender);
		if(clininc_EnuGetNode(BACKEND_INFORMATION_LIST,local_EnuScan.id,BACKEND_INFORMATION_SEARCHBY_ID)==ok)/*check that the id into data base or not*/
		{
			clininc_EnuEditNodeInformation(local_EnuScan);
			Gui_u8Status = GUI_ADMIN_MAIN_MENU ;
		}
		else/*not in data base*/
		{
			Gui_u8StatusPrevious = Gui_u8Status ;
			Gui_u8Status = GUI_WRONG ;	
		}
		local_Enu_Status = ok;/*make status ok*/
	}
	else if(Gui_u8Status == GUI_ADMIN_NEW_SLOT)/*add new slot backend*/
	{
		private_EnuGetDatatSringToInteger(&local_EnuScan_time.id);
		private_EnuGetDatatSringToInteger(&local_EnuScan_time.time);
		/*check that the id into informtion lit or not*/
		if(clininc_EnuGetNode(BACKEND_INFORMATION_LIST,local_EnuScan_time.id,BACKEND_INFORMATION_SEARCHBY_ID)==ok)
		{
			/*check that the id reserved a slot before into time ist*/
			if(clininc_EnuGetNode(BACKEND_TIME_LIST,local_EnuScan_time.id,BACKEND_INFORMATION_SEARCHBY_ID)==ok)
			{
			   Gui_u8StatusPrevious = Gui_u8Status ;
				Gui_u8Status = GUI_WRONG ;	
			}
			else
			{
				/*check the slot is reserved or not*/
				if(clininc_EnuGetNode(BACKEND_TIME_LIST,local_EnuScan_time.time,BACKEND_INFORMATION_SEARCHBY_TIME)==ok)
				{
					clininc_EnuSearchNodeAddSlot(local_EnuScan_time.time,local_EnuScan_time.id);
					Gui_u8Status = GUI_ADMIN_MAIN_MENU ;	
				}
				else
				{
					Gui_u8StatusPrevious = Gui_u8Status ;
					Gui_u8Status = GUI_WRONG ;	
				}
			}
		}
		else/*not in data base*/
		{	
			Gui_u8StatusPrevious = Gui_u8Status ;
			Gui_u8Status = GUI_WRONG ;	
	
		}
		
		local_Enu_Status = ok ;/*make status ok*/
	}
	else if(Gui_u8Status == GUI_ADMIN_DELET_SLOT)/*delete time slot backend*/
	{
		
		private_EnuGetDatatSringToInteger(&local_EnuScan_time.time);/*scan number of slot*/
		
		if(local_EnuScan_time.time>BACKEND_FIVE)/*check if the number is out of time scope*/
		{
			Gui_u8StatusPrevious = Gui_u8Status ;
			Gui_u8Status = GUI_WRONG ;	
		}	
		else/*slot number int our scope*/
		{
			clininc_EnuEditNodeTimeNull(local_EnuScan_time.time);
			Gui_u8Status = GUI_ADMIN_MAIN_MENU;	
		}
		local_Enu_Status = ok ;	
	}	
	else if(Gui_u8Status == GUI_USER_ENTER_ID_check)/*user id check backend*/
	{
		private_EnuGetDatatSringToInteger(&local_EnuScan.id);/*scan the user id*/
		if(clininc_EnuGetNode(BACKEND_INFORMATION_LIST,local_EnuScan.id,BACKEND_INFORMATION_SEARCHBY_ID)== ok)/*check id into data base*/
		{
			Gui_u8Status = GUI_USER_MAIN_MENU ;
		}
		else/*not into data base*/
		{
			Gui_u8StatusPrevious = Gui_u8Status ;
			Gui_u8Status = GUI_WRONG ;	
		}
		local_Enu_Status = ok ;	/*make status ok*/
	}
	else if(Gui_u8Status == GUI_USER_MAIN_MENU )/*user main menu backend*/
	{
		local_u32_main_node = GUI_USER_MAIN_MENU  ;/*main node user main menu*/
		private_EnuGetDatatSringToInteger(&local_u32_scan);/*scan user options*/
		
		if(	local_u32_scan == BACKEND_ONE)/*print information mode*/
		{
			Gui_u8Status =  GUI_USER_PRINT_DATA ;
			clininc_EnuGetNode(BACKEND_INFORMATION_LIST,local_EnuScan.id,BACKEND_INFORMATION_SEARCHBY_ID);
			clininc_EnuGetNode(BACKEND_TIME_LIST,local_EnuScan.id,BACKEND_INFORMATION_SEARCHBY_ID);
			Gui_u8Status = GUI_USER_PRINT_DATA ;
		}
		else if(local_u32_scan== BACKEND_TWO)/*print time slots*/
		{
			Gui_u8Status  = GUI_USER_PRINT_RESERVATIONS_1;
		}
		else if(local_u32_scan== BACKEND_THREE)/*return to main menu*/
		{
				Gui_u8Status = GUI_SYESTEM_MAIN_MENU ;
		}
		else /*wrong option*/
		{
			Gui_u8StatusPrevious = Gui_u8Status ;
			Gui_u8Status = GUI_WRONG ;
		}
		local_Enu_Status = ok ;	/*make the status ok*/
	}
	else if (Gui_u8Status  == GUI_USER_PRINT_DATA)/*print informatiom*/
	{
		Gui_u8Status = GUI_USER_MAIN_MENU;
		local_Enu_Status = ok ;	
	}
	else if (Gui_u8Status  == GUI_USER_PRINT_RESERVATIONS_1)/*printf time slots backend*/
	{
			local_u8Countrr++;		
			if(local_u8Countrr == BACKEND_ONE)
			{
				clinic__t2_PRINT = clinic_head_t2;/*assign address of ti,e list to the pinter*/ 
			}	
			if(local_u8Countrr>BACKEND_FIVE)/*check for counter*/
			{
				local_u8Countrr = BACKEND_ZERO; /*counter will be zero*/
				Gui_u8Status = GUI_USER_MAIN_MENU;/*return to user main menu*/
			}
			else/*counter less than five*/
			{
				GUI_EnuScan_time_g.time = clinic__t2_PRINT->time;/*assign time to the glopal variable*/
				GUI_EnuScan_time_g.id = clinic__t2_PRINT->id;/*assign id to the glopal variable*/
				clinic__t2_PRINT =  clinic__t2_PRINT->ptr_T2;/*mae pointer points to the next node*/
				
				Gui_u8Status  = GUI_USER_PRINT_RESERVATIONS_2 ;/*move to the part2 of printing time slots*/
			}
			local_Enu_Status = ok ;	/*make the status ok*/
	}
		return  local_Enu_Status;
}
/*init task TO CRATE THE TIME LIST 5 TIME SLOTS */
extern checks Backend_EnuBackendTask_init(void)
{
	u8 loclal_u8counter ; 
	checks local_Enu_Status;
	PATEINT_T2 local_EnuScan_time;
	
	for(loclal_u8counter=BACKEND_ZERO;loclal_u8counter<BACKEND_FIVE;loclal_u8counter++)
	{
		local_EnuScan_time.id = BACKEND_ZERO ; 
		local_EnuScan_time.time = loclal_u8counter+BACKEND_ONE;
		clininc_EnuCreateNode(&local_EnuScan_time,BACKEND_TIME_LIST);
	}
	return  local_Enu_Status = ok;
}
	

/*function to create node for information of user OR NODE FOR TIME*/
static checks clininc_EnuCreateNode(void * Copy_PvoidGetNode,u8 Copy_u8voidGetListName)
{
	
	checks local_clinicsStatus = notok ;/*flag for the creation of the node with notok intial status*/
	if(Copy_u8voidGetListName == BACKEND_INFORMATION_LIST)/*CHECK LIST OF INFORMATION*/
	{
		PATEINT_T1 * local_PT1  = (PATEINT_T1*)malloc(sizeof(PATEINT_T1)); /*create node*/
		if(local_PT1 !=NULL) /*check the node is created or not*/
		{
			local_clinicsStatus = ok ; /*this means that the node is created*/
		}		
		*local_PT1 = *(PATEINT_T1*)Copy_PvoidGetNode;/*assign the data to the created node*/
		if(clinic_head_t1 == NULL)/*check that the node is empty or not*/
		{
			clinic_head_t1 = local_PT1;/*here the list is empty so we will make the head points to the created node*/
			clinic_head_t1->ptr_T1 =NULL; /*then we will make the tail of the node points to null*/
		}
		else/*the list is not empty*/
		{
			PATEINT_T1 * local_move = NULL;/*pointer to information node to move through the linkedlist*/
			local_move =  clinic_head_t1 ;/*here we will try to get the end of the list to add the new created node*/ 
			while(local_move->ptr_T1!=NULL)/*here we check for the last node*/
			{
				local_move =local_move->ptr_T1;/*here we will make move pointer  points to the next node*/
			}
				local_move->ptr_T1 = local_PT1 ;/*here we will make last node points to the new created node*/
				local_PT1->ptr_T1 = NULL ; /*here we will make the created node acts as last node by pointing to null*/
		}
	}
	else if(Copy_u8voidGetListName == BACKEND_TIME_LIST)/*CHECK LIST OF TIME*/
	{
		PATEINT_T2 * local_PT2  = (PATEINT_T2*)malloc(sizeof(PATEINT_T2)); /*create node*/
		if(local_PT2 !=NULL) /*check the node is created or not*/
		{
			local_clinicsStatus = ok ; /*this means that the node is created*/
		}		
		*local_PT2 = *((PATEINT_T2*)Copy_PvoidGetNode);/*assign the data to the created node*/
		
		if(clinic_head_t2 == NULL)/*check that the node is empty or not*/
		{
			clinic_head_t2 = local_PT2;/*here the list is empty so we will make the head points to the created node*/
			clinic_head_t2->ptr_T2 =NULL; /*then we will make the tail of the node points to null*/
		}
		else/*the list is not empty*/
		{
			PATEINT_T2 * local_move = NULL;/*pointer to information node to move through the linkedlist*/
			local_move =  clinic_head_t2 ;/*here we will try to get the end of the list to add the new created node*/ 
			while(local_move->ptr_T2!=NULL)/*here we check for the last node*/
			{
				local_move =local_move->ptr_T2;/*here we will make move pointer  points to the next node*/
			}
				local_move->ptr_T2 = local_PT2 ;/*here we will make last node points to the new created node*/
				local_PT2->ptr_T2 = NULL ; /*here we will make the created node acts as last node by pointing to null*/
		}
	}
	
	return  local_clinicsStatus ;  /*here we return status*/	
}
/*function to get  node information (information list or time list */
static checks clininc_EnuGetNode(u8 Copy_u8voidGetListName,u32 Copy_u8ID,u8 Copy_u8SearchBy)
{
	u8 local_CounterString;
	checks local_clinicsStatus =notok ;/*intial status notok*/
	if(Copy_u8voidGetListName == BACKEND_INFORMATION_LIST)/*CHECK LIST OF INFORMATION*/
	{
		
		PATEINT_T1 * local_move = clinic_head_t1;/*assign head of information list to pointer*/
		if(local_move == NULL)
		{
			local_clinicsStatus = notok ;/*in case of list is emty*/
		}
		else
		{
			if(Copy_u8SearchBy == BACKEND_INFORMATION_SEARCHBY_ID)
				{
							while(local_move !=NULL && local_move->id != Copy_u8ID )/*check for id*/

						{
									
							local_move =local_move->ptr_T1;/*assign the address of next node to the pointer*/
									
						}
						if(local_move ==NULL)/*check that you exist from the loop becasue of id not exist*/
						{
							local_clinicsStatus =notok ;
						}
						else/*id isexist*/
						{
							local_clinicsStatus =ok ;/*status ok*/
							GUI_EnuScan_g.id = local_move->id;/*just assign value to the ointer to print it into main*/
							
							for(local_CounterString =0 ; local_CounterString<10;local_CounterString++)
							{
								GUI_EnuScan_g.name[local_CounterString] = local_move->name[local_CounterString];
							}
							GUI_EnuScan_g.age = local_move->age;
							GUI_EnuScan_g.gender = local_move->gender; /*assign addes of node to the variable to use it into main*/
						}
				}	
		}
	}
	else if(Copy_u8voidGetListName == BACKEND_TIME_LIST)/*CHECK LIST OF time*/
	{
		
		PATEINT_T2 * local_move = clinic_head_t2;/*assign address of head of time list to pointer*/
		if(local_move == NULL)/*check the list is empty or not*/
		{
			local_clinicsStatus = notok ;/*in case of empty make the status not ok */
		}
		else/*the list is not empty*/
		{
			if(Copy_u8SearchBy == BACKEND_INFORMATION_SEARCHBY_ID)
			{
					while(local_move !=NULL && local_move->id != Copy_u8ID)/*check for the exist node by id*/
					{
						
						local_move =local_move->ptr_T2;
						
					}
					if(local_move ==NULL)/*the node is not exist*/
					{
						local_clinicsStatus =notok ;/*make the status not ok */
					}
					else/*the node i exist*/
					{
						local_clinicsStatus =ok ;/*make te status ok*/
						GUI_EnuScan_time_g.id = local_move->id;/*just assign value to the ointer to print it into main*/
						GUI_EnuScan_time_g.time = local_move->time;
					}
			}
			else if(Copy_u8SearchBy == BACKEND_INFORMATION_SEARCHBY_TIME)
			{
				
				while(local_move !=NULL && local_move->time != Copy_u8ID)/*check for the exist node by id*/
					{
						
						local_move =local_move->ptr_T2;
						
					}
					if(local_move ==NULL)/*the node is not exist*/
					{
						local_clinicsStatus =notok ;/*make the status not ok */
					}
					else/*the node i exist*/
					{
						if(local_move->id == 0)/*not reserved*/
						{
							
							local_clinicsStatus =ok ;/*make te status ok*/
							
						}
						
					}	
			}
		}
	}
	
	return local_clinicsStatus ;/*return stats*/
}

/*function to delete slot in time list*/
static checks clininc_EnuEditNodeTimeNull(u8 copy_u8time)
{

	PATEINT_T2 * local_move = clinic_head_t2;/*pointer to point t tile list*/
	checks local_clinicsStatus = notok ;/*intial status not ok */
		while(local_move != NULL)/* search for non null nodes*/
			{
				if(local_move->time == copy_u8time)/*check for the slot*/
				{
					local_move->id =0 ;/*set id of slot with zreo thatmeans that the slot is empty*/
					local_clinicsStatus = ok;/*set status is ok*/
					break ;
				}
				else
				{
					local_move =local_move->ptr_T2; /*make pointer point to the next node*/
				
				}
				
			}
	return local_clinicsStatus;/*rerurn status*/
}


/*function to edit node of information list*/
static checks clininc_EnuEditNodeInformation(PATEINT_T1 copy_u8id)
{

	PATEINT_T1 * local_move = clinic_head_t1;/*here we make the pointer points to the information list*/
	u8 i ;/*counter for string indexing*/
	checks local_clinicsStatus = notok ;/*intial status not ok*/
		while(local_move != NULL)/*check for non null node*/
	{
		if(local_move->id == copy_u8id.id)/*serach for the node by using id*/
		{
			for(i = 0; i < 10 ; i++)/*here we try to move the new string name*/
			{
				
			local_move->name[i] = copy_u8id.name[i];
			}
			local_move->age = copy_u8id.age;/*new age*/
			local_move->gender = copy_u8id.gender;/*new gender*/
			
			local_clinicsStatus = ok;/*mae the status ok*/
			break ;
		}
		else
		{
		local_move =local_move->ptr_T1;/*ake the pinter points to te=he next node*/
		}
	}
	return local_clinicsStatus;/*return status*/
}
/*TO ADD TIME SLOT*/
static checks clininc_EnuSearchNodeAddSlot(u32 copy_u32time,u32 copy_u32id)
{
	checks local_clinicsStatus = notok  ;/*check variable with intial status notok*/
	PATEINT_T2 * local_move = clinic_head_t2;/*pointer points to the time list*/
 
	while(local_move != NULL)/*to check for null*/
	{
		if(local_move->time == copy_u32time)/*check the value of time*/
		{			
			if(local_move->id == 0)/*check if the slot is empty or not*/
			{   
			    	
				local_move->id = copy_u32id;/*assign the slot with id*/
				local_clinicsStatus = ok;/*make status ok that means that the assignation is done*/
				break;
			}		
		}			
			
			local_move = local_move->ptr_T2;/*make ove pointer points to the next nude*/	
	}
	return local_clinicsStatus;
}
/*back end function to get the data with string format then convert it it to integer*/
static checks private_EnuGetDatatSringToInteger(u32 * copy_Pu32GetIntegerData)
{
	
	
	checks local_clinicsStatus = ok ;
	u8 local_u8Counter = BACKEND_ZERO  ;
	u32 local_u32Step= BACKEND_ONE;
	*copy_Pu32GetIntegerData = BACKEND_ZERO; 
	u8 local_Au8GetInsertedData[BACKEDN_INPUT_SIZE];
	scanf("%s",local_Au8GetInsertedData);
	while(local_Au8GetInsertedData[local_u8Counter] != BACKEND_STRING_TERMINATOR)
	{
		local_u8Counter++;
	}
		
	while(local_u8Counter>BACKEND_ZERO)
	{
		*copy_Pu32GetIntegerData += (local_Au8GetInsertedData[local_u8Counter-BACKEND_ONE]-BACKEND_ZERO_ACII) * local_u32Step ;
		local_u32Step *= BACKEND_TEN;
		local_u8Counter--;
	}
	return local_clinicsStatus ;

}
