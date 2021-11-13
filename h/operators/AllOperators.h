#pragma once

#include <vector>
#include "Operation.h"
#include <unordered_map>

using std::vector;
using std::unordered_map;

class AllOperators {
    public:
    	static void init();
    
    	void get(string text, vector<Operator>& out);
    
    	#define DECLARE_OP(name, text, prece, input, overload)\
    		const Operator name {
                new OperatorData(text, prece, input, overload)
            };
    
    	#define ALL_OPS 																\

    	DECLARE_OP(	loop,		 "loop", 5,			OperatorData::BOTH,		false	);	\
    	DECLARE_OP(	ifOp,		 "??",	 6,			OperatorData::BOTH,		false	);	\
    	DECLARE_OP(	pipe,		 ";",	 6,			OperatorData::BOTH,		false	);	\
    	DECLARE_OP(	colon,		 ":",	 24,		OperatorData::BOTH,		false	);	\
    	DECLARE_OP(	doubleColon, "::",	 24,		OperatorData::BOTH,		false	);	\
    	DECLARE_OP(	comma,		 ",",	 35,		OperatorData::BOTH,		false	);	\
    	DECLARE_OP(	orOp,		 "||",	 36,		OperatorData::BOTH,		false	);	\
    	DECLARE_OP(	andOp,		 "&&",	 38,		OperatorData::BOTH,		false	);	\
    	DECLARE_OP(	equal,		 "=",	 40,		OperatorData::BOTH,		true	);	\
    	DECLARE_OP(	notEqual,	 "!==",	 40,		OperatorData::BOTH,		false	);	\
    	DECLARE_OP(	greater,	 ">",	 50,		OperatorData::BOTH,		true	);	\
    	DECLARE_OP(	less,		 "<",	 50,		OperatorData::BOTH,		true	);	\
    	DECLARE_OP(	greaterEq,	 ">=",	 50,		OperatorData::BOTH,		true	);	\
    	DECLARE_OP(	lessEq,		 "<=",	 50,		OperatorData::BOTH,		true	);	\
    	DECLARE_OP(	plus,		 "+",	 61,		OperatorData::BOTH,		true	);	\
    	DECLARE_OP(	minus,		 "-",	 61,		OperatorData::BOTH,		true	);	\
    	DECLARE_OP(	multiply,	 "*",	 71,		OperatorData::BOTH,		true	);	\
    	DECLARE_OP(	divide,		 "/",	 71,		OperatorData::BOTH,		true	);	\
    	DECLARE_OP(	mod,		 "%",	 70,		OperatorData::BOTH,		true	);	\
    	DECLARE_OP(	notOp,		 "!",	 74,		OperatorData::RIGHT,	true	);	\
    	DECLARE_OP(	plusPlus,	 "++",	 75,		OperatorData::LEFT,		false	);	\
    	DECLARE_OP(	minusMinus,	 "--",	 75,		OperatorData::LEFT,		false	);	\
    	DECLARE_OP(	dot,		 ".",	 81,		OperatorData::BOTH,		false	);	\
    	DECLARE_OP(	rightArrow,	 "=>",	 83,		OperatorData::BOTH,		false	);	\
    	DECLARE_OP(	import,		 "==>",	 90,		OperatorData::RIGHT,	false	);	\
    	DECLARE_OP(	openPeren,	 "(",	 100,		OperatorData::RIGHT,	false	);	\
    	DECLARE_OP(	closePeren,	 ")",	 99,		OperatorData::LEFT,		false	);	\
    	DECLARE_OP(	openSqBrac,	 "[",	 100,		OperatorData::BOTH,		false	);	\
    	DECLARE_OP(	closeSqBrac, "]",	 99,		OperatorData::LEFT,		false	);	\
    	DECLARE_OP(	openCrBrac,	 "{",	 100,		OperatorData::RIGHT,	false	);	\
    	DECLARE_OP(	closeCrBrac, "}",	 99,		OperatorData::LEFT,		false	);	\
	
	    ALL_OPS;
	
	    unordered_map<string, Operator>& getOpsMap() {return opsMap;}
	
	    bool isOpenBrac(Operator op);
	    bool isCloseBrac(Operator op);

    private:
    	AllOperators();
    
    	void putOpInMap(Operator op);
    
    	unordered_map<string, Operator> opsMap;
    };
    
    extern AllOperators* ops;
