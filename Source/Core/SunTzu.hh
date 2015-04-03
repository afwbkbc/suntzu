#ifndef SUNTZU_HH_
#define SUNTZU_HH_

#include "Utils/ArgumentParser.hh"
#include "UI/UI.hh"
#include "Game/Game.hh"
#include "AI/AI.hh"

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

	std::vector<AI *>::iterator AIsBegin() {
		return mAIs.begin();
	};
	std::vector<AI *>::iterator AIsEnd() {
		return mAIs.end();
	};

	UI *getUI() {
		return mUI;
	};

	void SetGame(Game *game) {
		mGame = game;
	}
	Game *GetGame() {
		return mGame;
	}
	void SetAI(AI *ai) {
		mAI = ai;
	}
	AI *GetAI() {
		return mAI;
	}
private:

	utils::ArgumentParser *mArgumentParser;
	UI *mUI;

	std::vector<Game *> mGames;
	Game *mGame = NULL;

	std::vector<AI *> mAIs;
	AI *mAI;
};

extern SunTzu *gSunTzu;

#endif /* SUNTZU_HH_ */
