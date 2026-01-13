/*
 * task_blinker.c
 *
 *  Created on: 12.06.2023
 *      Author: manni4
 */

#include "task_console.h"

#include <stdio.h>

#include "pico.h"
#include "pico/stdlib.h"
#include "pico/stdio.h"
#include "pico/async_context.h"
#include "pico/async_context_poll.h"
#include "pico/runtime.h"

void process_char(async_context_t *taskp,
				  async_when_pending_worker_t *worker)
{
	console_task_t *task = worker->user_data;
	switch (task->c)
	{
	case 'r':
	{
	}
	break;
	case 'e':
	{
	}
	break;
	case ' ':
	default:
		printf("\n\n");
		printf("------------------------------------\n");
		printf("AUDIO Test\n");
		printf("r reset processor\n");
		printf("e event bits\n");
		printf("press key to select\n");
		printf("------------------------------------\n");
		break;
	}
	task->has = false;
}

void chars_available_callback(void *taskp)
{
	console_task_t *task = taskp;
	task->c = getchar_timeout_us(1);
	task->has = true;
	async_context_set_work_pending(&task->async_context.core,
								   &task->worker);
}

void console_task_init(console_task_t *task)
{
	if (!async_context_poll_init_with_defaults(&task->async_context))
	{
		panic("Async context console init fail");
		return;
	}
	stdio_set_chars_available_callback(chars_available_callback, task);

	task->worker.do_work = process_char;
	task->worker.user_data = task;
	async_context_add_when_pending_worker(&(task->async_context.core),
										  &task->worker);
}
