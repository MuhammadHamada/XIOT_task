const int LED_PIN = 12;
const int pb_PIN = 7;
const int tmp_PIN = 6;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT); // pin #12 is set to be an output (LED)
  pinMode(pb_PIN, INPUT);   // pin #7 is set to be an input (push button) 
  pinMode(tmp_PIN,INPUT);   // pin #6 is set to be an input (Temperature sensor)
 }

// nextState saves the nextState State of the led if the push button is pressed
bool nextState = false;

// f1 & f2 are 2 flages to alternate between high and low correctly
bool f1 = false;  
bool f2 = false;

const uint32_t PERIOD = 3000;  // 3 seconds
uint32_t previousMillis = 0;

void readCurrentTemperature()
{
    Serial.println("Current Temperature : " + analogRead(tmp_PIN));
}

void loop()
{
  if(digitalRead(pb_PIN) == LOW && !f1) {
    Serial.println("pressed");
    if(nextState){ 
      digitalWrite(LED_PIN,HIGH);
    }else {
      digitalWrite(LED_PIN,LOW);  
    }
    f1=true;
    f2=false;
  }
  if(digitalRead(pb_PIN) == HIGH && !f2) {
    nextState = !nextState;
    f2=true;
    f1=false;
  }
    if (millis() - previousMillis >= PERIOD) {
        readCurrentTemperature();
        previousMillis += PERIOD;
    }
    
}
