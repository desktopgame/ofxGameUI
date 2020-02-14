#pragma once
#ifndef GUI_IEVENTHANDLER_HPP
#define GUI_IEVENTHANDLER_HPP
#include <ofAppRunner.h>
#include <memory>
namespace ofxGameUI {
/**
 * IEventHandler.
 */
class IEventHandler : public std::enable_shared_from_this<IEventHandler> {
public:
	explicit IEventHandler() = default;
	virtual ~IEventHandler(){}

	/**
	 * @param key
	 */
	virtual void keyPressed(int key) = 0;

	/**
	 * @param key
	 */
	virtual void keyReleased(int key) = 0;

	/** 
	 * @param x
	 * @param y
	 */
	virtual void mouseMoved(int x, int y) = 0;

	/**
	 * @param x
	 * @param y
	 * @param button
	 */
	virtual void mouseDragged(int x, int y, int button) = 0;

	/**
	 * @param x
	 * @param y
	 * @param button
	 */
	virtual void mousePressed(int x, int y, int button) = 0;

	/**
	 * @param x
	 * @param y
	 * @param button
	 */
	virtual void mouseReleased(int x, int y, int button) = 0;

	/**
	 * @param x
	 * @param y
	 */
	virtual void mouseEntered(int x, int y) = 0;

	/**
	 * @param x
	 * @param y
	 */
	virtual void mouseExited(int x, int y) = 0;

	/**
	 * @param w
	 * @parma h
	 */
	virtual void windowResized(int w, int h) = 0;

	/**
	 * @param dragInfo
	 */
	virtual void dragEvent(ofDragInfo dragInfo) = 0;

	/**
	 * @param msg
	 */
	virtual void gotMessage(ofMessage msg) = 0;
private:
};
}
#endif