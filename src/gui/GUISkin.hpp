#pragma once
#ifndef GUI_GUISKIN_HPP
#define GUI_GUISKIN_HPP
#include <glm/glm.hpp>

/**
 * GUISkin.
 */
template<typename T>
struct GUISkin {
	explicit GUISkin();
	T style;
	glm::ivec2 size;
};

template<typename T>
inline GUISkin<T>::GUISkin() : style(), size() {
}
#endif