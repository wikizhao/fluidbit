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
int bp_cmd_check(int paranum, char **para)
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
int bp_cmd_forward(int paranum, char **para)
{
    int res = BP_OK;
    bp_cmd_assign_st assignpara;    /* Set zero when used */
    bp_cmd_list_st listpara;        /* Set zero when used */


    /* Commands will be forwarded according to the second parameter */
    /* HELP */
    if (0 == strcmp(para[1], BP_CMD_HELP) || 0 == strcmp(para[1], BP_CMD_HELP_SHORT))
    {
        /* Check syntax correctness */
        if (paranum > 2)
        {
            return BP_ERR_PARA;
        }

        /* Show help information */
        res = bp_cmd_help();

        return res;
    }
    /* CHECK */
    if (0 == strcmp(para[1], BP_CMD_CHECK) || 0 == strcmp(para[1], BP_CMD_CHECK_SHORT))
    {
        /* Check syntax correctness */
        if (paranum > 2)
        {
            return BP_ERR_PARA;
        }

        /* Check the environment */
        printf("This is environment information.\n");

        return res;
    }
    /* LIST */
    if (0 == strcmp(para[1], BP_CMD_LIST) || 0 == strcmp(para[1], BP_CMD_LIST_SHORT))
    {
        /* Check syntax correctness */
        if (paranum > 3)
        {
            return BP_ERR_PARA;
        }

        /* Set zero */
        memset(&listpara, 0, sizeof(listpara));

        /* Copy domain name */
        if (2 != paranum)
        {
            memcpy(listpara.domain_name, para[2], strlen(para[2]));
        }

        /* Forward command */
        res = bp_list(listpara);
        
        return res;
    }
    /* ASSIGN */
    if (0 == strcmp(para[1], BP_CMD_ASSIGN) || 0 == strcmp(para[1], BP_CMD_ASSIGN_SHORT))
    {
        /* Check syntax correctness */
        if (paranum != 4)
        {
            return BP_ERR_PARA;
        }

        /* Copy domain name and bandwidth */
        memcpy(assignpara.domain_name, para[2], strlen(para[2]));
        memcpy(assignpara.bandwidth, para[3], strlen(para[3]));

        /* Forward command */
        res = bp_assign(assignpara);

        return res;

    }
    /* STATUS */
    if (0 == strcmp(para[1], BP_CMD_STATUS) || 0 == strcmp(para[1], BP_CMD_STATUS_SHORT))
    {
        /* Check syntax correctness */
        if (paranum != 2)
        {
            return BP_ERR_PARA;
        }

        /* Forward command */
        res = bp_status();

        return res;
    }
    
    
    return res;
}

/*******************************************
*   Function:bp_cmd_help
*   Description:
*   Show help information
*
********************************************/
static int bp_cmd_help(void)
{
    printf("Useage:\n");
    
    printf("\n\tbpool check\n");

    printf("\n\tbpool list [domain name]\n");

    printf("\n\tbpool assign {domain name} {bandwidth}\n");

    printf("\n\tbpool status\n");

    printf("\n\tbpool help\n");

    printf("\n");
    
    return BP_OK;
    
}


