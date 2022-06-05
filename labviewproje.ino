#define sensor1  A0
#define sensor2  A1
#define LED1  13 
#define LED2  12
#define buzzer 8

unsigned long  t1 = 0;
unsigned long  t2 = 0;
unsigned long time;
float speed;
float distance = 20.0;

int flag1 = 0;
int flag2 = 0;


void setup() 
{

  pinMode (sensor1, INPUT); 
  pinMode (LED1, OUTPUT); 
  pinMode (sensor2, INPUT); 
  pinMode (LED2, OUTPUT); 
  pinMode (buzzer, OUTPUT);
  Serial.begin(9600);
  delay(1000);
  
}

void loop()
{

  int value1 = digitalRead(sensor1);
  int value2 = digitalRead(sensor2);
  if (value1 == LOW && flag1 == 0){
  //Serial.println(digitalRead(sensor1));
  digitalWrite(LED1, HIGH);
  t1 = millis();
  flag1 = 1;
  }
  if(value1 == HIGH){digitalWrite(LED1, LOW);}

  if (value2 == LOW && flag2 == 0) {
    digitalWrite(LED2, HIGH);
    t2 = millis();
    //Serial.println(digitalRead(sensor2));
    flag2 = 1;
  }
  if(value2 == HIGH ){digitalWrite(LED2, LOW);}

  if (flag1 == 1 && flag2 == 1){
    if (t1 > t2){ time = t1 - t2; }
    else if (t2 > t1){ time = t2 - t1; }

    time = time / 1000; // milisaniye saniye cinsinden hesaplanıyor
    speed = (distance / time); // hız = mesafe / zaman
    speed = speed * 3600; //saniye saate çevriliyor 60saniye --> 1dk / ? saniye --> 60dk 
    speed = speed / 100000; //santimetre kilometreye çevriliyor
    
  }

  if (speed == 0){
    if (flag1 == 0 && flag2 == 0){
      Serial.println("Araba algilanmadi");
    }
    else{Serial.println("Araniyor");
    }
  }
  else {
    if(speed > 25){Serial.println("yuksek hiz"); digitalWrite(buzzer, HIGH);}
    else{Serial.println("normal hiz");}
    delay(1000);
    digitalWrite(buzzer, LOW);
    speed = 0; 
    flag1 = 0;
    flag2 = 0;
  }

}
