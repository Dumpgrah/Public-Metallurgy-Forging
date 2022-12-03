modded class ND_Smelter : Inventory_Base
{
	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
	{		
		super.OnPlacementComplete( player, position, orientation );
		SetTemperature(0);

		SetIsPlaceSound( true );
		if ( GetGame().IsMultiplayer()  &&  GetGame().IsServer() || !GetGame().IsMultiplayer() )
		{
			//remove grass
			Object cc_object = GetGame().CreateObjectEx( OBJECT_CLUTTER_CUTTER , position, ECE_PLACE_ON_SURFACE );
			cc_object.SetOrientation( orientation );
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( GetGame().ObjectDelete, 1000, false, cc_object );
			
			SetIsPlaceSound( true );
		}
	}
	override string GetPlaceSoundset()
	{
		return "placeBarrel_SoundSet";
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
	override bool CanPutIntoHands( EntityAI parent )
    {
        super.CanPutIntoHands( parent );    

        //if ( GetInventory().AttachmentCount() == 0 && GetInventory().GetCargo().GetItemCount() == 0 )
        //{
        //    return true;
        //}
		if ( GetTemperature() >= 1)
		{
			return false;
		}
        return true;

    }
	override bool CanPutInCargo( EntityAI parent )
    {
		super.CanPutInCargo(parent);
		if ( GetTemperature() >=1)
		{
			return false;
		}
        return true;
    }
};