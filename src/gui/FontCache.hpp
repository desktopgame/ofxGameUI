#pragma once
#ifndef COMMON_FONTCACHE_HPP
#define COMMON_FONTCACHE_HPP
#include <ofTrueTypeFont.h>
#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

namespace ofxGameUI {
using FontInstance = std::shared_ptr<ofTrueTypeFont>;
/**
 * FontData.
 */
struct FontData {
	FontInstance instance;
	std::string fontName;
	int fontSize;
};
/**
 * FontCache.
 */
class FontCache {
public:
	/**
	 * return a create new font.
     * return cache, if already exists
	 * @param fontName
	 * @param fontSize
	 * @return
	 */
	static FontInstance load(const std::string& fontName, int fontSize);
	/**
	 * remove all cache.
	 */
	static void clear();
private:
	static std::vector<FontData> fontVec;
	FontCache() = delete;
	~FontCache() = delete;
};
}
#endif