#include <ArduinoJson.h> // JSON 통신을 위한 헤더 포함

int trig1 = 2;
int echo1 =  3;

int trig2= 4;
int echo2 = 5;

int trig3 = 8;
int echo3 =  9;

long duration1, distance1, duration2,distance2, duration3,distance3;

char msg[50];//ultra json serial

void ultra_Json(float distance1,float distance2,float distance3){
  StaticJsonDocument<200> doc;  //JSON변환에 필요한 버퍼 선언, 용량 200 설정
  JsonArray ultra = doc.createNestedArray("ultra");
  ultra.add(distance1);
  ultra.add(distance2);
  ultra.add(distance3);

  serializeJson(ultra, Serial);
  Serial.println();
  serializeJsonPretty(doc,Serial);
}


void setup() {
   //시리얼 통신을 설정(전송속도 9600bps)
  Serial.begin(9600);
  while (!Serial) continue;
  
  //초음파 송신부-> OUTPUT, 초음파 수신부 -> INPUT
  pinMode(trig1,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);
  pinMode(trig3,OUTPUT);
  pinMode(echo3,INPUT);

}

void loop() {

  digitalWrite(trig1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig1,HIGH);
  delayMicroseconds(5);
  digitalWrite(trig1,LOW);
  duration1= pulseIn(echo1, HIGH);

  digitalWrite(trig2,LOW);
  delayMicroseconds(2);
  digitalWrite(trig2,HIGH);
  delayMicroseconds(5);
  digitalWrite(trig2,LOW);
  duration2= pulseIn(echo2, HIGH);

  digitalWrite(trig3,LOW);
  delayMicroseconds(2);
  digitalWrite(trig3,HIGH);
  delayMicroseconds(5);
  digitalWrite(trig3,LOW);
  duration3= pulseIn(echo3, HIGH);

  //초음파는 29마이크로초 당 1센치를 이동
  //초음파의 이동 거리 = duration(왕복에 걸린시간) / 29 / 2
  distance1 = (duration1/2)/29;
  distance2 = (duration2/2)/29;
  distance3 = (duration3/2)/29;

  ultra_Json(distance1, distance2, distance3);
  
  delay(2000);
}
