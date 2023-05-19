#define ZERO_EXCEPTION_ID 0
#define INVALID_OPERATION_CODE_ID 1

static void zeroDivision();
static void invalidOperationCode();

void exceptionDispatcher(int exception) {
	switch(exception){
		case ZERO_EXCEPTION_ID:
			zeroDivision();
			break;
		case INVALID_OPERATION_CODE_ID:
			invalidOperationCode();
			break;
		default:
			return;
	}
}

static void zeroDivision() {
	ncPrint("Error - divide by 0 Exception");
}

static void invalidOperationCode(){
	ncPrint("Error - invalid operation code Exception");
}
