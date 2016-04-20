#include <SODAQMdot.h>

// Put here your SSID of lora gateway
#define GATEWAY_SSID "Your_Lora_Gateway_SSID"
// Put here your PASS of lora gateway
#define GATEWAY_PASS "Your_Lora_Gateway_PASS"
// Put here your frequenci sub-band of lora gateway
#define GATEWAY_SUB_BAND "1"

Ubidots loraClient;


void setup()
{
    // The code will not start unless the serial monitor is opened or 10 sec is passed
    // incase you want to operate Autonomo with external power source
    while ((!SerialUSB) && (millis() < 10000))
        ;
    
    SerialUSB.begin(115200);
    SerialUSB.println("Here we start !! ");

    Serial1.begin(115200);
    loraClient.setOnBee(BEE_VCC, BEEDTR, BEECTS);
    while(!loraClient.loraConnection(GATEWAY_SSID, GATEWAY_PASS, GATEWAY_SUB_BAND));
}

void loop() {
    float value = analogRead(A0);
    loraClient.loraSend(value);
    delay(1000);
}
