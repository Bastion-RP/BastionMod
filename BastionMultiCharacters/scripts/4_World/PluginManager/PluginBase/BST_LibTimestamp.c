class BST_LibTimestamp : PluginBase {
    private static const int STARTING_YEAR = 2020; // DO NOT CHANGE THIS EVER!
    private static const int HOURS_IN_DAY = 24;
    private static const int MINUTES_IN_HOUR = 60;

    private ref map<int, int> _mapGregorianCalender;

    void BST_LibTimestamp() {
        _mapGregorianCalender = new map<int, int>();

        _mapGregorianCalender.Insert(1, 31);
        _mapGregorianCalender.Insert(2, 28);
        _mapGregorianCalender.Insert(3, 31);
        _mapGregorianCalender.Insert(4, 30);
        _mapGregorianCalender.Insert(5, 31);
        _mapGregorianCalender.Insert(6, 30);
        _mapGregorianCalender.Insert(7, 31);
        _mapGregorianCalender.Insert(8, 31);
        _mapGregorianCalender.Insert(9, 30);
        _mapGregorianCalender.Insert(10, 31);
        _mapGregorianCalender.Insert(11, 30);
        _mapGregorianCalender.Insert(12, 31);
    }

    string GetHourTimestampFormatted() {
        int day, month, year, hour, minute, second;
        string strDay, strMonth, strHour, strMinute, strSecond;

        GetHourMinuteSecondUTC(hour, minute, second);
        GetYearMonthDayUTC(year, month, day);

        // Set leading zero
        if (day < 10) {
            strDay = "0" + day;
        } else {
            strDay = "" + day;
        }
        // Set leading zero
        if (month < 10) {
            strMonth = "0" + month;
        } else {
            strMonth = "" + month;
        }
        // Set leading zero
        if (hour < 10) {
            strHour = "0" + hour;
        } else {
            strHour = "" + hour;
        }
        // Set leading zero
        if (minute < 10) {
            strMinute = "0" + minute;
        } else {
            strMinute = "" + minute;
        }
        // Set leading zero
        if (second < 10) {
            strSecond = "0" + second;
        } else {
            strSecond = "" + second;
        }

        return "[" + strMonth + "/" + strDay + "/" + year + "][" + strHour + ":" + strMinute + ":" + strSecond + "]";
    }

    int GetCurrentTimestamp() {
        // Get current time, ignoring seconds. Have to have it as an out var though.
        int month, day, year, hour, minute, second, i, daysPassedTotal, minutesTimestamp;

        daysPassedTotal = 0;

        GetYearMonthDayUTC(year, month, day);
        GetHourMinuteSecondUTC(hour, minute, second);

        // Get days passed in years prior to current
        for (i = (year - 1); i >= STARTING_YEAR; i--) {
            // Account for leap year
            if ((i % 4) == 0) {
                daysPassedTotal += 366;
            } else {
                daysPassedTotal += 365;
            }
        }
        // Get days passed current year
        for (i = 1; i < month; i++) {

            if (_mapGregorianCalender.Contains(i)) {
                int daysInMonth = _mapGregorianCalender.Get(i);

                // Account for leap year
                if (i == 2 && (year % 4) == 0) {
                    daysInMonth += 1;
                }
                daysPassedTotal += daysInMonth;
            }
        }
        if (second > 30) {
            minute += 1;
        }
        daysPassedTotal += (day - 1);
        minutesTimestamp = ((daysPassedTotal * HOURS_IN_DAY * MINUTES_IN_HOUR) + (hour * MINUTES_IN_HOUR) + minute);
        return minutesTimestamp;
    }

    map<int, int> GetGregorianCalender() { return _mapGregorianCalender; }
}

BST_LibTimestamp GetBSTLibTimestamp() {
    return BST_LibTimestamp.Cast(GetPlugin(BST_LibTimestamp));
}