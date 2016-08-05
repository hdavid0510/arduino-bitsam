#include <SPI.h>
#include <WS2801.h>


//상수 선언//////////////////////////////////////////////////////////
#define MODE_LIGHT  1   //조명 모드
#define MODE_SENSE  2   //아트월 (Art Wall) 모드
#define MODE_TIMER  3   //비주얼 타종알람 모드

#define LED_NUM     125
#define WS2801_Dpin 18  //변경금지! SPL두이노 LED체인(I2C) 신호연결선#1(데이터선)
#define WS2801_Cpin 19  //변경금지! SPL두이노 LED체인(I2C) 신호연결선#2(클럭선)

WS2801 ledchain = WS2801(LED_NUM, WS2801_Dpin, WS2801_Cpin); // LED체인 설정

const unsigned char ledarray[10][5]={
    {0,19,20,39,40},
    {1,18,21,38,41},
    {2,17,22,37,42},
    {3,16,23,36,43},
    {4,15,24,35,44},
    {5,14,25,34,45},
    {6,13,26,33,46},
    {7,12,27,32,47},
    {8,11,28,31,48},
    {9,10,29,30,49}
};


//변수 선언///////////////////////////////////////////////////////////
int mode;
unsigned int currenttime=0; //현재시간 저장
unsigned int lasttime = 0; //지난시간 저장 ; dleta time 계산용
unsigned int thisperiodtime = 0; //이번교시 지난시간
unsigned int thisperiodnum = 0; //교시 #
unsigned int timetable[] = {30, 1, 0, 2, 0, 3, 0, 4,31, 5, 0, 6, 0, 7,32}; //1~9:교시 0:쉬는시간 30:조회시간 31:점심시간 32:종례시간
unsigned int timelength[] ={1000,3000,1000,3000,1000,3000,1000,3000,4000,3000,1000,3000,1000,3000,1000}; //수업 시간 디버깅용


//아두이노 기본 함수들/////////////////////////////////////////////////////////////////
void setup() {
	Serial.begin(115200);
	ledchain.begin();
   
    sense_setup();
    timer_setup();
    
    mode = MODE_TIMER;
    Serial.println("setup>");

    currenttime = millis();
}

void loop() {
    //Serial.print(millis()); Serial.println(" LOOP>");
    static int pin = 0; //지난번 버튼값
    int in = analogRead(7);
    //Serial.print("button sensor=");Serial.println(in);
   if(in != pin){
        pin = in;
        if(in<150){
            mode = MODE_LIGHT;
        }else if(in<550){
            mode = MODE_SENSE;
        }else if(in<800){
            mode = MODE_TIMER;
            for(unsigned char i=0; i<LED_NUM; i++) ledchain.setPixelColor(i,0,0,0); ledchain.show();
        }
    };

    thisperiodtime += (currenttime - lasttime); //지나간 시간 더하기
    //Serial.print("thisperiodtime = "); Serial.println(thisperiodtime);
    if(thisperiodtime >= timelength[thisperiodnum]){
        thisperiodtime = 0; thisperiodnum++; 
        if(thisperiodnum == 16) thisperiodnum = 0;
        if(mode == MODE_TIMER){
            for(unsigned char i=0; i<LED_NUM; i++) ledchain.setPixelColor(i,0,0,0); ledchain.show();
        }
    }
    lasttime = currenttime;
    currenttime = millis();
    
    //Serial.print("loop> mode=");Serial.println(mode);
    if(mode == MODE_SENSE){
        sense_loop();
    }else if(mode == MODE_TIMER){
        timer_loop();
    }else if(mode == MODE_LIGHT){
        light_loop();
    }
}


