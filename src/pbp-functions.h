#ifndef pbpfunctions10620201425
#define pbpfunctions10620201425

#include <string>

class pbpFunctions {
    public:

        // Constructor & Destructor
        pbpFunctions();
        ~pbpFunctions();

        // Variable stuff
        void bFastMonsters(bool inpt);
        void bRespawningMonsters(bool inpt);
        void bNoMonsters(bool inpt);
        void bNoCheats(bool inpt);

        bool bGet_fastMonsters();
        bool bGet_respawningMonsters();
        bool bGet_noMonsters();
        bool bGet_noCheats();

        void iSave(int inpt);
        void iDifficulty(int inpt);
        void iCompLevel(int inpt);
        void iMap(int inpt);

        /*
        void iEpisode(int inpt);
        void iLevel(int inpt);
        */

        int iGet_save();
        int iGet_difficulty();
        int iGet_compLevel();
        int iGet_map();

        void sWadLocation(std::string inpt);

        std::string sGet_wadLocation();
        // End of variable stuff

        // Functions for launching prboom+
        std::string createScript(pbpFunctions& pbp0);
        void launchScript(pbpFunctions& pbp0);
        int makeScript(pbpFunctions& pbp0);

    protected:

    private:
        bool fastMonsters, respawningMonsters, noMonsters, noCheats;
        int save, difficulty, compLevel, episode, level, map;
        std::string wadLocation;

};

#endif