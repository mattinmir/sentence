#include "Sentence.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <cstdlib>
#include <iterator>
#include <time.h>

int main()
{
	srand(time(NULL));

	int population = 10;
	std::string target = "he";
	double mutate_chance = 0.01;
	int len = target.length();
	std::vector<Sentence> sentences;

	for (unsigned int i = 0; i < population; i++)
		sentences.push_back(Sentence(len, mutate_chance));

	for (auto &s : sentences)
		s.calc_fitness(target);

	std::sort(sentences.begin(), sentences.end(), std::greater<>());

	do
	{
		sentences.erase(sentences.begin() + (population / 2) , sentences.end());

		std::vector<Sentence>::const_iterator mother = sentences.begin();
		std::vector<Sentence>::const_iterator father = sentences.begin()+1;
		for (int i = 0; i < population/2; i++)
		{
			sentences.push_back(child(mother, father));
			mother += 2;
			father += 2;
		}
		for (auto &s : sentences)
			s.calc_fitness(target);

		std::sort(sentences.begin(), sentences.end());

	} while (sentences.begin()->text() != target);
	
}
