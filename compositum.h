#pragma once
#include "quantum.h"
/* В этом файле надо обьявлять свои слои, кастомные клавиши, макросы и прочие штуки, которые могут использоваться во всех кимапах, если у тебя их несколько. Функции тут вроде не обьявляют. */

// Слои
//   вернее, их номера.
//   lang_shift Ильи использует дополнительные слои для шифта, поэтому буквы придётся писать дважды.
#define LATIN 0
#define LATIN_SHIFT 1
#define CYRILLIC 2
#define CYRILLIC_SHIFT 3
#define LETTER 4
#define MOON 5
#define SUN 6


// Кастомные клавиши
//   но только те, которые нужно будет описывать кодом в keymap.c
enum custom_key {
    A = SAFE_RANGE, // Первый пункт в этом енуме должен равняться этому
	kDTSP, // Точка с пробелом для русского языка
	// Дополнительные клавиши добавляй сюда
	// ...
	ILYA_FLEX, // А это костыль для ланг_шифта
};

// Илья по-другому как-то обьясняет, я не особо понимаю, ладно: https://github.com/optozorax/moonlander/tree/master/lang_shift#задание-safe_range
#define CUSTOM_SAFE_RANGE ILYA_FLEX

// Кастомные клавиши
//   но только те, которые можно описать через дефолтные ймкшные кикоды
//   1. Включающие слой при зажатии. См https://docs.qmk.fm/#/feature_layers?id=switching-and-toggling-layers чтобы узнать, какие ещё фокусы со слоями бывают.
#define kMOON MO(MOON)
#define kSUN MO(SUN)
#define kLETTER MO(LETTER)

// Макрос раскладки
//   тебе придётся это под себя менять, не забывай про \ в конце строк
#define LAYOUT(\
	k01, k02,  k03,  k04,  k05,  k06,		\
	k11, k12,  k13,  k14,  k15,  k16,  k17,	\
	k21, k22,  k23,  k24,  k25,  k26,  k27,	\
			   ktl1, ktl2, ktl3, ktl4, ktl5,\
	\
		  k31,  k32,  k33,  k34, k35, k36,	\
	k41,  k42,  k43,  k44,  k45, k46, k47,	\
	k51,  k52,  k53,  k54,  k55, k56, k57,	\
	ktr1, ktr2, ktr3, ktr4, ktr5			\
	) \
{\
	{ktr1, 	k31, 	k32, 	k33, 	k34, 	k35, 	k36},	\
	{k41, 	k42, 	k43, 	k44, 	k45, 	k46, 	k47},	\
	{k51, 	k52, 	k53, 	k54, 	k55, 	k56, 	k57},	\
	{ktr2, 	ktr3, 	ktr4, 	ktr5, 	KC_NO, 	KC_NO, 	KC_NO},	\
	{ktl5, 	k06, 	k05, 	k04, 	k03, 	k02, 	k01},	\
	{k17, 	k16, 	k15, 	k14, 	k13, 	k12, 	k11},	\
	{k27, 	k26, 	k25, 	k24, 	k23, 	k22, 	k21},	\
	{ktl4, 	ktl3, 	ktl2, 	ktl1, 	KC_NO, 	KC_NO, 	KC_NO},	\
}

#define LMOD0 ALT_0  
#define LMOD1 CTRL_0  
#define LMOD2 KC_SPC  
#define LMOD3 SHF_N  
#define LMOD4 KC_ENT  
#define LMOD5 KC_DEL
#define LMOD6 kSUN

#define RMOD0 WIN_0  
#define RMOD1 kLETTER  
#define RMOD2 SHF_N  
#define RMOD3 KC_RCTRL  
#define RMOD4 KC_BSPC  
#define RMOD5 KC_ESC
#define RMOD6 kMOON
// Поскольку 14 клавиш между слоями не меняются, есть смысл сделать так, чтобы не пришлось их дублировать вручную. 
// Этот макрос именно это и делает. Остаётся задать те клавиши, которые меняются между слоями.
#define FINGERS(\
    k01, k02, k03, k04, k05, k06, \
    k11, k12, k13, k14, k15, k16, \
    k21, k22, k23, k24, k25, k26, \
    \
    k31, k32, k33, k34, k35, k36, \
    k42, k43, k44, k45, k46, k47, \
    k52, k53, k54, k55, k56, k57  \
  ) \
LAYOUT(\
    k01, k02, k03, k04, k05, k06,			\
    k11, k12, k13, k14, k15, k16, 	LMOD4, \
    k21, k22, k23, k24, k25, k26, 	LMOD5,	\
		LMOD0, LMOD1, LMOD2, LMOD3, LMOD6,	\
    \
			k31,  k32,   k33,   k34, k35, k36,	\
    RMOD4,	k42,  k43,   k44,   k45, k46, k47,	\
    RMOD5,	k52,  k53,   k54,   k55, k56, k57,	\
    RMOD6, RMOD3, RMOD2, RMOD1, RMOD0		\
)

