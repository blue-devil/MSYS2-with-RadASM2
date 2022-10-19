# MSYS2-with-RadASM2

This repo provides related and needed files to code with Mingw64 and Mingw32 with [RadASM2][web-github-radasm2-release]. [MSYS2][web-msys2] Project hosts a variety of building tools such as mingw64/mingw32, clang64, ucrt64 and much more.


[![](https://img.shields.io/badge/MSYS2%20-20220904%20-yellow.svg?style=flat-square&colorB=8d4c83&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAMAAABEpIrGAAAAt1BMVEUAAACZmZnTXmT5+fmZmZnTXmT5+fmZmZnTXmTsxcf5+fmZmZnTXmT5+fnTXmTx2tv5+fnTXmT5+fmZmZnTXmT5+fmZmZnTXmT5+fnTXmT5+fmZmZnTXmTm5ub5+fmZmZnTXmTvz9D5+fmZmZnTXmT5+fmZmZnFxcXNzc3TXmT5+fmZmZnTXmT5+fmZmZnTXmT5+fmZmZmfn5+lpaWrq6u9vb3JycnTXmTb29vh4eHn5+fz8/P5+fnAmjdlAAAAMXRSTlMAEBAQICAgMDAwMEBAQFBQUGBgcHBwgICAj4+fn5+fr6+vr7+/v8/Pz8/P39/f7+/vUe+MYwAAAVhJREFUeNrNkWUW4zAMhKdMTrkNlpmZff9zraWqnN3f+xUyL5onaWz8V5Qdp/zQyaKTxRdZbXDEa6SHbwbm7ZpVUoca1vTaItUkNZ5tNn4EjLQlapAGhw3RwospG5rS4Li582phaWYAxGjWVgwpEDKXl5BZx3NtSAYIPNejSlJmaYcM/tNgis0ax7CMItEw9WUcAs3N8hqOqSa1rFl5NnC0noINA1rUPG87yjD0Xw3KiOk7FtaSc7bpPRusY3KWekGnfpWYvWcDOvouG8qUeS+GijSgeADHWMdIXC+Xy6g+4xjcoPm8RYcFk8yl3jfgGaI8NmSf97wQmVxTA6LJywjOUyHrxJBQaSgUOhmloghjNTnl56oaBPN5gDDmgasCu10NJtU2wkivXJT6q3R0MgkfYauTSpxWyKcnNsI4BXOFVRv9fj/ckLftBFZVKNtW+CunNP6Niwd/ADstSfotxUeaAAAAAElFTkSuQmCC)](https://www.msys2.org/) [![](https://img.shields.io/badge/MINGW%20-12.2.x%20-green.svg?style=flat-square&colorB=71b21f&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACAAAAAgCAYAAABzenr0AAAAGXRFWHRTb2Z0d2FyZQBBZG9iZSBJbWFnZVJlYWR5ccllPAAAAdVJREFUeNrMVoFxwyAMND0P4A3qbJAVskBnICN4kozgzNAFskI2SDqBvQHV57APY4QE7V2rOw774PVvGUk0TYE55440HpgLcZbGVIpLkcOJK3HmyV0pLkeudhaR14lgyEVnDHmZCIGcdSaQ60TQYqcgD511gWitTUny4fO9K/gSmI1woxb3liBHWB40W2PMlZ7Pwp86Yx/2e9yR3oG5anBtgvxGA18y0nuDTaQUy6NAvqzf6P0EER5nORweWoZ8sZyIFHnj8TkRK/kqgCHPieDIJREbcpgRyDdhu3x8QURPTp4Z8tBmGifC3ZEdhLvHGyBgUpAvdiBnIO9x4JSY2ePm1CKyYFA6QgSeiABmRXasxwvkS53YCUBYNanmw/9KNcyVuF3lM0EWcP80dKLJghzudSbCs2CiOrAjYcglETncTkRcCS0N551qyrGtwOUbkT/lNb2g/81u2Lsy6ytwjz+PQKob2h92Qw1uPYhtJgtqu6GE22RBK9SBmm6Yw+1SsBWKUG03TOEuqfw3yq5W2w1DXEe4+V92w5PfpOqGr1jqu+FyH2D9G8WNaA0jk7KjdBnJKTTCnZAlF0SoyFPdMBaRJWdEqMl3AiIRg4Y8EnEpIYd9CzAAWKtwzXvloAcAAAAASUVORK5CYII=)](https://www.msys2.org/) [![](https://img.shields.io/badge/RadASM%20-v2.2.2.x%20-red.svg?style=flat-square&colorB=C94C1E&logo=data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABQAAAAgCAYAAAASYli2AAACcklEQVR42tWVXWiPURzHz/FyQZOiVuatuFEoKzfKSCs35EJeCqFcEEa5s2heNrXiApuXFDYveUlKSywlIRfczM0WjZvJlGKTRLb5fHvOU6fT+T/PY3bj1Kff8z8vn+f8znPO+dshihnBYv8L4awRcl2FRTarBy8bQzgEjdbabzl9nxCW2IwOFYTrsBTKEH7PET4lLLYlGpcTrkC5qxqL8HeO8CVhoQ0qRxMOw34Y5TVVIPyYI+whTLVehZ9iWgZAL1mN8G6GbArhA/TZEilqKx2HCbADXkAV0oESwhOEfdChbXOUh1ovxS+wlcH3aNvC82VX3wx7Qyl9NhEugXZEU7ixX8E6Br13nTVDPU927R3QCl0wTX2h2rUNQqUv/ATLkHUGM1hLuBF8pFipZ+zBcIZKpw1O0vjYk24mnIXxEZHGNMIBxgxJ2M2P2PF7DafhGh1/0G8Gzzv1cWASfIZn0EJ7VzpIQqWyUguulFUXiDXwApxhYE9O2ibc2PMJNbAxkp5Oyh3NGvHzQkJPrK/aANtLjNNuOAU3kf/KFTrpGsJtaIdxbu3C0gvn4Dzi3qLCI3Su4/cCnnfDBvcCv/yEW0a7o6gwWI5tJvniMwutYZbQa9elsUqzgun/JKStjKAzvAvmDXuG1M1xqerkTAyG6Cy3FREeM8k2kag6MomvcBGaefG7LOF6k1wK6SUbFl0iOpqt/v+NjYjmEva4NQpPi9K6b5JN/UiXQTg+vbF1nlc4USytPpNcok1Iuk1G0eWgS0Hnd3akXbeIbuqWvP9lXxhOW2k9cOvzMJZWUWG/Sf4/lNbbv5GEwjeSSIaof7iitPwBoSgbVud1Jo0AAAAASUVORK5CYII=)](http://www.softpedia.com/get/Programming/File-Editors/RadASM.shtml)


## Setup

First install MSYS2 with MINGW64/MINGW32
* Download [MSYS2 Installer][web-msys2-releases]
  * Alternatively use winget `winget install -e --id msys2.msys2`
* Install MSYS2 to your `C:\` drive
* Open Start Menu and run `MSYS2 MSYS`
* Run the commands below for installing MINGW64/MINGw32

```bash
pacman -S --needed base-devel
pacman -Syyu
pacman -S mingw-w64-x86_64-toolchain
pacman -S mingw-w64-i686-toolchain
```

RadASM setup is easy:
* Extract [RadASM2][web-github-radasm2-release] to wherever you want.
* Extract the files i have listed below to RadASM folder:
```
RadASM\MINGW32.ini
RadASM\MINGW64.ini
RadASM\MSYS2
RadASM\Addins
```

* Open `RadASM.ini` with your fav editor and add `MINGW32` and `MINGW64` under `Assembler` section; look at the sample below:
```
[Assembler]
Assembler=MINGW32,MINGW64,MASM64,masm,UASM32,UASM64,nasm,mingw
```

**NOTE1**: You don't have to write that much programming languages like me. But you must add at least one programming language to run RadASM2.

**NOTE2**: Don't let the last `mingw` make you confused. It is the old mingw from the old `www.mingw.org` era, see [Does anybody know the status of www.mingw.org?][web-stackoverflow-old-mingw]. 

## TODO
* [x] Check types in MINGW64Type.api and MINGW32Type.api
* [x] Edit/Fix Code section in MINGWxx.ini
* [x] Implement Debug parameters under `Project>xxx` section in MINGWxx.ini
* [ ] When using structures ,like OPENFILENAME, after pressing dot the menu of struct elements are `sometimes` showing.
* [ ] CppParse parses `struct stName{...};` but not `struct{...}stvarname;`
* [ ] User created functions aren't parsed and highlighted.

## Resources
* [MSYS2][web-msys2]
* [RadASM2][web-github-radasm2]
* [RadASM2 v2.2.2.4][web-github-radasm2-release]

## Contributors
* [Blue DeviL // SCT][web-github-bluedevil]

## License
This project is under GPLv3 license.

[web-github-bluedevil]: https://github.com/blue-devil
[web-msys2]: https://www.msys2.org/
[web-msys2-releases]: https://github.com/msys2/msys2-installer/releases
[web-github-radasm2-release]: https://github.com/blue-devil/RadASM2/blob/master/Release/RadASM-2.2.2.4-FullPackage.zip
[web-github-radasm2]: https://github.com/mrfearless/RadASM2
[web-stackoverflow-old-mingw]: https://stackoverflow.com/questions/65661720/does-anybody-know-the-status-of-www-mingw-org
