include <AccelStepper.h>
#include <MultiStepper.h>

#include <SPI.h>
#include <WiFi101.h>

char ssid[] = "wifiNetwork"; 
char pass[] = "wifiPassword"; 
int keyIndex = 0; 

int status = WL_IDLE_STATUS;

WiFiServer server(80);

AccelStepper stepper(1, 9, 8);

float distance = 0;
float distance_mm_multiplier = 25.4;
float duration = 0;
float duration_sec_multiplier = 60;

void setup() {
  setup_stepper();
  setup_wifi();
}

void loop() {
  stepper.runSpeedToPosition();
  WebListenForClients();
}
