# pico-tutorial

Repository contenente gli esempi trattati nell'articolo -- di antima.it.

## Contenuti

- [pico-tutorial](#pico-tutorial)
  - [Contenuti](#contenuti)
  - [Installazione della pico-sdk](#installazione-della-pico-sdk)
  - [Startup del progetto cmake](#startup-del-progetto-cmake)
  - [Build e upload](#build-e-upload)

## Installazione della pico-sdk

https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf

L'installazione è nativamente descritta per sistemi debian-like ed in aprticolare usando il Raspberry Pi OS. Il capitolo 9 include metologie utilizzabili per Windows e Mac.
## Startup del progetto cmake


Template base per un generico progetto cmake per pico chiamato **myproject**:

```cmake
cmake_minimum_required(VERSION 3.12)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
project(myproject C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(myproject main.c)
target_link_libraries(myproject pico_stdlib)

pico_add_extra_outputs(myproject)

```

## Build e upload

Buildare progetti usando vscode con il plugin cmake tools è intuitivo e diretto. Caricare file è anche molto semplice, usando i binari uf2 e caricandoli usando un approccio drag & drop..

Ho comunque incluso un semplice makefile per GNU make, tramite cui è possibile flashare il binario su pico usando:

```bash
make flash
```

**N.B.** su windows, suppongo che il pico venga montato sull'unità **"D:"**, se così non fosse, il makefile va cambiato a mano.