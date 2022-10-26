  // Tortilleria 
const int sensor1     = 2;
const int sensor2     = 4;
const int relay1      = 12;
const int relay2      = 13;
const int stopButton  = 7;
const int led1        = 8;
const int led2        = 9;

int counter1          = 0;
int counter2          = 0;
int prevStatus1       = 0;
int prevStatus2       = 0;
int valueSensor1      = 0;
int valueSensor2      = 0;


void setup() {

Serial.begin(9600);
pinMode(stopButton,INPUT);
pinMode(sensor1,INPUT);
pinMode(sensor2,INPUT);
pinMode(relay1,OUTPUT);
pinMode(relay2,OUTPUT); 

}

void loop() {

if(digitalRead(stopButton) == HIGH) 
{
  valueSensor1 = digitalRead(sensor1);
  valueSensor2 = digitalRead(sensor2);

    if (valueSensor1 != prevStatus1)
    {
      if(valueSensor1 == HIGH)
      {
        counter1++;
        delay(100);
        Serial.println(counter1);
        digitalWrite (led1,HIGH);
      }
      if(valueSensor1 == LOW)
      {
        digitalWrite(led1,LOW);
      }
    }

  prevStatus1 = valueSensor1;

    if (counter1 == 25)
    {
        digitalWrite(relay1,HIGH);
        delay(100);
    }
      else
    {
        digitalWrite(relay1,LOW);
    }
    if (counter1 == 26)
    {
        counter1 = 1;
        delay(100);
    }
    
    if (valueSensor2 != prevStatus2)
    {
      if(valueSensor2 == HIGH)
      {
        counter2++;
        delay(100);
        Serial.println(counter2);
        digitalWrite (led2,HIGH);
      }
      if(valueSensor2 == LOW)
      {
        digitalWrite(led1,LOW);
      }
    }

  prevStatus2 = valueSensor2;

    if (counter2 == 25)
    {
        digitalWrite(relay2,HIGH);
        delay(100);
    }    
      else
    {
        digitalWrite(relay2,LOW);
    }
    if (counter2 == 26)
    {
        counter2 = 1;
        delay(100);
    }
}

if(digitalRead(stopButton) == LOW)
{
//0 
}
}
