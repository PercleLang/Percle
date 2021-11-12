#pragma once

#include "PrecleProgram.h"

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

//	Returns the location of a pattern in a string, or -1 if it can't find it
//		In: the string to search
//		startPosition: where to start looking (inclusive)
//		Pattern: the single or multi character pattern to search for, wildcards are not yet supported
//		Returns: the absolute position (not the offset) of the first instance of the pattern in the input, or -1 if it can't find it

int searchInString(const string& in, const string& pattern, int startPos=0);

//	replaces all instances of one substring with another
//		In: the string to search
//		searchFor: pattern to replace
//		replaceWith: new value
//		Returns: in after replace operation

string replaceSubstring(const string& in, const string& searchFor, const string& replaceWith);

//	sets the given array to be the given string sliced up using the given pattern
//		In: the string to slice
//		Pattern: the pattern used to chop up the string, will not be included in output
//		Out: all the substrings will be appended to this

void sliceStringBy(const string& in, const string& pattern, vector<string>& out);

//	indents a string
//		In: the string to indent (can be multi line)
//		indent: the string to use as the indent
//		Returns: the string indented

string indentString(const string& in, string indent="    ", int level=1);

//	Returns the original string with the tabs replaced by the correct number of spaces
//		In: the string to convert
//		SpaceNum: number of spaces per tab
//		Returns: a string with the tabs replaced by spaces

string tabsToSpaces(const string& in, int spaceNum=4);

//	Runs tabsToSpaces on an entire array of strings

void tabsToSpaces(vector<string>& in);

//	Returns the original string but padded with the given padding string
//		In: the string to pad
//		Size: the size of the output string
//		Alignment:
//			1  : left
//			-1 : right
//			0  : center
//		Pad: the string to use for padding (assumes this string is one char long)
//		LeftCap: a string to put on the left size of the input (inside the padding) that will not get chopped
//		RightCap: a string to put on the right size of the input (inside the padding) that will not get chopped
//		Returns: the padded string, or the chopped string if the input is shorter then the size

string padString(const string& in, int size, int alignment=1, string pad=" ", string leftCap="", string rightCap="");

//	Returns the specific line (starting at 1) in the string it is sent
//		In: the (presumably multiline) string
//		lineNum: the line to return
//		Returns: the specific line (without newlines), or an empty string if that line is invalid

string getTextOfLine(const string& in, int lineNum);

//	takes an array of lines and puts a box around it
//		In: an array of strings, each which will be on a new line
//		BoxName: the name of the box
//		LineNum: the offset of line numbers, no line nums will be displayed if -1
//		AlwaysWidthMax: if to always use the max width
//		MaxWidth: the max width of a line, will be truncated if longer
//		Returns: a string with a box around the content (must be displayed in monospace obviously)

string lineListToBoxedString(const vector<string>& in, string boxName="", int lineNum=-1, bool alwaysWidthMax=false, int maxWidth=-1);

//	puts the contents of a string into a well formatted
//		In: the input stringz
//		BoxName: the name that will appear at the top of the box
//		ShowLineNums: if to show line numbers
//		AlwaysWidthMax: if to always use the max width
//		MaxWidth: the maximum width of the contents of the box (with borders it may be a bit wider), if any line is longer it will be chopped
//		Returns: the boxed string

string putStringInBox(const string& in, string boxName="", bool showLineNums=false, bool alwaysWidthMax=false, int maxWidth=-1);

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

//	load entire file and return its contents
//		InName: the path to the file to open
//		Debug: if to print status several times to stdout
//		Returns: the contents of the file, or an empty string if there is an error

string loadEntireFile(string inName, bool debug=false);

bool writeFile(const string& filename, const string& contents, bool debug=false);

// Returns a random character that can be an upper case letter, a lower case letter or a digit

char getRandChar();

// Given a hint name and a function to check if a name is unique, Returns a unique string
// Checker should return true if the given name IS valid
// If alwaysAppendRandom, it will always append a number of random digits

string getUniqueString(string hint, std::function<bool (string)> checker, bool alwaysAppendRandom=false);

//	Run a shell command and return the output
//		Cmd: The command to run
//		Returns: The output of the command

string runCmd(string cmd, bool printOutput=false);

//	get width of the current terminal
//		Returns: Width of the terminal

int getTermWidth();
