/*
 * task_blinker.c
 *
 *  Created on: 12.06.2023
 *      Author: manni4
 */

#include "task_blinker.h"
#include "pico/stdlib.h"

#define PICO_DEFAULT_TOGGLE_PIN 16
#define BLINK_TIMEOUT_MS 888

const uint LED_PIN = PICO_DEFAULT_LED_PIN;
static bool toggle = true;

void process_blink(async_context_t *context,
				   struct async_work_on_timeout *worker)
{
	blinky_task_t *task = worker->user_data;

	toggle = !toggle;
	gpio_put(LED_PIN, toggle);

	async_context_add_at_time_worker_in_ms(
		&task->async_context.core,
		&task->worker,
		BLINK_TIMEOUT_MS);
}

void blinky_task_init(blinky_task_t *task)
{
	{
		gpio_init(LED_PIN);
		gpio_set_dir(LED_PIN, GPIO_OUT);
	}

	if (!async_context_poll_init_with_defaults(&task->async_context))
	{
		panic("Async context console init fail");
	}

	task->worker.do_work = process_blink;
	task->worker.user_data = task;

	async_context_add_at_time_worker_in_ms(
		&task->async_context.core,
		&task->worker,
		BLINK_TIMEOUT_MS);
}
