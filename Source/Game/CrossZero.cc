#include "CrossZero.hh"

#include <string.h>
#include <iostream>
#include <assert.h>

namespace game {

	CrossZero::CrossZero() {
		// TODO Auto-generated constructor stub

	}

	CrossZero::~CrossZero() {
		// TODO Auto-generated destructor stub
	}

	void CrossZero::clearField() {
		memset(&mField, ' ', sizeof(mField));
		mMyChar = mAIChar = ' ';
		std::cout << std::endl << "New game." << std::endl;
	}

	int CrossZero::initWorld() {

		this->clearField();

		return EXIT_SUCCESS;
	}

	int CrossZero::initAI(AI *ai) {
		ai::InputFormat iF;
		ai::OutputFormat oF;

		assert(CZ_X > 0 && CZ_X <= 9 && CZ_Y > 0 && CZ_Y <= 9);

		iF.inputType = ai::input_type_t::PERCEPTION;
		iF.dataLen = CZ_X * CZ_Y;
		mFieldOutput = ai->addInputListener(iF);

		iF.inputType = ai::input_type_t::JOY;
		iF.dataLen = 1;
		mScoreOutput = ai->addInputListener(iF);

		oF.outputType = ai::output_type_t::MOTORIC;
		oF.dataLen = CZ_X * CZ_Y;
		mMoveInput = ai->addOutputGenerator(oF);

		return EXIT_SUCCESS;
	}

	char CrossZero::getWinner() {
		unsigned char i,ii,w,ww;
		for (unsigned char y = 0; y < CZ_Y ; y++) {
			for (unsigned char x = 0; x < CZ_X ; x++) {
				char c = mField[x][y];
				if (c != ' ') {
#define _comma ,
#define _checkline(_xy, _cz, _f1, _f2, _e1, _e2, _e3)\
	if (_cz - _xy >= CZ_TOWIN _e1) {\
		w = _xy + CZ_TOWIN;\
		for (i = _xy _e2 ; i < w ; i++ _e3)\
			if (mField[_f1][_f2] != c)\
				break;\
		if (i == w)\
			return c;\
	}
					_checkline(y, CZ_Y, x, i,,,); // v
					_checkline(x, CZ_X, i, y,,,); // h
					_checkline(x, CZ_X, i, ii, && CZ_Y - y >= CZ_TOWIN, _comma ii = y, _comma ii++); // d1
					_checkline(x, CZ_X, i, ii, && y >= CZ_TOWIN - 1, _comma ii = y, _comma ii--); // d2
#undef _checkline
#undef _comma

					if (CZ_Y - y >= CZ_TOWIN) {
						w = y + CZ_TOWIN;
						for (i = y ; i < w ; i++)
							if (mField[x][i] != c)
								break;
						if (i == w)
							return c;
					}
				}
			}
		}
		return ' ';
	}

	void CrossZero::printField() {
		for (char y = -1; y < CZ_Y + 1 ; y++) {
			for (char x = -1; x < CZ_X+1 ; x++) {
				if ((y >= 0) && (y < CZ_Y)) {
					if ((x >= 0) && (x < CZ_X))
						std::cout << mField[x][y];
					else
						std::cout << '|';
				}
				else {
					if ((x >= 0) && (x < CZ_X))
						std::cout << '-';
					else
						std::cout << '+';
				}
			}
			std::cout << std::endl;
		}
	}

	void CrossZero::iterateWorld() {

		if (mMyChar == ' ') {
			std::cout << "You start." << std::endl;
			mMyChar = 'X';
			mAIChar = 'O';
		}

		std::cout << std::endl;

		std::cout << "Your turn." << std::endl;

		this->printField();

		std::string move="";
		unsigned char mx, my;

		do {
			if (move != "")
				std::cout << "Invalid move!" << std::endl;

			std::cout << "Your move (<x><y>): ";

			std::getline(std::cin, move);
		} while (!((move.size() == 2)
			&& (move[0] >= '1') && (move[0] <= ('0' + CZ_X))
			&& (move[1] >= '1') && (move[1] <= ('0' + CZ_Y))
			&& (mField[mx=move[0]-'0'-1][my=move[1]-'0'-1] == ' ')
		));

		mField[mx][my] = mMyChar;

		this->printField();

		if (this->getWinner() == mMyChar) {
			std::cout << "You won! Press enter to continue." << std::endl;
			std::getline(std::cin, move);
			this->clearField();
		}

	}

	void CrossZero::setInputs(AI *ai) {
		ai::data_t data[CZ_X * CZ_Y];
		ai->setInput(mFieldOutput,data);

		if (mAIChar == ' ') {
			std::cout << "AI starts." << std::endl;
			mAIChar = 'X';
			mMyChar = 'O';
		}

		std::cout << std::endl;

		std::cout << "AI's turn." << std::endl;

		this->printField();

	}

	void CrossZero::getOutputs(AI *ai) {
		ai::data_t data[CZ_X * CZ_Y];
		ai->getOutput(mMoveInput, data);

		ai::data_t val, max;
		char mx=-1, my=-1;
		for (unsigned char y = 0; y < CZ_Y ; y++)
			for (unsigned char x = 0; x < CZ_X ; x++) {
				if (mField[x][y] == ' ') {
					val = data[y * CZ_X + x];
					if ((mx == -1) || (val > max)) {
						max = val;
						mx = x;
						my = y;
					}
				}
			}
		assert(mx != -1);
		assert(mField[mx][my] == ' ');

		std::cout << "AI's move (<x><y>): " << (char)('0'+mx+1) << (char)('0'+my+1) << std::endl;

		mField[mx][my] = mAIChar;

		this->printField();

		if (this->getWinner() == mAIChar) {
			std::cout << "You lost! Press enter to continue." << std::endl;
			std::string move;
			std::getline(std::cin, move);
			this->clearField();
		}
	}
} /* namespace game */
