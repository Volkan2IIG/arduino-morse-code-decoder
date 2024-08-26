const int ledPin = 13;
const int buttonPin = 7;
unsigned long pressStartTime = 0;
unsigned long pressDuration = 0;
unsigned long lastPressTime = 0;
String morseCode = "";
String decodedMessage = "";

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    pressStartTime = millis();  // Butona basma süresini başlat
    digitalWrite(ledPin, HIGH);  // LED'i yakarak geri bildirim ver

    while (digitalRead(buttonPin) == LOW) {
      // Butona basılı tutulduğunda
    }

    digitalWrite(ledPin, LOW);  // Buton bırakıldığında LED'i söndür
    pressDuration = millis() - pressStartTime;  // Butona basılı tutulma süresi
    lastPressTime = millis();  // Son basma zamanını güncelle

    if (pressDuration < 200) {
      morseCode += ".";
    } else if (pressDuration > 200) {
      morseCode += "-";
    } else if (pressDuration >= 3000) {
      // Eğer 3 saniye basılı tutulduysa, boşluk ekle
      decodedMessage += " ";
      Serial.println(decodedMessage);
    }

  } else if (morseCode.length() > 0 && millis() - lastPressTime > 1000) {
    // Eğer belirli bir süre (1 saniye) butona basılmamışsa, harfi çöz
    decodedMessage += morseToChar(morseCode);
    morseCode = "";  // Morse kodunu sıfırla

    // Mesajı seri monitöre yazdır
    Serial.println(decodedMessage);
  }
}

char morseToChar(String code) {
  if (code == ".-") return 'A';
  if (code == "-...") return 'B';
  if (code == "-.-.") return 'C';
  if (code == "-..") return 'D';
  if (code == ".") return 'E';
  if (code == "..-.") return 'F';
  if (code == "--.") return 'G';
  if (code == "....") return 'H';
  if (code == "..") return 'I';
  if (code == ".---") return 'J';
  if (code == "-.-") return 'K';
  if (code == ".-..") return 'L';
  if (code == "--") return 'M';
  if (code == "-.") return 'N';
  if (code == "---") return 'O';
  if (code == ".--.") return 'P';
  if (code == "--.-") return 'Q';
  if (code == ".-.") return 'R';
  if (code == "...") return 'S';
  if (code == "-") return 'T';
  if (code == "..-") return 'U';
  if (code == "...-") return 'V';
  if (code == ".--") return 'W';
  if (code == "-..-") return 'X';
  if (code == "-.--") return 'Y';
  if (code == "--..") return 'Z';
  if (code == ".----") return '1';
  if (code == "..---") return '2';
  if (code == "...--") return '3';
  if (code == "....-") return '4';
  if (code == ".....") return '5';
  if (code == "-....") return '6';
  if (code == "--...") return '7';
  if (code == "---..") return '8';
  if (code == "----.") return '9';
  if (code == "-----") return '0';
  return '?'; // Geçersiz Morse kodları için
}
