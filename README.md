# LogisimCTR
A digital logic simulation for the 3DS

To build the project follow the [Building instructions](Building.md) (Although it's just `make <the target you need>`)

# Requirements
- Devkitpro installed and in the PATH (tested and used on Linux, but should work on other OSes, follow [the wiki](https://devkitpro.org/wiki/Getting_Started) to install it)
- The C/C++ compiler, and make (`sudo apt install build-essential` (for Ubuntu) SHOULD do the job)
- Some knowledge on how compiling and 3DS homebrew dev works (should come back in handy when compiling for the first time)
- #### NOTE FOR WINDOWS USERS: make sure to have citra (and citra-qt/room) in your PATH, else you have to point the location of your executable in the makefile in the `citra` and `run` targets

## NOTE : The software has been tested only on a 2DS, so please submit an issue if any other 3DS model works/doesn't work

# For novices in 3DS homebrew: Installing LogisimCTR on your 3DS system

There are both a .CIA (to install on the HOME screen) and .3DSX/SDMH (to start from the Homebrew Launcher)
If you download the CIA, just copy it to the SD card (in any directory you want) and install it from FBI (or you can use [Boop](https://github.com/miltoncandelero/Boop) to remote install it)

If you downloaded LogisimCTR.zip, copy the extracted content from inside the `3ds` folder to the SD card (maybe inside the `3ds` folder, for easier access from Homebrew Launcher). Make sure that both 3DSX and SMDH files are in the same directory (it may not work if they are separate)

### Contents of LogisimCTR.zip:
```
3ds
├── LogisimCTR.3dsx
└── LogisimCTR.smdh
```

__________________________________________________________________________________________________________


This project uses the [3DS template](https://github.com/TricksterGuy/3ds-template) from TricksterGuy, so shoutout to him.
