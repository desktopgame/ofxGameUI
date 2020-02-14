#include "Button.hpp"
#include "GUIUtility.hpp"
#include <ofGraphics.h>
#include <ofMatrixStack.h>

namespace ofxGameUI {
Button::Button() 
	:normalImage(),
	pressImage(),
	text(),
	font(),
	fontSprite(nullptr),
	normalSkin(), 
	pressSkin(), 
	pressCount(0),
	pressed(false),
	fontColor(ofColor::black), 
	fontSize(40),
	fontFile("mplus-1p-regular.ttf"),
	callback() {
	normalSkin.size = glm::ivec2(300, 60);
	pressSkin.size = glm::ivec2(300, 60);
	pressSkin.style = pressSkin.style.press(true);
}


void Button::draw() {
	ofSetColor(ofColor::white);
	int imgW = 0;
	if (pressed) {
		pressImage.draw(position);
		pressCount++;
		if (pressCount == 10) {
			this->pressCount = 0;
			this->pressed = false;
			if (callback != nullptr) {
				callback();
			}
		}
		imgW = pressImage.getWidth();
	} else {
		normalImage.draw(position);
		imgW = normalImage.getWidth();
	}
	ofSetColor(fontColor);
	int strW = font->stringWidth(text);
	int strH = font->stringHeight(text);
	fontSprite.draw(position.x + ((imgW - strW) / 2), position.y + strH);
}

glm::vec3 Button::getSize() const {
	if (pressed) {
		return glm::vec3(pressSkin.size, 0);
	}
	else {
		return glm::vec3(normalSkin.size, 0);
	}
}

void Button::mousePressed(int x, int y, int button) {
	if (button != 0) {
		return;
	}
	if (!pressed && isContains(x, y)) {
		this->pressed = true;
	}
}
// protected
void Button::onLoad() {
	this->font = FontCache::load(fontFile, fontSize);
	fontSprite.setFont(font);
	fontSprite.setText(text);
	fontSprite.buildMesh();
	ofPixels normalPix, pressPix;
	normalPix.allocate(normalSkin.size.x, normalSkin.size.y, ofImageType::OF_IMAGE_COLOR_ALPHA);
	pressPix.allocate(pressSkin.size.x, pressSkin.size.y, ofImageType::OF_IMAGE_COLOR_ALPHA);
	ofxIcon::writeButtonImage(normalPix, normalSkin.style);
	ofxIcon::writeButtonImage(pressPix, pressSkin.style);
	normalImage.setFromPixels(normalPix);
	pressImage.setFromPixels(pressPix);
	normalImage.mirror(true, false);
	pressImage.mirror(true, false);
	this->mesh = font->getStringMesh(this->text, 0, 0);
}

void Button::onUnload() {
	normalImage.clear();
	pressImage.clear();
}
}