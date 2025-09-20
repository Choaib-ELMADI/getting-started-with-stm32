#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_

#include "stm32f446xx.h"

void convert_char_bits(unsigned char);

void gpio_init(void);

void lcd_enable_data_latch(void);
void lcd_disable_data_latch(void);
void lcd_enable_read(void);
void lcd_enable_write(void);
void lcd_enable_dr(void);
void lcd_enable_ir(void);

void lcd_data(unsigned char);
void lcd_command(unsigned char);
void lcd_print_string(unsigned char *, unsigned char);

void lcd_init(void);

#endif // LCD_DRIVER_H_
