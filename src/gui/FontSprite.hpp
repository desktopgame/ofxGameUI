#pragma once
#ifndef GUI_FONTSPRITE_HPP
#define GUI_FONTSPRITE_HPP
#include <ofTrueTypeFont.h>
#include <string>
#include "FontCache.hpp"
namespace ofxGameUI {
/**
 * FontSprite.
 */
class FontSprite {
public:
	explicit FontSprite(FontInstance font);

	/**
	 * overwrite font.
	 * @param font
	 */
	void setFont(FontInstance font);

	/**
	 * returns font.
	 * @return
	 */
	FontInstance getFont() const;

	/**
	 * overwrite text.
	 * @param text
	 */
	void setText(const std::string& text);
	/**
	 * returns text.
	 * @return
	 */
	std::string getText() const;

	/**
	 * build mesh by current font, and text.
	 */
	void buildMesh();

	/**
	 * @param pos
	 */
	void draw(glm::vec2 pos);

	/**
	 * @param x
	 * @param y
	 */
	void draw(float x, float y);

	/**
	 * return true if have need call a buileMesh().
	 * @return
	 */
	bool isInvalid() const;
private:
	FontInstance font;
	std::string text;
	ofVboMesh mesh;
	bool invalid;
};
}
#endif