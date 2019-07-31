#include <stdio.h>
int main(void)
{
    unsigned int o[16]={01,02,04,010,020,040,0100,0200,0400,01000,02000,04000,01000000};
    unsigned int d[16]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
    unsigned int h[16]={0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80,0x100,0x200,0x400,0x800,0x1000,0x2000,0x4000,0x8000};
    unsigned char c[8]={'\1','\2','\4','\10','\20',' ','@','\200'};
    unsigned int ro[16],rd[16],rh[16],x;
    unsigned char rc[8],ch;
    unsigned int i;
    printf("\n\n Enter any symbol: ");
    scanf("%c",&ch);
    for(i=0;i<8;i++) {
        if(ch&o[i])ro[i]=1;else ro[i]=0;
        if(ch&d[i])rd[i]=1;else rd[i]=0;
        if(ch&h[i])rh[i]=1;else rh[i]=0;
        if(ch&c[i])rc[i]=1;else rc[i]=0;
    }
    printf("\n\n Ch= %c \n",ch);
    printf("\n RO: ");
    for(i=0;i<8;i++) printf("%3d",ro[7-i]);
    printf("\n RD: ");
    for(i=0;i<8;i++) printf("%3d",rd[7-i]);
    printf("\n RH: ");
    for(i=0;i<8;i++) printf("%3d",rh[7-i]);
    printf("\n RC: ");
    for(i=0;i<8;i++) printf("%3d",rc[7-i]);
    printf("\n\n Enter an integer: ");
    scanf("%d",&x);
    for(i=0;i<16;i++) {
        if(x&o[i])ro[i]=1; else ro[i]=0;
        if(x&d[i])rd[i]=1; else rd[i]=0;
        if(x&h[i])rh[i]=1; else rh[i]=0;
        if(x&c[i])rc[i]=1; else rc[i]=0;
    }
    printf("\n\n X= %d \n",x);
    printf("\n RO: ");
    for(i=0;i<16;i++)printf("%3d",ro[15-i]);
    printf("\n RD: ");
    for(i=0;i<16;i++)printf("%3d",rd[15-i]);
    printf("\n RH: ");
    for(i=0;i<16;i++)printf("%3d",rh[15-i]);
    return 0;
}
