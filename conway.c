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
