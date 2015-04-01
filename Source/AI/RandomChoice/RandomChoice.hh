#ifndef RANDOMCHOICE_HH_
#define RANDOMCHOICE_HH_

#include "AI/AI.hh"

namespace ai {

class RandomChoice : public AI {
public:
	RandomChoice();
	virtual ~RandomChoice();

	const std::string getName() {
		return "randomchoice";
	}

	input_id_t addInputListener(struct ai::InputFormat &format);
	input_id_t addOutputGenerator(struct ai::OutputFormat &format);

private:
	int mInputLen;
	int mOutputLen;
};

} /* namespace ai */
#endif /* RANDOMCHOICE_HH_ */
