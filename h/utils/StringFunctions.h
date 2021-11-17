#pragma once

#include "PercleProgram.h"

#include <string>
using std::string;
using std::to_string;

#include <vector>
using std::vector;

#include <functional>
using std::string;

#include "utils/stringUtils.h"

/*
    Returns if the substring matches the input
	nothing needed for unicode
		In: the string to check against
		Position: the location in 'in' to line the start of the substring up with
		subStr: the string to compare with
		Returns: if the substring matches the input at the given location
*/

bool substringMatches(const string& in, int pos, const string& subStr);

/*
	Returns the location of a pattern in a string, or -1 if it can't find it
		In: The string to search
		startPosition: Where to start looking (inclusive)
		Pattern: The single or multi character pattern to search for, wildcards are not yet supported
		Returns: Number, the absolute position (not the offset) of the first instance of the pattern in the input, or -1 if not found
*/

int searchInString(const string& in, const string& pattern, int startPos = 0);

/*
	Replaces all instances of one substring with another
		In: The string to search
		SearchFor: Pattern to replace
		ReplaceWith: New value
		Returns: Bool, if the action was successful; true, otherwise false
*/

string replaceSubstring(const string& in, const string& searchFor, const string& replaceWith);

/*
	Sets the given array to be the given string sliced up using the given pattern
		In: The string to slice
		Pattern: The pattern used to chop up the string, will not be included in output
		Out: All the substrings will be appended to this
*/

void sliceStringBy(const string& in, const string& pattern, vector<string>& out);

/*
	Indents a string
		In: The String to indent (can be multi line)
		indent: The string to use as the indent
		Returns: The string indented
*/

string indentString(const string& in, string indent = "    ", int level = 1);

/*
	Returns the original string with the tabs replaced by the correct number of spaces
		In: The string to convert
		SpaceNum: Number of spaces per tab
		Returns: A string with the tabs replaced by spaces
*/

string tabsToSpaces(const string& in, int spaceNum = 4);

//	Runs tabsToSpaces on an entire array of strings

void tabsToSpaces(vector<string>& in);

/*	Returns the original string but padded with the given padding string
		In: The string to pad
		Size: The size of the output string
		Alignment:
			1  : Left
		   -1  : Right
			0  : Center
		Pad: The String to use for padding (assumes this string is one char long)
		LeftCap: A string to put on the left size of the input (inside the padding) that will not get chopped
		RightCap: A string to put on the right size of the input (inside the padding) that will not get chopped
		Returns: The padded string, or the chopped string if the input is shorter then the size
*/

string padString(const string& in, int size, int alignment=1, string pad = " ", string leftCap = "", string rightCap = "");

//	Returns the specific line (starting at 1) in the string it is sent
//		In: The (presumably multiline) string
//		LineNum: The line to return
//		Returns: the specific line (without newlines), or an empty string if that line is invalid

string getTextOfLine(const string& in, int lineNum);

//	takes an array of lines and puts a box around it
//		In: an array of strings, each which will be on a new line
//		BoxName: the name of the box
//		LineNum: the offset of line numbers, no line nums will be displayed if -1
//		AlwaysWidthMax: if to always use the max width
//		MaxWidth: the max width of a line, will be truncated if longer
//		Returns: a string with a box around the content (must be displayed in monospace obviously)

string lineListToBoxedString(const vector<string>& in, string boxName = "", int lineNum = -1, bool alwaysWidthMax = false, int maxWidth = -1);

//	puts the contents of a string into a well formatted
//		In: the input stringz
//		BoxName: the name that will appear at the top of the box
//		ShowLineNums: if to show line numbers
//		AlwaysWidthMax: if to always use the max width
//		MaxWidth: the maximum width of the contents of the box (with borders it may be a bit wider), if any line is longer it will be chopped
//		Returns: the boxed string

string putStringInBox(const string& in, string boxName = "", bool showLineNums = false, bool alwaysWidthMax = false, int maxWidth = -1);

//	Puts the contents of a string into a table, with tabs being verticle seporators and newlines being horizontle ones
//		In: the input string
//		TableName: the name that will apear at the top of the table
//		Returns: a string that looks like a table

string putStringInTable(const string& in, string tableName);

// Assembles one section of a tree
string assembleTreeString(const string& root, vector<string>& leaves);

// Converts a double to a string, with always at least one zero before and after the decimal

string doubleToString(double in);

int stringToInt(string in);

double stringToDouble(string in);

/*	
	Load entire file and return its contents
		InName: The path to the file to open
		Debug: If to print status several times to stdout
		Returns: The contents of the file, or an empty string if there is an error
*/

string loadEntireFile(string inName, bool debug = false);

bool writeFile(const string& filename, const string& contents, bool debug = false);

// Given a hint name and a function to check if a name is unique, Returns a unique string
// Checker should return true if the given name IS valid
// If alwaysAppendRandom, it will always append a number of random digits

string getUniqueString(string hint, std::function<bool (string)> checker, bool alwaysAppendRandom = false);

//	Run a shell command and return the output
//		Cmd: The command to run
//		Returns: The output of the command

string runCmd(string cmd, bool printOutput = false);

//	Get width of the current terminal
//		Returns: Width of the terminal

int getTerminalWidth();
