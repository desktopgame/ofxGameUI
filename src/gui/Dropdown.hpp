#pragma once
#ifndef COMMON_DROPDOWN_HPP
#define COMMON_DROPDOWN_HPP
#include "Component.hpp"
#include <string>
#include <vector>
#include <ofImage.h>
#include <ofTrueTypeFont.h>
#include "FontCache.hpp"
#include "FontSprite.hpp"
#include "GUISkin.hpp"
#include <ofxIcon.h>
/**
 * Dropdown.
 */
class Dropdown : public Component {
public:
	explicit Dropdown();
	void draw() override;
	glm::vec3 getSize() const override;
	int getDrawOrder() const override;
	
	void mousePressed(int x, int y, int button) override;
	void mouseReleased(int x, int y, int button) override;

	std::string getSelectedItem() const;

	GUISkin<ofxIcon::DropdownStyle> skin;
	ofColor fontColor;
	ofColor enableColor;
	ofColor disableColor;
	std::string fontFile;
	int fontSize;
	std::vector<std::string> items;
	int selectedIndex;
protected:
	void onLoad() override;
	void onUnload() override;
private:
	FontSprite findFontSprite(const std::string& item) const;
	bool pulldown;
	FontInstance font;
	std::vector<FontSprite> fontSprites;
	ofImage backgroundImage;
	ofImage itemImage;
};
#endif