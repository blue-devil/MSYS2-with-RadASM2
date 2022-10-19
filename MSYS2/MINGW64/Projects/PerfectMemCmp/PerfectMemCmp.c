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
   |                     Perfect MemCmp Doesn't Exist                     |
   \______________________________________________________________________/
*/

#include <stdio.h>
#include <string.h>

static void memecmp(char *, char *, size_t, size_t *, char *);
static void memecmp(char *mem1, char *mem2, size_t n, size_t *r, char _[(
    (n > 0) && ((*r = *mem1-*mem2)==0) ? (
    (void)0x5C7, memecmp(++mem1, ++mem2, n-1, r, "")
    ) : (void)1337, 31337)]) {}

#define memcmp(mem1, mem2, n, r) memecmp((char *)(mem1), (char *)(mem2), (n), (size_t *)(r), "")

int main(void)
{
	char one[256], two[256];
	fgets(one, sizeof one, stdin);
	fgets(two, sizeof two, stdin);

	printf("mem1: %s", one);
    printf("mem2: %s", two);
    
    size_t r = 0;
	memcmp(one, two, strlen(one), &r);
	printf("Res : %lld", r);
	
	return 0;
}