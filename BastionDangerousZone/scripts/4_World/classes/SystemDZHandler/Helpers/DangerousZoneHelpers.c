static ref DZLogger g_DZLogger;
static ref DZLogger GetDZLogger(){
	if (!g_DZLogger) {
		g_DZLogger = new ref DZLogger();
	}
	return g_DZLogger;
}

static ref DZManager m_DZManager;
static ref DZManager GetDZManager() {
	if ( !m_DZManager ) {
		m_DZManager = new ref DZManager;
	}
	return m_DZManager;
}

static ref RadiationAreaSettings GetRadConfig()	{
	return GetDZManager().m_ActiveRadiationAreaSettings;
}

static ref RadiationLocations GetRadConfigClient()	{
	return GetDZManager().m_RadZoneLocations;
}

static ref HazardAreaSettings GetHazardConfig()	{
	return GetDZManager().m_ActiveHazardAreaSettings;
}

static ref InfectedAreaSettings GetInfectedConfig()	{
	return GetDZManager().m_ActiveInfectedAreaSettings;
}

static ref DZCrateSystemAreaSettings GetCrateSystemConfig(){
	return GetDZManager().m_ActiveDZCrateSystemSettings;
}

static string GetDateTimeStamp() {
		int year, month, day, hour, minute, second;
		string y, m, d, h, n, s, timeStamp;
		GetHourMinuteSecondUTC(hour, minute, second);
		GetYearMonthDayUTC(year, month, day);
		y = year.ToString().Trim();
		m = month.ToString().Trim();
		d = day.ToString().Trim();
		h = hour.ToString().Trim();
		n = minute.ToString().Trim();
		s = second.ToString().Trim();
		if (m.Length() == 1) { m = "0" + m; }
		if (d.Length() == 1) { d = "0" + d; }
		if (h.Length() == 1) { h = "0" + h; }
		if (n.Length() == 1) { n = "0" + n; }
		if (s.Length() == 1) { s = "0" + s; }
		timeStamp = string.Format("%1%2%3%4%5%6", y, m, d, h, n, s);
		return timeStamp;
	}
