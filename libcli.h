/**
 * @file        libcli.h
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

#ifndef __LIBCLI__
#define __LIBCLI__

#include <unistd.h>
#include "libcliid.h"
#include "cmd_hier.h"

extern int GL_FD_OUT;

void
init_libcli();

void
set_device_name(const char *cons_name);

/*import functions. These functions to be used to get access to 
 * library global variables - the zero level command hooks */

param_t *
libcli_get_show_hook(void);

param_t *
libcli_get_debug_hook(void);

param_t *
libcli_get_debug_show_hook(void);

param_t *
libcli_get_config_hook(void);

param_t *
libcli_get_clear_hook(void);

param_t *
libcli_get_run_hook(void);

void
enable_show_extension_param_brief(param_t *param);

void
set_param_cmd_code(param_t *param, int cmd_code);

/*See the definition of this fn to know about arguments*/
void
init_param(param_t *param,              
           param_type_t param_type,     
           char *cmd_name,              
           cmd_callback callback,
           user_validation_callback user_validation_cb_fn,
           leaf_type_t leaf_type,
           char *leaf_id,
           char *help);

void 
libcli_register_param(param_t *parent, param_t *child);

void
libcli_register_display_callback(param_t *param,
                                 display_possible_values_callback disp_callback);

show_ext_t
get_show_extension_type(ser_buff_t *b);
/*After this call, libcli_register_param MUST not be invoked on param*/
void
support_cmd_negation(param_t *param);

void
dump_cmd_tree();

void
start_shell(void);

#define HIDE_PARAM(param_ptr)   ((param_ptr)->ishidden = 1)
#define IS_PARAM_HIDDEN(param_ptr)  ((param_ptr)->ishidden == 1)

void
cli_register_ctrlC_handler(void (*app_ctrlC_signal_handler)(void ));

#endif
