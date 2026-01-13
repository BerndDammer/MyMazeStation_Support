#include <stdio.h>
#include "pico.h"
#include "pico/stdio.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"

#include "pico/async_context.h"
#include "pico/async_context_poll.h"


#include "task_blinker.h"
#include "task_console.h"
#include "task_tud.h"



int main(void)
{
	int poll_counter = 0;

	stdio_init_all();

	console_task_t console_task;
	async_context_t *async_context_blinky;
	async_context_t *async_context_tinyusb;

	printf("\nStarting");
	printf("\nTime ms since start %i", //
			to_ms_since_boot(get_absolute_time()) //
					);

	console_task_init(&console_task);

	async_context_blinky = async_blinky_init();
	if (async_context_blinky == NULL )
	{
		panic("blinky iii");
	}

	async_context_tinyusb = async_tinyusb_init();
	if (async_context_tinyusb == NULL )
	{
		panic("tud iii");
	}

	while (true)
	{
		async_context_poll( &console_task.async_context.core);
		async_context_poll( async_context_blinky);
		async_context_poll( async_context_tinyusb);

		poll_counter++;
	}
	return 0;
}
