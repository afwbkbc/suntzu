#include "ArgumentParser.hh"

#include <assert.h>

#include "Core/SunTzu.hh"

namespace utils {

void ArgumentParser::insertArgs(TCLAP::CmdLine *cmd, TCLAP::Arg **args) {
	mCmd->add(args[ARG::GAME]);
}

void ArgumentParser::processArgs(struct Arg *arguments, TCLAP::Arg **args, int len) {
	struct Arg *arg;
	for (unsigned char i = 0; i < len; i++) {

		arg = &arguments[i];

#define _parse(_argtype, _vartype, _argclass, _pre)\
if (arg->type == ARGTYPE::_argtype) {\
	if (arg->value != NULL)\
		delete (_vartype *)arg->value;\
	arg->value = new _vartype(_pre((TCLAP::_argclass *)args[i])->getValue());\
}

		_parse(BOOL, bool, SwitchArg, !);
		_parse(STRING, std::string, ValueArg<std::string>,);

#undef _parse

		delete args[i];
	}
}

TCLAP::Arg ** ArgumentParser::prepareArgs(struct Arg *arguments, int len) {
	TCLAP::Arg **args = new TCLAP::Arg*[len];
	struct Arg *arg;
	for (unsigned char i = 0; i < len; i++) {
		arg = &arguments[i];
		if (arg->type == ARGTYPE::BOOL)
			args[i] = new TCLAP::SwitchArg("", arg->key, arg->description, arg->mandatory);
		else if (arg->type == ARGTYPE::STRING)
			args[i] = new TCLAP::ValueArg<std::string>("", arg->key, arg->description, arg->mandatory, arg->value?*(std::string *)(arg->value):"", arg->name);
		else
			assert(false);
	}
	return args;
}

void ArgumentParser::handleArgs(struct Arg *arguments, int len) {
	TCLAP::Arg **args = this->prepareArgs(arguments, len);
	this->insertArgs(mCmd, args);
	mCmd->reset();
	mCmd->parse( mArgc, mArgv );
	this->processArgs(arguments, args, len);
	delete args[len];
}

ArgumentParser::ArgumentParser(int argc, char *argv[]) {

	mArgc = argc;
	mArgv = argv;

}

ArgumentParser::~ArgumentParser() {
	// TODO Auto-generated destructor stub
}

#define _getfunc(_argtype,_gettype,_vartype)\
	_vartype ArgumentParser::get##_gettype(ARG argid) {\
		assert(argid < ARG::_MAX);\
		struct Arg *arg = &mArguments[argid];\
		assert(arg->id == argid);\
		assert(arg->type == ARGTYPE::_argtype);\
		assert(arg->value != NULL);\
		return *(_vartype *)arg->value;\
	}

	_getfunc(BOOL, Bool, bool);
	_getfunc(STRING, String, std::string);

#undef _getfunc

void ArgumentParser::run() {

	mArguments[ARG::GAME].name = "";

	for (std::vector<Game *>::iterator it = gSunTzu->gamesBegin(); it != gSunTzu->gamesEnd() ; ++it) {
		if (mArguments[ARG::GAME].name != "")
			mArguments[ARG::GAME].name += "|";
		mArguments[ARG::GAME].name += (*it)->getName();
	}

	try {

		mCmd = new TCLAP::CmdLine("", ' ', "SunTzu 0.9");

		this->handleArgs(mArguments, ARG::_MAX);

		Game *foundGame = NULL;
		std::string game;
		if ((game = this->getString(ARG::GAME)) != "") {
			for (std::vector<Game *>::iterator it = gSunTzu->gamesBegin(); it != gSunTzu->gamesEnd() ; ++it) {
				if ((*it)->getName() == game) {
					foundGame = *it;
					break;
				}
			}
		}
		if (foundGame == NULL) {
			gSunTzu->getUI()->FatalError("Invalid game. Specify one of: " + mArguments[ARG::GAME].name);
			exit(EXIT_FAILURE);
		}
		if (foundGame->getArgumentsLen()>0) {
			this->handleArgs(foundGame->getArguments(), foundGame->getArgumentsLen());
		}

		/*
		std::vector<TCLAP::Arg *> xorlist;
		xorlist.push_back(args[ARG::LOCAL]);
		xorlist.push_back(args[ARG::SEARCH]);
		xorlist.push_back(args[ARG::HOST]);
		cmd.xorAdd( xorlist );
		*/

		delete mCmd;
		mCmd = NULL;

	} catch (TCLAP::ArgException &e) {
		{ std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; }
	}
}

} /* namespace utils */
