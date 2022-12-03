//modded class PlayerBase extends ManBase
//{
//    override void Init()
//    {
//        if ( !GetGame().IsServer() || !GetGame().IsMultiplayer() )
//        {
//
//            DayzPlayerItemBehaviorCfg     toolsOneHanded = new DayzPlayerItemBehaviorCfg;
//            toolsOneHanded.SetToolsOneHanded();
//			
//			DayzPlayerItemBehaviorCfg 	twoHanded = new DayzPlayerItemBehaviorCfg;
//			twoHanded.SetTwoHanded();
//			
//			DayzPlayerItemBehaviorCfg 	heavyItemBehaviour = new DayzPlayerItemBehaviorCfg;
//			heavyItemBehaviour.SetHeavyItems();
//
//			GetDayZPlayerType().AddItemInHandsProfileIK("ND_IronDaggerBlade", "dz/anims/workspaces/player/player_main/weapons/player_main_1h_knife.asi", toolsOneHanded, 		"dz/anims/anm/player/ik/gear/combatknife.anm"); 
//			
//			GetDayZPlayerType().AddItemInHandsProfileIK("ND_CrucibleBase", "dz/anims/workspaces/player/player_main/props/player_main_2h_pot.asi", twoHanded,
// 							"dz/anims/anm/player/ik/two_handed/CookingPot.anm");
//							
//			GetDayZPlayerType().AddItemInHandsProfileIK("ND_ClayCrucibleBase", "dz/anims/workspaces/player/player_main/props/player_main_2h_pot.asi", twoHanded,
// 							"dz/anims/anm/player/ik/two_handed/CookingPot.anm");
//							
//			GetDayZPlayerType().AddItemInHandsProfileIK("ND_Smelter", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,				"dz/anims/anm/player/ik/heavy/55galDrum.anm");
//			
//			GetDayZPlayerType().AddItemInHandsProfileIK("ND_TreeStump", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,				"dz/anims/anm/player/ik/heavy/55galDrum.anm");
//			
//			GetDayZPlayerType().AddItemInHandsProfileIK("ND_BaseAnvilStump", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", heavyItemBehaviour,				"dz/anims/anm/player/ik/heavy/55galDrum.anm");
//        }
//        super.Init();
//        
//
//    }
//    
//}
modded class ModItemRegisterCallbacks
{
    override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterHeavy(pType, pBehavior);
        pType.AddItemInHandsProfileIK("ND_BaseAnvilStump", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior, "dz/anims/anm/player/ik/heavy/55galDrum.anm");
        pType.AddItemInHandsProfileIK("ND_TreeStump", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior, "dz/anims/anm/player/ik/heavy/55galDrum.anm");
        pType.AddItemInHandsProfileIK("ND_Smelter", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior, "dz/anims/anm/player/ik/heavy/55galDrum.anm");
        pType.AddItemInHandsProfileIK("ND_SteelAnvil", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior, "dz/anims/anm/player/ik/heavy/55galDrum.anm");
		pType.AddItemInHandsProfileIK("SmelterBase", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior, "dz/anims/anm/player/ik/heavy/55galDrum.anm");
    };
	override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterTwoHanded(pType, pBehavior);
		pType.AddItemInHandsProfileIK("ND_MakeShirtAnvilBase", "dz/anims/workspaces/player/player_main/props/player_main_2h_pot.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/CookingPot.anm");
		pType.AddItemInHandsProfileIK("ND_CrucibleBase", "dz/anims/workspaces/player/player_main/props/player_main_2h_pot.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/CookingPot.anm");
		pType.AddItemInHandsProfileIK("ND_ClayCrucibleBase", "dz/anims/workspaces/player/player_main/props/player_main_2h_pot.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/CookingPot.anm");
		//pType.AddItemInHandsProfileIK("MF_Halbread", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_fireaxe.asi", pBehavior, 		"dz/anims/anm/player/ik/two_handed/FirefighterAxe.anm");
	};
	override void RegisterPoleArms(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
	{
		super.RegisterOneHanded(pType, pBehavior);
		pType.AddItemInHandsProfileIK("MF_Halbread", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_spear.asi", pBehavior,				"dz/anims/anm/player/ik/two_handed/pitchfork.anm");
	};
	
};