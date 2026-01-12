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

async_context_poll_t async_context_blinky;
async_at_time_worker_t s_process_blink;

static void port_blinker_init()
{
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}


void process_blink(async_context_t *context,
		struct async_work_on_timeout *worker)
{
		toggle = !toggle;
	    gpio_put(LED_PIN, toggle);

	async_context_add_at_time_worker_in_ms(&async_context_blinky.core,
			&s_process_blink, BLINK_TIMEOUT_MS);
}

async_context_t* async_blinky_init(void)
{
	port_blinker_init();

	if (!async_context_poll_init_with_defaults(&async_context_blinky))
	{
		panic("Async context console init fail");
		return NULL ;
	}

	s_process_blink.do_work = process_blink;
	async_context_add_at_time_worker_in_ms(&async_context_blinky.core,
			&s_process_blink, BLINK_TIMEOUT_MS);

	return &async_context_blinky.core;
}
