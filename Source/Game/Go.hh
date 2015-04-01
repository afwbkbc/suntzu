#ifndef GO_HH_
#define GO_HH_

#include "Game.hh"

namespace game {

class Go : public Game {
public:
	Go();
	virtual ~Go();

	const std::string getName() {
		return "go";
	}

	int initWorld() {

		return EXIT_SUCCESS;
	}
	int initAI(AI *ai) {

		return EXIT_SUCCESS;
	}

};

} /* namespace game */
#endif /* GO_HH_ */
