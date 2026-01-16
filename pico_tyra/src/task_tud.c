/*
 * task_demux.c
 *
 *  Created on: 20.06.2023
 *      Author: manni4
 */

#include "task_tud.h"
#include <stdio.h>
#include "tusb.h"

#include "pico/async_context_poll.h"

void process_tud(async_context_t *context,
				 struct async_when_pending_worker *worker)
{
	tud_task_t *task = worker->user_data;

	tud_task();
	async_context_set_work_pending(&task->async_context.core, &task->worker);
}

void tud_task_init(tud_task_t *task)
{
	tusb_init();

	if (!async_context_poll_init_with_defaults(&task->async_context))
	{
		panic("Async context console init fail");
		return;
	}
	task->worker.do_work = process_tud;
	task->worker.user_data = task;

	async_context_add_when_pending_worker(&task->async_context.core, &task->worker);
	async_context_set_work_pending(&task->async_context.core, &task->worker);
}
