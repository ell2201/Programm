#include <stdio.h>
int main(int argc, char **argv)
{
	char s[80],prev=' ',c,a;
	int i=0;
	while((c=getchar( ))!=' ')
	{
		if((c==' ')&&(prev==' '))
		{
			continue;
		}
		s[i]=c;
		i++;
		prev=c;
		if(c=='.')
		{
			s[i]='\n';
            i++;
            prev=' ';	
		}
		}
	s[i]='\0';
	puts(s);
	a=0;
	i=0;
	while(s[i]!='\n')
	{
		if(s[i]==' ')
		{
			a++;
		}
		i++;
	}
	printf("kolicetvo slov: %d",a+1);

	return 0;
}

