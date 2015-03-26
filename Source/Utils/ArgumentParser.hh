#ifndef ARGUMENTPARSER_HH_
#define ARGUMENTPARSER_HH_

#include <string>
#include <tclap/CmdLine.h>

namespace utils {

class ArgumentParser {
public:
	ArgumentParser(int argc, char *argv[]);
	virtual ~ArgumentParser();

	void run();

	enum ARG {
		GAME,

		_MAX,
	};
	bool getBool(ARG argid);
	std::string getString(ARG argid);

	enum ARGTYPE {
		BOOL,
		STRING,
	};
	struct Arg {
		ARG id;
		ARGTYPE type;
		std::string key;
		std::string name;
		std::string description;
		bool mandatory;
		void *value;
	};

	void handleArgs(struct Arg *arguments, int len);

	void insertArgs(TCLAP::CmdLine *cmd, TCLAP::Arg **args);
	TCLAP::Arg ** prepareArgs(struct Arg *arguments, int len);
	void processArgs(struct Arg *arguments, TCLAP::Arg **args, int len);

private:
	struct Arg mArguments[ARG::_MAX] = {
		{ ARG::GAME, ARGTYPE::STRING, "game", "", "Game to play", true, NULL },
	};
	TCLAP::CmdLine *mCmd;
	int mArgc;
	char **mArgv;
};

} /* namespace utils */
#endif /* ARGUMENTPARSER_HH_ */
