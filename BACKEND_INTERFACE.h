#ifndef BACKEND_interface_h                             	/*header guard*/
#define BACKEND_interface_h									/*header guard*/
extern PATEINT_T1 GUI_EnuScan_g; 							/*GLOPAL public VARIABLE  TO ACCESS DATA LIST*/
extern PATEINT_T2 GUI_EnuScan_time_g;						/*GLOPAL public VARIABLE  TO ACCESS Time LIST*/
extern checks Backend_EnuBackendTask_init(void);			/*glopal public init */
extern checks Backend_EnuBackendTask(void);					/*glopal public task */
extern PATEINT_T1 * clinic_head_t1 ;						/*header of information list*/
extern PATEINT_T2 * clinic_head_t2 ;						/*header of time list*/
#endif