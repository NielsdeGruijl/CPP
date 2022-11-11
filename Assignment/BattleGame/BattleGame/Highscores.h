#pragma once
#include <iostream>
#include <fstream>
#include "gameObject.hpp"

class Highscores : public GameObject
{
	private:
		std::vector<int> highScores;
		std::vector<int> scores;
	public:
		std::vector<int> topFive;
	public:
		Highscores(std::string identifier);
		~Highscores();

		void update() override;
		void render(sf::RenderWindow& window) override;

		void AddHS(const int HS);
		void WriteHS(const int HS);
		void ReadHS();
		void ClearHS();
};