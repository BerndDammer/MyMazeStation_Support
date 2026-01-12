/*
 * task_blinker.c
 *
 *  Created on: 12.06.2023
 *      Author: manni4
 */

#include "task_blinker.h"


//#include "hardware/structs/scb.h"

#include <stdio.h>


#include "pico.h"
#include "pico/stdlib.h"
#include "pico/stdio.h"
//#include "pico/types.h"
#include "pico/async_context.h"
#include "pico/async_context_poll.h"
#include "pico/runtime.h"

//#define STR_BUF_LEN 100


//static int c;

async_context_poll_t async_context_console;
async_when_pending_worker_t process_char_worker;

struct char_callback_para_t
{
	char c;
	bool has;
} cbp;

static void console_menu()
{
	printf("\n\n");
	printf("------------------------------------\n");
	printf("AUDIO Test\n");
	printf("r reset processor\n");
	printf("e event bits\n");
	printf("press key to select\n");
	printf("------------------------------------\n");

}


void process_char(async_context_t *context,
		struct async_when_pending_worker *worker)
{
	switch (cbp.c)
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
		console_menu();
		break;
	}
	cbp.has = false;
}


void chars_available_callback(void *char_callback_para)
{
	cbp.c = getchar_timeout_us(1);
	cbp.has = true;
	async_context_set_work_pending(&async_context_console.core,
			&process_char_worker);
}

async_context_t* async_console_init(void)
{
	if (!async_context_poll_init_with_defaults(&async_context_console))
	{
		panic("Async context console init fail");
		return NULL ;
	}
	stdio_set_chars_available_callback(chars_available_callback, (void*) &cbp);

	process_char_worker.do_work = process_char;
	async_context_add_when_pending_worker(&async_context_console.core,
			&process_char_worker);

	return &async_context_console.core;
}

