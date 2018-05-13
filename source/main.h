/*
 *
 *
 */

#ifndef MAIN_H
#define MAIN_H

#include "mbed.h"
#include "Adafruit_SSD1306.h"
#include "images.h"
#include "manFigure.h"
#include "nrf52_digital.h"
#include "max30101.h"
#include "max30101_regs.h"

#define I2C_SDA     (p3)
#define I2C_SCL     (p4)

#define MAN_FIGURE_REPS                 (1)
#define MENU_WAIT_MS                    (2000)
#define MAN_FIGURE_FRAME_DURATION_MS    (50)
#define START_UP_DELAY_S    (5)

#define PO_I2C_DATA_PIN     (p17)
#define PO_I2C_CLK_PIN      (p18)
#define PO_EN_PIN           (p9)
#define PO_R_ADDRESS        (0xAF)
#define PO_W_ADDRESS        (0xAE)

#endif