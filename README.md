## Композитум 0.1
Совещайся с [доками ймк](https://docs.qmk.fm/). У нас наверняка разные версии ЙМК, что-то может пойти не так, мною не предусмотренное.

### Куда класть эту папку
В `qmk_firmware/keyboards` под именем `compositum`.

### Заметка про Ильины модули
Я использую в твоей раскладке `lang_shift`. Должен работать хорошо. Но, поскольку, я твою прошивку на основне прошивки для Сагариса делал, тут немного старая версия. Свежак всегда здесь: https://github.com/optozorax/moonlander

В новой версии нет `SHF_N`, есть `SFT_N`. Ты это заметишь, если обновишь `lang_shift`.

### Как собирать
Я умею только через обычный `make` собирать. Для выполнения команд, сначала переместись в `qmk_firmware`.

#### Собрать, но не прошивать
```sh
make compositum:default
```
У меня это работало.

#### Собрать и прошить
```sh
make compositum:default:avrdude
```
Я это не проверял. Для удобства прошивания добавил тебе в раскладку клавишу `RESET`.

### Что тут ещё делать
* Тут ещё долго надо крутить раскладки. Я просто примерную набросал для понимания.
* Физические параметры в `config.h` обязательно надо правильно настроить.

