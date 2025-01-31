// use this code for the debugging purpose this code includes the serial monitor.

#include <LiquidCrystal.h>
#include <WiFi.h> 
#include <NTPClient.h> 
#include <WiFiUdp.h>
#include <max6675.h>
#include <SPI.h>

// i used ikohm potentiometer and 270 ohm resistor

const char *ssid = "ASHWANI_PC 5992";   // this is my computer's hotspot name and password
const char *password = "wU70356}";
MAX6675 thermocouple(2,0,4);    // sck cs so order of the parameters

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 19800, 60000);

LiquidCrystal lcd(16, 17, 18, 19, 21, 22);    // rs en d5 d6 d7 d8   order of the parameters


void setup() {
  
  Serial.begin(115200);  // serial monitor start
  pinMode(12,OUTPUT);   // these three are for the leds
  pinMode(14,OUTPUT);
  pinMode(5,OUTPUT);
  delay(10);
  lcd.begin(16, 2);
  // Turn on the backlight
  pinMode(3, OUTPUT); 
  digitalWrite(3, HIGH);
  lcd.print("Hello, World!");

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  timeClient.begin();
  delay(2000);


}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature = thermocouple.readCelsius();
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" degrees Celsius");
  if (temperature >= 27.00){
      digitalWrite(12, LOW);
      digitalWrite(14, HIGH);
      String tempStr = String(temperature);
      String myString = "temp : "+tempStr+" H";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(myString);

  }
  else{
      digitalWrite(14, LOW);
      digitalWrite(12, HIGH);
      String tempStr = String(temperature);
      String myString = "temp: "+ tempStr +" L";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(myString);

    }
  timeClient.update();
  Serial.print("Current time: ");
  String currentTime =  timeClient.getFormattedTime();
  Serial.println(currentTime);
  lcd.setCursor(0,1);
  lcd.print(currentTime);
  String currentHour = currentTime.substring(0, 2);
  int hour = currentHour.toInt();
  if (hour >= 17 && hour <= 19){
    digitalWrite(5,HIGH);
  }
  else{
    digitalWrite(5,LOW);
  }
  delay(1000);
}

