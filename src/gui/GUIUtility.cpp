#include "GUIUtility.hpp"
#include <ofMatrixStack.h>
#include <ofGraphics.h>
#include <ofAppRunner.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

namespace ofxGameUI {
bool GUIUtility::isContains(glm::ivec2 position, glm::ivec2 size, int x, int y) {
	return x > position.x && x < position.x + size.x && y > position.y && y < position.y + size.y;
}
void GUIUtility::push2DMatrix(int width, int height) {
	glm::mat4 proj = glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f);
	ofSetMatrixMode(ofMatrixMode::OF_MATRIX_PROJECTION);
	ofPushMatrix();
	ofLoadIdentityMatrix();
	ofLoadMatrix(proj);

	ofSetMatrixMode(ofMatrixMode::OF_MATRIX_MODELVIEW);
	ofPushMatrix();
	ofLoadIdentityMatrix();
}
void GUIUtility::pop2DMatrix() {
	// ‚à‚Æ‚É–ß‚·
	ofSetMatrixMode(ofMatrixMode::OF_MATRIX_PROJECTION);
	ofPopMatrix();

	ofSetMatrixMode(ofMatrixMode::OF_MATRIX_MODELVIEW);
	ofPopMatrix();
}
void GUIUtility::enable2DViewSettings() {
	ofSetOrientation(OF_ORIENTATION_DEFAULT, false);
	ofEnableAlphaBlending();
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
}
void GUIUtility::disable2DViewSettings() {
	ofSetOrientation(OF_ORIENTATION_DEFAULT, true);
	ofEnableAlphaBlending();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}
}
