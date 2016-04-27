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
    float value0 = analogRead(A0);
    float value1 = analogRead(A1);
    float value2 = analogRead(A2);
    float value3 = analogRead(A3);
    loraClient.add("Variable_Name_0",value0);
    loraClient.add("Variable_Name_1",value1);
    loraClient.add("Variable_Name_2",value2);
    loraClient.add("Variable_Name_3",value3);
    loraClient.loraSend();
    delay(1000);
}
