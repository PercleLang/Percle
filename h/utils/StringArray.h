#pragma once

#include "stringUtils.h"

namespace str {
	void splitBy(vector<string>& out, const string& in, const string& splitter, bool keepSplitter = false);

	inline void splitByLine(vector<string>& out, const string& in);

	int getMaxWidth(vector<string>& in);

	void padWidths(vector<string>& out, int size=-1, StringPadAlignment alignment=ALIGNMENT_LEFT, string pad=" ", string leftCap="", string rightCap="");

	string join(vector<string>& in, string joiner="\n", bool addAtEnd=true);

	inline void splitByLine(vector<string>& out, const string& in) {
		splitBy(out, in, "\n");
	}
}
