#include <Arduino.h>
#include <ArduinoJson.h>



const int numChannels = 6;
int adcValues[numChannels];
float sumValues[numChannels];
const int AIN0_pin = A0;
const int AIN1_pin = A1;
const int AIN2_pin = A2;
const int AIN3_pin = A3;
const int AIN4_pin = A4;
const int AIN5_pin = A5;
#define NUM_AIN_CHANNELS 6  // 定义需要采集的模拟输入通道数量

const int AIN_pins[NUM_AIN_CHANNELS] = {AIN0_pin, AIN1_pin, AIN2_pin, AIN3_pin, AIN4_pin, AIN5_pin};

void setup() {
    Serial.begin(115200);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    for (int i = 0; i < numChannels; i++) {
        sumValues[i] = 0;
    }
}

void loop() {

    char data = Serial.read();


    if (data == 'A') {
        digitalWrite(2, HIGH);
        Serial.println("CH21OK");

    }else if (data == 'a'){
        digitalWrite(2, LOW);
        Serial.println("CH20OK");

    }else if (data == 'B') {
        digitalWrite(3, HIGH);
        Serial.println('CH31OK');

    }else if (data == 'b'){
        digitalWrite(3, LOW);
        Serial.println("CH30OK");

    }else if (data == 'C') {
        digitalWrite(4, HIGH);
        Serial.println("CH41OK");

    }else if (data == 'c'){
        digitalWrite(4, LOW);
        Serial.println("CH40OK");

    }else if (data == 'D') {
        digitalWrite(5, HIGH);
        Serial.println("CH51OK");

    }else if (data == 'd'){
        digitalWrite(5, LOW);
        Serial.println("CH50OK");

    }else if (data == 'E') {
        digitalWrite(6, HIGH);
        Serial.println("CH61OK");

    }else if (data == 'e'){
        digitalWrite(6, LOW);
        Serial.println("CH60OK");

    }else if (data == 'F') {
        digitalWrite(7, HIGH);
        Serial.println("CH71OK");

    }else if (data == 'f'){
        digitalWrite(7, LOW);
        Serial.println("CH70OK");

    }else if (data == 'G') {
        digitalWrite(8, HIGH);
        Serial.println("CH81OK");

    }else if (data == 'g'){
        digitalWrite(8, LOW);
        Serial.println("CH80OK");

    }else if (data == 'H') {
        digitalWrite(9, HIGH);
        Serial.println("CH91OK");

    }else if (data == 'h'){
        digitalWrite(9, LOW);
        Serial.println("CH90OK");

    }else if (data == 'I') {
        digitalWrite(10, HIGH);
        Serial.println("CH101OK");

    }else if (data == 'i'){
        digitalWrite(10, LOW);
        Serial.println("CH100OK");

    }else if (data == 'J') {

        digitalWrite(11, HIGH);
        Serial.println("CH111OK");

    }else if (data == 'j'){

        digitalWrite(11, LOW);
        Serial.println("CH110OK");

    }else if (data == 'K') {
        digitalWrite(12, HIGH);
        Serial.println("CH121OK");

    }else if (data == 'k'){
        digitalWrite(12, LOW);
        Serial.println("CH120OK");

    }else if (data == 'L') {
        digitalWrite(13, HIGH);
        Serial.println("CH131OK");

    }else if (data == 'l'){
        digitalWrite(13, LOW);
        Serial.println("CH130OK");

    }else if (data == 'O'){
        float voltage_values[NUM_AIN_CHANNELS];  // 存放电压值的数组

        // 采集数据并转换为电压值
        for (int i = 0; i < NUM_AIN_CHANNELS; i++) {
            int raw_value = analogRead(AIN_pins[i]);  // 读取第i个模拟输入通道的原始数值
            float voltage = (float)raw_value * (5.0 / 1023.0);  // 将原始数值转换为电压值
            voltage_values[i] = voltage;  // 将电压值存放到数组中
        }
        // 将电压值按JSON格式输出
        StaticJsonDocument<128> doc;
        for (int i = 0; i < NUM_AIN_CHANNELS; i++) {
            doc["AIN" + String(i)] = voltage_values[i];
        }
        String output;
        serializeJson(doc, output);
        Serial.println("VOL" + output + "OK");  // 输出JSON格式化后的电压值，并在头尾添加字符串“VOL”和“OK”
    }else if (data == 'P'){
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        Serial.println("CH0OK");

    }else if (data == 'Q'){
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        Serial.println("CH1OK");

    }else if (data == 'R'){
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        Serial.println("CH2OK");

    }else if (data == 'S'){
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        Serial.println("CH3OK");

    }else if (data == 'T'){
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        Serial.println("CH4OK");

    }else if (data == 'U'){
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        Serial.println("CH5OK");

    }else if (data == 'V'){
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        Serial.println("CH6OK");

    }else if (data == 'W'){
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        Serial.println("CH7OK");

    }else if ( data == 'Z'){
        Serial.println("OK");
    }
}


