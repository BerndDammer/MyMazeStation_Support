/*
 * task_demux.c
 *
 *  Created on: 20.06.2023
 *      Author: manni4
 */

#include "task_tud.h"
#include <stdio.h>
#include "tusb.h"

#include "pico/async_context.h"
#include "pico/async_context_poll.h"

async_context_poll_t async_context_tinyusb;
async_when_pending_worker_t tinyusb_worker;


void process_tud(async_context_t *context,
		struct async_when_pending_worker *worker)
{
		tud_task();
	async_context_set_work_pending(&async_context_tinyusb.core,
			&tinyusb_worker);
}


async_context_t *async_tinyusb_init(void)
{
	tusb_init();

	if (!async_context_poll_init_with_defaults(&async_context_tinyusb))
	{
		panic("Async context console init fail");
		return NULL;
	}
		tinyusb_worker.do_work = process_tud;
	async_context_add_when_pending_worker(&async_context_tinyusb.core,
			&tinyusb_worker);

			async_context_set_work_pending(&async_context_tinyusb.core,
			&tinyusb_worker);

	return( &async_context_tinyusb.core);
}
