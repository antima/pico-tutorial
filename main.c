#include "pico/stdlib.h"
#include "hardware/pwm.h"

typedef enum {
	FADEIN,
	FADEOUT
} fade_type;

void fade(bool fade_in, const uint gpio) {
	uint ctr = 0;
	
	for(int i = 0; i < 255; i++) {
		if(fade_in) {
			pwm_set_gpio_level(gpio, ctr * ctr);
		} else {
			pwm_set_gpio_level(gpio, (255 - ctr) * (255 - ctr));
		}
		sleep_ms(10);
	}
}

int main() {
	uint pir_data;
	const uint led1 = 0;
	const uint led2 = 1;
	const uint pir_sensor = 15;

	gpio_set_function(led1, GPIO_FUNC_PWM);
	gpio_set_function(led2, GPIO_FUNC_PWM);

	gpio_init(pir_sensor);
	gpio_set_dir(pir_sensor, GPIO_IN);

	uint slice_id_zero = pwm_gpio_to_slice_num(led1);

	pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 1.f);
    pwm_init(slice_id_zero, &config, true);

	while(1) {
		pir_data = gpio_get(pir_sensor);
		fade(pir_data, led1);
		fade(pir_data, led2);
	}
}