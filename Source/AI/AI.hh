#ifndef AI_HH_
#define AI_HH_

#include <string>

namespace ai {

	typedef unsigned char input_id_t;
	typedef unsigned char output_id_t;
	enum data_type_t {
		FLOAT,
	};
	enum input_type_t {
		PERCEPTION,
		FEELING,
	};
	enum output_type_t {
		MOTORIC,
	};

	struct InputFormat {
		input_type_t inputType;
		data_type_t dataType;
		int dataLen;
	};

	struct OutputFormat {
		output_type_t outputType;
		data_type_t dataType;
		int dataLen;
	};
}

class AI {
public:
	AI();
	virtual ~AI();

	virtual const std::string getName()=0;

	virtual ai::input_id_t addInputListener(struct ai::InputFormat &format)=0;
	virtual ai::output_id_t addOutputGenerator(struct ai::OutputFormat &format)=0;
};

#endif /* AI_HH_ */
