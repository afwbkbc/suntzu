#include "ArgumentParser.hh"

#include <assert.h>
#include <string.h>

#include "Core/SunTzu.hh"

namespace utils {

ArgumentParser::ArgumentParser(int argc, char *argv[]) {

	mArgc = argc;
	mArgv = argv;

}

ArgumentParser::~ArgumentParser() {
	// TODO Auto-generated destructor stub
}

#define _getfunc(_argtype,_gettype,_vartype)\
	_vartype ArgumentParser::get##_gettype(int argid) {\
		assert(argid < mAllArgumentsMax);\
		struct Arg *arg = mAllArguments[argid];\
		assert(arg->id == argid);\
		assert(arg->type == ARGTYPE::_argtype);\
		assert(arg->value != NULL);\
		return *(_vartype *)arg->value;\
	}

	_getfunc(BOOL, Bool, bool);
	_getfunc(STRING, String, std::string);

#undef _getfunc

int ArgumentParser::run() {

	Game *game = NULL;
	if ((mArgc > 1) && (mArgv[1] != "") && (mArgv[1][0] != '-')) {
		for (std::vector<Game *>::iterator it = gSunTzu->gamesBegin(); it != gSunTzu->gamesEnd() ; ++it)
			if (mArgv[1] == (*it)->getName()) {
				game = *it;
				break;
			}
	}

	if (!game) {

		std::string gamesString = "";
		for (std::vector<Game *>::iterator it = gSunTzu->gamesBegin(); it != gSunTzu->gamesEnd() ; ++it) {
			if (gamesString != "")
				gamesString += "|";
			gamesString += (*it)->getName();
		}

		std::cout << "Usage:" << std::endl << "\t" << mArgv[0] << " <" << gamesString << ">" << " [...]" << std::endl;

		return EXIT_FAILURE;
	}

	mArguments[ARG::AI].name = "";
	for (std::vector<::AI *>::iterator it = gSunTzu->AIsBegin(); it != gSunTzu->AIsEnd() ; ++it) {
		if (mArguments[ARG::AI].name != "")
			mArguments[ARG::AI].name += "|";
		mArguments[ARG::AI].name += (*it)->getName();
	}

	try {

		mCmd = new TCLAP::CmdLine("", ' ', "SunTzu 0.9", false);

		int gameArgumentsMax = game->getArgumentsMax();
		assert(mAllArguments == NULL);
		mAllArguments = new Arg*[ARG::_MAX + gameArgumentsMax];
		for (unsigned char i = 0 ; i < ARG::_MAX ; i++)
			mAllArguments[i] = &mArguments[i];
		if (gameArgumentsMax > 0) {
			struct Arg *gameArguments = game->getArguments();
			for (unsigned char i = ARG::_MAX ; i < gameArgumentsMax ; i++)
				mAllArguments[i] = &gameArguments[i - ARG::_MAX];
			mAllArgumentsMax = gameArgumentsMax;
		}
		else
			mAllArgumentsMax = ARG::_MAX;

		struct Arg *arg;

		TCLAP::Arg **args = new TCLAP::Arg*[mAllArgumentsMax];

		std::string defaultString;

		for (unsigned char i = 0; i < mAllArgumentsMax; i++) {
			arg = mAllArguments[i];
			if (arg->type == ARGTYPE::BOOL)
				args[i] = new TCLAP::SwitchArg(arg->shortKey, arg->longKey, arg->description, arg->mandatory);
			else if (arg->type == ARGTYPE::STRING) {
				defaultString = this->getString(arg->id);
				args[i] = new TCLAP::ValueArg<std::string>(arg->shortKey, arg->longKey, arg->description + (defaultString.empty()?"":" (default: "+defaultString+")"), arg->mandatory, arg->value?*(std::string *)(arg->value):"", arg->name);
			}
			else
				assert(false);
		}

		mCmd->add(args[ARG::AI]);
		mCmd->add(args[ARG::VERBOSE]);

		if (gameArgumentsMax > 0) {
			game->insertArguments(mCmd, args);
		}

		int tmpArgv0Len = strlen(mArgv[0]) + strlen(mArgv[1]) + 2;
		char *tmpArgv0 = new char[tmpArgv0Len];
		snprintf(tmpArgv0, tmpArgv0Len, "%s %s", mArgv[0], mArgv[1]);
		char *argv1Backup = mArgv[1];
		mArgv[1] = tmpArgv0;

		mCmd->parse( mArgc - 1, mArgv + 1 );

		mArgv[1] = argv1Backup;
		delete[] tmpArgv0;

		for (unsigned char i = 0; i < mAllArgumentsMax; i++) {

			arg = mAllArguments[i];

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


		delete[] args;

		delete mCmd;
		mCmd = NULL;

		//for (int i = 0; i < gameArgumentsMax ; i++)
			//printf("%s %s\n", mAllArguments[i]->longKey.c_str(), (char *)mAllArguments[i]->value);

	} catch (TCLAP::ArgException &e) {
		{ std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; }
		return EXIT_FAILURE;
	}

	::AI *ai = NULL;
	std::string ainame = this->getString(ARG::AI);
	for (std::vector<::AI *>::iterator it = gSunTzu->AIsBegin(); it != gSunTzu->AIsEnd() ; ++it)
		if (ainame == (*it)->getName()) {
			ai = *it;
			break;
		}

	if (ai == NULL) {
		gSunTzu->getUI()->FatalError("AI \"" + ainame + "\" not found!");
		return EXIT_FAILURE;
	}

	gSunTzu->SetAI(ai);
	gSunTzu->SetGame(game);

	return EXIT_SUCCESS;
}

} /* namespace utils */
