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
};

} /* namespace game */
#endif /* GO_HH_ */
