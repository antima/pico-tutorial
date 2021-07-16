#include "pico/stdlib.h"

int main() {
	uint pir_data;
	const uint led = 0;
	const uint pir_sensor = 15;

	gpio_init(led);
	gpio_init(PICO_DEFAULT_LED_PIN);
	gpio_init(pir_sensor);

	gpio_set_dir(led, GPIO_OUT);
	gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
	gpio_set_dir(pir_sensor, GPIO_IN);

	while(1) {
		pir_data = gpio_get(pir_sensor);
		gpio_put(led, pir_data);
		gpio_put(PICO_DEFAULT_LED_PIN, pir_data);
	}
}