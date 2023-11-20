#include <stdio.h>
/********************************************************************************************/
/* function to encryption or decryption with the key */
/******************************************************************************************/
void cyber(char * arr ,int c,int key,int CESAR{

	key%=26;
    
	if(CESAR==2){
        key*=-1;
    }
	
	for(int i = 0; i<c ;i++){
        if(arr[i]==' ')
        {
            continue ;
        }
        if(arr[i] <='Z'&&arr[i] >='A')
        {
       arr[i] = arr[i] +key;
       if(arr[i]>'Z')
	    {
           arr[i]-=26;
        }
       if(arr[i]<'A')
	    {
           arr[i]+=26;
        }
         continue ;   
        }
        if(arr[i] <='z'&&arr[i] >='a')
        {
			arr[i] = arr[i] +key;
	    
			if(arr[i]>'z')
			{
				arr[i]-=26;
			}
			if(arr[i]<'a')
			{
				arr[i]+=26;
			}
           
        }
  }
	
    
}
int main() {
    // Write C code here
   
    char name[100]={0} ;
    
    int c= 0 , CESAR=1;
    unsigned int key;
	// get the string from the user  with space
    printf("enter u string \n ");
     

    for(int i =0;;i++){
		scanf("%c", &name[i]);
		if (name[i]=='\n')
		{
			break;
		}
    }
	// chosie encryption or decryption
    printf("encryption : 1 \n decryption : 2 \n  ");
    scanf("%d", &CESAR);
    // enter the key form 0 to 255
    printf("enter u key\n ");
    scanf("%d", &key);
  // calculate the size of string   
    c =sizeof(name);
	//call function
    cyber(name ,c ,key , );
	//print the output of encryption or  decryption
    printf("%s ",name);
    return 0;
}