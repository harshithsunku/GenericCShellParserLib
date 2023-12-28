/**
 * @file        serialize.h
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

#ifndef __SERIALIZE__
#define __SERIALIZE__

/* Data types supported*/


typedef struct serialized_buffer{
    #define SERIALIZE_BUFFER_DEFAULT_SIZE 512
    void *b;
    int size;
    int next;
    int checkpoint;
} ser_buff_t;

/* init functions*/
void init_serialized_buffer(ser_buff_t **b);
void init_serialized_buffer_of_defined_size(ser_buff_t **b, int size);

/* Serialize functions*/

void serialize_uint8 (ser_buff_t *b, char data);
void serialize_int8 (ser_buff_t *b, char data);
void serialize_int32 (ser_buff_t *b, int data);
void serialize_uint32(ser_buff_t *b, unsigned int data);
void serialize_float (ser_buff_t *b, float data);
void serialize_double(ser_buff_t *b, double data);
void serialize_string(ser_buff_t *b, char *data, int size);
char is_serialized_buffer_empty(ser_buff_t *b);
/* get functions*/
int  get_serialize_buffer_size(ser_buff_t *b);
int get_serialize_buffer_current_ptr_offset(ser_buff_t *b);
char *get_serialize_buffer_current_ptr(ser_buff_t *b);
void serialize_buffer_skip(ser_buff_t *b, int size);
void copy_in_serialized_buffer_by_offset(ser_buff_t *b, int size, char *value, int offset);

/* De-Serialize function */

void de_serialize_string(char *dest, ser_buff_t *b, int val_size);


/* free Resourse*/
void free_serialize_buffer(ser_buff_t *b);

/*reset function*/
void truncate_serialize_buffer(ser_buff_t **b);
void reset_serialize_buffer(ser_buff_t *b);
void restore_checkpoint_serialize_buffer(ser_buff_t *b);
int get_serialize_buffer_checkpoint_offset(ser_buff_t *b);
void mark_checkpoint_serialize_buffer(ser_buff_t *b);
/* Details*/
void print_buffer_details(ser_buff_t *b, const char *fn, int lineno);

/* Deserialize functions as a macro*/

#define deserialize_primitive(ser_buff, dest, type)				\
do{										\
	ser_buff_t *_b = (ser_buff_t *)(ser_buff);				\
	memcpy((char *)&dest, (char *)(_b->b) + _b->next, sizeof(type));	\
	_b->next += sizeof(type);						\
}while(0);


#if 0
#define deserialize_string(ser_buff, dest, size)				\
do{										\
	ser_buff_t *_b = (ser_buff_t *)(ser_buff);				\
	memcpy((char *)dest, (char *)(_b->b) + _b->next, size);			\
	_b->next += size;							\
}while(0);
#endif
	
#define serialize_primitive(ser_buff, dest, type)				\
do{                                                                             \
	if (ser_buff == NULL) assert(0);					\
	ser_buff_t *buff = (ser_buff_t *)(ser_buff);				\
	int available_size = buff->size - buff->next;				\
	char isResize = 0;							\
	while(available_size < sizeof(type)){					\
        	buff->size = buff->size * 2;					\
	        available_size = buff->size - buff->next;			\
        	isResize = 1;							\
    	}									\
        if(isResize == 0){							\
        memcpy((char *)buff->b + buff->next, &data, sizeof(type));		\
        buff->next += sizeof(type);						\
        return;									\
    }										\
    buff->b = realloc(buff->b, buff->size);					\
    memcpy((char *)buff->b + buff->next, &data, sizeof(type));			\
    buff->next += sizeof(type);							\
}while(0);


#endif
