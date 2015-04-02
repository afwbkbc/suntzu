#include "RandomChoice.hh"

#include <assert.h>
#include <stdlib.h>

namespace ai {

	RandomChoice::RandomChoice() {
		// TODO Auto-generated constructor stub
		srand(time(NULL));
	}

	RandomChoice::~RandomChoice() {
		// TODO Auto-generated destructor stub
	}

	input_id_t RandomChoice::addInputListener(struct ai::InputFormat &format) {
		struct InputListener listener;
		listener.id = mNextInputId++;
		listener.format = format;
		mInputListeners.push_back(listener);
		return listener.id;
	}
	input_id_t RandomChoice::addOutputGenerator(struct ai::OutputFormat &format) {
		struct OutputGenerator generator;
		generator.id = mNextOutputId++;
		generator.format = format;
		mOutputGenerators.push_back(generator);
		return generator.id;
	}

	void RandomChoice::setInput(ai::input_id_t id, ai::data_t *data) {
		for (std::vector<struct InputListener>::iterator it = mInputListeners.begin() ; it != mInputListeners.end() ; ++it) {
			if (it->id == id) {
				if (it->format.inputType == ai::input_type_t::PERCEPTION) {
					// nothing to do
				}
				else
					assert(false);
				return;
			}
		}
		assert(false);
	}

	void RandomChoice::getOutput(ai::output_id_t id, ai::data_t *data) {
		for (std::vector<struct OutputGenerator>::iterator it = mOutputGenerators.begin() ; it != mOutputGenerators.end() ; ++it) {
			if (it->id == id) {
				if (it->format.outputType == ai::output_type_t::MOTORIC) {
					for (unsigned char i = 0 ; i < it->format.dataLen ; i++) {
						data[i] = -1+2*((float)rand())/RAND_MAX;
					}
				}
				else
					assert(false);
				return;
			}
		}
		assert(false);
	}

	void RandomChoice::iterate() {

	}

} /* namespace ai */
