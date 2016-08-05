//bool islighton = false;

void light_setup() {
}

void light_loop() {
//	if(!islighton){
//		islighton = true;
		for(unsigned char i=0; i<LED_NUM; i++)
			ledchain.setPixelColor(i,255,255,255);
		ledchain.show();
//	}
}
