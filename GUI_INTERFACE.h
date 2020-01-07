#ifndef GUI_interface_h							/*Header guard*/
#define GUI_interface_h							/*Header guard*/
/*this is the following mode for he gui*/
#define GUI_SYESTEM_MAIN_MENU				0 	/*main page*/
#define GUI_ADMIN_ENTER_PASSWORD 			1	/*admin enter password page*/	
#define GUI_CLOSE_MODE 						2	/*close page*/
#define GUI_ADMIN_MAIN_MENU 				3	/*admin main menu page*/
#define GUI_WRONG 							4	/*wrong page*/
#define GUI_ADMIN_NEW_USER					5	/* new user page*/
#define GUI_ADMIN_EDIT_USER					6	/*edit user page*/
#define GUI_ADMIN_NEW_SLOT					7	/*new slot page*/
#define GUI_ADMIN_DELET_SLOT				8	/*delete slot oage*/
#define GUI_USER_ENTER_ID_check 			9 	/*check id of user page*/ 
#define GUI_USER_MAIN_MENU 					10 	/*user main page*/
#define GUI_USER_PRINT_DATA 				11	/*user data page*/ 
#define GUI_USER_PRINT_RESERVATIONS_1		12 	/*time slots part1 page*/
#define GUI_USER_PRINT_RESERVATIONS_2		13	/*time slots part2 page*/ 
extern u32 Gui_u8Status ;						/*global public variable for the status of the curent page*/
extern u32 Gui_u8StatusPrevious ;				/*global public variable for the status of the previous page*/
extern checks GUI_EnuGuiTask(void);				/*global public function  as atask of the gui*/
#endif											/*Header guard*/								