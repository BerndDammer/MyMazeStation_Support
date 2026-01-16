#include "reset_ports.h"
#include "hardware/gpio.h"

#define PORT_BASE 2

void reset_ports_init(void)
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

void reset_port_activate(int index, bool active)
{
    gpio_put(index + PORT_BASE, !active);
}