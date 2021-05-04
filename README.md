# Ikaruga

##### A light-weight clone of the bullet hell shooter game.

<img src="https://i.imgur.com/pSzG1XM.png" alt="screenshot of game" width="400"/>

### Dependencies

- [gcc](https://gcc.gnu.org/) or [clang](https://clang.llvm.org/ ) or [MSVC 2015+]("https://www.visualstudio.com/")
- [cmake](https://cmake.org/)

### Ubuntu

```
 $ sudo apt-get install gcc cmake
```

### MacOS

```
$ brew install gcc cmake
```

### Windows

- [Visual Studio 2015+](https://visualstudio.microsoft.com/)

## Quick Start

### CMake

#### Linux

```
$ git clone https://github.com/uiuc-sp21-cs126/final-project-rishisek-illinois.git
$ mkdir build
$ cd build/
$ cmake ..
$ make
$ ./ikaruga
```

#### Windows

```
> git clone https://github.com/uiuc-sp21-cs126/final-project-rishisek-illinois.git
> mkdir build
> cd build
> cmake ..
> cmake --build .
> .\ikaruga
```

## Controls

### Player movement

| Key | Action |
|-----|--------|
| `W` | Up |
| `A` | Left |
| `S` | Down |
| `D` | Right |

### Bullet action

| Key | Action |
|-----|--------|
| `ENTER` `RETURN` | Fire a bullet |
| `RSHIFT` | Switch bullet type |
| `LEFT` | Tilt aim left |
| `RIGHT` | Tilt aim right |