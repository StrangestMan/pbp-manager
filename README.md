# pbp-manager

## GUI manager for PrBoom+ built in Qt

After using [PrBoom+](https://github.com/coelckers/prboom-plus)'s CLI features for a long time, I got fed up with specifying the iwad every time or needing to execute a script. This is my answer to dealing with launch options.

### Usage

To use pbp-manager, simply run the compiled program and enter in your desired values:

* Wad File Location: This is the literal path to where-ever your main doom wad is (DOOM.WAD or DOOM2.WAD). This is a required field; leaving it empty will stop Doom from launching

* Comp Level: The compatability level PrBoom+ uses. You should leave this alone if you're unsure about it. Read up on compatability levels [here](https://github.com/coelckers/prboom-plus/blob/master/prboom2/doc/README.compat)

* Difficulty: How realistic you want Doomguy's experience to be

  * Respawning Monsters: Enemies will respawn after a random amount of time to ruin your day

  * Fast Monsters: Monsters shoot far more often, lob faster projectiles, and pinkies run at supersonic speeds

  * No Monsters: Disables monsters spawning

  * No Cheats: Prevents the use of DeHacked files

* Load Level: Loads the specified level

* _**Launch Script**_: Runs Doom with the previously specified settings. *This will only launch the game*

* _**Make Script**_: Makes a file named `pbp-manager.sh` that when executed will run Doom with the previously specified settings. _This doesn't run the game, it just makes a file that can run the game_

Remember: `Launch Script` runs the game, `Make Script` saves your settings to a file

### Dependencies

[PrBoom+](https://github.com/coelckers/prboom-plus)

Qmake & Qt headers (qtbase5-dev, qt5-qmake)

A C++ compiler

### Installing

First, make sure you have all the dependencies. Then:

1. Clone the repo

1. `cd` into the directory

1. Make a folder called "build" and `cd` into it

1. Generate a makefile with Qmake

1. Run the makefile

Bash commands:

```bash
    git clone https://github.com/StrangestMan/pbp-manager
    cd pbp-manager 
    mkdir build && cd build
    qmake ..
    make
```

I suggest adding both pbp-manager and PrBoom+ to your PATH, but it's not necessary
