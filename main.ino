//Komunikasi dengan Blynk
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "your_template_id"
#define BLYNK_TEMPLATE_NAME "your_template_name"
#define BLYNK_AUTH_TOKEN "your_auth_token"
#include <BlynkSimpleEsp32.h>
#define SOUND_SPEED 0.034
#include <WiFi.h> 
#include <WiFiClient.h>
const char* ssid	= "name_your_wifi";
const char* pass = "your_password"; 
const int trigPin = 14;
const int echoPin = 27;
const int button = 25;
const int relay = 4;
BlynkTimer timer;
long duration;
float distanceCm;
int buttonState = 0;
bool pumpState = false;
bool lastButtonState = HIGH;
int jarakmaks = 18; //fill with your tank height
float tinggiAir;
int tinggiAirmaks = 14.8; //fill with your target
void pembacaan(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * SOUND_SPEED/2;
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);

  tinggiAir = jarakmaks - distanceCm;
  Serial.println("Tinggi air(Cm): ");
  Serial.println(tinggiAir);
  Blynk.virtualWrite(V2, tinggiAir);
  delay(1000);
  if (tinggiAir >= tinggiAirmaks){
    Blynk.logEvent("fulltank", "Tangki Air Sudah Penuh!");
    digitalWrite(relay, HIGH);
    Serial.println("Tangki air sudah penuh!");
  }
}

BLYNK_WRITE(V3) {
  bool Relay = param.asInt();
  if (Relay == 1) {
    digitalWrite(relay, LOW);
  } else {
    digitalWrite(relay, HIGH);
  }
}

void setup() {
  Serial.begin(115200); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass,"blynk.cloud",80);
  timer.setInterval(1000L, pembacaan);
  pinMode(button, INPUT_PULLUP);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
}
void loop() {
  bool currentButton = digitalRead(button);
  Serial.println(currentButton);
  if (lastButtonState == HIGH && currentButton == LOW) {
    pumpState = true;
    digitalWrite(relay, LOW);
    delay(200);
  }
  lastButtonState = currentButton;
  Blynk.run();
  timer.run();
}