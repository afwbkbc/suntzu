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
		LOCAL = utils::ArgumentParser::ARG::_MAX,
		SEARCH,
		HOST,

		_MAX,
	};

	struct utils::ArgumentParser::Arg *getArguments() {
		return mArguments;
	}
	int getArgumentsMax() {
		return ARG::_MAX;
	}
	void insertArguments(TCLAP::CmdLine *cmd, TCLAP::Arg **args) {
		std::vector<TCLAP::Arg *> xorlist;
		xorlist.push_back(args[ARG::LOCAL]);
		xorlist.push_back(args[ARG::SEARCH]);
		xorlist.push_back(args[ARG::HOST]);
		cmd->xorAdd( xorlist );

	}

private:
	struct utils::ArgumentParser::Arg mArguments[ARG::_MAX] = {
		{ (utils::ArgumentParser::ARG)ARG::LOCAL, utils::ArgumentParser::ARGTYPE::BOOL, "l", "local", "", "Search game on localhost", true, new bool(true) },
		{ (utils::ArgumentParser::ARG)ARG::SEARCH, utils::ArgumentParser::ARGTYPE::STRING, "s", "search", "IP Address", "IP Address to search game on", true, new std::string("127.0.0.1") },
		{ (utils::ArgumentParser::ARG)ARG::HOST, utils::ArgumentParser::ARGTYPE::BOOL, "h", "host", "", "Host the game", true, new bool(false) },
	};

};

} /* namespace game */
#endif /* SMAC_HH_ */
