#ifndef PERGAMESETTINGS_H
#define PERGAMESETTINGS_H

#include <string>

extern bool perGameSettingsButtons;

extern bool perGameSettings_directBoot;	// Homebrew only
extern int perGameSettings_dsiMode;
extern int perGameSettings_language;
extern int perGameSettings_ramDiskNo;
extern int perGameSettings_boostCpu;
extern int perGameSettings_boostVram;
extern int perGameSettings_bootstrapFile;

void loadPerGameSettings(std::string filename);
void savePerGameSettings(std::string filename);
bool checkIfShowAPMsg (std::string filename);
void dontShowAPMsgAgain (std::string filename);
void perGameSettings(std::string filename);
std::string getSavExtension(void);
std::string getImgExtension(void);



#endif //PERGAMESETTINGS_H
