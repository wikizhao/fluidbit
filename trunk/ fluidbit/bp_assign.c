/***********************************
*   File name: bp_assign.c
*   Description:
*
************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bp_public.h"
#include "bp_assign.h"

/*******************************************
*   Function:bp_assign
*   Description:
*
********************************************/
int bp_assign(bp_cmd_assign_st assign_para)
{


    printf("Assign %s to %s.\n", assign_para.bandwidth, assign_para.domain_name);

    return BP_OK;
    
}



