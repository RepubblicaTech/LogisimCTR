# LogisimCTR
A digital logic simulation for the 3DS

To build the project follow the [Building instructions](Building.md) (Although it's just `make <the target you need>`)

# Requirements
- Devkitpro installed and in the PATH (tested and used on Linux, but should work on other OSes, follow [the wiki](https://devkitpro.org/wiki/Getting_Started) to install it)
- The C/C++ compiler, and make (`sudo apt install build-essential` SHOULD do the job)
- Some knowledge on how compiling and 3DS homebrew dev works (should come back in handy when compiling for the first time)
- NOTE FOR WINDOWS USERS: make sure to have citra (and citra-qt/room) in your PATH, else you have to point the location of your executable in the makefile in the `citra` and `run` targets


This project uses the [3DS template](https://github.com/TricksterGuy/3ds-template) from TricksterGuy, so shoutout to him.
