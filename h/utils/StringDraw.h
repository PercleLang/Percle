#pragma once

#include "String.h"

namespace str {
    string getBoxedString(const string& in, string boxName = "", bool showLineNums = false, bool alwaysWidthMax = false, int maxWidth = -1);

    void putArrayInTreeNodeBox(vector<string>& data);

    string makeList(vector<string>& data);

    string putStringInTreeNodeBox(const string& in);
    string makeRootUpBinaryTree(const string& root, const string& leftBranch, const string& rightBranch, const string& leftLeaf, const string& rightLeaf);
}
