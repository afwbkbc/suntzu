#ifndef SMAC_HH_
#define SMAC_HH_

#include "Game.hh"
#include "Utils/ArgumentParser.hh"

namespace game {

class SMAC : public Game {
public:
	SMAC();
	virtual ~SMAC();

	const std::string getName() {
		return "smac";
	}

	enum ARG {
		LOCAL,
		SEARCH,
		HOST,

		_MAX,
	};

	struct utils::ArgumentParser::Arg *getArguments() {
		return mArguments;
	}
	int getArgumentsLen() {
		return ARG::_MAX;
	}
private:
	struct utils::ArgumentParser::Arg mArguments[ARG::_MAX] = {
		{ (utils::ArgumentParser::ARG)ARG::LOCAL, utils::ArgumentParser::ARGTYPE::BOOL, "local", "", "Search game on localhost", true, new bool(true) },
		{ (utils::ArgumentParser::ARG)ARG::SEARCH, utils::ArgumentParser::ARGTYPE::STRING, "search", "IP Address", "IP Address to search game on", true, new std::string("127.0.0.1") },
		{ (utils::ArgumentParser::ARG)ARG::HOST, utils::ArgumentParser::ARGTYPE::BOOL, "host", "", "Host the game", true, new bool(false) },
	};

};

} /* namespace game */
#endif /* SMAC_HH_ */
