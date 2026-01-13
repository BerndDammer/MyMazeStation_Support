
#include "tusb.h"
#include "usb_device_midi.h"
#include "hardware/gpio.h"

// This include shows the necessary callbacks
// XXX cannot include
// #include "midi_device.h"

#define PORT_BASE 2
#define PORT_COUNT 8
#define SCORE_BASE 0X30

void tud_midi_rx_cb(uint8_t itf)
{
	if (!gpio_is_pulled_up(PORT_BASE))
	{
		for (int i = PORT_BASE; i < PORT_BASE + PORT_COUNT; i++)
		{
			gpio_init(i);
			gpio_set_drive_strength(i, GPIO_DRIVE_STRENGTH_2MA);
			gpio_set_pulls(i, true, false);
			gpio_set_dir(i, true);
			gpio_set_slew_rate(i, GPIO_SLEW_RATE_SLOW);
			gpio_put(i, true);
		}
	}
	uint8_t packet[4];
	bool reading = true;

	while (reading)
	{
		int charcount = tud_midi_available();
		reading = charcount > 0;
		if (reading)
		{
			printf("Readcount %i\n", charcount);
			if (tud_midi_packet_read(packet))
			{
				printf("%02X %02X %02X %02X\n", //
					   packet[0], packet[1], packet[2], packet[3]);
				if ((packet[0] & 0X0E) == 0X08)
				{
					int base = packet[2] - SCORE_BASE;
					if ((base >= 0) && (base < PORT_COUNT))
					{
						gpio_put(base + PORT_BASE, packet[0] & 1 ? true : false);
					}
					else
					{
						puts("Wrong Score\n");
					}
				}
				else
				{
					puts("Wrong Code\n");
				}
			}
			else
			{
				printf("false at read\n");
			}
		}
	}
}
