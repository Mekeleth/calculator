# Engineer's Calculator
The calculator that lets you convert number between three given bases: binary, decimal or hexadecimal.

## Installation
In order to compile the project, you need to install *GTKMM* library:
[https://www.gtkmm.org/en/download.html](https://www.gtkmm.org/en/download.html)

## Compilation
In order to compile main.cxx, type in your console:
```
$ g++ main.cxx --std=gnu++14 `pkg-config gtkmm-3.0 --cflags --libs`
```
