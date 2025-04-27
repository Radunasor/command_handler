/*
 * lc_command_structure.h
 *
 *  Created on: Apr 25, 2025
 *      Author: raalm
 */

#ifndef APPLICATION_USER_LC_COMMAND_STRUCTURE_H_
#define APPLICATION_USER_LC_COMMAND_STRUCTURE_H_

#include <stdlib.h>

#include "lc_command_list.h"

typedef struct lc_command_structure_st
{
	lc_command_list_t command_type;
	float target_position;
	float movement_time_duration;
}lc_command_structure_t;

#endif /* APPLICATION_USER_LC_COMMAND_STRUCTURE_H_ */
