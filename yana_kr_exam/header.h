#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

struct birth {
	int date;
	int month;
	int year;
	birth(int d, int m, int y) : date(d), month(m), year(y) {}
};

struct memb {
	std::string name;
	birth dmy;
	int age;
	int crs;
	std::string MAS;
	memb (std::string n, birth d, int a = 0, int c = 0, std::string M = "") : name(n), dmy(d), age(a), crs(c), MAS(M) {}
};

class TPerson {
	friend std::istream& operator>>(std::istream& input, TPerson& obj); // перегрузка оператора ввода
private:
	int number;
	std::vector<memb> vec_membs;
	std::pair<int, int> Date(memb& temp);
public:
	TPerson() { number = 0; }
	~TPerson() = default;
	void Curious();
	void bubble_sort_age();
};