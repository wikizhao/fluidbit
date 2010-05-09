/***************************************
*   File name: bp_cmd.h
*   Description:
*    Provide commander line interfaces
*    or sth
****************************************/

#ifndef __BP_CMD_H
#define __BP_CMD_H

/* Primary parameter */
#define BP_CMD_CHECK            "check"
#define BP_CMD_CHECK_SHORT      "c"

#define BP_CMD_HELP             "help"
#define BP_CMD_HELP_SHORT       "h"

#define BP_CMD_LIST             "list"
#define BP_CMD_LIST_SHORT       "l"

#define BP_CMD_ASSIGN           "assign"
#define BP_CMD_ASSIGN_SHORT     "a"

#define BP_CMD_STATUS           "status"
#define BP_CMD_STATUS_SHORT     "s"

static int bp_cmd_help(void);

#endif

