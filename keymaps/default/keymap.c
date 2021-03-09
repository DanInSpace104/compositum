// Эта штука подставляется при компиляции как-то
#include QMK_KEYBOARD_H

// Подключаем ланг_шифт
#include "lang_shift/include.h"

// Слои задаются здесь. Обычные ймкшные найдёшь, Ильины смотри здесь: https://github.com/optozorax/moonlander/blob/master/lang_shift/include.h либо в аналогичном файле здесь. 
// Там ↑ много полезного.
//
// Все кикоды *_0, RU_*, EN_*, AG_* взяты из ланг_шифта. Довольно много, да. KC_* из ЙМК.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	// Латиница. Если зажимается какой-то мод, то по идее этот мод будет зажиматься с буквами с этого слоя. 
	[LATIN] = FINGERS(
			KC_DQUO, EN_Q, EN_D, EN_R,  EN_W,  EN_B,
			KC_TAB,  EN_A, EN_S, EN_H,  EN_T,  EN_G,
			KC_LPRN, EN_Z, EN_X, EN_M,  EN_C,  EN_V,

			EN_J,   EN_F,   EN_U,    EN_P,   KC_COLN, KC_QUOT,
			EN_Y,   EN_N,   EN_E,    EN_O,   EN_I,    LA_CHNG,
			EN_K,   EN_L,   EN_COMM, EN_DOT, KC_UNDS, KC_RPRN
			), 
	// Шифтовая латинка. EN_A — обычная буква, а EN_S_A — та же самая, но с шифтом.
	[LATIN_SHIFT] = FINGERS(
			KC_DQUO, EN_S_Q, EN_S_D, EN_S_R,  EN_S_W,  EN_S_B,
			KC_TAB,  EN_S_A, EN_S_S, EN_S_H,  EN_S_T,  EN_S_G,
			EN_LT, EN_S_Z, EN_S_X, EN_S_M,  EN_S_C,  EN_S_V,

			EN_S_J, EN_S_F, EN_S_U,  EN_S_P, KC_COLN, KC_QUOT,
			EN_S_Y, EN_S_N, EN_S_E,  EN_S_O, EN_S_I,  LA_CHNG,
			EN_S_K, EN_S_L, KC_LT,   KC_GT,  KC_UNDS, EN_GT
			),
	// Кириллица.
	// Обрати внимание на kDTSP, это точка с пробелом.
	[CYRILLIC] = FINGERS(
			RU_JO,   RU_TS, RU_SF, RU_P, RU_JA, RU_ZH,
			KC_TAB,  RU_U,  RU_I,  RU_JE, RU_O,  RU_A,
			KC_LPRN, RU_F,  RU_E,  RU_H, RU_Y,  RU_J,

			RU_Z, RU_V, RU_K,    RU_D,  RU_CH, RU_SH,
			RU_L, RU_N, RU_T,    RU_S,  RU_R,  LA_CHNG,
			RU_B, RU_M, AG_CMSP, kDTSP, RU_G,  KC_RPRN
			),
	[CYRILLIC_SHIFT] = FINGERS(
			RU_S_JO,   RU_S_TS, RU_S_SF, RU_S_P, RU_S_JA, RU_S_ZH,
			KC_TAB,  RU_S_U,  RU_S_I,  RU_S_JE, RU_S_O,  RU_S_A,
			KC_LPRN, RU_S_F,  RU_S_E,  RU_S_H, RU_S_Y,  RU_S_J,

			RU_S_Z, RU_S_V, RU_S_K,    RU_S_D,  RU_S_CH, RU_S_SH,
			RU_S_L, RU_S_N, RU_S_T,    RU_S_S,  RU_S_R,  LA_CHNG,
			RU_S_B, RU_S_M, AG_CMSP, kDTSP, RU_S_G,  KC_RPRN
			),
	[LETTER] = FINGERS(
			_______, _______, RU_HD,   _______, _______, _______,
			_______, _______, _______, _______, _______, _______,
			_______, _______, _______, _______, _______, _______,

			_______, _______, _______, _______, _______, _______,
			_______, _______, RU_SC,   RU_JU,   _______, _______,
			_______, _______, _______, _______, _______, _______
	),
	// На Луне будет примерно то, что было на второй той картинке.
	// Я тебе сделал нумпад как у себя http://klavarog.tk/rev/4573ea3/раскладки_цифр#5 ; он проверенно удобный
	[MOON] = LAYOUT(
			EN_DQUO, _______, KC_6, KC_5,  KC_4,  KC_APP,
			KC_PERC, KC_3,    KC_2, KC_1,  KC_0,  KC_PLUS, LMOD4,
			_______, _______, KC_7, KC_8,  KC_9,  KC_ASTR, LMOD5,
                              LMOD0, LMOD1,  LMOD2,  LMOD3, LMOD6,

			KC_PAUS, KC_HOME,   KC_UP,   KC_END,   AG_SCLN, KC_QUOT,
	KC_BSPC, KC_INS,  KC_LEFT,   KC_DOWN, KC_RIGHT, KC_PGUP, _______,
	RMOD5,	KC_PSCR, KC_VOLD,   KC_MEDIA_PLAY_PAUSE, KC_VOLU,  KC_PGDN, _______,
	RMOD6, RMOD3, RMOD2, RMOD1, RMOD0	),
	// На Солнце я раскидал эфки, но в основном это копия Луны. Сам придумаешь, что тут можно разместить. Подумай про эмуляцию мыши или сложные хоткеи.
	// Я использую такую раскладку эфок на Сагарисе.
	// Обрати внимание на RESET, эта клавиша аналогична замыканию промикры. Нажимай её, когда ймк просит ресетнуть.
	[SUN] = FINGERS(
			_______, _______, EN_DLR,  KC_EXLM, AG_QUES,  EN_CIRC,
			RESET, EN_PIPE, AG_SCLN, KC_EQL,  KC_MINS,  EN_GRV,
			_______,   _______, AG_BSLS, EN_TILD, AG_SLSH,  EN_HASH,

			EN_AMPR, EN_AT,   KC_F1, KC_F2,  KC_F3,  KC_F4,
			EN_RCBR, EN_LCBR, KC_F5, KC_F6,  KC_F7,  KC_F8,
			EN_RBRC, EN_LBRC, KC_F9, KC_F10, KC_F11, KC_F12
	),
};

// След две функции нужны для ланг_шифта
void user_timer(void) {
	lang_shift_user_timer();
}

void matrix_scan_user(void) {
	user_timer();
}

// Здесь задаются кастомные клавиши и прочие макросы
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	// Для ланг_шифта
	if (!lang_shift_process_record(keycode, record))
		return false;

	switch (keycode) {
		// Пример кастомной клавиши. Пишешь case <клавиша>:, клавиши задаются в enum custom_key (compositum.h).
		case kDTSP:
			// Если клавиша нажата, то то-сё. Если добавишь else-ветку, то сможешь обрабатывать отжатие клавиши.
			if (record->event.pressed) {
				// tap_code16 нажимает клавишу. Она лучше tap_code, потому что поддерживает моды, но всё ещё очень слаба, ибо не все клавиши поддерживает.
				// У Ильи есть https://github.com/optozorax/moonlander/tree/master/arbitrary_keycode, в котором есть функция, которая делает это лучше.
				tap_code16(KC_SLSH);
				tap_code16(KC_SPC);
			}
			// Код каждой кастомной клавиши должен кончаться на return false, чтобы показать, что что-то было нажато, наверное.
			return false;
	}
	return true;
}
