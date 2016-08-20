# Space Fortress (Working Title)

Space Fortress (Working Title) aims to be an open-ended, mostly realistic (physics-wise), medium-soft sci-fi procedurally generated galaxy simulator/sandbox/roguelike in the vein of Dwarf Fortress, rendered in pure ASCII.

## Compiling `sfwt` from source
### \*Nix (GNU/Linux, Mac OS X\*, \*BSDs\*)
\* - while currently untested, the instructions should work for any modern version of those systems.

#### Dependencies

You need the following dependencies installed in order to build `sfwt`:  
*  `cmake`  
* `C++14`-compatible compiler (newer versions of `clang`, `g++` etc)
* `ncurses`

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

### Windows  

[Coming soon]
