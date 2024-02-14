PROJ := Discovertos

CC := arm-none-eabi-gcc
LL := arm-none-eabi-ld
NM := arm-none-eabi-nm
OD := arm-none-eabi-objdump

MCPU := cortex-m4
MARCH := armv7e-m
SRCDIR := src
INCDIR := include
LIBDIR := lib
BUILDIR := build

CFLAGS = -I $(INCDIR) -mcpu=$(MCPU) -mthumb -Wall -O0 -specs=nano.specs -specs=nosys.specs
LFLAGS = -nostdlib -T STM32.ld -Wl,-Map=$(PROJ).map

SRCS = $(wildcard $(SRCDIR)/*.c)

OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDIR)/%.o, $(SRCS))
ACTIONS = all clean help action

.PHONY: $(ACTIONS)
all : $(PROJ).elf
#	.\$(BUILDIR)\$(PROJ)
clean :
	del /Q $(BUILDIR)
help :
	$(CC) --help
action :
	@echo $(ACTIONS)

$(PROJ).elf : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(BUILDIR)/$@
$(BUILDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $^
nm : $(BUILDIR)/$(PROJ).elf
	$(NM) $^
objdump : $(BUILDIR)/$(PROJ).elf
	$(OD) -h $^
