//Copy from https://www.sparkfun.com/news/1705
//For study only
//If there are some lisence issue, Please contact with me.
//Thank you!


/* MQTT/Phant RGB Controller
 * by: Jim Lindblom, SparkFun Electronics
 * with lots of help from: Todd Treece (thanks Todd!)
 * 
 * Fun with MQTT, Arduino, and Phant. This example sketch uses
 * MQTT to subscribe to a Phant data stream. When values labeled
 * "red", "green", or "blue" change on the Phant stream, the
 * Arduino will be notified and update its LEDs accordingly.
 */
#include <SPI.h>  // Include SPI for the Ethernet library
#include <Ethernet.h>
#include <PubSubClient.h>

// Enter a MAC address for your controller below.
// Newer Ethernet shields have a MAC address printed on a sticker on the shield
byte mac[] = { 0x42, 0x24, 0x4D, 0x3D, 0x2D, 0x00 };

// Destination server, our MQTT broker.
char server[] = "data.sparkfun.com";

EthernetClient ethClient;
// Create an mqttClient object. Give it the MQTT broker server,
// the MQTT port (default is 1883), a callback function, and
// an EthernetClient object to use:
PubSubClient mqttClient(server, 1883, mqttCallback, ethClient);

// To set up MQTT we need:
char arduinoID[] = "jimsArduino"; // An ID for the MQTT client
// ...and the topics we want to subscribe to. To subscribe to a
// Phant topic, the format is output/pub_key/field_name. Our
// stream's public key is roE6z8QZq5iyEdrMGwdG.
char redTopic[] = "output/roE6z8QZq5iyEdrMGwdG/red";
char greenTopic[] = "output/roE6z8QZq5iyEdrMGwdG/green";
char blueTopic[] = "output/roE6z8QZq5iyEdrMGwdG/blue";

// LED pins:
byte redLEDPin = 3;
byte greenLEDPin = 5;
byte blueLEDPin = 6;

void setup()
{
  // Initialize LED pins:
  pinMode(redLEDPin, OUTPUT);
  digitalWrite(redLEDPin, LOW);
  pinMode(greenLEDPin, OUTPUT);
  digitalWrite(greenLEDPin, LOW);
  pinMode(blueLEDPin, OUTPUT);
  digitalWrite(blueLEDPin, LOW);
  
  // Enable serial for debug messages:
  Serial.begin(9600);
  
  // Connect to Ethernet via DHCP:
  if (Ethernet.begin(mac) == 0)
  {
    Serial.println("Failed to connect. Looping :(.");
    while (1) ;
  }
  Serial.print("Connected! IP: ");
  Serial.println(Ethernet.localIP());
  
  // Set up MQTT connection:
  // For some reason, Phant only works if the user and ID fields
  // are present (it doesn't seem to care what they are).
  if (mqttClient.connect(arduinoID, "tempuser", "tempID"))
  {
    // Once MQTT is connected, subscribe to topics of interest:
    mqttClient.subscribe(redTopic);
    mqttClient.subscribe(greenTopic);
    mqttClient.subscribe(blueTopic);
    Serial.println("Subscribed! Here we go!");
  }
  else
  {
    Serial.println("Failed to connect to MQTT. Looping :(.");
    while (1) ;
  }
}

// loop just needs to call the MQTT loop, which keeps the 
// connection alive, and checks for any new published data.
void loop()
{
  mqttClient.loop();
}

// mqttCallback function is entered whenever a subscribed value
// changes.
void mqttCallback(char* topic, byte* payload, unsigned int length)
{
  // Convert the topic char array to a string. And keep it within
  // the proper range of analog outputs. (0-255).
  int value = toInt(payload, length);
  value = constrain(value, 0, 255);
  
  // Now check if the topic char array matches any of our red,
  // green, or blue LED topics. We'll use strstr to search a
  // string for another string:
  if (strstr(topic, redTopic))
  {
    Serial.print("Setting Red LED to ");
    Serial.println(value);
    analogWrite(redLEDPin, value);    
  }
  else if (strstr(topic, greenTopic))
  {
    Serial.print("Setting Green LED to ");
    Serial.println(value);
    analogWrite(greenLEDPin, value);
  }
  else if (strstr(topic, blueTopic))
  {
    Serial.print("Setting Blue LED to ");
    Serial.println(value);
    analogWrite(blueLEDPin, value);
  }
}


// Helper function to convert a byte array to an equivalent
// integer value.
int toInt(byte* payload, int length) 
{
  int i;
  char val[10];

  for(i = 0; i < length; i++) 
    val[i] = payload[i];
  val[i] = '\0';

  return atoi(val);
}
