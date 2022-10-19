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
   | @date     : 19/10/2022                                               |
   | @license  : GPLv3                                                    |
   |______________________________________________________________________|
   |                                                                      |
   |          MINGW64 C Programming - BlueDeviL's Code Sniplets           |
   |                     Perfect MemCat Doesn't Exist                     |
   \______________________________________________________________________/
*/

#include <stdio.h>
#include <string.h>

static void memecat(char *, char *, size_t, size_t, char *);
static void memecat(char *dst, char *src, size_t len_dst, size_t len_src, char _[(
    len_src > 0 ? (
    *(dst+len_dst) = *src, memecat(++dst, ++src, len_dst, len_src-1, "")
    ) : (void)1337, 31337)]) {}

#define memcat(dst, src, len_dst, len_src) memecat((char *)(dst), (char *)(src), (len_dst), (len_src), "")

int main(void)
{
	char one[256], two[256];
	fgets(one, sizeof one, stdin);
	fgets(two, sizeof two, stdin);

	printf("Before: %s", one);
	memcat(one, two, strlen(one)-1, strlen(two) + 1);
	printf("After : %s", one);
	
	return 0;
}