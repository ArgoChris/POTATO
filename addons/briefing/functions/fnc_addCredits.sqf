#include "script_component.hpp"
//Auto add credits from description.ext:

params ["_unit"];
TRACE_1("params",_unit);

private _missionName = getText (missionConfigFile >> "onLoadName");
private _authorName = getText (missionConfigFile >> "author");
private _worldName = getText (configFile >> "CfgWorlds" >> worldName >> "description");

private _missionFrameworkDate = getMissionConfigValue ["bwmfDate", "Pre-March2016"];
private _potatoVersion = getText (configFile >> "CfgPatches" >> "potato_core" >> "versionStr");

_unit createDiaryRecord ["diary", ["Credits", format ["
<font size=16>%1</font><br/>
<font size=13>by %2</font><br/>
<font size=13>on %3</font><br/>
<br/>
Bourbon Warfare Mission Framework<br/>
BWMF Version: %4<br/>
Based on F3 (http://www.ferstaberinde.com/f3/en/)<br/>
<br/>
<br/>
POTATO Version: %5
", _missionName, _authorName, _worldName, _missionFrameworkDate, _potatoVersion]]];
