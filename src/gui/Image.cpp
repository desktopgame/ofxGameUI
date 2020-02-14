#include "Image.hpp"
#include "GUIUtility.hpp"
#include <ofGraphics.h>

namespace ofxGameUI {
Image::Image() :image(), icon(), size(0,0), forceOverwriteSize(false) {
}

void Image::draw() {
	ofSetColor(ofColor::white);
	image.draw(position.x, position.y, size.x, size.y);
}

glm::vec3 Image::getSize() const {
	return glm::vec3(size, 0);
}
// protected
void Image::onLoad() {
	image.load(icon);
	image.mirror(true, false);
	if (!forceOverwriteSize) {
		this->size = glm::vec2(image.getWidth(), image.getHeight());
	}
}

void Image::onUnload() {
	image.clear();
}

}