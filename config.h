#pragma once
#include "config_common.h"

// Всякие товарные настройки, от этого зависит, как компьютер будет видеть твою клавиатуру. 4E это аскии-код для N. DAN, получается.
#define VENDOR_ID 0x6875
#define PRODUCT_ID 0x0001
#define DEVICE_VER 1
#define MANUFACTURER DanInSpace
#define PRODUCT Compositum
#define DESCRIPTION Ergonomic split keyboard

// Настройки рядов.
// google: pro micro pinout, там смотри пины
#define MATRIX_ROWS 8
#define MATRIX_COLS 7
#define MATRIX_ROW_PINS { D0, D1, D2, D3, D4, C6, D7, E6 }
#define MATRIX_COL_PINS { B2, B3, B1, F7, B6, F5, F4 }

// Если не работает, то попробуй ROW2COL. Эта настройка отвечает за расположение диодов
#define DIODE_DIRECTION COL2ROW

// Сколько длится нажатие или что-то такое. Чем ты быстрее, тем это должно быть меньше. 140 — довольно оптимальное значение для меня.
#define TAPPING_TERM 140
// Сколько длится дебаунс. 5 достаточно почти всегда. Увеличь, если почему-то двойные нажатия проскакивают.
#define DEBOUNCING_DELAY 5

// https://docs.qmk.fm/#/faq_keymap?id=mechanical-lock-switch-support
// не особо понимаю, зачем это
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

// Дефолтный способ переключения раскладок.
// https://github.com/optozorax/moonlander/tree/master/lang_shift#задать-характеристики
#define LANG_CHANGE_DEFAULT LANG_CHANGE_ALT_SHIFT
