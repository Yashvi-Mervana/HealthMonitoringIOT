// #include <WiFi.h>
// #include <WiFiClient.h>
// #include <WiFiServer.h>
// #include <WiFiUdp.h>
// #include <ThingSpeak.h>
#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.   
#include <LM35.h>

// char ssid[] = "Hogwarts";        // your network SSID (name)
// char pass[] = "alohomora";    // your network password (use for WPA, or use as key for WEP)
//int keyIndex = 0;             // your network key Index number (needed only for WEP)
// int status = WL_IDLE_STATUS;
// WiFiServer server(80);
// unsigned long myChannelNumber = 2095787;
// const char * myWriteAPIKey = "K4DAWSX5S52CQ0JW";

// Define the analog pin, the LM35's Vout pin is connected to
#define sensorPin A0
const int PulseWire = 1;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED;
int buzzerPin = 8;          // The on-board Arduino LED, close to PIN 13.
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore.
                               // Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
                               // Otherwise leave the default "550" value. 
PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"

void setup() {
    // Start serial
  Serial.begin(9600);
  // delay(1);
  // // Connecting to a WiFi network
  // Serial.println();
  // Serial.println();
  // Serial.print("Connecting to ");
  // //Serial.println(ssid);
  
  // WiFi.begin("Hogwarts","alohomora");
  
  // while (WiFi.status() != WL_CONNECTED) {
  //   delay(50);
  //   Serial.print(".");
  // }

  // Serial.println("");
  // Serial.println("WiFi connected");  
  // Serial.println("IP address: ");
  // Serial.println(WiFi.localIP());
  // Serial.begin(115200);


  // pinMode(LED,OUTPUT);   // For Serial Monitor

  // // Configure the PulseSensor object, by assigning our variables to it. 
  // pulseSensor.analogInput(PulseWire);   
  // pulseSensor.blinkOnPulse(LED);       //auto-magically blink Arduino's LED with heartbeat.
  //pulseSensor.setThreshold(550);   

  // Double-check the "pulseSensor" object was created and "began" seeing a signal. 
   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
  }   
  //ThingSpeak.begin(client);
}
//WiFiClient client;

void loop() {
if (pulseSensor.sawStartOfBeat()) {            // Constantly test to see if "a beat happened".
int myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
                                               // "myBPM" hold this BPM value now. 
 Serial.println("♥  A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
 Serial.print("BPM: ");                        // Print phrase "BPM: " 
 Serial.println(myBPM);                        // Print the value inside of myBPM. 

  // ThingSpeak.setField(2,myBPM);
  // ThingSpeak.writeFields("2095790", "S30FVB5SZ2SJDT5L");
}

  delay(100);                    // considered best practice in a simple sketch.
   int reading = analogRead(sensorPin);

  // Convert that reading into voltage
  float voltage = reading * (5.0 / 1024.0);

  // Convert the voltage into the temperature in Celsius
  float temperatureC = voltage * 100;

  //Print the temperature in Celsius
  if(temperatureC>25 && temperatureC<40){
 Serial.print("Temperature: ");
 Serial.print(temperatureC);
 Serial.print("\xC2\xB0"); // shows degree symbol
  Serial.print("C  |  ");}
  else{
    pinMode(buzzerPin, OUTPUT); //addigning pin to Output mode</p><p>}</p><p>void loop() {
    tone(buzzerPin, 50);
    delay(50);
    noTone(buzzerPin);
    delay(100);
  }
  
  // Print the temperature in Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  if(temperatureF>75 && temperatureF<104){
  Serial.print(temperatureF);
  Serial.print("\xC2\xB0"); // shows degree symbol
  Serial.println("F");}
  else{
    pinMode(buzzerPin, OUTPUT); //addigning pin to Output mode</p><p>}</p><p>void loop() {
    tone(buzzerPin, 50);
    delay(50);
    noTone(buzzerPin);
    delay(100);
  }
  // ThingSpeak.setField(1,temperatureC);
  // ThingSpeak.writeFields("2095787", "K4DAWSX5S52CQ0JW");

  delay(1000); // wait a second between readings

}
