#ifndef GAME_HH_
#define GAME_HH_

#include "Utils/ArgumentParser.hh"
#include "AI/AI.hh"

#include <string>

class Game {
public:
	Game();
	virtual ~Game();

	virtual const std::string getName()=0;

	virtual struct utils::ArgumentParser::Arg *getArguments() {
		return NULL;
	}
	virtual int getArgumentsMax() {
		return 0;
	}
	virtual void insertArguments(TCLAP::CmdLine *cmd, TCLAP::Arg **args) {};

	virtual int initWorld()=0;
	virtual int initAI(AI *ai)=0;

private:

};

#endif /* GAME_HH_ */
