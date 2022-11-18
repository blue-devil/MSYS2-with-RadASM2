/*  ______________________________________________________________________
   |  ______ __          ,.'   __.'.__  .   ______               ___      |
   | |      |  |         /b`  '-.   .-'  d\|      ;             |   |     |
   | |   __ |  |        .5h     /.'.\    =5|   _   \            |   |     |
   | |.  1 \|  |        (0=h    '   '    =C)   1\   \        .--:.  |     |
   | |   1_/|  |        ?3==,          .==7|   | \   \       |__|   |     |
   | |.     | .-- -.-----{=`==oo____oo==`=}|   |  |.----.-- -.--:.  |     |
   | |.  __ | |  V |  ^__|'"o58888888888,; |.  |  ||  ^_|  V |  |.  |     |
   | |:  1 \|_|____|_____| `?88P^\,?88^\P  |.  | / |____|\___|__|:  |___  |
   | |:  1_/   /            C8?\__d88\_/'  |:  1/   / .         |:  1   | |
   | |::.. .  /             `8o8888/\88P   |::.. . /            |::.. . | |
   | `-------'               '7oo88oo8P    `------'             `-------' |
   |                     Cooo##~\/\/\/~====>        github.com/blue-devil |
   |                                                 gitlab.com/bluedevil |
   | Freedom doesn't come from second-hand thoughts.      www.sctzine.com |
   |______________________________________________________________________|
   | @author   : Blue DeviL <bluedevil@sctzine.com>                       |
   | @tester   : ErrorInside <errorinside@sctzine.com>                    |
   | @IDE      : RadASM v2.2.2.4                                          |
   | @template : Blue DeviL                                               |
   | @date     : 18/11/2022                                               |
   | @license  : GPLv3                                                    |
   |______________________________________________________________________|
   |                                                                      |
   |          MINGW64 C Programming - BlueDeviL's Code Sniplets           |
   |                          99 Bottles of Beer                          |
   \______________________________________________________________________/
*/
#include <stdio.h>
#include <stdlib.h>

void print_song(void)
{
    char sverse1[] = "%s bottle%s of beer on the wall, %s bottle%s of beer.\n";
    char sverse2[] = "Take one down and pass it around, %s bottle%s of beer on the wall.\n\n";
    char sverse3[] = "Go to the store and buy some more, 99 bottles of beer on the wall.\n\n";

    char sBeer1[3];
    char sBeer2[3];
    int nBeer = 99;
    while (nBeer >= 0)
    {
        sprintf(sBeer1, "%d", nBeer);
        sprintf(sBeer2, "%d", nBeer - 1);
        if (nBeer == 2)
        {
            printf(sverse1, sBeer1, "s", sBeer1, "s");
            printf(sverse2, sBeer2, "");
        }
        else if (nBeer == 1)
        {
            printf(sverse1, sBeer1, "", sBeer1, "");
            printf(sverse2, "no more", "s");
        }
        else if (nBeer == 0)
        {
            printf(sverse1, "No more", "s", "no more", "s");
            printf(sverse3);
        }
        else
        {
            printf(sverse1, sBeer1, "s", sBeer1, "s");
            printf(sverse2, sBeer2, "s");
        }

        nBeer--;
    }
}

int main(void)
{
    print_song();

    return EXIT_SUCCESS;
}
