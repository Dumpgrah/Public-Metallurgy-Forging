ref ForgingSettings m_ForgingSettings
class ForgingSettings
{ 
	protected static string DirPATH = "$profile:Metallurgy&Forging";
	protected static string ForgingConfig = DirPATH + "\\ForgingSettings.json";
	
	//Default Values
	string ConfigVersion = "1";
	
	string I ="Forging Settings";
	int SmithMetalTemp=700;
	int SmithNuggetDmg =3;
	int SmithNuggetTime=15;
	int SmithNailsTime=24;
	int SmithBarDmg =6;
	int SmithBarTime=36;
	int SmithIngotDmg =8;
	int SmithIngotTime=64;
	int CastNuggetConsumedNail=20;
	int CastIronNailProduced=3;
	int ImpureNuggetConsumedNail=18;
	int ImpureIronNialProduced=5;
	int PureNuggerConsumedNail=16;
	int PureIronNailProduced=7;
	string I2 = "Casting Setting";
	int CastMetalTime=30;
	int TempToPourMetal=1538;
	int PourIronNugget=10;
	int CastNuggetsMade=2;
	int ImpureNuggetsMade=2;
	int PureNuggetMade=2;
	int PourIronBars=25;
	int CastBarMade=1;
	int ImpureBarMade=1;
	int PureBarMade=1;
	int PourIronIngot=40;
	int PourAnvilMetal=50;
	int RequiredQuantityToCastAnvil=49;
	
	void ForgingSettings()
	{
		
	}
	
	// Load config file or create default file if config doesn't exsit
	void Load(){
		if (FileExist(ForgingConfig)) //If config exist load File
		{
	        JsonFileLoader<ForgingSettings>.JsonLoadFile(ForgingConfig, this);
			if ( ConfigVersion != "1")
			{
				ConfigVersion = "1";
				
				//CrudeSmeltIronSmeltTemperature =1550;

				
				
				JsonFileLoader<ForgingSettings>.JsonSaveFile(ForgingConfig, this);
			}
		}

		else//File does not exist create file
		{
			if (!FileExist(DirPATH))
			{
				MakeDirectory(DirPATH);
			}
			JsonFileLoader<ForgingSettings>.JsonSaveFile(ForgingConfig, this);
		}

	}
};

//Helper function to return Config
static ref ForgingSettings GetForgingSettings()
{
	if (!m_ForgingSettings)
	{
		m_ForgingSettings = new ForgingSettings;
		m_ForgingSettings.Load();
	}
	return m_ForgingSettings;
};