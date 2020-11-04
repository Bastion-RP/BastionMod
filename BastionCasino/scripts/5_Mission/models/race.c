class Race{

    ref array<ref Rat> rats;
    ref Rat winRat;
	float goalLine;
	float startPos;
	bool isAnimationFinished = false;

    void Race(int ratCount,float startPosParam, float goalLineParam, int  maxWinQouta) {
        rats = new array<ref Rat>;
        for(int x; x < ratCount; x++) {
            ref Rat rat = new Rat(startPosParam, x + 1, maxWinQouta);
			rats.Insert(rat);
        }
		goalLine = goalLineParam;
		startPos = startPosParam;
    }

    void CreateRaceResults() {
		if (!IsServerCasino()){
			return;
		}
		
        bool isLastStep = false;

        while (!isLastStep) {
            isLastStep = true;
			DebugMessageCasino("Add new stepp");
            foreach(int i, Rat rat: rats) {
                int newPos = rat.GetLastPosition() + Math.RandomIntInclusive(1, 10);

                if (DAYZ_CASINO_DEBUG && i == 0) {
                    newPos =  rat.GetLastPosition() + 10;
                }
				
				if (goalLine <= newPos && goalLine + DAYZ_CASINO_ANIMATE_STEPS_AFTER_GOAL_RATE_RACE > newPos) {
                    if (null == winRat) {
						DebugMessageCasino("Has win rat");
                        winRat = rat;
                    }
                    rat.AddStep(newPos);
					isLastStep = false;
                } else if(goalLine + DAYZ_CASINO_ANIMATE_STEPS_AFTER_GOAL_RATE_RACE < newPos){
					isLastStep = true;
				} else {
                    rat.AddStep(newPos);
                    isLastStep = false;
                }
            }
        }
		DebugMessageCasino("race calculated");
    }
	
	void SetImages(array<ImageWidget> images) {
		if (IsServerCasino()) {
			return;
		}
		foreach(int index, ImageWidget image: images) {
			if (rats.IsValidIndex(index)) {
				Rat rat = rats.Get(index);
				rat.SetImageWidget(image);
			}
		}
	}
	
	void AnimateStep(int step) {
		bool isFinished = true;
		foreach(Rat rat: rats) {
			rat.GoToStep(step, goalLine);
			isAnimationFinished = isFinished && rat.isAnimationFinished;
			
			if (rat.hasPassGoal && rat.number == winRat.number) {
				winRat.hasPassGoal = true;
			}
		}
		
		DebugMessageCasino("Animation status race " + isAnimationFinished);
	}
	
	
};