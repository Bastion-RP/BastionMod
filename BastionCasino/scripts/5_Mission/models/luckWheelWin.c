class LuckyWheelWin
{
    private int luckyDegree;
    private int winAmmount;

    void LuckyWheelWin(int degree, int ammount) {
        luckyDegree = degree * 10;
        winAmmount = ammount;
    }

    int GetLuckyDegree() {
        return luckyDegree;
    }

    int GetWinAmmount() {
        return winAmmount;
    }

};