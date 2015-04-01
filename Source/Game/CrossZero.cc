#include "CrossZero.hh"

#include <string.h>

namespace game {

	CrossZero::CrossZero() {
		// TODO Auto-generated constructor stub

	}

	CrossZero::~CrossZero() {
		// TODO Auto-generated destructor stub
	}

	int CrossZero::initWorld() {

		memset(&mField, 0, sizeof(mField));

		return EXIT_SUCCESS;
	}

	int CrossZero::initAI(AI *ai) {
		ai::InputFormat iF;
		ai::OutputFormat oF;

		iF.inputType = ai::input_type_t::PERCEPTION;
		iF.dataType = ai::data_type_t::FLOAT;
		iF.dataLen = CZ_X * CZ_Y;
		mFieldOutput = ai->addInputListener(iF);

		iF.inputType = ai::input_type_t::FEELING;
		iF.dataType = ai::data_type_t::FLOAT;
		iF.dataLen = 1;
		mPainOutput = ai->addInputListener(iF);

		oF.outputType = ai::output_type_t::MOTORIC;
		oF.dataType = ai::data_type_t::FLOAT;
		oF.dataLen = CZ_X * CZ_Y;
		mMoveInput = ai->addOutputGenerator(oF);

		return EXIT_SUCCESS;
	}

} /* namespace game */
