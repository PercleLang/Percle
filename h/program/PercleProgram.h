#pragma once

#include "Version.h"

#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <list>

using std::max;
using std::min;
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::vector;
using std::list;

#include "../h/main/StringFunctions.h"
#include "../h/main/Namespace.h"
#include "../h/main/StackFrame.h"
#include "../h/main/Token.h"
#include "../h/main/AstNode.h"
#include "../h/main/SourceFile.h"

extern vector<string> cmdLineArgs;

class Element;

class PercleProgram {
	public:
		PercleProgram();
		~PercleProgram() {
			cleanUp();
		}
		
		string getCpp();
		
		void resolveProgram(string inFilename, bool printExtraOutput);
		
		Namespace getGlobalActionTable();
		
		void execute();
	
	private:
		void cleanUp();
		
	private:
		shared_ptr<SourceFile> file = nullptr;
		
		vector<Token> tokens;
		
		AstNode astRoot = nullptr;
		
		Action actionRoot = createNewVoidAction();
		
		vector<char> whitespaceChars, letterChars, digitChars;
		char singleLineComment;
};
