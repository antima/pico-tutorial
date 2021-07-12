#include <pico/stdlib.h>

int main() {
	uint pirinfo;
	const uint PIR_PIN = 0;
	const uint LED_PIN = PICO_DEFAULT_LED_PIN;
	const uint BLED_PIN = 15;

	gpio_init(PIR_PIN);
	gpio_init(LED_PIN);
	gpio_init(BLED_PIN);


	gpio_set_dir(PIR_PIN, GPIO_IN);
	gpio_set_dir(LED_PIN, GPIO_OUT);
	gpio_set_dir(BLED_PIN, GPIO_OUT);

	for(;;) {
		pirinfo = gpio_get(PIR_PIN);
		gpio_put(LED_PIN, pirinfo);
		gpio_put(BLED_PIN, pirinfo);
		sleep_ms(50);
	}
}