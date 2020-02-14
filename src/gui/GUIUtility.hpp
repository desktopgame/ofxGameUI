#pragma once
#ifndef OFXGAMEUI_GUIUTILITY_HPP
#define OFXGAMEUI_GUIUTILITY_HPP
#include <ofRectangle.h>
#include <ofImage.h>
#include <glm/glm.hpp>

namespace ofxGameUI {
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

/**
 * push ortho matrix.
 * @param width
 * @param height
 */
void push2DMatrix(int width, int height);

/**
 * pop matrix.
 */
void pop2DMatrix();

struct ViewSettings {

};
/**
 * enable 2d view settings.
 */
void enable2DViewSettings();

/**
 * disable 2d view settings.
 */
void disable2DViewSettings();
}
}
#endif