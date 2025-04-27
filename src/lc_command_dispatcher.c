/*
 * lc_command_dispatcher.c
 *
 *  Created on: Apr 25, 2025
 *      Author: raalm
 */

#include <stdio.h>

#include "lc_command_dispatcher.h"
#include "mc_interface.h"
#include "mc_api.h"

static bool lc_command_enable(lc_command_structure_t *command);
static bool lc_command_disbale(lc_command_structure_t *command);
static bool lc_command_initialize(lc_command_structure_t *command);
static bool lc_command_move(lc_command_structure_t *command);


struct {
	lc_command_list_t command;
	bool (*callback)(lc_command_structure_t *);
} lc_command_callback_struct[] = {
		{LC_MOTOR_COMMAND_LIST_ENABLE, lc_command_enable},
		{LC_MOTOR_COMMAND_LIST_DISABLE, lc_command_disbale},
		{LC_MOTOR_COMMAND_LIST_INITIALIZE, lc_command_initialize},
		{LC_MOTOR_COMMAND_LIST_MOVE, lc_command_move},

		{_LC_MOTOR_COMMAND_LIST_LAST, NULL},
};

static bool lc_command_enable(lc_command_structure_t *command)
{
	return MC_StartMotor1();
}

static bool lc_command_disbale(lc_command_structure_t *command)
{
	return MC_StopMotor1();
}

static bool lc_command_initialize(lc_command_structure_t *command)
{

	return false;
}

static bool lc_command_move(lc_command_structure_t *command)
{
	if (MC_GetControlPositionStatusMotor1() != TC_READY_FOR_COMMAND)
		return false;

	MC_ProgramPositionCommandMotor1(command->target_position, command->movement_time_duration);

	return true;
}


void lc_command_dispatcher_dispatch(lc_command_structure_t *rx_command)
{
	for(uint8_t command_idx = _LC_MOTOR_COMMAND_LIST_LAST; command_idx ; command_idx--)
	{
		if(lc_command_callback_struct[command_idx].command == rx_command->command_type)
		{
			if(!lc_command_callback_struct[command_idx].callback(rx_command))
				printf("command callback %d failed to execute \n", lc_command_callback_struct[command_idx].command);

			break;
		}
	}
}

