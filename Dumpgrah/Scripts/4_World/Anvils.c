class ND_MSPureIronAnvilStump : Anvil_Base{};
class ND_MSImpureIronAnvilStump : Anvil_Base{};
class ND_MSCastIronAnvilStump : Anvil_Base{};
class ND_MakeShiftCastIronAnvil : ItemBase{};
class ND_MakeShiftImpureIronAnvil : ItemBase{};
class ND_MakeShiftPureIronAnvil : ItemBase{};
class Anvil_Base : Inventory_Base
{
	PlayerBase 		m_Player;
	
	void Anvil_Base()
	{
	};
	string GetForgingMetal()
	{
		ItemBase thing = ItemBase.Cast(FindAttachmentBySlotName("ForgeMetal"));
		if(thing)
		{
			
			if(thing.IsInherited(ND_IngotBase))
			{
				return "Ingot";
			}
			if(thing.IsInherited(ND_ImPureIronBar))
			{
				return "Bar";
			}
			if(thing.IsInherited(ND_NuggetBase))
			{
				return "Nugget";
			}
		};
		return "";
	};
	int GetForgingMetalCount()
	{
		ItemBase thing = ItemBase.Cast(FindAttachmentBySlotName("ForgeMetal"));
		if(thing)
		{
			if(thing.IsInherited(ND_IngotBase))
			{
				return 1;
			}
			return thing.GetQuantity();
			
		}

		
		return 0;
	};
	int GetForgingBarCount()
	{
		ItemBase thing = ItemBase.Cast(FindAttachmentBySlotName("ForgeMetal"));
		if(thing)
		{
			if(thing.IsInherited(ND_IronBar))
			{
				return true;
			}
			else if(thing.IsInherited(ND_CastBar))
			{
				return false;
			}
			return thing.GetQuantity();
			
		}

		
		return false;
	};
	int GetForgingNuggetCount()
	{
		ItemBase thing = ItemBase.Cast(FindAttachmentBySlotName("ForgeMetal"));
		if(thing)
		{
			if(thing.IsInherited(ND_NuggetBase))
			{
				return 20;
			}
			return thing.GetQuantity();
			
		}

		
		return false;
	};
	bool IsTemperatureValid()
	{
		float SmithTemp = GetForgingSettings().SmithMetalTemp;
		ItemBase thing = ItemBase.Cast(FindAttachmentBySlotName("ForgeMetal"));
		if(thing)
		{
		  if(thing.GetTemperature() >= SmithTemp)
		  {
			 return true; 
		  }
		  
		}
		
		return false;
	};
	int GetOutPutOccupied()
	{
		ItemBase thing = ItemBase.Cast(FindAttachmentBySlotName("ForgeMetalOne"));
		if(thing)
		{
			if(thing.IsInherited(ND_IngotBase))
			{
				return 1;
			}
			return thing.GetQuantity();
			
		}

		
		return 0;
	};
	void ShowSimpleSelection(string selectionName, bool hide = false)
    {
        TStringArray selectionNames = new TStringArray;
        ConfigGetTextArray("simpleHiddenSelections",selectionNames);
        int selectionId = selectionNames.Find(selectionName);
        SetSimpleHiddenSelectionState(selectionId, hide);
    };
	///////////
	ND_CastIngot GetCastIronIngot()
	{
		return ND_CastIngot.Cast( GetAttachmentByType( ND_CastIngot ) );
	};
	
	ND_ImPureIronIngot GetImPureIronIngot()
	{
		return ND_ImPureIronIngot.Cast( GetAttachmentByType( ND_ImPureIronIngot ) );
	};
	
	ND_IronIngot GetIronIngot()
	{
		return ND_IronIngot.Cast( GetAttachmentByType( ND_IronIngot ) );
	};
	/////////////
	ND_CastBar GetCastBar()
	{
		return ND_CastBar.Cast( GetAttachmentByType( ND_CastBar ) );
	};
	
	ND_ImPureIronBar GetImPureIronBar()
	{
		return ND_ImPureIronBar.Cast( GetAttachmentByType( ND_ImPureIronBar ) );
	};
	ND_IronBar GetND_IronBar()
	{
		return ND_IronBar.Cast( GetAttachmentByType( ND_IronBar ) );
	};
	//////////////////////
	ND_CastNugget GetCastNugget()
	{
		return ND_CastNugget.Cast( GetAttachmentByType( ND_CastNugget ) );
	};

	ND_ImPureIronNugget GetImPureIronNugget()
	{
		return ND_ImPureIronNugget.Cast( GetAttachmentByType( ND_ImPureIronNugget ) );
	};

	ND_IronNugget GetIronNugget()
	{
		return ND_IronNugget.Cast( GetAttachmentByType( ND_IronNugget ) );
	};
	//Start Ingot Functions

	void DestroyIngotAndCreateItem(string CreationType)
	{
		string thingName =  FindAttachmentBySlotName("ForgeMetal").GetType();
		
		
		if ( thingName == "ND_CastIngot" )
		{
			GetGame().ObjectDelete( GetCastIronIngot() );
			GetInventory().CreateAttachment("ND_Cast" + CreationType ); //Produces Item in the output slot
			AddHealth("","Health",-2);
		};
		if ( thingName == "ND_ImPureIronIngot" )
		{
			GetGame().ObjectDelete( GetImPureIronIngot() );
			GetInventory().CreateAttachment("ND_Impure" + CreationType); //Produces Item in the output slot
			AddHealth("","Health",-2);
		};
		if ( thingName == "ND_IronIngot" )
		{
			GetGame().ObjectDelete( GetIronIngot() );
			GetInventory().CreateAttachment("ND_Pure" + CreationType); //Produces Item in the output slot
			AddHealth("","Health",-2);
		};
	};
	void DestroyBarAndItem(string CreationType)
	{
		string thingName =  FindAttachmentBySlotName("ForgeMetal").GetType();
		
		//ItemBase NDCastBar = GetCastBar();
		ItemBase NDImPureIronBar = GetImPureIronBar();
		ItemBase NDIronBar = GetND_IronBar();
	
		
		//if ( thingName == "ND_CastBar")
		//{
		//	ND_ToolWedges Wedges = ND_ToolWedges.Cast(GetInventory().CreateAttachment("ND_" + CreationType) );
		//	Wedges.AddQuantity(2);
		//	AddHealth("","Health",-1);
		//	NDCastBar.AddQuantity(-4);
		//}
		if ( thingName == "ND_ImPureIronBar" )
		{
			GetInventory().CreateAttachment("ND_" + CreationType ); 
			AddHealth("","Health",-1);
			NDImPureIronBar.AddQuantity(-8);
		};
		if ( thingName == "ND_IronBar" )
		{
			GetInventory().CreateAttachment("ND_" + CreationType ); 
			AddHealth("","Health",-1);
			NDImPureIronBar.AddQuantity(-2);
		};
	};
	void DestroyNuggetAndItem(string CreationType)
	{
		string thingName =  FindAttachmentBySlotName("ForgeMetal").GetType();

		
		ItemBase NDCastNugget = GetCastNugget();
		ItemBase NDImPureIronNugget = GetImPureIronNugget();
		ItemBase NDIronNugget = GetIronNugget();

		float CastIronNailMade = GetForgingSettings().CastIronNailProduced;
		float ImpureIronNialMade = GetForgingSettings().ImpureIronNialProduced;
		float PureIronNailMade = GetForgingSettings().PureIronNailProduced;
		float CastNuggetConsumed = GetForgingSettings().CastNuggetConsumedNail;
		float ImpureNuggetConsumed = GetForgingSettings().ImpureNuggetConsumedNail;
		float PureNuggetConsume = GetForgingSettings().PureNuggerConsumedNail;	
		//nails
		if ( thingName == "ND_CastNugget")
		{
			ND_CastIronNails castNails = ND_CastIronNails.Cast(GetInventory().CreateAttachment("ND_Cast" + CreationType) );
			castNails.AddQuantity(CastIronNailMade);
			AddHealth("","Health",-1);
			NDCastNugget.AddQuantity(-CastNuggetConsumed);
		}
		else if (NDImPureIronNugget && thingName == "ND_ImPureIronNugget")
		{
			ND_ImpureIronNails impurenails = ND_ImpureIronNails.Cast(GetInventory().CreateAttachment("ND_Impure" + CreationType) );
			impurenails.AddQuantity(ImpureIronNialMade);
			AddHealth("","Health",-1);
			NDImPureIronNugget.AddQuantity(-ImpureNuggetConsumed);
		}
		else if ( NDIronNugget && thingName == "ND_IronNugget" )
		{
			ND_PureIronNails PureNails = ND_PureIronNails.Cast(GetInventory().CreateAttachment("ND_Pure" + CreationType) );
			PureNails.AddQuantity(PureIronNailMade);
			AddHealth("","Health",-1);
			NDIronNugget.AddQuantity(-PureNuggetConsume);
		};

	};
	void DestoryNuggetAndCreateWedges(string CreationType)
	{		
		string thingName =  FindAttachmentBySlotName("ForgeMetal").GetType();

		
		ItemBase NDCastNugget = GetCastNugget();
		ItemBase NDImPureIronNugget = GetImPureIronNugget();
		ItemBase NDIronNugget = GetIronNugget();

		if ( thingName == "ND_ImPureIronNugget")
		{
			ND_ToolWedges Wedges = ND_ToolWedges.Cast(GetInventory().CreateAttachment("ND_" + CreationType) );
			Wedges.AddQuantity(2);
			AddHealth("","Health",-1);
			NDImPureIronNugget.AddQuantity(-4);
		}
		else if ( thingName == "ND_IronNugget" )
		{
			ND_ToolWedges Wedges1 = ND_ToolWedges.Cast(GetInventory().CreateAttachment("ND_" + CreationType) );
			Wedges1.AddQuantity(2);
			AddHealth("","Health",-1);
			NDIronNugget.AddQuantity(-4);
		};
	};
	bool NuggetNailCheck()
	{
		float CastNuggetConsumed = GetForgingSettings().CastNuggetConsumedNail;
		float ImpureNuggetConsumed = GetForgingSettings().ImpureNuggetConsumedNail;
		float PureNuggetConsume = GetForgingSettings().PureNuggerConsumedNail;	
		
		
		if(GetCastNugget().GetQuantity() >= CastNuggetConsumed )
		{
			return true;
		}
		else if(GetImPureIronNugget().GetQuantity() >= ImpureNuggetConsumed )
		{
			return true;
		}
		else if(GetIronNugget().GetQuantity() >= PureNuggetConsume )
		{
			return true;
		};
		return false;
	}
	override void OnPlacementStarted( Man player) 
	{
		super.OnPlacementStarted( player );
		SetTakeable(false);
	};
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{		
		super.OnPlacementComplete( player, position, orientation );
		

		SetIsPlaceSound( true );
	};
	override string GetPlaceSoundset()
	{
		return "placeBarrel_SoundSet";
	};
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	};
	override bool CanPutIntoHands( EntityAI parent )
    {
        super.CanPutIntoHands( parent );    
        if ( GetInventory().AttachmentCount() >= 1)
        {
            return false;
        }
        return true;

    };
	override bool CanPutInCargo( EntityAI parent )
    {
		super.CanPutInCargo(parent);
		if ( GetInventory().AttachmentCount() >= 1)
        {
            return false;
        }
        return true;
    };
};
class ND_SteelAnvil : Anvil_Base
{
	void ND_SteelAnvil()
	{
		ShowSimpleSelection("StumpAnvil", 0);
		ShowSimpleSelection("GroundAnvil", 1);
	};
	override void OnPlacementStarted( Man player) 
	{
		super.OnPlacementStarted( player );
		SetTakeable(false);
	};
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{		
		super.OnPlacementComplete( player, position, orientation );
		

		SetIsPlaceSound( true );
	};
	override string GetPlaceSoundset()
	{
		return "placeBarrel_SoundSet";
	};
	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item,slot_name);
		if(slot_name == "Anvil_Stand")
		{
			if ( item.IsKindOf("ND_TreeStump")) // any attachment but coal
			{
				ShowSimpleSelection("StumpAnvil", 1);
				ShowSimpleSelection("GroundAnvil", 0);
			};
		};
	};
	
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		
		if(slot_name == "Anvil_Stand")
		{
			if ( item.IsKindOf("ND_TreeStump")) // any attachment but coal
			{
				ShowSimpleSelection("StumpAnvil", 0);
				ShowSimpleSelection("GroundAnvil", 1);
			};
		};
	};
	void ShowSimpleSelection(string selectionName, bool hide = false)
    {
        TStringArray selectionNames = new TStringArray;
        ConfigGetTextArray("simpleHiddenSelections",selectionNames);
        int selectionId = selectionNames.Find(selectionName);
        SetSimpleHiddenSelectionState(selectionId, hide);
    };
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	};
	override bool CanPutIntoHands( EntityAI parent )
    {
        super.CanPutIntoHands( parent );    

        if ( GetInventory().AttachmentCount() >= 2)
        {
            return false;
        }
        return true;

    };
	override bool CanPutInCargo( EntityAI parent )
    {
		super.CanPutInCargo(parent);
        if ( GetInventory().AttachmentCount() >= 2 )
        {
            return false;
        }
        return true;
    };
};