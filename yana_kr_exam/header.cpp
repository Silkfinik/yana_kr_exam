#include "header.h"
#include <unordered_map>

std::string normal_str(std::string str) {
	std::string res;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == ' ') {
			res += str[i];
			while (str[i] == ' ') {
				i++;
			}
		}
	res += str[i];
	return res;
	}
}

std::string name_parse(std::string name) {
	std::string name1;
	int i = 0;
	while (!(name[i] > 47 && name[i] < 58)) {
		name1 += name[i];
		i++;
	}
	return name1.substr(0, name1.length() - 1); // убираем пробел в конце
}

int mtoi(std::string str) {
	std::unordered_map<std::string, int> monthMap = {
		{"january", 1},
		{"february", 2},
		{"march", 3},
		{"april", 4},
		{"may", 5},
		{"june", 6},
		{"july", 7},
		{"august", 8},
		{"september", 9},
		{"october", 10},
		{"november", 11},
		{"december", 12}
	};
	return monthMap[str];
}

std::istream& operator>>(std::istream& input, TPerson& obj) {
	std::string name;
	std::ifstream input_file("Name.txt"); // открытие файла
	if (input_file.is_open()) {
		std::string line;
		while (std::getline(input_file, line)) {
			int date, month, year;
			line = normal_str(line);
			std::string name = name_parse(line);
			int first_num = line.find_first_of("0123456789");
			date = std::stoi(line.substr(first_num, 2));
			line = line.substr(first_num + std::to_string(date).length() + 1);
			month = mtoi(line.substr(0, line.find(" ")));
			year = std::stoi(line.substr(line.find(" ") + 1, 4));
			obj.vec_membs.push_back(memb(name, birth(date, month, year)));
			obj.number++;
		}
	}
	else {
		std::cout << "File not found!" << std::endl;
	}
	input_file.close();
	return input;
}

std::pair<int, int> TPerson::Date(memb temp) {
	temp.age = 2024 - temp.dmy.year;
	std::pair<int, int> res;
	std::string temp_str;
	if (temp.dmy.date < 10) {
		temp_str = "0" + std::to_string(temp.dmy.date);
	}
	else {
		temp_str = std::to_string(temp.dmy.date);
	}
	if (temp.dmy.month < 10) {
		temp_str += "0" + std::to_string(temp.dmy.month);
	}
	else {
		temp_str += std::to_string(temp.dmy.month);
	}
	temp_str += std::to_string(temp.dmy.year);
	res.first = std::stoi(temp_str);
	while (!temp_str.empty()) {
		res.second += *temp_str.end() - 48;
		temp_str.pop_back();
	}
	return res;
}

int TPerson::Curious(std::pair<int, int> temp) {
	int c, d, e, crs;
	std::string temp_str;
	temp_str = std::to_string(temp.second);
	while (!temp_str.empty()) {
		c += *temp_str.end() - 48;
		temp_str.pop_back();
	}
	d = temp.second - std::to_string(temp.second)[0] - 48;
	temp_str = std::to_string(d);
	while (!temp_str.empty()) {
		e += *temp_str.end() - 48;
		temp_str.pop_back();
	}
	crs = std::stoi(std::to_string(temp.second) + std::to_string(c) + std::to_string(d) + std::to_string(e));
	
}
