#ifndef AI_HH_
#define AI_HH_

#include <string>

namespace ai {

	typedef float data_t;
	typedef unsigned char input_id_t;
	typedef unsigned char output_id_t;
	enum input_type_t {
		PERCEPTION,
		JOY,
	};
	enum output_type_t {
		MOTORIC,
	};

	struct InputFormat {
		input_type_t inputType;
		int dataLen;
	};

	struct OutputFormat {
		output_type_t outputType;
		int dataLen;
	};
}

class AI {
public:
	AI();
	virtual ~AI();

	virtual const std::string getName()=0;

	virtual void init()=0;
	virtual void shutdown()=0;
	virtual ai::input_id_t addInputListener(struct ai::InputFormat &format)=0;
	virtual ai::output_id_t addOutputGenerator(struct ai::OutputFormat &format)=0;
	virtual void setInput(ai::input_id_t id, ai::data_t *data)=0;
	virtual void getOutput(ai::output_id_t id, ai::data_t *data)=0;
	virtual void iterate()=0;
};

#endif /* AI_HH_ */
