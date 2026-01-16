
#include "reset_ports.h"
#include "tusb.h"
#include "usb_device_midi.h"

#define SCORE_BASE 0X30

void tud_midi_rx_cb(uint8_t itf)
{
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
						reset_port_activate(base, packet[0] & 1 ? true : false);
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
