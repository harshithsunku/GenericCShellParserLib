/**
 * @file        cliconst.h
 * @brief       GenericCShellParserLIB: A comprehensive and versatile CLI parsing library for C applications.
 * @author      Harshith Sunku
 * @date        12/22/2023
 * @version     1.0
 * @website     https://www.harshith.in/ | https://harshithsunku.in/
 * @repository  https://github.com/harshithsunku/GenericCShellParserLIB
 *
 * @note        This file is part of GenericCShellParserLIB, which offers robust CLI functionalities for C projects. 
 *              The library includes a range of built-in commands like show, config, debug, clear, and more, making it
 *              ideal for integrating powerful and customizable shell parsing capabilities into various applications.
 * @details     Designed for easy integration and extensibility, GenericCShellParserLIB allows developers to quickly 
 *              implement a command-line interface tailored to their application's needs. Further details about the 
 *              implementation can be found in the README or the official documentation at the above website/github.
 * 
 * GenericCShellParserLIB is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * GenericCShellParserLIB is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GenericCShellParserLIB. If not, see <https://www.gnu.org/licenses/>.
 *
 * @bugs        No known bugs at the time of writing.
 * @todo        Features or fixes planned for future versions.
 */

#ifndef __LIBCLICONSTANTS__
#define __LIBCLICONSTANTS__

#define CMD_NAME_SIZE           32
#define MAX_CMD_TREE_DEPTH      16
#define LEAF_VALUE_HOLDER_SIZE  64/* It should be atleast CMD_NAME_SIZE*/
#define LEAF_ID_SIZE            32
#define PARAM_HELP_STRING_SIZE  64
#define CONS_INPUT_BUFFER_SIZE  2048
#define TERMINAL_NAME_SIZE      CONS_INPUT_BUFFER_SIZE
#define TLV_MAX_BUFFER_SIZE     1024
#define POSSIBILITY_ARRAY_SIZE  10 
#define DEFAULT_DEVICE_NAME     "Generic_Cli_Shell"
#define MODE_CHARACTER          "/"
#define SUBOPTIONS_CHARACTER    "?"
#define CMD_EXPANSION_CHARACTER "."
#define MAX_OPTION_SIZE         16
#define CMD_HIST_RECORD_FILE    "CMD_HIST_RECORD_FILE.txt"
#define FILE_CMD_SIZE_MAX       (LEAF_VALUE_HOLDER_SIZE * MAX_CMD_TREE_DEPTH)
#define MODE_PARAM_INDEX        0
#define SUBOPTIONS_INDEX        1
#define CMD_EXPANSION_INDEX     2
#define CHILDREN_START_INDEX    3
#define CHILDREN_END_INDEX      (MAX_OPTION_SIZE -1)
#define MAX_SAVED_CMDS          30


#define NEGATE_CHARACTER        "no"
#define GOTO_TOP_STRING         "cd"
#define GOTO_ONE_LVL_UP_STRING  "cd.."
#define CLEAR_SCR_STRING        "cls"
#define DO                      "do"

#define SHOW_EXTENSION_PARAM            "SHOW_EXTENSIONS"
#define SHOW_EXTENSION_PARAM_BRIEF      "SHOW_BRIEF"
#define SHOW_EXTENSION_PARAM_DETAIL     "SHOW_DETAIL"
#define SHOW_EXTENSION_PARAM_EXTENSIVE  "SHOW_EXTENSIVE"

typedef enum{
    brief,
    detail,
    extensive,
    none
} show_ext_t;

/* Default Command Codes*/
/*CMD codes need not be unique, but should be unique with in same command sharing 
 * the same command handler. For example, cmd code of SHOW_HISTORY and SHOW_HISTORY_N 
 * should be distinct because both commands have the same cmd handler */

#define SHOW_HELP                   1
#define SHOW_HISTORY                2
#define SHOW_HISTORY_N              3
#define SHOW_REGISTERED_COMMANDS    4
#define CONFIG_SUPPORTSAVE_ENABLE   5
#define CONFIG_CONSOLEN_NAME_NAME   6
#define DEBUG_SHOW_CMDTREE          7
#define CONFIG_LOAD_FILE			8
#define CMDCODE_RUN_UT_TC   9 /* run ut <ut-file-name> <tc-no>*/
#define CMDCODE_DEBUG_UT    10 /* debug ut [enable | disable] */

typedef enum{
    COMPLETE,
    ERROR,
    INVALID_LEAF,
    USER_INVALID_LEAF,
    CMD_NOT_FOUND,
    INCOMPLETE_COMMAND,
    MULTIPLE_MATCHING_COMMANDS,
    UNKNOWN
} CMD_PARSE_STATUS;

#endif /* __LIBCLICONSTANTS__ */
