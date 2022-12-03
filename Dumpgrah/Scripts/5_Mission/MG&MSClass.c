modded class MissionGameplay extends MissionBase
{
	override void OnMissionStart()
	{
		super.OnMissionStart();
		GetRPCManager().AddRPC( "Dumpgrah_SS", "RPCSmeltingSettings", this, SingeplayerExecutionType.Both );
		GetRPCManager().AddRPC( "Dumpgrah_FS", "RPCForgingSettings", this, SingeplayerExecutionType.Both );
		
		Print("[Dumpgrah_SS,Dumpgrah_FS][Client] Requesting Config From Server");
        //Send an RPC call to the server to ask for the config
        GetRPCManager().SendRPC("Dumpgrah_SS", "RPCSmeltingSettings", new Param1< SmelterSettings >( NULL ), true, NULL);
		GetRPCManager().SendRPC("Dumpgrah_FS", "RPCForgingSettings", new Param1< ForgingSettings >( NULL ), true, NULL);
	}
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate( timeslice );

		// book reading
		PlayerBase pBase = PlayerBase.Cast(GetGame().GetPlayer());
		if (pBase && pBase.IsReadingBook())
		{
			pBase.ToggleBookReading();
			InventoryItem book = pBase.GetItemInHands();
			BookMenu bookMenu = BookMenu.Cast( GetUIManager().EnterScriptedMenu(MENU_BOOK, NULL) );
			if (bookMenu)
			{
				PlayerControlDisable(INPUT_EXCLUDE_ALL);
				bookMenu.ReadBook(book);
			}
		}
	}
	
	void RPCSmeltingSettings( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
		Param1< SmelterSettings > data  //Player ID, Icon
		if ( !ctx.Read( data ) ) return;
		m_SmelterSettings = data.param1;
		Print("SmeltingSettingRecieved");
	}
	
	void RPCForgingSettings( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
		Param1< ForgingSettings > data  //Player ID, Icon
		if ( !ctx.Read( data ) ) return;
		m_ForgingSettings = data.param1;
		Print("forgingsettingRecieved");
	}
};
modded class MissionServer extends MissionBase
{
	override void OnInit()
	{
		super.OnInit();
		Print("[Dumpgrah_SS,Dumpgrah_FS] OnInit");
		GetSmelterSettings();
		GetForgingSettings();
		
		GetRPCManager().AddRPC( "Dumpgrah_SS", "RPCSmeltingSettings", this, SingeplayerExecutionType.Both );
		GetRPCManager().AddRPC( "Dumpgrah_FS", "RPCForgingSettings", this, SingeplayerExecutionType.Both );
	}
	
			
	void SendSmeltingSettings( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
		if (sender)
		{
			GetRPCManager().SendRPC("Dumpgrah_SS", "RPCSmeltingSettings", new Param1< SmelterSettings >( GetSmelterSettings() ), true, sender);
		}
	}
	void SendForgingSettings( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target )
	{
		if (sender)
		{
			GetRPCManager().SendRPC("Dumpgrah_FS", "RPCForgingSettings", new Param1< ForgingSettings >( GetForgingSettings() ), true, sender);
		}
	}
	
};