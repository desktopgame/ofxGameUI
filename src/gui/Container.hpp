#pragma once
#ifndef COMMON_CONTAINER_HPP
#define COMMON_CONTAINER_HPP
#include "Component.hpp"
#include <vector>
#include <memory>
namespace ofxGameUI {
/**
 * Container.
 */
class Container : public Component {
public:
	explicit Container();

	void draw() override;

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

	void addComponent(std::shared_ptr<Component> component);
	std::shared_ptr<Component> getComponentAt(int index) const;
	int getCompoentCount() const;

protected:
	void onLoad() override;
	void onUnload() override;
	virtual void onLayout();
private:
	std::vector<std::shared_ptr<Component> > children;
};
}
#endif