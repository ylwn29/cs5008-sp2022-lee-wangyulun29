// name: Yulun Wang
// email: wang.yulun@northeastern.edu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
 
int getrepeat(char *str,char ch)
{
    char *ptr=str;
    int repeat=0;
    while(*ptr==ch)
    {
        ptr+=1;
        repeat++;    
    }
    return repeat;        
}

char *runlengthencoding(char *str,char *rle )
{
    char *ptr=str;
    char *ptrend=&str[strlen(str)];
    char encoding[100];
    int repeat;
    strcpy(rle,"");

    while(ptr<ptrend)
    {
        repeat=getrepeat(ptr,*ptr);
        if(repeat>1)
        {
            sprintf(encoding,"%c%d",*ptr,repeat);
            strcat(rle,encoding);
            ptr=ptr+repeat;
        }else
        {
            sprintf(encoding,"%c",*ptr);
            strcat(rle,encoding);
            ptr++;
        }
    }
    
    return rle;    
}

int getcount(char *rle)
{   
    int count=0;
    //
    // Add your code here to return count for the current char
    // see count in decode_rle
     
    return count;
}

char *decode_rle(char *rle, char *str)
{
    char *ptr=rle;
    char *ptrend=&rle[strlen(rle)];
    char decoding[100];
    int i=0,j=0,count=0, digit=0;
    strcpy(str, "");
    //
    //
    // Add your code here to decode rle
    char temp[100];
    strcpy(temp,""); 
    for (i=0;i<strlen(rle);i++){
        if (isalpha(rle[i])){
	    digit=i;	    
	    if(isdigit(rle[i+1])){
		while (isdigit(rle[i+1])){		   		
		    strcat(temp,&rle[i+1]); 		    		    
		    i++;   		    		    
	        }		
	        int count=atoi(temp);		
		for (j=0;j<count;j++){		
	            sprintf(decoding,"%c",rle[digit]);
		    strcat(str,decoding);
	        }
	        strcpy(temp,"");
	    }else{
	        sprintf(decoding,"%c",rle[digit]);
		strcat(str,decoding);
	    }
    	}	
    }
    //str[i] = '\0';
    return str;
}


int main()
{
    char str_org[]="WWWWWWWWWWWWWWWWWWWWWWWWWWWWbAAAABBCBBCBBCaaa";
    char rle[100];
    runlengthencoding(str_org,rle);
    printf("str_org:[%s] => rle:[%s]\n",str_org,rle);

    char str_dec[100];
    decode_rle(rle,str_dec);
    printf("rle:[%s] => str_dec:[%s]\n",rle, str_dec);
    return 0;
}
