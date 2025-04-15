#pragma once
#include "../Machine.h"

#include <iostream>
#include <string>
#include <queue>
#include <fstream>

using std::string;
using std::fstream;



class MobQueue {
public:
	MobQueue();
	~MobQueue();

	void loadFromLevelFile(std::string file);
	Machine getMachineType(std::string machineAbrv);

private:
	std::queue<string> mQueue;
	
};