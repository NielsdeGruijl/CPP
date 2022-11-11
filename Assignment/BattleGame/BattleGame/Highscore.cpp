#include "Highscores.h"
#include <algorithm>

Highscores::Highscores(std::string identifier) :
	GameObject(identifier)
{
}

Highscores::~Highscores() {}

void Highscores::update() {}

void Highscores::render(sf::RenderWindow& window) {}

void Highscores::AddHS(const int HS)
{
	highScores.push_back(HS);
}

void Highscores::WriteHS(const int HS)
{
	ReadHS();

	if (std::find(scores.begin(), scores.end(), HS) == scores.end())
	{
		scores.push_back(HS);
	}
	else {
		std::cout << "no new scores found\n";
	}

	std::ofstream os("HighScores.cmgt");

	if (os.is_open())
	{
		if (scores.size() > 0)
		{
			for (int i = 0; i < scores.size(); i++)
			{
				os << scores[i] << "\n";
			}
		}
		os.close();
	}

	else { printf("couldn't open file"); }
}

void Highscores::ReadHS()
{
	std::ifstream is("HighScores.cmgt");
	std::string output;

	if (is.is_open())
	{
		while (std::getline(is, output))
		{
			if (std::find(scores.begin(), scores.end(), std::stoi(output)) == scores.end())
			{
				scores.push_back(std::stoi(output));
			}
		}
		is.close();
	}
	else { printf("your code is shit cunt"); }

	std::sort(scores.begin(), scores.end(), std::greater<int>());

	for (int i = 0; i < scores.size() && i < 5; i++)
	{
		if (std::find(topFive.begin(), topFive.end(), scores[i]) == topFive.end())
		{
			topFive.push_back(scores[i]);
		}
	}

	std::sort(topFive.begin(), topFive.end(), std::greater<int>());
}

void Highscores::ClearHS() 
{
	std::ofstream os("HighScores.cmgt.", std::ofstream::trunc);

	highScores.clear();
	scores.clear();
	topFive.clear();
}