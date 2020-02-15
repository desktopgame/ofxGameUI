#include "Dropdown.hpp"
#include <ofGraphics.h>
#include <algorithm>
#include "Canvas.hpp"

namespace ofxGameUI {
Dropdown::Dropdown()
 : fontFile("mplus-1p-regular.ttf"), fontSprites(),
	fontSize(14),
	items(),
	skin(),
	selectedIndex(0),
	backgroundImage(),
	itemImage(),
	fontColor(ofColor::black),
	enableColor(ofColor::black),
	disableColor(ofColor::gray),
	pulldown(false) {
	skin.size = glm::ivec2(400, 60);
}

void Dropdown::draw() {
	ofSetColor(ofColor::white);
	backgroundImage.draw(position);
	auto str = items.at(selectedIndex);
	int imgW = backgroundImage.getWidth() - skin.style.computeSlotWidth(backgroundImage.getWidth());
	int imgH = backgroundImage.getHeight();
	int strW = font->stringWidth(str);
	int strH = font->stringHeight(str);
	ofSetColor(enableColor);
	findFontSprite(str).draw(position.x + ((imgW - strW) / 2), position.y + strH + ((imgH - strH) / 2));
	if (!pulldown) {
		return;
	}
	//要素を表示する
	glm::vec3 curPos = position;
	curPos.y += backgroundImage.getHeight();
	for (int i = 0; i < static_cast<int>(items.size()); i++) {
		if (i == selectedIndex) continue;
		str = items.at(i);
		strW = font->stringWidth(str);
		strH = font->stringHeight(str);
		//アイコンを非選択として表示
		ofSetColor(ofColor::white);
		itemImage.draw(curPos);
		//フォントは通常色
		ofSetColor(disableColor);
		findFontSprite(str).draw(curPos.x + ((imgW - strW) / 2), curPos.y + strH + ((imgH - strH) / 2));
		curPos.y += backgroundImage.getHeight();
	}
}

glm::vec3 Dropdown::getSize() const {
	return glm::vec3(skin.size.x, skin.size.y,0);
}

int Dropdown::getDrawOrder() const {
	return pulldown ? 1 : 0;
}

void Dropdown::mousePressed(int x, int y, int button) {
	if (!pulldown) {
		if (isContains(x, y)) {
			this->pulldown = true;
		}
	} else {
		this->pulldown = false;
		glm::vec2 scale = hasCanvas() ? getCanvas().getScale() : glm::vec2(1, 1);
		//どの要素が選択されたか判別
		int imgW = static_cast<int>(static_cast<float>(backgroundImage.getWidth()) * scale.x);
		int imgH = static_cast<int>(static_cast<float>(backgroundImage.getHeight()) * scale.y);
		glm::vec3 curPos = position * scale;
		curPos.y += backgroundImage.getHeight();
		for (int i = 0; i < static_cast<int>(items.size()); i++) {
			if (i == selectedIndex) continue;
			bool selected = x > curPos.x && x < curPos.x + imgW && y > curPos.y && y < curPos.y + imgH;
			if (selected) {
				this->selectedIndex = i;
				break;
			}
			curPos.y += static_cast<float>(backgroundImage.getHeight()) * scale.y;
		}
	}
}

void Dropdown::mouseReleased(int x, int y, int button) {
}

std::string Dropdown::getSelectedItem() const {
	return items.at(selectedIndex);
}
// protected
void Dropdown::onLoad() {
	ofPixels pix, itemPix;
	pix.allocate(skin.size.x, skin.size.y, ofImageType::OF_IMAGE_COLOR_ALPHA);
	itemPix.allocate(skin.size.x, skin.size.y, ofImageType::OF_IMAGE_COLOR_ALPHA);
	ofxIcon::writeDropdownImage(pix, skin.style);
	ofxIcon::util::fillColor(itemPix, skin.style._fillColor);
	ofxIcon::util::drawBorder(itemPix, skin.style._borderColor, skin.style._edgeSize);
	itemImage.setFromPixels(itemPix);
	backgroundImage.setFromPixels(pix);
	backgroundImage.mirror(true, false);
	this->font = FontCache::load(fontFile, fontSize);
	fontSprites.clear();
	for (auto item : items) {
		FontSprite spr(font);
		spr.setText(item);
		spr.buildMesh();
		fontSprites.emplace_back(spr);
	}
}

void Dropdown::onUnload() {
}

// private
FontSprite Dropdown::findFontSprite(const std::string & item) const {
	auto iter = std::find_if(fontSprites.begin(), fontSprites.end(), [item](auto e) -> bool { return e.getText() == item; });
	return *iter;
}

}