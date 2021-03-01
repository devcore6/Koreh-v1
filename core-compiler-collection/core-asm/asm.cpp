#include <asm.h>

std::vector<std::pair<uint64_t, std::string>> labels;

void addlabel(std::string label) {
	std::pair<uint64_t, std::string> pair;
	pair.first = binarydata.size();
	pair.second = label;
	labels.push_back(pair);
}

uint64_t getaddress(std::string label) {
	for(size_t i = 0; i < labels.size(); i++) if(labels[i].second == label) return labels[i].first;
	return 0xFFFFFFFFFFFFFFFF;
}

std::vector<std::pair<size_t, std::string>> scheduled;

void schedulereplace(size_t pos, std::string label) {
	std::pair<uint64_t, std::string> pair;
	pair.first = pos;
	pair.second = label;
	labels.push_back(pair);
}

void doreplaces() {
	for(size_t i = 0; i < scheduled.size(); i++) {
		uint64_t val = getaddress(scheduled[i].second);
		if(mode == 32) for(size_t j = 0; j < 4; j++) binarydata[scheduled[i].first + j] = (unsigned char)((val & ((uint64_t)0xFF << (4 * (3 - j)))) >> (4 * (3 - j)));
		else for(size_t j = 0; j < 8; j++) binarydata[scheduled[i].first + j] = (unsigned char)((val & ((uint64_t)0xFF << (8 * (7 - j)))) >> (8 * (7 - j)));
	}
}