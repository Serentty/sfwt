# Starfell 
(Note: this README is still incomplete.)

Starfell (aka SFWT) aims to be an open-ended, mostly realistic (physics-wise), medium-soft sci-fi procedurally generated galaxy simulator/sandbox/roguelike in the vein of Dwarf Fortress, rendered in ASCII, on the back of the SFML library.  
(That's a lot of buzzwords, we know. And a very broad scope.)

Currently, the project is in a *very* early stage of development (and will likely remain that way for a *very long while*) - as such, don't expect particularly rich gameplay (if any) or blazing-fast, bug-free code.

Currently we do not provide downloadable pre-compiled binaries, so you will have to compile the project yourself if you want to run it. See the "Compiling `sfwt` from source" section for instructions.

## Compiling `sfwt` from source
### GNU/Linux  

#### Dependencies

You need the following dependencies installed in order to build and run `sfwt`:  
*  `cmake`  
* `C++17`-compatible compiler (`clang`, `g++` etc)
* `sfml` (`sfml-dev` in some distributions)
* `yaml-cpp`
* `boost` (the game doesn't use it, but the above library does)

It is recommended to use the newest versions available for your system/distribution.

##### Cloning the repository

```
git clone https://github.com/Gareth422/sfwt.git
```

#### Building and running   

```
$ cd sfwt  
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./sfwt
```

### OS X/macOS

[Coming soon]

### Windows  

Build on Windows using MSYS2. The same libraries are required, and can all be found in the repositories.

## Contributing & Licensing

If you're interested, you can join us on our IRC channel at Freenode, using either a dedicated IRC client or a web client, such as [this one](http://webchat.freenode.net/?channels=sfwt).
