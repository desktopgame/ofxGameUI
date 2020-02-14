#include "Canvas.hpp"
#include <ofMatrixStack.h>
#include <ofGraphics.h>
#include <ofAppRunner.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "GUIUtility.hpp"

namespace ofxGameUI {
Canvas::Canvas(glm::ivec2 resolutionSize) : children(), resolutionSize(resolutionSize) {
}

Canvas::Canvas() : Canvas(glm::ivec2(1280,720)) {
}

Canvas::~Canvas() {
	unload();
}

void Canvas::addComponent(Component::Instance component) {
	children.emplace_back(component);
}

Component::Instance Canvas::getComponent(int index) const {
	return children.at(index);
}

int Canvas::getComponentCount() const {
	return static_cast<int>(children.size());
}

void Canvas::setResolutionSize(glm::ivec2 resolutionSize) {
	this->resolutionSize = resolutionSize;
}

glm::ivec2 Canvas::getResolutionSize() const {
	return resolutionSize;
}

glm::vec2 Canvas::getScale() const {
	float w = static_cast<float>(ofGetWidth());
	float h = static_cast<float>(ofGetHeight());
	return glm::vec2(w / static_cast<float>(resolutionSize.x), h / static_cast<float>(resolutionSize.y));
}

void Canvas::load() {
	for (auto c : children) {
		c->load();
	}
	for (auto c : children) {
		c->installCanvas(this);
	}
}

void Canvas::unload() {
	for (auto c : children) {
		c->unload();
	}
	for (auto c : children) {
		c->uninstallCanvas(this);
	}
}

void Canvas::draw() {
	std::sort(children.begin(), children.end(), [](auto a, auto b) -> bool {
		return a->getDrawOrder() < b->getDrawOrder();
	});
	GUIUtility::enable2DViewSettings();
	GUIUtility::push2DMatrix(resolutionSize.x, resolutionSize.y);
	// ‘S‚Ä•`‰æ
	for (auto c : children) {
		c->draw();
	}
	GUIUtility::pop2DMatrix();
	GUIUtility::disable2DViewSettings();
}

void Canvas::keyPressed(int key) {
	for (auto c : children) {
		c->keyPressed(key);
	}
}

void Canvas::keyReleased(int key) {
	for (auto c : children) {
		c->keyReleased(key);
	}
}

void Canvas::mouseMoved(int x, int y) {
	for (auto c : children) {
		c->mouseMoved(x, y);
	}
}

void Canvas::mouseDragged(int x, int y, int button) {
	for (auto c : children) {
		c->mouseDragged(x, y, button);
	}
}

void Canvas::mousePressed(int x, int y, int button) {
	for (auto c : children) {
		c->mousePressed(x, y, button);
	}
}

void Canvas::mouseReleased(int x, int y, int button) {
	for (auto c : children) {
		c->mouseReleased(x, y, button);
	}
}

void Canvas::mouseEntered(int x, int y) {
	for (auto c : children) {
		c->mouseEntered(x, y);
	}
}

void Canvas::mouseExited(int x, int y) {
	for (auto c : children) {
		c->mouseExited(x, y);
	}
}

void Canvas::windowResized(int w, int h) {
	for (auto c : children) {
		c->windowResized(w, h);
	}
}

void Canvas::dragEvent(ofDragInfo dragInfo) {
	for (auto c : children) {
		c->dragEvent(dragInfo);
	}
}

void Canvas::gotMessage(ofMessage msg) {
	for (auto c : children) {
		c->gotMessage(msg);
	}
}
}