#ifndef RANDOMCHOICE_HH_
#define RANDOMCHOICE_HH_

#include "AI/AI.hh"

#include <vector>

namespace ai {

class RandomChoice : public AI {
public:
	RandomChoice();
	virtual ~RandomChoice();

	const std::string getName() {
		return "randomchoice";
	}

	input_id_t addInputListener(struct InputFormat &format);
	output_id_t addOutputGenerator(struct OutputFormat &format);
	void setInput(input_id_t id, data_t *data);
	void getOutput(output_id_t id, data_t *data);
	void iterate();

private:
	int mInputLen;
	int mOutputLen;

	struct InputListener {
		input_id_t id;
		struct InputFormat format;
	};

	struct OutputGenerator {
		output_id_t id;
		struct OutputFormat format;
	};

	std::vector<InputListener> mInputListeners;
	input_id_t mNextInputId = 0;
	std::vector<OutputGenerator> mOutputGenerators;
	input_id_t mNextOutputId = 0;
};

} /* namespace ai */
#endif /* RANDOMCHOICE_HH_ */
