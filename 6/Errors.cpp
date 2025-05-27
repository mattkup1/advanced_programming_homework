#include "Clock.h"
#include "Account.h"

// From Clock.h
const char* HOUR_ERROR = "Invalid time - number of hours is not valid";
const char* MINUTE_ERROR = "Invalid time - number of minutes is not valid";
const char* SECOND_ERROR = "Invalid time - number of seconds is not valid";

// From Account.h
const char* ACC_NUM_EX        = "ERROR: account number must be positive";
const char* ACC_CODE_EX       = "ERROR: code must be of 4 digits";
const char* EMAIL_AT_EX       = "ERROR: email must contain @";
const char* DOMAIN_EX         = "ERROR: email must end with .com or .co.il";
const char* WITHDRAW_LIMIT_EX = "ERROR: cannot withdraw more than 2500 NIS";
const char* DEPOSIT_LIMIT_EX  = "ERROR: cannot deposit more than 10000 NIS";
const char* CREDIT_LIMIT_EX   = "ERROR: cannot have less than 6000 NIS";

