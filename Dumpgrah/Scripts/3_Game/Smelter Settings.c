ref SmelterSettings m_SmelterSettings
class SmelterSettings
{ 
	protected static string DirPATH = "$profile:Metallurgy&Forging";
	protected static string SmeltingConfig = DirPATH + "\\SmelterSettings.json";
	
	//Default Values
	string ConfigVersion = "1";
	
	string I0 ="Crude Smelter Setting";
	int CrudeSmeltIronSmeltTemperature =1550;
	int CrudeTimeToSmeltIron = 1350;
	int CrudeSmeltIronEfficiencyMin =45;
	int CrudeSmeltIronEfficiencyMax = 60;
	string I1  ="Crude Smelter Setting Conti";
	int CrudeTimeToSmeltPureIron = 1350;
	int CrudeSmeltPureIronEfficiencyMin = 75;
	int CrudeSmeltPureIronEfficiencyMax = 95;
	int CrudeSmelterTimeToSmeltCharcoal = 187;
	int CrudeSmelterHeatingRate = 8;
	int CrudeSmelterCoolingRate = 15;
	int CrudeCureClayItems = 187;
	string I2 ="This Does Nothing Ignore me";
	string I3 ="Improved Smelter Setting";
	int ImprovedSmeltIronSmeltTemperature =1550;
	int ImprovedTimeToSmeltIron = 1300;
	int ImprovedSmeltIronEfficiencyMin =65;
	int ImprovedSmeltIronEfficiencyMax = 80;
	string I4 ="Improved Smelter Setting Conti";
	int ImprovedTimeToSmeltPureIron = 1350;
	int ImprovedSmeltPureIronEfficiencyMin = 85;
	int ImprovedSmeltPureIronEfficiencyMax = 99;
	int ImprovedSmelterTimeToSmeltCharcoal = 187;
	int ImprovedSmelterHeatingRate = 12;
	int ImprovedSmelterCoolingRate = 7;
	int ImprovedCureClayItems = 187;
	
	void SmelterSettings()
	{
		
	}
	
	// Load config file or create default file if config doesn't exsit
	void Load(){
		if (FileExist(SmeltingConfig)) //If config exist load File
		{
	        JsonFileLoader<SmelterSettings>.JsonLoadFile(SmeltingConfig, this);
			if ( ConfigVersion != "1")
			{
				ConfigVersion = "1";
				
				//CrudeSmeltIronSmeltTemperature =1550;

				
				
				JsonFileLoader<SmelterSettings>.JsonSaveFile(SmeltingConfig, this);
			}
		}

		else//File does not exist create file
		{
			if (!FileExist(DirPATH))
			{
				MakeDirectory(DirPATH);
			}
			JsonFileLoader<SmelterSettings>.JsonSaveFile(SmeltingConfig, this);
		}

	}
};

//Helper function to return Config
static ref SmelterSettings GetSmelterSettings()
{
	if (!m_SmelterSettings)
	{
		m_SmelterSettings = new SmelterSettings;
		m_SmelterSettings.Load();
	}
	return m_SmelterSettings;
};