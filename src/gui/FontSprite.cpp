#include "FontSprite.hpp"
#include <ofGraphics.h>

namespace ofxGameUI {
FontSprite::FontSprite(FontInstance font) : font(font), text(), mesh(), invalid(true) {
}

void FontSprite::setFont(FontInstance font) {
	this->font = font;
	this->invalid = true;
}

FontInstance FontSprite::getFont() const {
	return font;
}

void FontSprite::setText(const std::string & text) {
	this->text = text;
	this->invalid = true;
}

std::string FontSprite::getText() const {
	return text;
}

void FontSprite::buildMesh() {
	if (invalid) {
		this->invalid = false;
		this->mesh = font->getStringMesh(this->text, 0, 0);
	}
}

void FontSprite::draw(glm::vec2 pos) {
	ofSetMatrixMode(ofMatrixMode::OF_MATRIX_MODELVIEW);
	ofPushMatrix();
	ofLoadIdentityMatrix();
	ofTranslate(pos);
	font->getFontTexture().bind();
	mesh.draw();
	font->getFontTexture().unbind();
	ofPopMatrix();
}

void FontSprite::draw(float x, float y) {
	draw(glm::vec2(x, y));
}

bool FontSprite::isInvalid() const {
	return invalid;
}

}