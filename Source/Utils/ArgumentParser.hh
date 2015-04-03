#ifndef ARGUMENTPARSER_HH_
#define ARGUMENTPARSER_HH_

#include <string>
#include <tclap/CmdLine.h>

namespace utils {

class ArgumentParser {
public:
	ArgumentParser(int argc, char *argv[]);
	virtual ~ArgumentParser();

	int run();

	enum ARG {
		AI,
		VERBOSE,

		_MAX,
	};
	bool getBool(int argid);
	std::string getString(int argid);

	enum ARGTYPE {
		BOOL,
		STRING,
	};
	struct Arg {
		ARG id;
		ARGTYPE type;
		std::string shortKey;
		std::string longKey;
		std::string name;
		std::string description;
		bool mandatory;
		void *value;
	};

private:

	struct Arg mArguments[ARG::_MAX] = {
		{ ARG::AI, ARGTYPE::STRING, "a", "ai", "", "AI engine to use", false, new std::string("randomchoice") },
		{ ARG::VERBOSE, ARGTYPE::BOOL, "v", "verbose", "", "Show more verbose output", true, NULL },
	};
	TCLAP::CmdLine *mCmd;
	int mArgc;
	char **mArgv;

	struct Arg **mAllArguments = NULL;
	int mAllArgumentsMax = 0;
};

} /* namespace utils */
#endif /* ARGUMENTPARSER_HH_ */
