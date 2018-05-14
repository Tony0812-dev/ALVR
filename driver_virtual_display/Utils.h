#pragma once

#include <Windows.h>
#include <stdint.h>
#include <string>

#include "openvr_driver.h"

// Get elapsed time in us from Unix Epoch
inline uint64_t GetTimestampUs() {
	FILETIME ft;
	GetSystemTimeAsFileTime(&ft);

	uint64_t Current = (((uint64_t)ft.dwHighDateTime) << 32) | ft.dwLowDateTime;
	// Convert to Unix Epoch
	Current -= 116444736000000000LL;
	Current /= 10;

	return Current;
}

inline std::string DumpMatrix(const float *m) {
	char buf[200];
	snprintf(buf, sizeof(buf),
		"%.3f %.3f %.3f %.3f\n"
		"%.3f %.3f %.3f %.3f\n"
		"%.3f %.3f %.3f %.3f\n"
		"%.3f %.3f %.3f %.3f\n"
		, m[0], m[4], m[8], m[12]
		, m[1], m[5], m[9], m[13]
		, m[2], m[6], m[10], m[14]
		, m[3], m[7], m[11], m[15]);
	return std::string(buf);
}