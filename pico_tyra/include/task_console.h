/*
 * task_blinker.h
 *
 *  Created on: 12.06.2023
 *      Author: manni4
 */

#ifndef TASK_CONSOLE_H_
#define TASK_CONSOLE_H_


#include "pico/async_context.h"

async_context_t *async_console_init(void);

#endif /* TASK_CONSOLE_H_ */
