#include "Container.hpp"
#include <algorithm>

Container::Container() : children() {
}

void Container::draw() {
	std::sort(children.begin(), children.end(), [](auto a, auto b) -> bool {
		return a->getDrawOrder() < b->getDrawOrder();
	});
	for (auto c : children) {
		c->draw();
	}
}

void Container::keyPressed(int key) {
	for (auto c : children) {
		c->keyPressed(key);
	}
}

void Container::keyReleased(int key) {
	for (auto c : children) {
		c->keyReleased(key);
	}
}

void Container::mouseMoved(int x, int y) {
	for (auto c : children) {
		c->mouseMoved(x, y);
	}
}

void Container::mouseDragged(int x, int y, int button) {
	for (auto c : children) {
		c->mouseDragged(x, y, button);
	}
}

void Container::mousePressed(int x, int y, int button) {
	for (auto c : children) {
		c->mousePressed(x, y, button);
	}
}

void Container::mouseReleased(int x, int y, int button) {
	for (auto c : children) {
		c->mouseReleased(x, y, button);
	}
}

void Container::mouseEntered(int x, int y) {
	for (auto c : children) {
		c->mouseEntered(x, y);
	}
}

void Container::mouseExited(int x, int y) {
	for (auto c : children) {
		c->mouseExited(x, y);
	}
}

void Container::windowResized(int w, int h) {
	for (auto c : children) {
		c->windowResized(w, h);
	}
}

void Container::dragEvent(ofDragInfo dragInfo) {
	for (auto c : children) {
		c->dragEvent(dragInfo);
	}
}

void Container::gotMessage(ofMessage msg) {
	for (auto c : children) {
		c->gotMessage(msg);
	}
}

void Container::addComponent(std::shared_ptr<Component> component) {
	children.push_back(component);
}

std::shared_ptr<Component> Container::getComponentAt(int index) const {
	return children.at(index);
}

int Container::getCompoentCount() const {
	return static_cast<int>(children.size());
}
// protected

void Container::onLoad() {
	for (auto c : children) {
		c->load();
	}
	onLayout();
}

void Container::onUnload() {
	for (auto c : children) {
		c->unload();
	}
}


void Container::onLayout() {
}
