#include "Component.hpp"
#include "GUIUtility.hpp"
#include "Canvas.hpp"

Component::Component() : position(), loaded(false), canvas(nullptr) {
}

void Component::load() {
	if (loaded) {
		unload();
	}
	onLoad();
	this->loaded = true;
}

void Component::unload() {
	if (loaded) {
		onUnload();
		this->loaded = false;
	}
}

void Component::center(int w, int h) {
	auto size = getSize();
	this->position = glm::vec3(w - size.x, h - size.y, 0) / 2.0f;
}

bool Component::isContains(int x, int y) const {
	glm::vec3 scale(1.0f, 1.0f, 1.0f);
	auto pos = position;
	auto size = getSize();
	if (hasCanvas()) {
		scale = glm::vec3(getCanvas().getScale(), 1.0f);
	}
	pos *= scale;
	size *= scale;
	return x > pos.x && x < pos.x + size.x && y > pos.y && y < pos.y + size.y;
}

int Component::getDrawOrder() const {
	return 0;
}

void Component::installCanvas(Canvas* canvas) {
	this->canvas = canvas;
	onInstallCanvas(*canvas);
}

void Component::uninstallCanvas(Canvas* canvas) {
	onUninstallCanvas(*canvas);
	this->canvas = nullptr;
}

const Canvas & Component::getCanvas() const {
	return *canvas;
}

Canvas & Component::getCanvas() {
	return *canvas;
}

bool Component::hasCanvas() const {
	return canvas != nullptr;
}

void Component::onInstallCanvas(Canvas & canvas) {
}

void Component::onUninstallCanvas(Canvas & canvas) {
}

void Component::right(int w) {
	position.x = w - getSize().x;
}

void Component::left(int w) {
	position.x = 0;
}

void Component::top(int h) {
	position.y = 0;
}

void Component::bottom(int h) {
	position.y = h - getSize().y;
}

void Component::keyPressed(int key) {
}

void Component::keyReleased(int key) {
}

void Component::mouseMoved(int x, int y) {
}

void Component::mouseDragged(int x, int y, int button) {
}

void Component::mousePressed(int x, int y, int button) {
}

void Component::mouseReleased(int x, int y, int button) {
}

void Component::mouseEntered(int x, int y) {
}

void Component::mouseExited(int x, int y) {
}

void Component::windowResized(int w, int h) {
}

void Component::dragEvent(ofDragInfo dragInfo) {
}

void Component::gotMessage(ofMessage msg) {
}
