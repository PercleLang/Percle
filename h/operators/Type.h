#pragma once

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;
using std::unique_ptr;

#include <cstring>
using std::memcpy;

class TypeBase;

typedef shared_ptr<TypeBase> Type;

const extern Type Unknown;
const extern Type Whatev;
const extern Type Void;
const extern Type Bool;
const extern Type Byte;
const extern Type Int;
const extern Type Dub;
extern Type String;

class CppProgram;
class ActionData;

struct NamedType {
	string name;
	Type type;
};

struct OffsetAndType {
	size_t offset;
	Type type;
};

class TypeBase: public std::enable_shared_from_this<TypeBase> {
    public:
    	virtual ~TypeBase() = default;
    
    	enum PrimitiveType {
    		UNKNOWN ,
    		VOID ,
    		BYTE,
    		DUB,
    		INT,
    		PTR,
    		BOOL,
    		TUPLE,
    		WHATEV,
    		METATYPE,
    	};
    
    	static Type makeNewVoid();
    	static Type makeNewPrimitive(PrimitiveType typeIn);
    	static Type makeNewWhatev();

    	Type getMeta();
    	Type getPtr();

    	virtual Type actuallyIs(Type target);
    
    	static string getString(PrimitiveType in);
    	virtual string getString() = 0;
    
    	string getName() {
            return nameHint.empty() ? getCompactString() : nameHint;
        }
    
        virtual string getCompactString() = 0;
    	virtual string getCppLiteral(void *data, CppProgram *prog) = 0;
    
    	virtual bool isCreatable() { return true;  };
    	virtual bool isVoid()      { return false; };
    	virtual bool isWhatev()    { return false; };
    
    	virtual size_t getSize() = 0;
    	virtual PrimitiveType getType() = 0;
    
    	bool matches(Type other);
    
    	virtual Type getSubType() {return Void;}
    	virtual OffsetAndType getSubType(string name) {return {0, nullptr};}
    
    	virtual vector<NamedType>* getAllSubTypes();
    
    	string nameHint = "";
    
    protected:
    	virtual bool matchesSameTypeType(Type other)=0;
    
    	Type ptrToMe = nullptr;
};

Type makeTuple(const vector<NamedType>& in, bool isAnonymous);

class TupleTypeMaker {
    public:
    	TupleTypeMaker();
    	void add(string name, Type type);

    	void add(Type type);
    
    	Type get(bool isAnonymous);
    
    private:
    	string getUniqueName();
    
    	std::unique_ptr<vector<NamedType>> subTypes;
};
