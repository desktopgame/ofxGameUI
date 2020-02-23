#include "FontCache.hpp"
#include <algorithm>

namespace ofxGameUI {
std::vector<FontData> FontCache::fontVec;

FontInstance FontCache::load(const std::string & fontName, int fontSize) {
	auto iter = std::find_if(FontCache::fontVec.begin(), FontCache::fontVec.end(), [fontName, fontSize](FontData e) -> bool {
		return e.fontName == fontName && e.fontSize == fontSize;
	});
	if (iter != FontCache::fontVec.end()) {
		return (*iter).instance;
	}
	//“ú–{Œê‚à•\Ž¦‚Å‚«‚é‚æ‚¤‚É
	ofTrueTypeFontSettings font_settings(fontName, fontSize);
	font_settings.antialiased = true;
	font_settings.addRanges(ofAlphabet::Japanese);
	font_settings.addRanges(ofAlphabet::Latin);
	font_settings.addRange(ofUnicode::Space);
	font_settings.addRange(ofUnicode::NumberForms);
	auto font = std::make_shared<ofTrueTypeFont>();
	bool loaded = font->load(font_settings);
	font->setLineHeight(18.0f);
	font->setLetterSpacing(1.037);
	assert(loaded);
	//‹L˜^
	FontData fd;
	fd.fontName = fontName;
	fd.fontSize = fontSize;
	fd.instance = font;
	FontCache::fontVec.push_back(fd);
	return font;
}

void FontCache::clear() {
	FontCache::fontVec.clear();
}

FontData::FontData() : instance(nullptr), fontName(), fontSize(0) {
}

}