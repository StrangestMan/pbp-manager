# Usage

To use pbp-manager, simply run the compiled program and enter in your desired values:

* Wad File Location: This is the literal path to where-ever your main doom wad is (DOOM.WAD or DOOM2.WAD, etc). This is a required field; leaving it empty will stop Doom from launching

* Comp Level: The compatability level PrBoom+ uses. You should leave this alone if you're unsure about it. Read up on compatability levels [here](https://github.com/coelckers/prboom-plus/blob/master/prboom2/doc/README.compat)

* Difficulty: How realistic you want Doomguy's experience to be

  * Respawning Monsters: Enemies will respawn after a random amount of time

  * Fast Monsters: Monsters shoot far more often, lob faster projectiles, and pinkies run at supersonic speeds

  * No Monsters: Stops monsters from spawning (Only monsters manually placed on the map. Monsters spawned through other methods [ex: Icon of Sin] will still spawn)

  * No Cheats: Prevents the use of DeHacked files

* Load Level: Loads the specified level

* _**Launch Script**_: Runs Doom with the previously specified settings. *This will only launch the game*

* _**Make Script**_: Makes a file named `pbp-manager.sh` that when executed will run Doom with the previously specified settings. _This doesn't run the game, it just makes a file that can run the game_

Remember: `Launch Script` runs the game, `Make Script` saves your settings to a file
