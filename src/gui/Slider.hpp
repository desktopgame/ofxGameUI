#pragma once
#ifndef GUI_SLIDER_HPP
#define GUI_SLIDER_HPP
#include "Component.hpp"
#include "GUISkin.hpp"
#include <ofxIcon.h>
#include <ofImage.h>

namespace ofxGameUI {
/**
 * Slider.
 */
class Slider : public Component {
public:
	explicit Slider();
	void draw() override;
	glm::vec3 getSize() const override;

	void mouseDragged(int x, int y, int button) override;
	void mousePressed(int x, int y, int button) override;
	void mouseReleased(int x, int y, int button) override;

	GUISkin<ofxIcon::SliderStyle> fillSkin;
	GUISkin<ofxIcon::SliderStyle> backSkin;
	GUISkin<ofxIcon::SliderKnobStyle> knobSkin;

	void setValue(float value);
	float getValue() const;
protected:
	void onLoad() override;
	void onUnload() override;
private:
	void editValueFromX(int posX);
	bool editing;
	float value;
	ofImage fillImage;
	ofImage backImage;
	ofImage knobImage;
};
}
#endif