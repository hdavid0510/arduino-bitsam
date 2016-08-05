#include <NewPing.h>

// 각 센서는 33ms(PING_INTERVAL)를 주기로 Ping 신호를 보낸다.
// 따라서 센서 전체 사이클에 33 * 4 = 132ms가 소요된다.
// 결과는 "oneSensorCycle" 함수로 보내 센서값따른 기능을 처리한다.
// (예를 들어, 로봇이 방향을 틀어야 하는지 판단하고 회전 함수 호출).
// 본 코드는 Event-driven 기반 시스템이므로 "delay" 사용 자제하고,
// loop()의 cycle이 33ms보다 빨라야 한다.
// (만약 다른 프로세스가 33ms보다 오래 작동할 경우,
// PING_INTERVAL 값을 조정해 센서감지체계가 뒤처지지 않게 해야 한다.)


//상수 선언///////////////////////////////////////////////////////
#define SONAR_NUM    	5	// 센서 개수
#define PING_INTERVAL	33	// 센서값 인식 사이 간격 Millisecond
#define LED_ADD		    100 // 센서 인식시 증가율
#define LED_SUB			50  // 센서 미인식시 감소율
#define LED_SMOOTH      4   // 센서 주변부 그라데이션 밝기 비율



//변수 선언/////////////////////////////////////////////////////
unsigned long pingTimer[SONAR_NUM];	// 센서 작동 시간 저장
unsigned int cm[SONAR_NUM];		// 센서 거리 저장
unsigned char currentSensor	= 0;	// 작동중인 센서 번호 저장


NewPing sonar[SONAR_NUM] = {//센서 목록 설정
 NewPing(12,13, 100) //발신핀(Trig)번호, 수신핀(Echo)번호, 최대감지거리(cm)
,NewPing( 4, 5, 100)
,NewPing( 6, 7, 100)
,NewPing( 8, 9, 100)
,NewPing(10,11, 100)
};

unsigned char red[LED_NUM], green[LED_NUM], blue[LED_NUM];
const unsigned char ledleftstart[SONAR_NUM]	={ 10, 50, 74, 94,114};
const unsigned char ledleftend[SONAR_NUM]		={ 19, 56, 78, 95,116};
const unsigned char ledcenterstart[SONAR_NUM]	={ 20, 57, 79, 94,117};
const unsigned char ledcenterend[SONAR_NUM]	={ 29, 61, 83,100,120};
const unsigned char ledrightstart[SONAR_NUM]	={ 30, 62, 84,101,121};
const unsigned char ledrightend[SONAR_NUM]	={ 39, 64, 88,105,123};


//센서 관련 함수들/////////////////////////////////////////////////////////////////////
void echoCheck() { // If ping echo, set distance to array.
	if (sonar[currentSensor].check_timer())
		cm[currentSensor] = sonar[currentSensor].ping_result / US_ROUNDTRIP_CM;
}

void oneSensorCycle() { // Do something with the results.
	Serial.print("["); Serial.print(millis()); Serial.print("\t]\t");
	for (unsigned char i = 0; i < SONAR_NUM; i++) {//각 센서마다 실행할 부분임
		Serial.print(i); Serial.print("="); Serial.print(cm[i]); Serial.print("cm\t");
		if(cm[i]){//0이 아닐 경우
			for(unsigned char c=ledleftstart[i]; c<=ledleftend[i]; c++){
				if(red[c]>((255-LED_ADD)/LED_SMOOTH)){ red[c] = 255/LED_SMOOTH; }
				else{ red[c] += LED_ADD/LED_SMOOTH; }
			}
			for(unsigned char c=ledcenterstart[i]; c<=ledcenterend[i]; c++){
				if(red[c]>(255-LED_ADD)){ red[c] = 255; }
				else{ red[c] += LED_ADD; }
			}
			for(unsigned char c=ledrightstart[i]; c<=ledrightend[i]; c++){
				if(red[c]>((255-LED_ADD)/LED_SMOOTH)){ red[c] = 255/LED_SMOOTH; }
				else{ red[c] += LED_ADD/LED_SMOOTH; }
			}
		}else{//cm[i]가 0인경우, 즉 미감지
			for(unsigned char c=ledleftstart[i]; c<=ledleftend[i]; c++){
				if(red[c]<(LED_SUB/LED_SMOOTH)){ red[c] = 0; }
				else{ red[c] -= LED_SUB/LED_SMOOTH; }
			}
			for(unsigned char c=ledcenterstart[i]; c<=ledcenterend[i]; c++){
				if(red[c]<LED_SUB){ red[c] = 0; }
				else{ red[c] -= LED_SUB; }
			}
			for(unsigned char c=ledrightstart[i]; c<=ledrightend[i]; c++){
				if(red[c]<(LED_SUB/LED_SMOOTH)){ red[c] = 0; }
				else{ red[c] -= LED_SUB/LED_SMOOTH; }
			}
		}
	}
    for(unsigned char i=0;i<LED_NUM;i++){
            ledchain.setPixelColor(i,red[i],green[i],blue[i]);
        }ledchain.show();
	Serial.println();
}

	
//아두이노 기본 함수들/////////////////////////////////////////////////////////////////
void sense_setup() {
	//센서 초기화
	pingTimer[0] = millis() + 75; // First ping start in ms.
	for (unsigned char i = 1; i < SONAR_NUM; i++)
		pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;

	//색상 저장 배열 초기화
	for(unsigned char i=0; i<LED_NUM; i++) red[i] = 0;
	for(unsigned char i=0; i<LED_NUM; i++) green[i] = 0;
	for(unsigned char i=0; i<LED_NUM; i++) blue[i] = 192;
	
}

void sense_loop() {
	for (unsigned char i = 0; i < SONAR_NUM; i++) {
		if (millis() >= pingTimer[i]) {
			pingTimer[i] += PING_INTERVAL * SONAR_NUM;
			if (i == 0 && currentSensor == SONAR_NUM - 1)
				oneSensorCycle(); // Do something with results.
			sonar[currentSensor].timer_stop();
			currentSensor = i;
			cm[currentSensor] = 0;
			sonar[currentSensor].ping_timer(echoCheck);
		}
	}
}
