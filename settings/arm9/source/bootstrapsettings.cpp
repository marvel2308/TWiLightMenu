
#include "common/inifile.h"
#include "common/bootstrappaths.h"
#include "bootstrapsettings.h"
#include <string.h>

BootstrapSettings::BootstrapSettings()
{
    bstrap_debug = false;
	bstrap_logging = false;
	bstrap_romreadled = BootstrapSettings::ELEDNone;
	bstrap_loadingScreen = BootstrapSettings::ELoadingRegular;
	bstrap_loadingScreenTheme = false;
	bstrap_loadingScreenLocation = false;
}

void BootstrapSettings::loadSettings()
{
    CIniFile bootstrapini(BOOTSTRAP_INI);

    // UI settings.
   	bstrap_debug = bootstrapini.GetInt("NDS-BOOTSTRAP", "DEBUG", bstrap_debug);
	bstrap_logging = bootstrapini.GetInt("NDS-BOOTSTRAP", "LOGGING", bstrap_logging);
	if (isDSiMode()) bstrap_romreadled = bootstrapini.GetInt("NDS-BOOTSTRAP", "ROMREAD_LED", bstrap_romreadled);
	bstrap_loadingScreen = bootstrapini.GetInt( "NDS-BOOTSTRAP", "LOADING_SCREEN", bstrap_loadingScreen);
	bstrap_loadingScreenTheme = bootstrapini.GetInt( "NDS-BOOTSTRAP", "LOADING_DARK_THEME", bstrap_loadingScreenTheme);
	bstrap_loadingScreenLocation = bootstrapini.GetInt( "NDS-BOOTSTRAP", "LOADING_SWAP_LCDS", bstrap_loadingScreenLocation);

}

void BootstrapSettings::saveSettings()
{
    CIniFile bootstrapini(BOOTSTRAP_INI);

    // UI settings.
    bootstrapini.SetInt("NDS-BOOTSTRAP", "DEBUG", bstrap_debug);
	bootstrapini.SetInt("NDS-BOOTSTRAP", "LOGGING", bstrap_logging);
	if (isDSiMode()) bootstrapini.SetInt("NDS-BOOTSTRAP", "ROMREAD_LED", bstrap_romreadled);
	bootstrapini.SetInt( "NDS-BOOTSTRAP", "LOADING_SCREEN", bstrap_loadingScreen);
	bootstrapini.SetInt( "NDS-BOOTSTRAP", "LOADING_DARK_THEME", bstrap_loadingScreenTheme);
	bootstrapini.SetInt( "NDS-BOOTSTRAP", "LOADING_SWAP_LCDS", bstrap_loadingScreenLocation);
    bootstrapini.SaveIniFile(BOOTSTRAP_INI);
}
