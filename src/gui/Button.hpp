#pragma once
#ifndef COMMON_BUTTON_HPP
#define COMMON_BUTTON_HPP
#include <ofImage.h>
#include <ofTrueTypeFont.h>
#include <string>
#include <functional>
#include <ofxIcon.h>
#include "Component.hpp"
#include "FontCache.hpp"
#include "FontSprite.hpp"
#include "GUISkin.hpp"
namespace ofxGameUI {
/**
 * Button.
 */
class Button : public Component {
public:
	using Callback = std::function<void()>;
	explicit Button();
	void draw() override;
	glm::vec3 getSize() const override;
	void mousePressed(int x, int y, int button) override;

	GUISkin<ofxIcon::ButtonStyle> normalSkin;
	GUISkin<ofxIcon::ButtonStyle> pressSkin;
	ofColor fontColor;
	int fontSize;
	std::string fontFile;
	std::string text;
	Callback callback;
protected:
	void onLoad() override;
	void onUnload() override;
private:
	FontInstance font;
	FontSprite fontSprite;
	ofImage normalImage;
	ofImage pressImage;
	ofVboMesh mesh;
	bool pressed;
	int pressCount;
};
}
#endif