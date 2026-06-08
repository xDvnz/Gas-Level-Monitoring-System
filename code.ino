// ==========================================
// DEFINE & TEMPLATE BLYNK
// ==========================================
#define BLYNK_TEMPLATE_ID "TMPL6F5vSNs8g"
#define BLYNK_TEMPLATE_NAME "Gas level Monitoring2"
#define BLYNK_PRINT Serial

// ==========================================
// LIBRARIES
// ==========================================
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// ==========================================
// PIN MAPPING & CONFIGURATION
// ==========================================
#define BLYNK_AUTH_TOKEN "use auth token from blynk app"
#define Buzzer D5
#define Green D6
#define Blue D7
#define Sensor A0

// Alamat I2C LCD umumnya 0x27 dengan ukuran 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ==========================================
// NETWORK & VARIABLES
// ==========================================
char auth[] = "auth_token";  // use your auth token from blynk app
char ssid[] = "Wifi_SSID";   // SSID Wi-Fi
char pass[] = "Wifi_PASS";   // Password Wi-Fi

BlynkTimer timer;
int pinValue = 0;

// ==========================================
// SETUP
// ==========================================
void setup() {
  Serial.begin(9600);
  
  // Inisialisasi LCD
  lcd.backlight();
  lcd.init();
  lcd.setCursor(3, 0);
  lcd.print("Projek IoT");
  lcd.setCursor(6, 1);
  lcd.print("2024");
  delay(5000);
  lcd.clear();
  
  // Menghubungkan ke Wi-Fi Display
  lcd.setCursor(0, 0);
  lcd.print("Connecting WiFi...");
  lcd.setCursor(0, 1);
  lcd.print(ssid);
  delay(10000);
  lcd.clear();

  // Konfigurasi I/O Pins
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Sensor, INPUT);

  // Inisialisasi Blynk
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(100L, notifiaction);
}

// ==========================================
// BLYNK COMS
// ==========================================
BLYNK_WRITE(V0) {
  pinValue = param.asInt();
}

// ==========================================
// CORE LOGIC & NOTIFICATIONS
// ==========================================
void notifiaction() {
  int sensor = analogRead(Sensor);
  Serial.println(sensor);
  
  // Kalibrasi nilai analog ke dalam bentuk persentase (0-100)
  sensor = map(sensor, 0, 1024, 0, 100);

  if (pinValue == 1) {
    if (sensor <= 60) {
      digitalWrite(Green, HIGH);
      digitalWrite(Blue, LOW);
      digitalWrite(Buzzer, LOW);
      lcd.setCursor(0, 1);
      lcd.print("Level:Normal ");
    } else if (sensor > 60) {
      digitalWrite(Green, LOW);
      digitalWrite(Blue, HIGH);
      digitalWrite(Buzzer, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("Level: High  ");
    }
    
    lcd.setCursor(0, 0);
    lcd.print("Value: ");
    lcd.print(sensor);
    Blynk.virtualWrite(V1, sensor);
    
  } else {
    // Jika pinValue tidak aktif (0)
    digitalWrite(Blue, LOW);
    digitalWrite(Buzzer, LOW);
    digitalWrite(Green, LOW);
    lcd.clear();
  }
}

// ==========================================
// MAIN LOOP
// ==========================================
void loop() {
  Blynk.run();
  timer.run();
}
