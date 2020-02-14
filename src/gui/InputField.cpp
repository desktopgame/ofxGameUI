#include "InputField.hpp"
#include "GUIUtility.hpp"
#include <ofEvents.h>
#include <ofGraphics.h>
#include <ofAppRunner.h>
#include <ofBaseApp.h>
#include <ofAppGLFWWindow.h>
#include <iostream>

namespace ofxGameUI {
InputField::InputField()
	: background(),
	focus(false), 
	sleepTimer(0), 
	sleepLength(20), 
	blinkTimer(0), 
	blinkRate(30), 
	isShift(false), 
	buffer(""), 
	caretPos(0), 
	font(), 
	fontSprite(nullptr),
	textMesh(),
	skin(),
	caretColor(ofColor::black),
	fontColor(ofColor::black),
	fontFile("mplus-1p-regular.ttf"),
    fontSize(14) {
	ofAddListener(ofGetWindowPtr()->events().keyPressed, this,
		&InputField::keycodePressed);
	skin.size = glm::ivec2(300, 60);
}

void InputField::draw() {
	drawBackground();
	if (blinkTimer == blinkRate) {
		sleepTimer++;
		if (sleepTimer == sleepLength) {
			this->sleepTimer = 0;
			this->blinkTimer = 0;
		}
		drawString(buffer);
		return;
	}
	if (focus) {
		blinkTimer++;
		drawCaret(caretPos);
	}
	drawString(buffer);
}

glm::vec3 InputField::getSize() const {
	return glm::vec3(skin.size.x, skin.size.y, 0);
}

void InputField::mousePressed(int x, int y, int button) {
	if (button != 0) {
		return;
	}
	this->focus = isContains(x, y);
	if (!focus) {
		this->isShift = false;
	}
}

void InputField::keyPressed(int key) {
	if (!focus) {
		return;
	}
	if (key == ofKey::OF_KEY_BACKSPACE) {
		if (!buffer.empty()) {
			buffer.erase(buffer.begin() + std::max(0, (caretPos - 1)));
			caretPos = std::max(0, caretPos - 1);
		}
	}
	if ((key == ofKey::OF_KEY_LEFT_SHIFT || key == ofKey::OF_KEY_RIGHT_SHIFT)) {
		this->isShift = true;
	}
	if (key == ofKey::OF_KEY_LEFT) {
		if (caretPos > 0) {
			caretPos--;
		}
	}
	else if (key == ofKey::OF_KEY_RIGHT) {
		if (caretPos < buffer.size()) {
			caretPos++;
		}
	}
}

void InputField::keyReleased(int key) {
	if (!focus) {
		return;
	}
	if ((key == ofKey::OF_KEY_LEFT_SHIFT || key == ofKey::OF_KEY_RIGHT_SHIFT)) {
		this->isShift = false;
	}
}

std::string InputField::getText() const {
	return buffer;
}
// protected
void InputField::onLoad() {
	ofPixels pix, caretPix;
	pix.allocate(skin.size.x, skin.size.y, ofImageType::OF_IMAGE_COLOR_ALPHA);
	caretPix.allocate(5, skin.size.y, ofImageType::OF_IMAGE_COLOR_ALPHA);
	ofxIcon::writeInputFieldImage(pix, skin.style);
	ofxIcon::util::fillColor(caretPix, caretColor);

	background.setFromPixels(pix);
	background.mirror(true, false);
	caret.setFromPixels(caretPix);
	caret.mirror(true, false);
	this->font = FontCache::load(fontFile, fontSize);
	fontSprite.setFont(font);
}

void InputField::onUnload() {
	background.clear();
}

// private
void InputField::drawCaret(int caretPos) {
	int w = font->stringWidth(buffer.substr(0, caretPos));
	caret.draw(position + glm::vec3(w, 0, 0));
}

void InputField::drawBackground() {
	ofSetColor(ofColor::white);
	background.draw(position);
}

void InputField::drawString(const std::string& str) {
	ofSetColor(fontColor);
	if (this->textMesh != str) {
		this->textMesh = str;
		fontSprite.setText(str);
		fontSprite.buildMesh();
	}
	int w = font->stringWidth(str);
	int h = font->stringHeight(str);
	int diff = std::max(0.0f, background.getHeight() - h);
	fontSprite.draw(glm::vec2(position.x, position.y + h + (diff / 2)));
}

void InputField::keycodePressed(ofKeyEventArgs & e) {
	if (e.type == ofKeyEventArgs::Released) {
		return;
	}
	if (!focus) {
		return;
	}
	int kc = e.keycode;
	int alphaA = static_cast<int>('A');
	int alphaZ = static_cast<int>('Z');
	int digit0 = static_cast<int>('0');
	int digit9 = static_cast<int>('9');
	char key = static_cast<char>(kc);
	bool isAlpha = kc >= alphaA && kc <= alphaZ;
	bool isDigit = kc >= digit0 && kc <= digit9;
	if (isAlpha && !isShift) {
		int diff = kc - static_cast<int>('A');
		int start = static_cast<int>('a');
		key = static_cast<char>(start + diff);
	}
	if (isAlpha || isDigit || (key == '@') || (key == '-')) {
		if (caretPos >= buffer.size()) {
			buffer.push_back(key);
		} else {
			buffer.insert(buffer.begin() + caretPos, key);
		}
		this->caretPos++;
	}
	//‚Í‚Ýo‚·‚È‚çŽ~‚Ü‚é
	int w = background.getWidth();
	if (font->stringWidth(buffer) > w) {
		buffer.pop_back();
		this->caretPos--;
	}
}

}