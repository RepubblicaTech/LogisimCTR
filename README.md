# LogisimCTR
A digital logic simulator for the 3DS

## The idea
How this thing should work and look like: [Digital Logic Sim by Sebastian Lague](https://sebastian.itch.io/digital-logic-sim)

![image](https://github.com/RepubblicaTech/LogisimCTR/assets/76620155/d3b4ceba-2e84-4af8-839e-9b100a4bebbf)


## The reality
How actually it is: 

![image](https://github.com/RepubblicaTech/LogisimCTR/assets/76620155/b7188138-1b87-4c5f-a858-d84e7e183686)

## Building
To build the project follow the [Building instructions](Building.md) (Although it's just `make <the target you need>`)

## Requirements
- Devkitpro installed and in the PATH (tested and used on Linux, but should work on other OSes, follow [devkitpro's wiki](https://devkitpro.org/wiki/Getting_Started) to install it)
- The C/C++ compiler, and make (`sudo apt install build-essential` (for Ubuntu) SHOULD do the job)
- Some knowledge on how compiling and 3DS homebrew dev works (should come back in handy when compiling for the first time)
- #### NOTE FOR WINDOWS USERS: make sure to have citra (and citra-qt/room) in your PATH, else you have to point the location of your executable in the makefile in the `citra` and `run` targets

### NOTE : The software has been tested only on a 2DS, so please submit an issue if any other 3DS model works/doesn't work.
### NOTE #2 : The `Makefile` has been used only on Linux, and since I got the `buildnumber` script implemented, might not work with Windows so please be sure to submit an issue to fix the problem if it's presented.

## For novices in 3DS homebrew: Installing LogisimCTR on your 3DS system

There are both a .CIA (to install on the HOME screen) and .3DSX/SDMH (to start from the Homebrew Launcher)
If you download the CIA, just copy it to the SD card (in any directory you want) and install it from FBI (or you can use [Boop](https://github.com/miltoncandelero/Boop) to remote install it)

If you downloaded LogisimCTR.zip, copy the extracted content from inside the `3ds` folder to the SD card (maybe inside the `3ds` folder, for easier access from Homebrew Launcher). Make sure that both 3DSX and SMDH files are in the same directory (it may not work if they are separate)

#### Contents of LogisimCTR.zip:
```
3ds
├── LogisimCTR.3dsx
└── LogisimCTR.smdh
```

__________________________________________________________________________________________________________

## Shoutouts

This project uses the [3DS template](https://github.com/TricksterGuy/3ds-template) from TricksterGuy.

The build number system source comes from [here](https://buildnumber.sourceforge.net/).

The table printing uses [this header](https://github.com/friedmud/variadic_table/blob/master/include/VariadicTable.h) from [freidmud's VariadicTable](https://github.com/friedmud/variadic_table).

The table printing uses [this header](https://github.com/friedmud/variadic_table/blob/master/include/VariadicTable.h) from [freidmud's VariadicTable](https://github.com/friedmud/variadic_table).
