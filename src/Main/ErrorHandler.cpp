#include "../h/main/Error.h"
#include "../h/functions/StringFunctions.h"
#include "../h/SourceFile.h"

#include <iostream>

using std::cout;
using std::endl;

ErrorHandler error;

string ErrorHandler::priorityToStr(ErrorPriority in) {
	switch (in) {   
	    case SOURCE_ERROR:
	    	return "error";
	    	break;

	    case SOURCE_WARNING:
	    	return "warning";
	    	break;
    
	    case JSYK:
	    	return "jsyk";
	    	break;
    
	    case INTERNAL_ERROR:
	    	return "INTERNAL ERROR";
	    	break;
    
	    case RUNTIME_ERROR:
	    	return "runtime error";
	    	break;
    
	    default:
	    	return "UNKNOWN PRIORITY LEVEL";
	    	break;
	}
}

void ErrorHandler::log(string msg, ErrorPriority priority, Token token) {
	if (priority == SOURCE_ERROR || priority == INTERNAL_ERROR || priority == RUNTIME_ERROR) {
		errorHasBeenLogged = true;
    }
	
	if (token) {
		cout << token -> getFile() << ":" << token -> getLine() << ":" << token -> getCharPos() << ": ";
    }

	cout << priorityToStr(priority) << ": " << msg << endl;
}

void ErrorHandler::msg(string in) {
	cout << "ErrorMessage: " << in << endl;
}

PercleError::PercleError(string msgIn, ErrorPriority priorityIn, Token tokenIn) {
	msg      = msgIn;
	priority = priorityIn;
	token    = tokenIn;
}

void PercleError::log() {
	error.log(msg, priority, token);
}
