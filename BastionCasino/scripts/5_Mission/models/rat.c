class Rat {
    ref array <int> positions;
    float quote;
    int number
	ImageWidget ratImage;
	bool isAnimationFinished = false;
	bool hasPassGoal = false;
	float yPos;

    void Rat(int startPos, int startNumber, int maxWinQouta) {
        positions = new array<int>;
        positions.Insert(startPos);
        quote = Math.RandomIntInclusive(10, maxWinQouta * 10) / 10;
        number = startNumber;
    }

    int GetLastPosition() {
        return positions.Get(positions.Count() - 1);
    }

    void AddStep(int stepPos) {
        this.positions.Insert(stepPos);
    }
	
	void SetImageWidget(ImageWidget image) {
		ratImage = image;
		float x = 0;
		image.GetPos(x, yPos);
	}
	
	void GoToStep(int index, float goalLine) {
		if (ratImage) {
			if (positions.IsValidIndex(index)) {
				int pos = positions.Get(index);
				
				if (goalLine < pos) {
					DebugMessageCasino("Has passed Goal " + number);
                	hasPassGoal = true;
				}

				ratImage.SetPos(pos, yPos);
			} else {
				isAnimationFinished = true;
			}
		} else {
			DebugMessageCasino("Has no image");
		}
	}
};