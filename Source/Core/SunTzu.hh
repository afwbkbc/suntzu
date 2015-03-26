#ifndef SUNTZU_HH_
#define SUNTZU_HH_

#include "Utils/ArgumentParser.hh"
#include "UI/UI.hh"
#include "Game/Game.hh"

#include <vector>

/*
 * Eternity lies ahead of us, and behind. Have you drunk your fill?
 */
class SunTzu {
public:
	SunTzu(int argc, char *argv[]);
	virtual ~SunTzu();

	int run();

	std::vector<Game *>::iterator gamesBegin() {
		return mGames.begin();
	};
	std::vector<Game *>::iterator gamesEnd() {
		return mGames.end();
	};

	UI *getUI() {
		return mUI;
	};
private:

	utils::ArgumentParser *mArgumentParser;
	UI *mUI;

	std::vector<Game *> mGames;

};

extern SunTzu *gSunTzu;

#endif /* SUNTZU_HH_ */
