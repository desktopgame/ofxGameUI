#include "Label.hpp"
#include <ofGraphics.h>

Label::Label() : 
	fontColor(ofColor::black),
	fontSize(40), 
	fontFile("mplus-1p-regular.ttf"), 
	text(),  
	font(nullptr),
	fontSprite(nullptr) {
}

void Label::draw() {
	ofSetColor(fontColor);
	fontSprite.draw(glm::vec2(position.x, position.y + font->stringHeight(text)));
}

glm::vec3 Label::getSize() const {
	auto w = font->stringWidth(text);
	auto h = font->stringHeight(text);
	return glm::vec3(w, h, 0);
}
// protected
void Label::onLoad() {
	this->font = FontCache::load(fontFile, fontSize);
	this->fontSprite.setFont(font);
	this->fontSprite.setText(text);
	fontSprite.buildMesh();
}

void Label::onUnload() {
}

