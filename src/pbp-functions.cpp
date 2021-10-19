#include "pbp-functions.h"

#include <sstream>
#include <fstream>
#include <ctime>

pbpFunctions::pbpFunctions() : fastMonsters{0}, respawningMonsters{0}, noMonsters{0}, noCheats{0}, save{-1}, difficulty{3}, compLevel{17}, map{0}, wadLocation{""}
{};

pbpFunctions::~pbpFunctions() {

}

// Only doing this for good practice, no need to sanitize values for booleans
void pbpFunctions::bFastMonsters(bool inpt) {
    fastMonsters = inpt;
}
void pbpFunctions::bRespawningMonsters(bool inpt) {
    respawningMonsters = inpt;
}
void pbpFunctions::bNoMonsters(bool inpt) {
    noMonsters = inpt;
}
void pbpFunctions::bNoCheats(bool inpt) {
    noCheats = inpt;
}
bool pbpFunctions::bGet_fastMonsters() {
    return fastMonsters;
}
bool pbpFunctions::bGet_respawningMonsters() {
    return respawningMonsters;
}
bool pbpFunctions::bGet_noMonsters() {
    return noMonsters;
}
bool pbpFunctions::bGet_noCheats() {
    return noCheats;
}


void pbpFunctions::iSave(int inpt) {
    save = inpt;
    // Prevent the user from accessing a save file that doesn't exist
    if(save > 7) {
        save = -1;
    }
}
void pbpFunctions::iDifficulty(int inpt) {
    difficulty = inpt;
    // Prevent the user from playing on a non-existent difficulty
    if(difficulty > 5) {
        difficulty = 5;
    }
}
void pbpFunctions::iCompLevel(int inpt) {
    compLevel = inpt;
    // Prevent the user from using an undefined compatability level
    if(compLevel > 17) {
        compLevel = 17;
    }
    // This will need to be updated whenever PrBoom+ comes out with a new complevel
    // Not a big problem now, but a way to automate the current level would be nice
}
void pbpFunctions::iMap(int inpt) {
    map = inpt;
    // Prevent the player from joining a non-existent map
    if(map > 32) {
        map = 32;
    }
    // This might be troublesome for custom maps / wads at a map index above 32
    // TODO: Look into ^^^
    
}

int pbpFunctions::iGet_save() {
    return save;
}
int pbpFunctions::iGet_difficulty() {
    return difficulty;
}
int pbpFunctions::iGet_compLevel() {
    return compLevel;
}
int pbpFunctions::iGet_map() {
    return map;
}


void pbpFunctions::sWadLocation(std::string inpt) {
    wadLocation = inpt;

    // TODO: Sanatize this input and error out whenever
    // the input doesn't work with linux filesystems
}
std::string pbpFunctions::sGet_wadLocation() {
    return wadLocation;
}

// End of variable stuff

std::string pbpFunctions::createScript(pbpFunctions& pbp0) {
    std::string retValue = "";     // make a string for the return value
    std::stringstream bashCommand; // make stringstream for string creation
    bashCommand << "prboom-plus "; // make sure the string has an actual command

    // I've gotta follow the command line order in prboom+'s manpage, so if things look jumbled, that's why
    bashCommand << "-complevel " << pbp0.iGet_compLevel() << " ";

    // Only add the save line if the user specified it
    if(pbp0.iGet_save() > -1) {
        bashCommand << "-loadgame " << pbp0.iGet_save() << " ";
    }

    bashCommand << "-warp " << pbp0.iGet_map() << " ";
    bashCommand << "-skill " << pbp0.iGet_difficulty() << " ";

    if(pbp0.bGet_respawningMonsters() == 1) {
        bashCommand << "-respawn ";
    }
    if(pbp0.bGet_fastMonsters() == 1) {
        bashCommand << "-fast ";
    }
    if(pbp0.bGet_noMonsters() == 1) {
        bashCommand << "-nomonsters ";
    }
    if(pbp0.bGet_noCheats() == 1) {
        bashCommand << "-nocheats ";
    }

    bashCommand << "-iwad " << pbp0.sGet_wadLocation();

    // Convert bashCommand to a c style string, then make it a std::string string
    retValue = bashCommand.str().c_str();

    bashCommand.str("");      // Empty the stringstream input
    bashCommand.clear();      // Clear the stringstream flags

    return retValue;
}

void pbpFunctions::launchScript(pbpFunctions& pbp0) {
    // Make a string with output of the create script func, make it a c-style char, and execute it
    std::string bashString = pbp0.createScript(pbp0);
    const char *bashCommand = bashString.c_str();
    system(bashCommand);

}
int pbpFunctions::makeScript(pbpFunctions& pbp0) {
    std::ofstream outfile;
    outfile.open("pbp-manager.sh");
    if(!outfile) {
        return 1; // Something broke and the file can't be opened
    }
    outfile << pbp0.createScript(pbp0);
    outfile.close();
    system("chmod +x pbp-manager.sh");

    return 0;

    // TODO: Timestamp these files
}
