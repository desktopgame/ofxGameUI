#pragma once
#ifndef GUI_CANVAS_HPP
#define GUI_CANVAS_HPP
#include <memory>
#include <vector>
#include "Component.hpp"
namespace ofxGameUI {
/**
 * Canvas.
 */
class Canvas {
public:
	explicit Canvas(glm::ivec2 solutionSize);
	explicit Canvas();
	~Canvas();

	/**
	 * create specified type component, and add to canvas.
	 * @param args
	 */
	template<typename T, typename ...Args>
	std::shared_ptr<T> addComponent(Args... args);

	/**
	 * add to canvas.
	 * @param component
	 */
	void addComponent(Component::Instance component);

	/**
	 * returns component for specified index.
	 * @param index
	 * @return
	 */
	Component::Instance getComponent(int index) const;

	/**
	 * reutrns count of components.
	 * @return
	 */
	int getComponentCount() const;

	/**
	 * overwrite solution size.
	 * @param solutionSize
	 */
	void setSolutionSize(glm::ivec2 solutionSize);

	/**
	 * returns solution size.
	 * @return
	 */
	glm::ivec2 getSolutionSize() const;

	/**
	 * return a scale of window size for against to resolutoin.
	 * @return
	 */
	glm::vec2 getScale() const;

	void load();
	void unload();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y) ;
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
private:
	std::vector<Component::Instance> children;
	glm::ivec2 solutionSize;
};
template<typename T, typename ...Args>
inline std::shared_ptr<T> Canvas::addComponent(Args ...args) {
	auto inst = std::make_shared<T>(args...);
	addComponent(inst);
	return inst;
}
}
#endif
