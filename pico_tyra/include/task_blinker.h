/*
 * task_blinker.h
 *
 *  Created on: 12.06.2023
 *      Author: manni4
 */

#ifndef TASK_BLINKER_H_
#define TASK_BLINKER_H_

#include "pico/async_context.h"
#include "pico/async_context_poll.h"

async_context_t* async_blinky_init(void);

#endif /* TASK_BLINKER_H_ */
