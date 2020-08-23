modded class BleedingSourcesManagerServer : BleedingSourcesManagerBase {
    void BSTMCLoadBleedingSource(BST_MCSaveBleeding bleeding) {
		array<int> arrBleedingTimes = bleeding.GetActiveTimes();
		int activeBits = bleeding.GetBits();
		int bitOffset = 0;
		int bleedsAdded = 0;

		for (int i = 0; i < BIT_INT_SIZE; i++) {
			int bit = 1 << bitOffset;
			
			if ((bit & activeBits) != 0 && CanAddBleedingSource(bit)) {
				AddBleedingSource(bit);
				
				if (bleedsAdded < arrBleedingTimes.Count()) {
					SetBleedingSourceActiveTime(bit, arrBleedingTimes[bleedsAdded]);
				}
				bleedsAdded++;
			}
			bitOffset++;
		}
    }
}