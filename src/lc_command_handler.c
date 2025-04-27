/*
 * lc_command_handler.c
 *
 *  Created on: Apr 25, 2025
 *      Author: raalm
 */
#include <stdbool.h>
#include <stdlib.h>

#include "lc_command_handler.h"
#include "lc_command_structure.h"
#include "lc_command_dispatcher.h"

static FDCAN_RxHeaderTypeDef fdcan1_rx_header;
static lc_command_structure_t command;
extern void Error_Handler(void); // todo: replace with proper logging/error handler

void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
	if((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != RESET)
	{
		if(HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &fdcan1_rx_header, (uint8_t *)&command) != HAL_OK)
		{
			Error_Handler();
			return;
		}
		if(HAL_FDCAN_ActivateNotification(hfdcan, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0) != HAL_OK)
		{
			Error_Handler();
			return;
		}
	}

	lc_command_dispatcher_dispatch(&command);
}

bool lc_command_handler_init()
{

	return true;
}

bool lc_commander_deinit()
{

	return true;
}
