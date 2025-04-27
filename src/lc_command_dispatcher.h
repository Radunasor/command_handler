/*
 * lc_command_dispatcher.h
 *
 *  Created on: Apr 25, 2025
 *      Author: raalm
 */

#ifndef APPLICATION_USER_LC_COMMAND_DISPATCHER_H_
#define APPLICATION_USER_LC_COMMAND_DISPATCHER_H_

#include "lc_command_common.h"
#include "lc_command_structure.h"

void lc_command_dispatcher_dispatch(lc_command_structure_t *command);

#endif /* APPLICATION_USER_LC_COMMAND_DISPATCHER_H_ */
