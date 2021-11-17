#pragma once

#include <string>
using std::string;

#include <vector>
using std::vector;

namespace str {
    inline void nextGlyph(int& out, const string& in);

    inline int getWidth(const string& in);
    inline int seek(const string& in, int distGlyph, int startPosByte = 0);

    inline bool subMatches(const string& in, int posBytes, const string& sub);
    inline bool hasSuffix(const string& in, const string& suffix);
    inline bool matches(const string& a, const string& b);
    inline bool hasPrefix(const string& in, const string& prefix);

    inline string sub(const string& in, int startGlyph, int endGlyph);

    int getGlyphPosOf(const string& in, string pattern);

    string tabsToSpaces(const string& in, int tabWidth = 4);

    enum StringPadAlignment {ALIGNMENT_LEFT = 1, ALIGNMENT_CENTER = 0, ALIGNMENT_RIGHT = -1};

    string pad(const string& in, int size, StringPadAlignment alignment = ALIGNMENT_LEFT, string pad = " ", string leftCap = "", string rightCap = "");

    inline void nextGlyph(int& out, const string& in) {
    	do {
    		out++;
    	} while (out < (int) in.size() && (in[out] & 0x80) && !(in[out] & 0x40));
    }

    inline int getWidth(const string& in) {
    	int glyphPos = 0;
    	int bytePos = 0;
    
    	while (bytePos < (int) in.size()) {
    		nextGlyph(bytePos, in);
    		glyphPos++;
    	}
    
    	return glyphPos;
    }

    inline int seek(const string& in, int distGlyph, int startPosByte) {
    	int i = startPosByte;
    
    	while (distGlyph > 0) {
    		nextGlyph(i, in);
    
    		distGlyph--;
    	}
    
    	return i;
    }

    inline bool subMatches(const string& in, int posBytes, const string& sub) {
    	if (posBytes < 0 || sub.size() + posBytes > in.size())
    		return false;
    
    	for (int i = 0; i < (int) sub.size(); i++) {
    		if (in[i + posBytes] != sub[i])
    			return false;
    	}
    
    	return true;
    }

    inline string sub(const string& in, int startGlyph, int endGlyph) {
    	int startByte = seek(in, startGlyph);
    	int endByte = (endGlyph < 0 ? (int)in.size() : seek(in, endGlyph - startGlyph, startByte));
    	return in.substr(startByte, endByte-startByte);
    }

    inline bool matches(const string& a, const string& b) {
    	if (a.size() != b.size())
    		return false;
    
    	return subMatches(a, 0, b);
    }

    inline bool hasPrefix(const string& in, const string& prefix) {
    	return subMatches(in, 0, prefix);
    }

    inline bool hasSuffix(const string& in, const string& suffix) {
    	return subMatches(in, in.size() - suffix.size(), suffix);
    }
}

#include "stringArray.h"
#include "stringDrawing.h"
