/***********************************
*   File name: bp_cmd.c
*   Description:
*    cmd line main source code
*    1.Parse the command recieved
*    2.Call relevant function complete 
*      user's request
************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bp_public.h"
#include "bp_cmd.h"




/*******************************************
*   Function:bp_cmd_check
*   Description:
*   Check syntax correctness of the command 
*
********************************************/
static int bp_cmd_check(int paranum, char **para)
{
    int res = BP_OK;
    int i = 0;
 
    /* Check numbers of parameters */
    if (paranum > BP_PARAMETER_NUM_MAX || paranum < BP_PARAMETER_NUM_MIN)
    {
        return BP_ERR_PARA;
    }

    /* Check length of parameters */
    for (i = 0; i < paranum; i++)
    {
        if (strlen(para[i]) > BP_PARAMETER_LEN_MAX)
        {
            return BP_ERR_PARA;
        }
    }

    return res;
}

/*******************************************
*   Function:bp_cmd_forward
*   Description:
*   Forward the command for next operation
*
********************************************/
static int bp_cmd_forward(int paranum, char **para)
{
    int res = BP_OK;


    /* Commands will be forwarded according to the second parameter */
    /* HELP */
    if (0 == strcmp(para[2], BP_CMD_HELP) || 0 == strcmp(para[2], BP_CMD_HELP_SHORT))
    {
        /*  */

        return res;
    }
    /* CHECK */
    if (0 == strcmp(para[2], BP_CMD_CHECK) || 0 == strcmp(para[2], BP_CMD_CHECK_SHORT))
    {
        /*  */
    }
    
    
    return res;
}

/*******************************************
*   Function:bp_cmd_help
*   Description:
*   Forward the command for next operation
*
********************************************/
static int bp_cmd_help(void)
{
    printf("Useage:\n");
    
    printf("bpool check\n");
    printf("\t\tCheck bandwidth pool environment.\n");

    printf("bpool list [domain name]\n");
    printf("\t\tCheck bandwidth pool environment.\n");
    printf("\t\t\tdomain number: The name of domain you want to list. If domain\
        name not specified, all the domains will be listed.\n");
    
    printf("bpool check\n");
    printf("\t\tCheck bandwidth pool environment.\n");
}


