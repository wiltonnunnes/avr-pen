help:
	@echo 'Help details:'
	@echo 'hex: compile hex file'
	@echo 'flash: install hex file'
	@echo 'program: compile hex and install'

hex:
	avr-gcc -Os -DF_CPU=8000000 -mmcu=attiny85 -c main.c
	avr-gcc -DF_CPU=8000000 -mmcu=attiny85 -o main.elf main.o
	avr-objcopy -O ihex main.elf main.hex
	rm main.o
	rm main.elf

flash:
	avrdude -c arduino -p attiny85 -P /dev/tty.usbmodemfd121 -U flash:w:main.hex