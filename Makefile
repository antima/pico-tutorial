ifdef OS
	CP = copy
	InPath = ".\build\led_pico.uf2"
	OutPath = "D:"
else
	CP = cp
	InPath = "build/led_pico.uf2"
	OutPath = "/media/${USER}/RPI-RP2"
endif

flash:
	$(CP) $(InPath) $(OutPath)

.PHONY : flash
