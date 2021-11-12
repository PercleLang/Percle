#include "../h/msclStringFuncs.h"
#include "../h/ErrorHandler.h"

#include <iostream>

using std::cout;
using std::endl;
using std::string;

struct Flags {
	string path;					              // Path to the percle exeutable that is now running
	bool debug          = false;				  // If to show debugging info
	bool help           = false;				  // If to show help message
	bool version        = false;				  // If to show version message
	bool runInterpreted = true;		      // If to run the program in the interpreter
	bool runCompiled    = false;		    // If to run the program compiled
	bool flagError      = false;			  // If to quit immediately, this is set if there is an unrecognised flag

	string cppOutFile = "";			        // Output file for transpiled C++ code, empty if flag not set
	string binOutFile = "";			        // Binary executable output file, empty if flag not set
};

Flags getFlags(int argc, char ** argv);

int main(int argc, char ** argv) {
  Flags flags = getFlags(argc, argv);

  if (flags.flagError) {
    cout << "No command found. Use 'pr help' for all help. \n" << endl;
		
    return 0;
  }

  if (flags.help)	{
		cout << "Percle Version: v" << VERSION_X << "." << VERSION_Y << "." << VERSION_Z << endl;
		cout << "usage: pinecone [options] [source file] [options]" << endl;
		cout << "options: " << endl;
		cout << "-v, -version   :  Display the version of Percle" << endl;
		cout << "-d, -debug     :  Display debugging info before running the program" << endl;
		cout << "-r, -run          Run the program with the interpreter" << endl;
		cout << "                  Active by default if no transpiling commands are present" << endl;
		cout << "               :  Currently, anything after -r is ignored" << endl;
		cout << "-cpp [file]    :  Transpile to C++ and save the output in the given file" << endl;
		cout << "-bin [file]    :  Transpile, compile with GCC and save the binary" << endl;
		cout << "-e, -execute   :  Transpile, compile and execute the binary" << endl;
		cout << "                    any combination of -cpp, -bin and -e can be used" << endl;
		cout << "                    like -r, anything after -e is ignored" << endl;
		cout << "-h, -help      :  Display this help and quit" << endl;
		cout << endl;
		cout << endl;
		
		return 0;
	}
  
  if (flags.version) {
		cout << "Percle Version: v" << VERSION_X << "." << VERSION_Y << "." << VERSION_Z << endl;
    
		return 0;
	}

  Flags getFlags(int argc, char ** argv) {
	  bool after = false;
	  Flags flags;

    for (int i = 1; i < argc; i++) {
      string arg(argv[i]);
      if (!after)
      {
        if (arg.size() > 1 && arg[0] == '-')
        {
          string flag = arg.substr(1, string::npos);

          if (flag == "d" || flag == "debug") {
            flags.debug = true;
          } else if (flag == "v" || flag == "version") {
            flags.version = true;
          } else if (flag == "h" || flag == "help") {
            flags.help = true;
          } else if (flag == "r" || flag == "run") {
            flags.runCompiled = false;
            flags.runInterpreted = true;

            after = true;
          } else if (flag == "cpp") {
            if (i + 1 >= argc) {
              cout << "output file must follow '-cpp' flag";
              flags.flagError = true;
            }

            flags.runInterpreted = false;

            flags.cppOutFile = string(argv[i + 1]);

            i++;
          } else if (flag == "bin") {
            if (i + 1 >= argc) {
              cout << "output file must follow '-bin' flag";
              flags.flagError = true;
            }

            flags.runInterpreted = false;

            flags.binOutFile = string(argv[i + 1]);

            i++;
          } else if (flag == "e" || flag == "execute") {
            flags.runCompiled = true;
            flags.runInterpreted = false;

            after = true;
          } else {
            cout << "Unknown flag '" + flag + "'" << endl;
            flags.flagError = true;
          }
        } else {
          flags.inFiles.push_back(arg);
          cmdLineArgs.push_back(arg);
        }
      } else {
        cmdLineArgs.push_back(arg);
      }
    }

  return flags;
}
