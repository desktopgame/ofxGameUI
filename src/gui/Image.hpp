#pragma once
#ifndef COMMON_IMAGE_HPP
#define COMMON_IMAGE_HPP
#include <ofImage.h>
#include <string>
#include "Component.hpp"
namespace ofxGameUI {
/**
 * Image.
 */
class Image : public Component {
public:
	explicit Image();
	void draw() override;
	glm::vec3 getSize() const override;

	std::string icon;
	glm::vec2 size;
	bool forceOverwriteSize;
protected:
	void onLoad() override;
	void onUnload() override;
private:
	ofImage image;
};
}
#endif