#include "stdio.h"
#include "mosquitto.h"
#include "assert.h"
#include "stdint.h"
#include "stddef.h"

#ifndef CERT_PATH
#define CERT_PATH
#endif


extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {

	bool clean_session = true;
	struct mosquitto *mosq = NULL;
	mosquitto_lib_init();
	void *data_1=(void *)data;
	mosq = mosquitto_new(NULL, clean_session, data_1);
	mosquitto_destroy(mosq);
	mosquitto_lib_cleanup();
	return 0;
}
