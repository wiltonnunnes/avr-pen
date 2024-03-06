help:
	@echo 'Help details:'
	@echo 'hex: compile hex file'
	@echo 'flash: install hex file'
	@echo 'program: compile hex and install'

hex:
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c main.c
	avr-gcc -DF_CPU=16000000UL -mmcu=atmega328p -o main.elf main.o
	avr-objcopy -O ihex main.elf main.hex
	rm main.o
	rm main.elf

flash:
	avrdude -c arduino -p atmega328p -P /dev/ttyACM0 -U flash:w:main.hex