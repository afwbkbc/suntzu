#ifndef TEST1_HH_
#define TEST1_HH_

#include "AI/AI.hh"

#include "Neuron.hh"
#include "Receptor.hh"
#include "Motoric.hh"

#include <vector>

namespace ai {

namespace test1 {

struct Input {
	struct InputFormat format;
	Receptor **receptors;
};

struct Output {
	struct OutputFormat format;
	Motoric **motorics;
};

}

class Test1 : public AI {
public:
	Test1();
	virtual ~Test1();

	const std::string getName() {
		return "test1";
	}

	input_id_t addInputListener(struct InputFormat &format);
	output_id_t addOutputGenerator(struct OutputFormat &format);
	void setInput(input_id_t id, data_t *data);
	void getOutput(output_id_t id, data_t *data);
	void iterate();

private:
	std::vector<test1::Neuron *> mNeurons;
	std::vector<test1::Input *> mInputs;
	std::vector<test1::Output *> mOutputs;
};

} /* namespace ai */
#endif /* TEST1_HH_ */
