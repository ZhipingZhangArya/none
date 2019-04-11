/*
 * mini_project-group10, by Zhiping Zhang, the coding part for the mini project of DBB200 Creative Electronic in TU/e,
 * This programming is to use dht11 humidity & temperature sensor to trigger two servo motors in certain ways.
 */
#include <dht11.h>                                             
#define DHT11PIN 2               //dht sensor in D2                            
dht11 DHT11;                                                       
#include <Servo.h>
Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo


void setup() {                                                   
  Serial.begin(9600);                                           
  pinMode(DHT11PIN,OUTPUT);      // pinmode setting                
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);  // attaches the servo on pin 9 to the servo object
}

void loop() {                                                
int chk = DHT11.read(DHT11PIN);             
int tem=(float)DHT11.temperature;              
int hum=(float)DHT11.humidity;                  

Serial.print("Tempeature:");                     
Serial.println(tem);                                
Serial.print("Humidity:");                      
Serial.print(hum);                                
Serial.println("%");                          


if (tem > 23){ // when temperature higher than the expected (set by user) value
  myservo1.write (90);   // the servo motor 1 rotate into the position with 90 degree which indicates the shape changing of the layer1    
}

else{     // when temperature lower than or equal to the expected (set by user) value       
  myservo1.write(0);     // the servo motor 1 rotate into the position with 0 degree which indicates the shape changing of the layer1        
}

if (hum > 50){    // when humidity value higher than the expected (set by user) value
  myservo2.write (90);   // the servo motor 2 rotate into the position with 90 degree which indicates the shape changing of the layer2 
}
else{     // when humidity value lower than or equal to the expected (set by user) value
  myservo2.write(0);     // the servo motor 2 rotate into the position with 0 degree which indicates the shape changing of the layer2         
}
delay(1000);                                       
}
