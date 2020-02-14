#include "Slider.hpp"
#include <ofPixels.h>

namespace ofxGameUI {
Slider::Slider() 
 : fillSkin(), 
   backSkin(),
   knobSkin(),
   editing(false),
   value(0.0f),
   fillImage(),
   backImage(),
   knobImage(){
	fillSkin.size = glm::ivec2(300, 15);
	backSkin.size = glm::ivec2(300, 15);
	backSkin.style = backSkin.style.fillColor0(ofColor::gray).fillColor1(ofColor::white).fillColor2(ofColor::gray);
	knobSkin.size = glm::ivec2(30, 30);
}

void Slider::draw() {
	int fillSubWidth = static_cast<int>(static_cast<float>(fillImage.getWidth()) * value);
	fillImage.drawSubsection(position.x, position.y, fillSubWidth, fillImage.getHeight(), 0, 0);

	int backSubWidth = static_cast<int>(static_cast<float>(backImage.getWidth()) * (1.0f - value));
	backImage.drawSubsection(position.x + fillSubWidth, position.y, backSubWidth, backImage.getHeight(), backImage.getWidth() - backSubWidth, 0);

	int knobHalfW = knobSkin.size.x / 2;
	int offsY = (knobSkin.size.y - fillSkin.size.y) / 2;
	knobImage.draw(position.x + fillSubWidth - knobHalfW, position.y - offsY);
}

glm::vec3 Slider::getSize() const {
	return glm::vec3(fillSkin.size, 0);
}

void Slider::mouseDragged(int x, int y, int button) {
	if (button != 0 || !editing) {
		return;
	}
	editValueFromX(x);
}

void Slider::mousePressed(int x, int y, int button) {
	if (button != 0) {
		return;
	}
	if (!editing && this->isContains(x, y)) {
		this->editing = true;
		editValueFromX(x);
	}
}

void Slider::mouseReleased(int x, int y, int button) {
	if (button != 0) {
		return;
	}
	this->editing = false;
}

void Slider::setValue(float value) {
	this->value = std::max(0.0f, std::min(1.0f, value));
}

float Slider::getValue() const {
	return value;
}

void Slider::onLoad() {
	if (fillSkin.size != backSkin.size) {
		throw std::logic_error("should be equal `fillSkin.size` and `backSkin.size`");
	}
	ofPixels fillPix, backPix, knobPix;
	fillPix.allocate(fillSkin.size.x, fillSkin.size.y, ofImageType::OF_IMAGE_COLOR_ALPHA);
	ofxIcon::writeSliderImage(fillPix, fillSkin.style);
	fillImage.setFromPixels(fillPix);
	fillImage.mirror(true, false);

	backPix.allocate(backSkin.size.x, backSkin.size.y, ofImageType::OF_IMAGE_COLOR_ALPHA);
	ofxIcon::writeSliderImage(backPix, backSkin.style);
	backImage.setFromPixels(backPix);
	backImage.mirror(true, false);
	
	knobPix.allocate(knobSkin.size.x, knobSkin.size.y, ofImageType::OF_IMAGE_COLOR_ALPHA);
	ofxIcon::writeSliderKnobImage(knobPix, knobSkin.style);
	knobImage.setFromPixels(knobPix);
	knobImage.mirror(true, false);
}
void Slider::onUnload() {
}

void Slider::editValueFromX(int posX) {
	posX -= position.x;
	this->value = static_cast<float>(posX) / static_cast<float>(fillImage.getWidth());
	this->value = std::max(0.0f, std::min(1.0f, this->value));
}
}