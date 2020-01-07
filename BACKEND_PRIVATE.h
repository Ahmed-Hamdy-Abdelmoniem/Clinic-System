#ifndef BACKEND_private_h                           /*header guard*/
#define BACKEND_private_h							/*header guard*/
#define BACKEND_ADMIN 						1 		/*private flag*/
#define BACKEND_USER 						2		/*private flag*/
#define BACKEND_CLOSE 						3		/*private flag*/	
#define BACKEND_ONE							1		/*private flag*/
#define BACKEND_TWO							2		/*private flag*/
#define BACKEND_THREE						3		/*private flag*/
#define BACKEND_FOUR						4		/*private flag*/
#define BACKEND_FIVE						5		/*private flag*/
#define BACKEND_INFORMATION_LIST			0		/*private flag*/
#define BACKEND_TIME_LIST 					1		/*private flag*/
#define BACKEND_CREATE_NODE 				2		/*private flag*/
#define BACKEND_PRINT_NODE 					3		/*private flag*/
#define BACKEND_EDIT_INFORMATION_NODE 		4		/*private flag*/
#define BACKEND_DELETE_TIME_NODE 			5		/*private flag*/
#define BACKEND_close_system 				5		/*private flag*/
#define BACKEND_INFORMATION_SEARCHBY_ID 	0		/*private flag*/
#define BACKEND_INFORMATION_SEARCHBY_TIME 	1		/*private flag*/	
#define BACKEND_WRONG_HANDLING				11 		/*private flag*/
#define BACKEND_ZERO						0
static PATEINT_T2 * clinic__t2_PRINT;


static checks clininc_EnuGetNode(u8 Copy_u8voidGetListName,u32 Copy_u8ID,u8 Copy_u8SearchBy);/*private function*/
static checks clininc_EnuEditNodeTimeNull(u8 copy_u8time);									/*private function*/
static checks clininc_EnuCreateNode(void * Copy_PvoidGetNode,u8 Copy_u8voidGetListName);	/*private function*/	
static checks clininc_EnuEditNodeInformation(PATEINT_T1 copy_u8id);							/*private function*/
static checks clininc_EnuSearchNodeAddSlot(u32 copy_u32time,u32 copy_u32id);				/*private function*/ 
#endif 
