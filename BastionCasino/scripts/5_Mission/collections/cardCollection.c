class CardCollection {
	
	private ref Card cardArray[52];

	void CardCollection() {
    	cardArray[0] = new Card(2, "BastionCasino/data/cards/herz_zwei.edds");
    	cardArray[1] = new Card(3, "BastionCasino/data/cards/herz_drei.edds");
    	cardArray[2] = new Card(4, "BastionCasino/data/cards/herz_vier.edds");
    	cardArray[3] = new Card(5, "BastionCasino/data/cards/herz_fuenf.edds");
    	cardArray[4] = new Card(6, "BastionCasino/data/cards/herz_sechs.edds");
    	cardArray[5] = new Card(7, "BastionCasino/data/cards/herz_sieben.edds");
    	cardArray[6] = new Card(8, "BastionCasino/data/cards/herz_acht.edds");
    	cardArray[7] = new Card(9, "BastionCasino/data/cards/herz_neun.edds");
    	cardArray[8] = new Card(10, "BastionCasino/data/cards/herz_zehn.edds");
    	cardArray[9] = new Card(10, "BastionCasino/data/cards/herz_bauer.edds");
    	cardArray[10] = new Card(10, "BastionCasino/data/cards/herz_dame.edds");
    	cardArray[11] = new Card(10, "BastionCasino/data/cards/herz_koenig.edds");
    	cardArray[12] = new Card(11, "BastionCasino/data/cards/herz_ass.edds", true);

    	cardArray[14] = new Card(2,  "BastionCasino/data/cards/karo_zwei.edds");
    	cardArray[15] = new Card(3,  "BastionCasino/data/cards/karo_drei.edds");
    	cardArray[16] = new Card(4,  "BastionCasino/data/cards/karo_vier.edds");
    	cardArray[17] = new Card(5,  "BastionCasino/data/cards/karo_fuenf.edds");
    	cardArray[18] = new Card(6,  "BastionCasino/data/cards/karo_sechs.edds");
    	cardArray[19] = new Card(7,  "BastionCasino/data/cards/karo_sieben.edds");
    	cardArray[20] = new Card(8,  "BastionCasino/data/cards/karo_acht.edds");
    	cardArray[21] = new Card(9,  "BastionCasino/data/cards/karo_neun.edds");
    	cardArray[22] = new Card(10, "BastionCasino/data/cards/karo_zehn.edds");
    	cardArray[23] = new Card(10, "BastionCasino/data/cards/karo_bauer.edds");
    	cardArray[24] = new Card(10, "BastionCasino/data/cards/karo_dame.edds");
    	cardArray[25] = new Card(10, "BastionCasino/data/cards/karo_koenig.edds");
    	cardArray[26] = new Card(11, "BastionCasino/data/cards/karo_ass.edds", true);

    	cardArray[27] = new Card(2,  "BastionCasino/data/cards/kreuz_zwei.edds");
    	cardArray[28] = new Card(3,  "BastionCasino/data/cards/kreuz_drei.edds");
    	cardArray[29] = new Card(4,  "BastionCasino/data/cards/kreuz_vier.edds");
    	cardArray[30] = new Card(5,  "BastionCasino/data/cards/kreuz_fuenf.edds");
    	cardArray[31] = new Card(6,  "BastionCasino/data/cards/kreuz_sechs.edds");
    	cardArray[32] = new Card(7,  "BastionCasino/data/cards/kreuz_sieben.edds");
    	cardArray[33] = new Card(8,  "BastionCasino/data/cards/kreuz_acht.edds");
    	cardArray[34] = new Card(9,  "BastionCasino/data/cards/kreuz_neun.edds");
    	cardArray[35] = new Card(10, "BastionCasino/data/cards/kreuz_zehn.edds");
    	cardArray[36] = new Card(10, "BastionCasino/data/cards/kreuz_bauer.edds");
    	cardArray[37] = new Card(10, "BastionCasino/data/cards/kreuz_dame.edds");
    	cardArray[38] = new Card(10, "BastionCasino/data/cards/kreuz_koenig.edds");
    	cardArray[39] = new Card(11, "BastionCasino/data/cards/kreuz_ass.edds", true);

    	cardArray[40] = new Card(2,  "BastionCasino/data/cards/pik_zwei.edds");
    	cardArray[41] = new Card(3,  "BastionCasino/data/cards/pik_drei.edds");
    	cardArray[42] = new Card(4,  "BastionCasino/data/cards/pik_vier.edds");
    	cardArray[43] = new Card(5,  "BastionCasino/data/cards/pik_fuenf.edds");
    	cardArray[44] = new Card(6,  "BastionCasino/data/cards/pik_sechs.edds");
    	cardArray[45] = new Card(7,  "BastionCasino/data/cards/pik_sieben.edds");
    	cardArray[46] = new Card(8,  "BastionCasino/data/cards/pik_acht.edds");
    	cardArray[47] = new Card(9,  "BastionCasino/data/cards/pik_neun.edds");
    	cardArray[48] = new Card(10, "BastionCasino/data/cards/pik_zehn.edds");
    	cardArray[49] = new Card(10, "BastionCasino/data/cards/pik_bauer.edds");
    	cardArray[50] = new Card(10, "BastionCasino/data/cards/pik_dame.edds");
    	cardArray[51] = new Card(10, "BastionCasino/data/cards/pik_koenig.edds");
    	cardArray[13] = new Card(11, "BastionCasino/data/cards/pik_ass.edds", true);
	}

	int GetRandomCardIndex(TIntArray cardAllreadyUsed) {
	    int cardNumber = Math.RandomIntInclusive(0, 51);
				
		while(true) {
			bool hasNewCard = true;
			foreach(int index, int usedCardNumber: cardAllreadyUsed){
				if (cardNumber != usedCardNumber) {
					continue;
				}
				cardNumber = Math.RandomIntInclusive(0, 51);
				hasNewCard = false;
				break;
			}
			
			if (hasNewCard) {
				break;
			}
		}

		DebugMessageCasino("card number return" + cardNumber);
		return cardNumber;
	}
	
	Card GetCardByIndex(int indexValue) {
		return cardArray[indexValue];
	}

}