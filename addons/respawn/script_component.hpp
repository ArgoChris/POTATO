#define COMPONENT respawn
#include "\z\potato\addons\core\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_RESPAWN
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_RESPAWN
    #define DEBUG_SETTINGS DEBUG_SETTINGS_RESPAWN
#endif

// define black-lists
#define ZEUS_ENABLED true
#define BLACK_LIST_UIDS []

// EULA info
#define EULA_CHECK QGVAR(eula_v1) // note change this on change of eula text
#define EULA_FULL_TEXT <t size='0.75'>\
By clicking agree, you agree to the following rules and conditions unless otherwise authorized by a group administrator. <br/>\
No respawns of players, outside premature transportation incidents or bringing in a reinforcement wave upon the completion of a concrete mission objective. <br/>\
No respawns of players on forces opposing the player force. <br/>\
No displays of nepotism when assigning slots and groups. <br/>\
If these rules and conditions are not met in full you or zeuses in general can and will be black listed from using the respawn tool\
</t>

// define colors
#define COLOR_BLACK ARR_4(0,0,0,0.75)
#define COLOR_EMPTY ARR_4(0,0,0,0)

#define COLOR_RED ARR_3(0.77,0.14,0.19)
#define COLOR_RED_ACTIVE ARR_2(COLOR_RED,1)
#define COLOR_RED_INACTIVE ARR_2(COLOR_RED,0.75)

#define COLOR_GREEN ARR_3(0.12,0.79,0.25)
#define COLOR_GREEN_ACTIVE ARR_2(COLOR_GREEN,1)
#define COLOR_GREEN_INACTIVE ARR_2(COLOR_GREEN,0.75)

#define COLOR_BLUE ARR_3(0.17,0.48,0.81)
#define COLOR_BLUE_ACTIVE ARR_2(COLOR_BLUE,1)
#define COLOR_BLUE_INACTIVE ARR_2(COLOR_BLUE,0.75)

// common display defines
#define MAIN_DISPLAY (findDisplay 46)
#define GROUP_TREE_IDC 800009

// admin display defines
#define ADMIN_RESPAWN_IDD 800000
#define ADMIN_RESPAWN (findDisplay ADMIN_RESPAWN_IDD)

#define ADMIN_BG_IDC 800001
#define ADMIN_BG (ADMIN_RESPAWN displayCtrl ADMIN_BG_IDC)

#define ADMIN_BGF_IDC 800002
#define ADMIN_BGF (ADMIN_RESPAWN displayCtrl ADMIN_BGF_IDC)

#define ADMIN_SPEC_BG_IDC 800003
#define ADMIN_SPEC_BG (ADMIN_RESPAWN displayCtrl ADMIN_SPEC_BG_IDC)

#define ADMIN_SPEC_FRAME_IDC 800004
#define ADMIN_SPEC_FRAME (ADMIN_RESPAWN displayCtrl ADMIN_SPEC_FRAME_IDC)

#define ADMIN_GROUP_FRAME_IDC 800005
#define ADMIN_GROUP_FRAME (ADMIN_RESPAWN displayCtrl ADMIN_GROUP_FRAME_IDC)

#define ADMIN_CONFIG_FRAME_IDC 800007
#define ADMIN_CONFIG_FRAME (ADMIN_RESPAWN displayCtrl ADMIN_CONFIG_FRAME_IDC)

#define ADMIN_SPEC_LIST_IDC 800008
#define ADMIN_SPEC_LIST (ADMIN_RESPAWN displayCtrl ADMIN_SPEC_LIST_IDC)

#define ADMIN_GROUP_TREE (ADMIN_RESPAWN displayCtrl GROUP_TREE_IDC)

#define ADMIN_FACTION_TEXT_IDC 800010
#define ADMIN_FACTION_TEXT (ADMIN_RESPAWN displayCtrl ADMIN_FACTION_TEXT_IDC)

#define ADMIN_FACTION_COMBO_IDC 800011
#define ADMIN_FACTION_COMBO (ADMIN_RESPAWN displayCtrl ADMIN_FACTION_COMBO_IDC)

#define ADMIN_GROUP_TEXT_IDC 800012
#define ADMIN_GROUP_TEXT (ADMIN_RESPAWN displayCtrl ADMIN_GROUP_TEXT_IDC)

#define ADMIN_GROUP_COMBO_IDC 800013
#define ADMIN_GROUP_COMBO (ADMIN_RESPAWN displayCtrl ADMIN_GROUP_COMBO_IDC)

#define ADMIN_CONFIG_TEXT_IDC 800014
#define ADMIN_CONFIG_TEXT (ADMIN_RESPAWN displayCtrl ADMIN_CONFIG_TEXT_IDC)

#define ADMIN_CONFIG_COMBO_IDC 800015
#define ADMIN_CONFIG_COMBO (ADMIN_RESPAWN displayCtrl ADMIN_CONFIG_COMBO_IDC)

#define ADMIN_ADD_BUTTON_IDC 800016
#define ADMIN_ADD_BUTTON (ADMIN_RESPAWN displayCtrl ADMIN_ADD_BUTTON_IDC)

#define ADMIN_DELETE_BUTTON_IDC 800017
#define ADMIN_DELETE_BUTTON (ADMIN_RESPAWN displayCtrl ADMIN_DELETE_BUTTON_IDC)

#define ADMIN_SLOT_BUTTON_IDC 800018
#define ADMIN_SLOT_BUTTON (ADMIN_RESPAWN displayCtrl ADMIN_SLOT_BUTTON_IDC)

#define ADMIN_UNSLOT_BUTTON_IDC 800019
#define ADMIN_UNSLOT_BUTTON (ADMIN_RESPAWN displayCtrl ADMIN_UNSLOT_BUTTON_IDC)

#define ADMIN_OPEN_RESPAWN_BUTTON_IDC 800020
#define ADMIN_OPEN_RESPAWN_BUTTON (ADMIN_RESPAWN displayCtrl ADMIN_OPEN_RESPAWN_BUTTON_IDC)

#define ADMIN_CLOSE_RESPAWN_BUTTON_IDC 800021
#define ADMIN_CLOSE_RESPAWN_BUTTON (ADMIN_RESPAWN displayCtrl ADMIN_CLOSE_RESPAWN_BUTTON_IDC)

#define ADMIN_TRIGGER_BUTTON_IDC 800022
#define ADMIN_TRIGGER_BUTTON (ADMIN_RESPAWN displayCtrl ADMIN_TRIGGER_BUTTON_IDC)

#define ADMIN_CANCEL_BUTTON_IDC 800023
#define ADMIN_CANCEL_BUTTON (ADMIN_RESPAWN displayCtrl ADMIN_CANCEL_BUTTON_IDC)

#define ADMIN_CHAT_BUTTON_ON_IDC 800024
#define ADMIN_CHAT_BUTTON_ON (ADMIN_RESPAWN displayCtrl ADMIN_CHAT_BUTTON_ON_IDC)

#define ADMIN_CHAT_BUTTON_OFF_IDC 800025
#define ADMIN_CHAT_BUTTON_OFF (ADMIN_RESPAWN displayCtrl ADMIN_CHAT_BUTTON_OFF_IDC)

#define ADMIN_CLOSE_BUTTON_IDC 800026
#define ADMIN_CLOSE_BUTTON (ADMIN_RESPAWN displayCtrl ADMIN_CLOSE_BUTTON_IDC)

#define ADMIN_MAP_IDC 800027
#define ADMIN_MAP (ADMIN_RESPAWN displayCtrl ADMIN_MAP_IDC)

// eula display defines
#define RESPAWN_EULA_IDD 800100
#define RESPAWN_EULA (findDisplay RESPAWN_EULA_IDD)

#define EULA_BG_IDC 800101
#define EULA_BG (RESPAWN_EULA displayCtrl EULA_BG_IDC)

#define EULA_BGF_IDC 800102
#define EULA_BGF (RESPAWN_EULA displayCtrl EULA_BGF_IDC)

#define EULA_TEXT_IDC 800103
#define EULA_TEXT (RESPAWN_EULA displayCtrl EULA_TEXT_IDC)

#define EULA_AGREE_BUTTON_IDC 800104
#define EULA_AGREE_BUTTON (RESPAWN_EULA displayCtrl EULA_AGREE_BUTTON_IDC)

#define EULA_DECLINE_BUTTON_IDC 800105
#define EULA_DECLINE_BUTTON (RESPAWN_EULA displayCtrl EULA_DECLINE_BUTTON_IDC)

// client display defines
#define CLIENT_RESPAWN_IDD 850000
#define CLIENT_RESPAWN (findDisplay CLIENT_RESPAWN_IDD)

#define CLIENT_BG_IDC 850001
#define CLIENT_BG (CLIENT_RESPAWN displayCtrl CLIENT_BG_IDC)

#define CLIENT_BGF_IDC 850002
#define CLIENT_BGF (CLIENT_RESPAWN displayCtrl CLIENT_BGF_IDC)

#define CLIENT_GROUP_TREE (CLIENT_RESPAWN displayCtrl GROUP_TREE_IDC)

#define CLIENT_SLOT_BUTTON_IDC 850003
#define CLIENT_SLOT_BUTTON (CLIENT_RESPAWN displayCtrl CLIENT_SLOT_BUTTON_IDC)

#define CLIENT_UNSLOT_BUTTON_IDC 850004
#define CLIENT_UNSLOT_BUTTON (CLIENT_RESPAWN displayCtrl CLIENT_UNSLOT_BUTTON_IDC)

#define CLIENT_CLOSE_TEXT_IDC 850005
#define CLIENT_CLOSE_TEXT (CLIENT_RESPAWN displayCtrl CLIENT_CLOSE_TEXT_IDC)

#define CLIENT_CLOSE_BUTTON_IDC 850006
#define CLIENT_CLOSE_BUTTON (CLIENT_RESPAWN displayCtrl CLIENT_CLOSE_BUTTON_IDC)

#include "\z\potato\addons\core\script_macros.hpp"
