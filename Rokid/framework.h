#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include "Rokid.h"

extern "C" _declspec(dllexport) void* Instantiate() {
	return (void*) new Rokid();
}

extern "C" _declspec(dllexport) bool Start(Rokid * t) {
	return t->start();
}

extern "C" _declspec(dllexport) bool Stop(Rokid * t) {
	return t->stop();
}

extern "C" _declspec(dllexport) bool IsRunning(Rokid * t) {
	return t->is_running();
}

extern "C" _declspec(dllexport) double* GetAngles(Rokid * t) {
	static double arr[3] = { 0, 0, 0 };
	t->get_gyro_angles_since_last_call(arr[0], arr[1], arr[2]);
	return arr;
}