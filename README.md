# libhandy-no-force-theme

A library that can be LD_PRELOADed to prevent an application built with libhandy from forcing a specific theme.

![before](https://github.com/tatokis/libhandy-no-force-theme/blob/master/img/before.png?raw=true)
![after](https://github.com/tatokis/libhandy-no-force-theme/blob/master/img/after.png?raw=true)

## Usage for individual applications

```bash
LD_PRELOAD=libhandy-no-force-theme.so.0 eog
```

## System-wide installation

To install globally, make sure that cmake is called with the correct prefix set as follows:

```bash
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr
sudo make install
```

If the library is installed in `/usr/local` then every time sudo is called, it will throw a warning about not being able to load it as `51libhandy-no-force-theme` will attempt to LD_PRELOAD it to every application.
