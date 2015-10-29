# ============================================
CC=arm-none-eabi-gcc
LD=arm-none-eabi-gcc
AR=arm-none-eabi-ar
AS=arm-none-eabi-as

OBJCOPY=arm-none-eabi-objcopy
OBJDUMP=arm-none-eabi-objdump
SIZE=arm-none-eabi-size

FULLASSERT = -DUSE_FULL_ASSERT

APP_NAME = demo
ROOT_PATH = ../
LIBROOT = $(ROOT_PATH)/lib/
DEVICE=$(LIBROOT)/CMSIS/CM3/DeviceSupport/ST/STM32F10x
CORE=$(LIBROOT)/CMSIS/CM3/CoreSupport
PERIPH=$(LIBROOT)/STM32F10x_StdPeriph_Driver

PTYPE = STM32F10X_MD
LDSCRIPT = ./stm32_flash.ld

CFLAGS  = -O1 -g
ASFLAGS = -g

LDFLAGS += -T$(LDSCRIPT) -mthumb -mcpu=cortex-m3
LDFLAGS += --specs=nosys.specs
LDFLAGS += -Wl,--gc-sections 
CFLAGS += -mcpu=cortex-m3 -mthumb -nostdlib -nostartfiles
CFLAGS += -I$(ROOT_PATH) -I$(DEVICE) -I$(CORE) -I$(PERIPH)/inc -I. -I../src/app
CFLAGS += -D$(PTYPE) -DUSE_STDPERIPH_DRIVER $(FULLASSERT)

vpath %.c $(ROOT_PATH)/lib/STM32F10x_StdPeriph_Driver/src

SRCS =  misc.c stm32f10x_can.c stm32f10x_dac.c stm32f10x_exti.c stm32f10x_gpio.c  \
	stm32f10x_pwr.c stm32f10x_sdio.c stm32f10x_usart.c stm32f10x_adc.c stm32f10x_cec.c \
	stm32f10x_dbgmcu.c stm32f10x_flash.c stm32f10x_i2c.c stm32f10x_rcc.c stm32f10x_spi.c \
	stm32f10x_wwdg.c stm32f10x_bkp.c stm32f10x_crc.c stm32f10x_dma.c stm32f10x_fsmc.c \
	stm32f10x_iwdg.c  stm32f10x_rtc.c  stm32f10x_tim.c

vpath %.c $(ROOT_PATH)/src/app/
SRCS += main.c

vpath %.c $(ROOT_PATH)/src/startup/

SRCS += system_stm32f10x.c
OBJS = $(SRCS:.c=.o)

vpath %.s $(ROOT_PATH)/src/startup/
ASRCS = startup_stm32f10x_md.s
OBJS += $(ASRCS:.s=.o)



all: $(APP_NAME).elf

$(APP_NAME).elf: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)
	$(OBJCOPY) -O ihex $(APP_NAME).elf $(APP_NAME).hex
	$(OBJCOPY) -O binary $(APP_NAME).elf $(APP_NAME).bin
	$(OBJDUMP) -St $(APP_NAME).elf >$(APP_NAME).lst
	$(SIZE) $(APP_NAME).elf

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
#	$(CC) -MM $(CFLAGS) $< > $*.d

%.o: %.s
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(OBJS:.o=.d) $(ELF) startup_stm32f* $(CLEANOTHER)
