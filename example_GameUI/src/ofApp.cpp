#include "ofApp.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){
	inputField.fontSize = 20;
	button.text = "Submit";
	button.callback = [this]() -> void {
		std::cout << inputField.getText() << std::endl;
	};
	inputField.load();
	button.load();

	inputField.center(800, 600);
	inputField.position.x -= inputField.getSize().x / 2;
	button.center(800, 600);
	button.position.x = inputField.position.x + inputField.getSize().x + 5;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofxGameUI::GUIUtility::enable2DViewSettings();
	ofxGameUI::GUIUtility::push2DMatrix(800, 600);
	inputField.draw();
	button.draw();
	ofxGameUI::GUIUtility::pop2DMatrix();
	ofxGameUI::GUIUtility::disable2DViewSettings();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	inputField.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	inputField.keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	inputField.mousePressed(x, y, button);
	this->button.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
