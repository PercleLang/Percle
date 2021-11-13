#pragma once

#include "Type.h"
#include "Action.h"
#include "Token.h"
#include "AstNode.h"
#include "../h/operators/Operation.h"

#include <unordered_map>
using std::unordered_map;

#include <vector>
using std::vector;

class StackFrame;

class NamespaceData;
typedef shared_ptr<NamespaceData> Namespace;

class NamespaceData: public std::enable_shared_from_this<NamespaceData> {
    public:
    	static Namespace makeRootNamespace();

    	Namespace makeChild();
    
    	Namespace makeChildAndFrame(string nameIn);
    
    	string getString();
    
    	string getStringWithParents();
    	shared_ptr<StackFrame> getStackFrame() {return stackFrame;}
    
    	void setInput(Type left, Type right);
    	void addNode(AstNode node, string id);
    
    	Type getType(string name, bool throwSourceError, Token tokenForError);
    
    	Action getDestroyer(Type type);
    
    	Action getCopier(Type type);
    
    	Action getActionForTokenWithInput(Token token, Type left, Type right, bool dynamic, bool throwSourceError, Token tokenForError);
    
    	vector<Action>* getDestroyerActions() {return &destructorActions;}
    	Action wrapInDestroyer(Action in);
    
    private:
    	void getNodes(vector<AstNodeBase*>& out, string text, bool checkActions, bool checkDynamic, bool checkWhatev);
    
    	void nodesToMatchingActions(vector<Action>& out, vector<AstNodeBase*>& nodes, Type leftInType, Type rightInType);
    
    	class IdMap {
    	    public:
    	    	void add(string key, AstNode node);
    	    	void get(string key, vector<AstNodeBase*>& out);

    	    private:
    	    	unordered_map<string, vector<AstNode>> nodes;
    	};
    
    	Action addVar(Type type, string name);
    
    	NamespaceData(Namespace parentIn, shared_ptr<StackFrame> stackFrameIn, string nameIn = "");
    
    	string myName;
    
    	shared_ptr<NamespaceData> parent;
    	shared_ptr<StackFrame> stackFrame;
    
    	IdMap actions;
    	IdMap dynamicActions;
    	IdMap whatevActions;
    	IdMap types;

    	vector<Action> destructorActions;
};
