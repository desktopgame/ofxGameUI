#include "GUIUtility.hpp"

namespace ofxGameUI {
bool GUIUtility::isContains(glm::ivec2 position, glm::ivec2 size, int x, int y) {
	return x > position.x && x < position.x + size.x && y > position.y && y < position.y + size.y;
}
}
