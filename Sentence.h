#pragma once
#include <string>
#include <iterator>
#include <vector>

class Sentence
{
public:
	Sentence(int _size, double _mutate_chance);
	Sentence(std::string _sentence, double _mutate_chance);

	void mutate();

	void calc_fitness(std::string target);

	double get_fitness();

	std::string text();

	bool operator>(Sentence &rhs);

	bool operator<(Sentence &rhs);

	void kill();

	friend Sentence child(std::vector<Sentence>::const_iterator mother, std::vector<Sentence>::const_iterator father);

private:
	std::string sentence;
	double mutate_chance;
	double fitness;
};