#ifndef TEST1_HH_
#define TEST1_HH_

#include "AI/AI.hh"

namespace ai {

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
};

} /* namespace ai */
#endif /* TEST1_HH_ */
