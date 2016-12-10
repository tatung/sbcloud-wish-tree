const int ledPin = 13;
const int redLedPin = 12;
const int analogInPin = A0;
int   ad;

int prevState = 0;
const int switchPin = 8;
const int delayTimer = 5000;
const String humanMsg = "HUMAN";
long humanDetectTime = 0;



void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
  delay(delayTimer);
  blinkLed();
}



void loop()
{
    // reading human sensor
//    blinkLed();
//    Serial.println(millis());
    ad = analogRead(analogInPin);
    if ( ad == 0 ) {
      digitalWrite(ledPin, LOW);
      if(prevState == 1){
        long holdTime = millis() - humanDetectTime;
        delay(500);
        Serial.println("On Hold Time: " + holdTime);
        Serial.println(" ");
        prevState = 0;
      }
    }else{
      digitalWrite(ledPin, HIGH);
      if(prevState == 0){
        blinkLed();
        blinkLed();
        humanDetectTime = millis();
        Serial.println(humanMsg);
        
        prevState = 1;
      }
    }

}

void blinkLed(){
  digitalWrite(redLedPin, HIGH);
  delay(100);
  digitalWrite(redLedPin, LOW);
  delay(100);
}

