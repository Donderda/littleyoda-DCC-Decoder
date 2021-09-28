/*
 * DISPLAYSSD1306.cpp
 * 
 * I²C Interface
 * 
 * D1 mini 	GPIO 	Shield
 * D1 	    5 	    SCL
 * D2 	    4 	    SDA
 *
 *  Created on: 07.06.2019
 *      Author: sven
 */

#include "DisplaySSD1306.h"
#include <Wire.h>
#include <Adafruit_GFX.h>


DisplaySSD1306::DisplaySSD1306(int rotation,int r, int c) : DisplayBase(c,r) {
	if (_rows == 0) {
		_rows = 6;
	}
	if (_cols == 0) {
		_cols = 10;
	}
	display = new Adafruit_SSD1306(-1);
	display->begin(SSD1306_SWITCHCAPVCC, 0x3C);
	switch (rotation) {
		case 0: display->setRotation(0); break;
		case 90: display->setRotation(1); rotate=true; break;
		case 180: display->setRotation(2); break;
		case 270: display->setRotation(3); rotate=true; break;

	}
	clear();
	display->display();
}

DisplaySSD1306::~DisplaySSD1306() {
	// TODO Auto-generated destructor stub
}

void DisplaySSD1306::clear() {
	display->clearDisplay();
  	display->setTextSize(1);
  	display->setTextColor(WHITE);
	display->setCursor(0,0);
}


void DisplaySSD1306::print(char c) {
	display->print(c);
}

void DisplaySSD1306::show() {
	display->display();
}

void DisplaySSD1306::setPos(int x, int y) {
	if (x == 0 && y ==0) {
		display->clearDisplay();
		display->setCursor(0,0);
	}
//	display->setCursor(x * 6, y * 8);
};
