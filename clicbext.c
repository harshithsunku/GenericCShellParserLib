/**
 * @file        clicbext.c
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

#include <stdio.h>
#include <stdlib.h>
#include "clicbext.h"

void
terminate_signal_handler(){

    /*-----------------------------------------------------------------------------
     *  Process has malfunctioned for some reason, user would like to see the memory
     *  state of the process for debugging. This function triggers all the show command
     *  one by one and write the output data to the file for future reference.
     *  -----------------------------------------------------------------------------*/
    collect_supportsave_data();
    exit(0);
}

void
collect_supportsave_data(){
    printf("%s() is called ...\n", __FUNCTION__);
}
