# XenonHEN Makefile
# Made by: Xenon Tech

# Settings:
Target = XenonHEN
OutDir = $(shell pwd)

# SDK path
OO_PS4_SDK = $(C:\Users\lovas\Desktop\XenonHEN\OpenOrbis\libPS4)

# Translater's settings
CC			= clang
LD			= ld.lld
CFLAGS		= -isystem $(OO_PS4_SDK)/lib -lkernel -lnotification -T $(OO_PS4_SDK)/link.x

# Source files
Source = $(wildcard *.c)
Object = $(Source:.c=.o)

# Main process
all: $(Target).bin

$(Target).bin: $(Object)
	$(LD) $(LDFLAGS) -o $(Target).elf $(Object)
	objcopy -O binary $(Target).elf $(OutDir)/$(Target).bin
	rm $(Target).elf

%.o %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(Target).bin $(Object)