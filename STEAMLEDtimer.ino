

//상수 선언////////////////////////////////////////////////////////////////////
const static unsigned char ledcharnum[10][10] = {
  {0x0e, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e} //0
  , {0x04, 0x0c, 0x14, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04} //1
  , {0x0e, 0x11, 0x01, 0x01, 0x02, 0x04, 0x08, 0x10, 0x10, 0x1f} //2
  , {0x0e, 0x11, 0x01, 0x01, 0x0e, 0x01, 0x01, 0x11, 0x11, 0x0e} //3
  , {0x02, 0x06, 0x06, 0x0a, 0x0a, 0x12, 0x12, 0x1f, 0x02, 0x02} //4
  , {0x1f, 0x10, 0x10, 0x10, 0x1e, 0x01, 0x01, 0x01, 0x11, 0x0e} //5
  , {0x0e, 0x11, 0x10, 0x10, 0x1e, 0x11, 0x11, 0x11, 0x11, 0x0e} //6
  , {0x1f, 0x11, 0x11, 0x01, 0x02, 0x02, 0x04, 0x04, 0x08, 0x08} //7
  , {0x0e, 0x11, 0x11, 0x11, 0x0e, 0x11, 0x11, 0x11, 0x11, 0x0e} //8
  , {0x0e, 0x11, 0x11, 0x11, 0x11, 0x0f, 0x01, 0x01, 0x11, 0x0e} //9
};
//const unsigned int ledcharmorning[50]={ //조회, 아침해
//    0x000000ff,0x000000ff,0x000000ff,0x000000ff,0x000000ff,0x00666600,0x00666600,0x00666600,0x00666600,0x00666600,
//    0x00666600,0x00666600,0x00666600,0x00666600,0x00666600,0x000000ff,0x000000ff,0x000000ff,0x000000ff,0x000000ff,
//    0x000000ff,0x000000ff,0x000000ff,0x000000ff,0x00ff0000,0x00666600,0x00666600,0x00666600,0x00666600,0x00666600,
//    0x00666600,0x00666600,0x00666600,0x00666600,0x00666600,0x000000ff,0x000000ff,0x000000ff,0x000000ff,0x000000ff,
//    0x000000ff,0x000000ff,0x000000ff,0x000000ff,0x000000ff,0x00666600,0x00666600,0x00666600,0x00666600,0x00666600
//};
const unsigned short ledcharmorning[]={
    0x00ff,0x00ff,0x00ff,0x00ff,0x00ff,0x0060,0x0060,0x0060,0x0060,0x0060,
    0x0060,0x0060,0x0060,0x0060,0x0060,0x00ff,0x00ff,0x00ff,0x00ff,0x00ff,
    0x00ff,0x00ff,0x00ff,0x00ff,0x0f00,0x0060,0x0060,0x0060,0x0060,0x0060,
    0x0060,0x0060,0x0060,0x0060,0x0060,0x00ff,0x00ff,0x00ff,0x00ff,0x00ff,
    0x00ff,0x00ff,0x00ff,0x00ff,0x00ff,0x0060,0x0060,0x0060,0x0060,0x0060
};
//const unsigned int ledcharevening[50]={ //종례, 저녁놀
//    0x00662222,0x00662222,0x00662222,0x00662222,0x00662222,0x00444400,0x00444400,0x00444400,0x00444400,0x00444400,
//    0x00444400,0x00444400,0x00444400,0x00444400,0x00444400,0x00662222,0x00662222,0x00662222,0x00662222,0x00662222,
//    0x00662222,0x00662222,0x00662222,0x00662222,0x00aa0000,0x00444400,0x00444400,0x00444400,0x00444400,0x00444400,
//    0x00444400,0x00444400,0x00444400,0x00444400,0x00444400,0x00662222,0x00662222,0x00662222,0x00662222,0x00662222,
//    0x00662222,0x00662222,0x00662222,0x00662222,0x00662222,0x00444400,0x00444400,0x00444400,0x00444400,0x00444400
//};
const unsigned short ledcharevening[50]={ //종례, 저녁놀
    0x0630,0x0630,0x0630,0x0630,0x0630,0x0040,0x0040,0x0040,0x0040,0x0040,
    0x0040,0x0040,0x0040,0x0040,0x0040,0x0630,0x0630,0x0630,0x0630,0x0630,
    0x0630,0x0630,0x0630,0x0630,0x0a00,0x0040,0x0040,0x0040,0x0040,0x0040,
    0x0040,0x0040,0x0040,0x0040,0x0040,0x0630,0x0630,0x0630,0x0630,0x0630,
    0x0630,0x0630,0x0630,0x0630,0x0630,0x0040,0x0040,0x0040,0x0040,0x0040
};
//const unsigned int ledcharlunch[50]={ //점심
//    0x00000000,0x00aaaaaa,0x00aaaaaa,0x00aaaaaa,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
//    0x00aaaaaa,0x00aaaaaa,0x00aaaaaa,0x00aaaaaa,0x00aaaaaa,0x00aaaaaa,0x00aaaaaa,0x00aaaaaa,0x00aaaaaa,0x00aaaaaa,
//    0x00000000,0x00aaaaaa,0x00aaaaaa,0x00aaaaaa,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
//    0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
//    0x00aaaaaa,0x00aaaaaa,0x00aaaaaa,0x00aaaaaa,0x00aaaaaa,0x00aaaaaa,0x00aaaaaa,0x00aaaaaa,0x00aaaaaa,0x00aaaaaa,
//};
const unsigned short ledcharlunch[50]={ //점심
    0x0000,0x0aaa,0x0aaa,0x0aaa,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
    0x0aaa,0x0aaa,0x0aaa,0x0aaa,0x0aaa,0x0aaa,0x0aaa,0x0aaa,0x0aaa,0x0aaa,
    0x0000,0x0aaa,0x0aaa,0x0aaa,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
    0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
    0x0aaa,0x0aaa,0x0aaa,0x0aaa,0x0aaa,0x0aaa,0x0aaa,0x0aaa,0x0aaa,0x0aaa,
};
const int ledstart[10] = {0x10, 0x18, 0x14, 0x12, 0x11, 0x11, 0x12, 0x14, 0x18, 0x10};


//LED관련 함수들///////////////////////////////////////////////////////////////
void printChar(const unsigned long ch[50]) {
  for (unsigned char i = 0; i < 50; i++) {
    ledchain.setPixelColor(i, (ch[i] >> 16)&0xff, (ch[i] >> 8) & 0xff, ch[i] & 0xff);
    Serial.print("printChar> "); Serial.print(ch[i],HEX);Serial.print(" ");
    Serial.print((ch[i] >> 16)&0xff); Serial.print(" "); Serial.print((ch[i] >> 8) & 0xff); Serial.print(" "); Serial.println(ch[i] & 0xff);
  } ledchain.show();
}
void printChar(const unsigned int ch[50]) {
  for (unsigned char i = 0; i < 50; i++) {
    ledchain.setPixelColor(i, (ch[i] >> 16)&0xff, (ch[i] >> 8) & 0xff, ch[i] & 0xff);
    Serial.print("printChar> "); Serial.print(ch[i],HEX);Serial.print(" ");
    Serial.print((ch[i] >> 16)&0xff); Serial.print(" "); Serial.print((ch[i] >> 8) & 0xff); Serial.print(" "); Serial.println(ch[i] & 0xff);
  } ledchain.show();
}
void printChar(const unsigned short ch[50]) {
  for (unsigned char i = 0; i < 50; i++) {
    ledchain.setPixelColor(i, (ch[i] >> 4)&0xf0, (ch[i]) & 0xf0, (ch[i]<<4) & 0xf0);
    Serial.print("printChar> "); Serial.print(ch[i],HEX);Serial.print(" ");
    Serial.print((ch[i] >> 6)&0xf0); Serial.print(" "); Serial.print((ch[i] >> 3) & 0xf0); Serial.print(" "); Serial.println((ch[i]<<1) & 0xf0);
  } ledchain.show();
}


//LED관련 함수들///////////////////////////////////////////////////////////////
void printCharNum(const uint8_t num, const uint8_t R = 255, const uint8_t G = 255, const uint8_t B = 255) {
  static uint8_t prevnum;
  static uint8_t prevR, prevG, prevB;
  if (num >= 10) {
    Serial.print("printCharNum> invalid number : "); Serial.println(num);
    return;
  } else if (num == prevnum && R == prevR && G == prevG && B == prevB) {
    //Serial.println("printCharNum> ignored");
    return;
  } else {
    prevnum = num;
    prevR = R; prevG = G; prevB = B;
    Serial.print("printCharNum> \""); Serial.print(num); Serial.print("\"printing\t");
    Serial.print(R); Serial.print("\t"); Serial.print(G); Serial.print("\t"); Serial.println(B);
    for (unsigned char i = 0; i < 10; i++) {
      for (unsigned char j = 0; j < 5; j++) {
        ledchain.setPixelColor(ledarray[i][4 - j], ((ledcharnum[num][i] >> j) & 0x1)*R, ((ledcharnum[num][i] >> j) & 0x1)*G, ((ledcharnum[num][i] >> j) & 0x1)*B);
      }
    }
    ledchain.show();
  }
}

void printArrow(const uint8_t R = 255, const uint8_t G = 255, const uint8_t B = 255) {
  Serial.print("printArrow> printing\t");
  Serial.print(R); Serial.print("\t"); Serial.print(G); Serial.print("\t"); Serial.println(B);
  for (unsigned char i = 0; i < 10; i++) {
    for (unsigned char j = 0; j < 5; j++) {
      ledchain.setPixelColor(ledarray[i][4 - j], ((ledstart[i] >> j) & 0x1)*R, ((ledstart[i] >> j) & 0x1)*G, ((ledstart[i] >> j) & 0x1)*B);
    }
  }
  ledchain.show();
}


//아두이노 기본 함수들/////////////////////////////////////////////////////////////////
void timer_setup() {
}

void timer_loop() {
   unsigned int t= ((double)thisperiodtime*75/timelength[thisperiodnum])+50;
  //Serial.print(thisperiodnum); Serial.print(" bar= 75*"); Serial.print(thisperiodtime); Serial.print("/"); Serial.print(timelength[thisperiodnum]); Serial.print(" "); Serial.println(t);
  if (1 <= timetable[thisperiodnum] && timetable[thisperiodnum] <= 9) { //n교시
    printCharNum(timetable[thisperiodnum], 64, 64, 255);
    for (unsigned int i = 50; i < LED_NUM; i++) {
      if (i < t) ledchain.setPixelColor(i, 0, 255, 0);
      else ledchain.setPixelColor(i, 0, 0, 0);
    }
  } else if (timetable[thisperiodnum] == 0) { // 쉬는시간
    printCharNum(timetable[thisperiodnum + 1], 255, 255, 32);
    for (unsigned int i = 50; i < LED_NUM; i++) {
      if (i < t) ledchain.setPixelColor(i, 255, 255, 32);
      else ledchain.setPixelColor(i, 0, 0, 0);
    }
  } else if (timetable[thisperiodnum] == 30) { // 조회
    //printArrow(255, 0, 255);
    printChar(ledcharmorning);
    for (unsigned int i = 50; i < LED_NUM; i++) {
      if (i < t) ledchain.setPixelColor(i, 255, 0, 255);
      else ledchain.setPixelColor(i, 0, 0, 0);
    }
  } else if (timetable[thisperiodnum] == 31) { // 점심
    //printArrow(255, 255, 0);
    printChar(ledcharlunch);
    for (unsigned int i = 50; i < LED_NUM; i++) {
      if (i < t) ledchain.setPixelColor(i, 255, 255, 0);
      else ledchain.setPixelColor(i, 0, 0, 0);
    }
  } else if (timetable[thisperiodnum] == 32) { // 종례
    //printArrow(255, 0, 255);
    printChar(ledcharevening);
    for (unsigned int i = 50; i < LED_NUM; i++) {
      if (i < t) ledchain.setPixelColor(i, 255, 0, 255);
      else ledchain.setPixelColor(i, 0, 0, 0);
    }
  }
  ledchain.show();
}

