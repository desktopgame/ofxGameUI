#pragma once
#ifndef COMMON_COMPONENT_HPP
#define COMMON_COMPONENT_HPP
#include <glm/glm.hpp>
#include <memory>
#include "IEventHandler.hpp"

class Canvas;
/**
 * Component.
 */
class Component : public IEventHandler {
public:
	using Instance = std::shared_ptr<Component>;
	using Reference = std::weak_ptr<Component>;
	Component();
	virtual ~Component(){}

	/**
	 * load a resources, for draw a this component.
	 */
	void load();
	/**
	 * unload resources.
	 */
	void unload();

	/**
	 * draw this component.
	 */
	virtual void draw() = 0;

	virtual void keyPressed(int key) override;
	virtual void keyReleased(int key) override;
	virtual void mouseMoved(int x, int y)  override;
	virtual void mouseDragged(int x, int y, int button) override;
	virtual void mousePressed(int x, int y, int button) override;
	virtual void mouseReleased(int x, int y, int button) override;
	virtual void mouseEntered(int x, int y) override;
	virtual void mouseExited(int x, int y) override;
	virtual void windowResized(int w, int h) override;
	virtual void dragEvent(ofDragInfo dragInfo) override;
	virtual void gotMessage(ofMessage msg) override;

	/**
	 * move a left.
	 * @param w
	 */
	void right(int w);

	/**
	 * move a right.
	 * @param w
	 */
	void left(int w);

	/**
	 * move a top.
	 * @param h
	 */
	void top(int h);

	/**
	 * move a bottom.
	 * @param h
	 */
	void bottom(int h);

	/**
	 * move a center.
	 * @param w
	 * @param h
	 */
	void center(int w, int h);

	/**
	 * return true if specified point is included in range of this component.
	 * @param x
	 * @param y
	 * @return
	 */
	bool isContains(int x, int y) const;

	/**
	 * @return
	 */
	virtual glm::vec3 getSize() const = 0;

	/**
	 * returns order of draw.
	 * bigger one is render in first.
	 * @return
	 */
	virtual int getDrawOrder() const;

	/**
	 * @param canvas
	 */
	void installCanvas(Canvas* canvas);

	/**
	 * @param canvas
	 */
	void uninstallCanvas(Canvas* canvas);

	const Canvas& getCanvas() const;
	Canvas& getCanvas();
	bool hasCanvas() const;

	glm::vec3 position;

protected:
	virtual void onInstallCanvas(Canvas& canvas);
	virtual void onUninstallCanvas(Canvas& canvas);
	virtual void onLoad() = 0;
	virtual void onUnload() = 0;

private:
	bool loaded;
	Canvas* canvas;
};
#endif