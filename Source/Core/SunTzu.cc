#include "SunTzu.hh"

#include <iostream>
#include <assert.h>
#include <cstdlib>

#include "UI/Console/Console.hh"

#include "Game/Go.hh"
#include "Game/SMAC.hh"

SunTzu *gSunTzu = NULL;

SunTzu::SunTzu(int argc, char *argv[]) {

	assert(gSunTzu == NULL);
	gSunTzu = this;

	mArgumentParser = new utils::ArgumentParser(argc, argv);
	mUI = new ui::Console;

	mGames.push_back(new game::Go);
	mGames.push_back(new game::SMAC);

}

SunTzu::~SunTzu() {

	for (std::vector<Game *>::iterator it = mGames.begin(); it != mGames.end() ; ++it) {
		delete *it;
	}
	mGames.clear();

	delete mUI;
	delete mArgumentParser;

	assert(gSunTzu != NULL);
	gSunTzu = NULL;
}

int SunTzu::run() {

	mArgumentParser->run();

	/*
	if (mArgumentParser->getBool(utils::ArgumentParser::ARG::HOST))
		return mUI->FatalError("Game hosting not supported yet.");

	std::string ip = mArgumentParser->getString(utils::ArgumentParser::ARG::SEARCH);
	std::cout << ip << std::endl;
*/


	return EXIT_SUCCESS;
}
