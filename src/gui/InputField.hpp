#pragma once
#ifndef OFXGAMEUI_INPUTFIELD_HPP
#define OFXGAMEUI_INPUTFIELD_HPP
#include <ofImage.h>
#include <ofEvents.h>
#include <string>
#include <ofTrueTypeFont.h>
#include <ofxIcon.h>
#include "Component.hpp"
#include "FontCache.hpp"
#include "FontSprite.hpp"
#include "GUISkin.hpp"
namespace ofxGameUI {
/**
 * InputField.
 */
class InputField : public Component {
public:
	explicit InputField();
	void draw()override;
	glm::vec3 getSize() const override;

	void mousePressed(int x, int y, int button) override;
	void keyPressed(int key) override;
	void keyReleased(int key) override;

	/**
	 * returns text.
	 * @return
	 */
	std::string getText() const;

	GUISkin<ofxIcon::InputFieldStyle> skin;
	ofColor caretColor;
	ofColor fontColor;
	std::string fontFile;
	int fontSize;
protected:
	void onLoad() override;
	void onUnload()override;
private:
	void drawCaret(int caretPos);
	void drawBackground();
	void drawString(const std::string& str);
	void keycodePressed(ofKeyEventArgs& e);
	bool focus;
	ofImage background;
	ofImage caret;
	int sleepTimer;
	int sleepLength;
	int blinkTimer;
	int blinkRate;
	bool isShift;
	FontInstance font;
	FontSprite fontSprite;
	std::string textMesh;

	std::string buffer;
	int caretPos;
};
}
#endif