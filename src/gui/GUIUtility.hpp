#pragma once
#ifndef COMMON_GUIUTILITY_HPP
#define COMMON_GUIUTILITY_HPP
#include <ofRectangle.h>
#include <ofImage.h>
#include <glm/glm.hpp>

namespace GUIUtility {
/**
 * return true if included in range.
 * @param position
 * @param size
 * @param x
 * @param y
 * @return
 */
bool isContains(glm::ivec2 position, glm::ivec2 size, int x, int y);
}
#endif