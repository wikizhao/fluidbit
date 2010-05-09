/***************************************
*   File name: bp_main.c
*   Description:
*    main entry of this programe
****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bp_public.h"

/*******************************************
*   Function:main
*   Description:
*
********************************************/
int main (int argc, char **argv)
{
    int res = BP_OK;

    res = bp_cmd_check(argc, argv);
    if (BP_OK != res)
    {
        return res;
    }

    res = bp_cmd_forward(argc, argv);
    if (BP_OK != res)
    {
        return res;
    }
        
    
    
    return res;
}



