#ifndef CROSSZERO_HH_
#define CROSSZERO_HH_

#include "Game.hh"
#include "Utils/ArgumentParser.hh"

#define CZ_X 3
#define CZ_Y 3
#define CZ_TOWIN 3

namespace game {

class CrossZero : public Game {
public:
	CrossZero();
	virtual ~CrossZero();

	const std::string getName() {
		return "crosszero";
	}

	int initWorld();
	int initAI(AI *ai);
	void iterateWorld();
	void setInputs(AI *ai);
	void getOutputs(AI *ai);

private:

	char mField[CZ_X][CZ_Y];

	ai::input_id_t mFieldOutput;
	ai::input_id_t mScoreOutput;
	ai::output_id_t mMoveInput;

	char mMyChar;
	char mAIChar;

	void clearField();
	void printField();
	char getWinner();
};

} /* namespace game */
#endif /* CROSSZERO_HH_ */
