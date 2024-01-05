#include <GyverOLED.h> // Использую библиотеку GyverOLED для общения с дисплеем https://github.com/GyverLibs/GyverOLED

GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled; // Объект OLED экрана (работа с ним)
// У меня базовый OLED экран 128x64 пикселя. Схема его подключения есть в README файле

bool updatable = false; // Стоит ли обновлять экран каждый раз (true) или обновлять только при получении новых данных (false)

void setup() {
	// Инициализация
	oled.init();
	oled.setScale(3); // Размер шрифта чуть побольше, чтобы видно было, т.к. планируется отправлять только один символ
	Serial.begin(9600);
	Serial.setTimeout(5);
}

void loop() {

	if (updatable){
		oled.clear();
		oled.setCursor(0, 0);
	}

	if (Serial.available() > 0){
		// Если есть данные в буфере, то читаем, обновляем значение
		char incomingByte = Serial.read();
		oled.clear();
		oled.setCursor(0, 0);
		oled.print(incomingByte);
	}
}