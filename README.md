# conway.c

[Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) implementation in C formatted as [Glider](https://en.wikipedia.org/wiki/Glider_(Conway%27s_Game_of_Life)). Inspired by [donut.c](https://www.a1k0n.net/2006/09/15/obfuscated-c-donut.html).

```c

                 x,y,cx,cy,dx,
                 dy,n,f[8][16]
                 ,b[8][16];main
                 (){f[0][1]=1;
                 f[1][2]=1;f[2
                 ][0]=1;f[2][1
                 ]=1;f[2][2]=1

                                 ;for(;;){for(cy
                                 =0;cy<8;++cy){
                                 for(cx=0;cx<16
                                 ;++cx){printf(
                                 "%c",".#"[f[cy
                                 ][cx]]);n=0;for
                                 (dx=-1;dx<=1;++

dx)for(dy=-1;    dy<=1;++dy)if   (!(dx==0&&dy==
0)){x=((cx+dx    )%16+16)%16;y   =((cy+dy)%8+8)
%8;if(f[y][x]    )n+=1;}b[cy][   cx]=f[cy][cx]?
(n==2||n==3):    n==3;}printf(   "\n");}memcpy(
f,b,sizeof(f)    );printf("\033" "[%dA\033[%dD"
,8,16);usleep    (100*1000);}}   // (c) Tsoding
```

## Files

- [conway.c](./conway.c) - the obfuscated version formatted as Glider,
- [conway.obfus.c](./conway.obfus.c) - the obfuscated unformatted version,
- [conway.orig.c](./conway.orig.c) - the original unobfuscated version,
- [imgformat.c](./imgformat.c) - the C code formatter.

## Build the Obfuscated Version

```console
$ gcc -std=c90 -w -o conway conway.c
$ ./conway
```

## Recreate the Obfuscated Version

```console
$ cc -o nob nob.c
$ ./nob
$ ./build/imgformat ./conway.obfus.c ./images/glider.png
```
