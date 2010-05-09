/***********************************
*   File name: bp_public.h
*   Description:
*    Provide main interfaces or sth
************************************/

#ifndef __BP_PUBLIC_H
#define __BP_PUBLIC_H

/* Error number */
#define BP_OK           0
#define BP_ERR_PARA     100

/*  */
#define BP_PARAMETER_NUM_MAX   6
#define BP_PARAMETER_NUM_MIN   2
#define BP_PARAMETER_LEN_MAX   256

/* Command struct used to deliver commands to corresponding function */
typedef struct _bp_cmd_assign_st
{
    char domain_name[BP_PARAMETER_LEN_MAX];
    char bandwidth[BP_PARAMETER_LEN_MAX];
} bp_cmd_assign_st;

typedef struct _bp_cmd_list_st
{
    char domain_name[BP_PARAMETER_LEN_MAX];
} bp_cmd_list_st;

/* Public functions */

int bp_cmd_check(int paranum, char **para);
int bp_cmd_forward(int paranum, char **para);

int bp_check_env(void);
int bp_list(bp_cmd_list_st list_para);
int bp_assign(bp_cmd_assign_st assign_para);
int bp_status(void);


#endif


