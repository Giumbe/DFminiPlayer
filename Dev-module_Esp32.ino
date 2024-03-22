#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial mySoftwareSerial(27, 26); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

const int pirPin = 14;
boolean presenceDetected = false;

void setup() {
  Serial.begin(9600);
  mySoftwareSerial.begin(9600);

  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1. Please recheck the connection!"));
    Serial.println(F("2. Please insert the SD card!"));
    while (true);
  }

  myDFPlayer.volume(20); // Imposta il volume desiderato
}

void loop() {
  Serial.println("A");
  if (digitalRead(pirPin) == HIGH && !presenceDetected) {
    presenceDetected = true;
    playRandomTrack();
  } else if (digitalRead(pirPin) == LOW && presenceDetected) {
    presenceDetected = false;
    myDFPlayer.stop(); // Ferma la riproduzione
  }
}

void playRandomTrack() {
  myDFPlayer.randomAll(); // Riproduci traccia casuale
  delay(15000); // Attendi * secondi prima di verificare la disponibilità
  //Serial.println(F("B"));

}
