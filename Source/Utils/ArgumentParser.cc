#include "ArgumentParser.hh"

#include <tclap/CmdLine.h>
#include <assert.h>

namespace utils {

ArgumentParser::ArgumentParser(int argc, char *argv[]) {

	try {

		TCLAP::CmdLine cmd("", ' ', "SunTzu 0.9");

		TCLAP::Arg *args[ARG::_MAX];

		struct ArgMap *arg;

		for (unsigned char i = 0; i < ARG::_MAX; i++) {
			arg = &mArguments[i];
			if (arg->type == TYPE::BOOL)
				args[i] = new TCLAP::SwitchArg("", arg->key, arg->description, arg->mandatory);
			else if (arg->type == TYPE::STRING)
				args[i] = new TCLAP::ValueArg<std::string>("", arg->key, arg->description, arg->mandatory, arg->value?*(std::string *)(arg->value):"", arg->name);
			else
				assert(false);
		}


        std::vector<TCLAP::Arg *> xorlist;
        xorlist.push_back(args[ARG::LOCAL]);
        xorlist.push_back(args[ARG::SEARCH]);
        xorlist.push_back(args[ARG::HOST]);
        cmd.xorAdd( xorlist );

		cmd.parse( argc, argv );

		for (unsigned char i = 0; i < ARG::_MAX; i++) {

			arg = &mArguments[i];

#define _parse(_argtype, _vartype, _argclass, _pre)\
	if (arg->type == TYPE::_argtype) {\
		if (arg->value != NULL)\
			delete (_vartype *)arg->value;\
		arg->value = new _vartype(_pre((TCLAP::_argclass *)args[i])->getValue());\
	}

			_parse(BOOL, bool, SwitchArg, !);
			_parse(STRING, std::string, ValueArg<std::string>,);

#undef _parse

			delete args[i];
		}

	} catch (TCLAP::ArgException &e) {
		{ std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; }
	}

}

ArgumentParser::~ArgumentParser() {
	// TODO Auto-generated destructor stub
}

#define _getfunc(_argtype,_gettype,_vartype)\
	_vartype ArgumentParser::get##_gettype(ARG argid) {\
		assert(argid < ARG::_MAX);\
		struct ArgMap *arg = &mArguments[argid];\
		assert(arg->id == argid);\
		assert(arg->type == TYPE::_argtype);\
		assert(arg->value != NULL);\
		return *(_vartype *)arg->value;\
	}

	_getfunc(BOOL, Bool, bool);
	_getfunc(STRING, String, std::string);

#undef _getfunc

} /* namespace utils */
