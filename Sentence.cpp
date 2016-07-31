#include "Sentence.h"
#include "random_string.h"
#include <iterator>
#include <vector>
#include <string>

Sentence::Sentence(int _size, double _mutate_chance) :sentence(random_string(_size)), mutate_chance(_mutate_chance), fitness(0)
{}

Sentence::Sentence(std::string _sentence, double _mutate_chance) : sentence(_sentence), mutate_chance(_mutate_chance), fitness(0)
{}

void Sentence::mutate()
{
	double mutate_threshold;

	for (char &c : sentence)
	{
		mutate_threshold = ((double)rand() / RAND_MAX);
		if (mutate_chance >= mutate_threshold)
			c = *(random_string(1).c_str());
	}
}

void Sentence::calc_fitness(std::string target)
{
	fitness = 0;
	for (int i = 0; i < sentence.length(); i++)
	{
		if (sentence[i] == target[i])
		{
			fitness += 1.0 / sentence.length();
		}
	}

}

double Sentence::get_fitness()
{
	return fitness;
}

std::string Sentence::text()
{
	return sentence;
}

bool Sentence::operator>(Sentence & rhs)
{
	return (this->fitness > rhs.fitness);
}

bool Sentence::operator<(Sentence & rhs)
{
	return (this->fitness < rhs.fitness);
}

void Sentence::kill()
{
	sentence = "";
}

Sentence child(std::vector<Sentence>::const_iterator mother, std::vector<Sentence>::const_iterator father)
{
	Sentence child = Sentence(*mother);


	for (int i = 0; i < child.sentence.length(); i++)
		child.sentence[i] = (rand() % 2) ? father->sentence[i] : mother->sentence[i] ;
	
	child.mutate();

	return child;
}
