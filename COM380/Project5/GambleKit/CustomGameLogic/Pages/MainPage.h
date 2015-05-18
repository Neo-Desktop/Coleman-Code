#pragma once

#include "..\CustomGame.h"

class MainPage :
	public GkGamePage
{
public:

	static const int ReelItem_Space		= 0,
					 ReelItem_Cherry	= 1,
					 ReelItem_Grape		= 2,
					 ReelItem_Lemon		= 3,
					 ReelItem_7			= 4,
					 ReelItem_Bar1		= 5,
					 ReelItem_Bar2		= 6,
					 ReelItem_Bar3		= 7;


	GkGameClickButton *btnStart, *btnBet, *btnLines;

	GkGameText *textCredits, *textWinning, *textBet, *textLines;

	GkGameAnimation *lineAnimations[5];

	GkGameReels *reels;

	GkGameReelsCombinationGenerator *combinationsGenerator;
	GkGameWinningsModel *winningsModel;
	GkGameWinningsAnalyzer *winningsAnalyzer;

	int bet, lines, winning, credits;

	GkSoundSource *sndReels, *sndReelStop, *sndBlip;


	MainPage(CustomGame *game);
	~MainPage(void);

	void Process(GkGame *game);
};

