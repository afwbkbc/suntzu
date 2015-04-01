#include "SunTzu.hh"

#include <iostream>
#include <assert.h>
#include <cstdlib>

#include "UI/Console/Console.hh"

#include "Game/CrossZero.hh"
#include "Game/Go.hh"
#include "Game/SMAC.hh"

#include "AI/RandomChoice/RandomChoice.hh"

SunTzu *gSunTzu = NULL;

SunTzu::SunTzu(int argc, char *argv[]) {

	assert(gSunTzu == NULL);
	gSunTzu = this;

	mArgumentParser = new utils::ArgumentParser(argc, argv);
	mUI = new ui::Console;

	mGames.push_back(new game::CrossZero);
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

	int ret;

	if ((ret=mArgumentParser->run()) != EXIT_SUCCESS)
		return ret;

	assert(mGame);

	mAI = new ai::RandomChoice;

	mUI->Log("initializing AI \"" + mAI->getName() + "\"");
	/* ... */

	mUI->Log("initializing game \"" + mGame->getName() + "\"");
	if ((ret=mGame->initWorld()) != EXIT_SUCCESS)
		return ret;
	if ((ret=mGame->initAI(mAI)) != EXIT_SUCCESS)
		return ret;



	return ret;
}
