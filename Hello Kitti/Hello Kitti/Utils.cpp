#include "stdafx.h"
#include "Utils.h"

string stringPhotoNumber(int value) {

	string stringValue = to_string(value);
	int nb0 = 10 - stringValue.length();
	string newValue = string(nb0, '0').append(stringValue);

	return newValue;
}