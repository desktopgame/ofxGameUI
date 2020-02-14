#pragma once
#ifndef OFXGAMEUI_LABEL_HPP
#define OFXGAMEUI_LABEL_HPP
#include <ofTrueTypeFont.h>
#include <string>
#include <glm/glm.hpp>
#include "Component.hpp"
#include "FontCache.hpp"
#include "FontSprite.hpp"
namespace ofxGameUI {
/**
 * Label.
 */
class Label : public Component {
public:
	explicit Label();

	void draw() override;
	glm::vec3 getSize() const override;

	ofColor fontColor;
	int fontSize;
	std::string fontFile;
	std::string text;
protected:
	void onLoad() override;
	void onUnload() override;
private:
	FontInstance font;
	FontSprite fontSprite;
};
}
#endif