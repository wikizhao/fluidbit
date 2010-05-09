/***********************************
*   File name: bp_list.c
*   Description:
*
************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bp_public.h"
#include "bp_list.h"

/*******************************************
*   Function:bp_list
*   Description:
*   Show check information
*
********************************************/
int bp_list(bp_cmd_list_st list_para)
{

    if (0 == strlen(list_para.domain_name))
    {
        printf("All the domain will be listed.\n");
    }
    else
    {
        printf("domain: %s will be listed.\n", list_para.domain_name);
    }
    
    return BP_OK;
    
}


