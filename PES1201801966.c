#include<stdio.h>

#include<stdlib.h>

#include<string.h>
#include "intal.h"





char* intal_add(const char* intal1, const char* intal2)

{

    int l1=strlen(intal1);

    int l2=strlen(intal2);

    int max=l1>=l2?l1:l2;

    int ind3=max-1;

    char * new=(char*)malloc(sizeof(char)*(max+1));

    new[max]='\0';

    int car=0;

    int i;

    if(l1!=l2)

    {   int ind1=l1-1;

        int ind2=l2-1;

        int min;

        //int which;

        if(l1==max)

           { min=ind2; 

           //which =1;

           }

        else 

            {min=ind1;

            //which=2;

            }

        

        for(i=min;i>=0;i--)

        {

            int c1=intal1[ind1] - '0' ;// atoi(intal1[ind1]);

            int c2=intal2[ind2]- '0' ;// atoi(intal2[ind2]);

            int ans=c1+c2+car;

            int add=ans%10;

            car=ans/10;

            new[ind3]=add +'0';

            ind1--;

            ind2--;

            ind3--;

        }

        if(l1>l2)

        {

            if(car!=0)

                {   

                    int c1=intal1[ind1] - '0';

                    int ans=car+c1;
                    car=ans/10;
                    ans=ans%10;
                    new[ind3]=ans + '0';

                    ind3--;

                    ind1--;

                    

                }

            while(ind1>=0)

            {
                int c1=intal1[ind1]-'0';
                int ans=c1+car;
                car=ans/10;
                ans=ans%10;
                new[ind3]=ans+'0';

                ind3--;

                ind1--;

            }
            if(car!=0)
            {
            char * newf=(char*)malloc(sizeof(char)*(max+2));
            newf[max+1]='\0';
            newf[0]=car+'0';
            for(int g=max;g>=1;g--)
            newf[g]=new[g-1];
            free(new);
            return newf;
            }

        }

        else

        {

            if(car!=0)

                {   

                    int c1=intal2[ind2] - '0';

                    int ans=car+c1;
                    car=ans/10;
                    ans=ans%10;
                    new[ind3]=ans + '0';

                    ind3--;

                    ind2--;

                    //car=0;

                }

            while(ind2>=0)

            {   
                int c1=intal2[ind2]-'0';
                int ans=c1+car;
                car=ans/10;
                ans=ans%10;
                new[ind3]=ans+'0';

                ind3--;

                ind2--;

            }
        if(car!=0)
        {
            char * newf=(char*)malloc(sizeof(char)*(max+2));
            newf[max+1]='\0';
            newf[0]=car+'0';
            for(int g=max;g>=1;g--)
            newf[g]=new[g-1];
            free(new);
            return newf;
        }

        }

        

        return new;



    }

    else

    {

        int ind=l2-1;

        for(i=l2-1;i>=0;i--)

        {

            int c1=intal1[ind] - '0' ;

            int c2=intal2[ind] - '0' ;

            int ans=c1+c2+car;

            int add=ans%10;

            car=ans/10;

            new[ind3]=add +'0';

            ind--;

            ind3--;

            

        }

        if (car!=0)

        {

            char * newf=(char*)malloc(sizeof(char)*(max+2));

            newf[0]=car+'0';

            newf[max+1]='\0';

            ind3=max-1;

            for(i=max;i>0;i--)

            {

                newf[i]=new[ind3];

                ind3--;

            }

            free(new);

        return newf;

         }

         return new;

        

    }

}



int intal_compare(const char* intal1, const char* intal2)

{

    int l1=strlen(intal1);

    int l2=strlen(intal2);

    if(l1>l2)

    {

        return 1;

    }

    else if(l1<l2)

    {

            return -1;

    }

    else

    {int i;

        for( i=0;i<=l1-1;i++)

        {

            if(intal1[i]!=intal2[i])

            break;

        }

        if(i==l1)

        return 0;

        else

        {

            if(intal1[i]>intal2[i])

            return 1;

            else

            {

                return -1;

            } 

        }

    }

}



char* intal_diff(const char* intal1, const char* intal2)

{

    int l1=strlen(intal1);

    int l2=strlen(intal2);

    int whichgreat=intal_compare(intal1,intal2);
    char *i1;char* i2;
    if(whichgreat==1)
    {   if(intal1[l1-1]!='\0')
        { i1=(char*)malloc(sizeof(char)*(l1+1));

        for(int j=0;j<l1;j++)
        {
        i1[j]=intal1[j];    }
        i1[l1]='\0';
        }
        else
        { i1=(char*)malloc(sizeof(char)*(l1));
            for(int j=0;j<l1;j++)
            {   i1[j]=intal1[j];}
        }
        if(intal2[l2-1]!='\0') 
        {    i2=(char*)malloc(sizeof(char)*(l2+1));
            for(int j=0;j<l2;j++)
            {
            i2[j]=intal2[j];    }
            i2[l2]='\0';
        }
        else
        {
             i2=(char*)malloc(sizeof(char)*(l2));
            for(int j=0;j<l2;j++)
            {i2[j]=intal2[j];}
        }
        
        // i1[l1]='\0';i2[l2]='\0';
    }
    if(whichgreat==-1)
    {
        if(intal2[l2-1]!='\0')
        { i1=(char*)malloc(sizeof(char)*(l2+1));

        for(int j=0;j<l2;j++)
        {
        i1[j]=intal2[j];   }
        i1[l2]='\0';
        }
        else
        { i1=(char*)malloc(sizeof(char)*(l2));
            for(int j=0;j<l2;j++)
            {   
            i1[j]=intal2[j];    }
        }
        if(intal1[l1-1]!='\0') 
        {    i2=(char*)malloc(sizeof(char)*(l1+1));
            for(int j=0;j<l1;j++)
            {
            i2[j]=intal1[j];    }
            i2[l1]='\0';
        }
        else
        {
             i2=(char*)malloc(sizeof(char)*(l1));
            for(int j=0;j<l1;j++)
            {i2[j]=intal1[j];}
        }
        // i1[l2]='\0';i2[l1]='\0';
        //line 414 and 415 repeated here.
    }

    if(whichgreat==0)

    {

        char *ans=(char*)malloc(sizeof(char)*2);

        ans[0]='0';

        ans[1]='\0';

        return ans;

    }

    // int bor=0;
    l1=strlen(i1);
        l2=strlen(i2);
    int ind1=l1-1;
    int ind2=l2-1;
    int ind3=999;
    int diff=l1-l2;
    char *new=(char*)malloc(sizeof(char)*1001);new[1000]='\0';
    int i;
    for(i=ind2;i>=0;i--)
    {
        int c1=i1[ind1]-'0';
       int c2=i2[ind2]-'0';
      int ans=c1-c2;
      if(ans<0)
      {
          int c3=i1[i-1+diff]-'0';
          c3--;
          if(c3!=-1)
          i1[i-1+diff]=c3+'0';
          else
          {
              c3++;
              int g=i-2;
              while(c3==0)
              {
                  c3=i1[g+diff]-'0';
                  g--;
              }
              g++;
              c3--;
              i1[g+diff]=c3+'0';
              g++;
              while(g!=i)
              {
                  i1[g+diff]='9';
                  g++;
              }
          }
          ans=c1-c2+10;
          new[ind3]=ans+'0';
      }
      else
      {
          new[ind3]=ans+'0';
      }
      ind1--;
      ind2--;
      ind3--;
    }
    while(ind1>=0)
    {   if(ind1==0 && i1[ind1]=='0')
        {ind1--;continue;}
        new[ind3]=i1[ind1];
        ind1--;
        ind3--;
    }
    int z=0;
    if(new[ind3+1]=='0')
    {
        while(new[z+ind3+1]=='0')
        z++;
    }
    char* newf=(char*)malloc(sizeof(char)*(1000-ind3-z));
    newf[1000-ind3-1-z]='\0';
    int ind=999;
    for(int h=1000-ind3-2-z;h>=0;h--)
    {
        newf[h]=new[ind];
        ind--;
    }
    free(new);
    return newf;
}



char* intal_multiply(const char* intal1, const char* intal2)
{
    int l1=strlen(intal1);
    int l2=strlen(intal2);
    if(strcmp(intal1,"0")==0 || strcmp(intal2,"0")==0)
    {
        char *r=(char*)malloc(sizeof(char)*2);
        r[0]='0';r[1]='\0';
        return r;
    }
    
    char *i1;char* i2;
    if(l1>=l2)
    {
        
         i1=(char*)malloc(sizeof(char)*(l1+1));i1[l1]='\0';
         i2=(char*)malloc(sizeof(char)*(l2+1));i2[l2]='\0';
        for(int i=l1-1;i>=0;i--)
        i1[i]=intal1[i];
        for(int i=l2-1;i>=0;i--)
        i2[i]=intal2[i];
       }
       else
       {
            i1=(char*)malloc(sizeof(char)*(l2+1));i1[l2]='\0';
         i2=(char*)malloc(sizeof(char)*(l1+1));i2[l1]='\0';
        for(int i=l2-1;i>=0;i--)
        i1[i]=intal2[i];
        for(int i=l1-1;i>=0;i--)
        i2[i]=intal1[i];
       } 
        
        l1=strlen(i1);
        l2=strlen(i2);
        char * r=(char*)malloc(sizeof(char)*2);r[0]='0';r[1]='\0';
        int i,j;
        int ind1=l1-1;
        int ind2=l2-1;
        
        int car=0;
        int c1,c2;
        int z=0;
        for(i=ind2;i>=0;i--)
        {   car =0;
            c2=i2[i]-'0';
            char * i3=(char*)malloc(sizeof(char)*(l1+1+z));i3[l1+z]='\0';
            int ind3=l1-1;
            for(int k=1;k<=z;k++)
            {
                i3[l1+z-k]='0';
            }
            for(j=ind1;j>=0;j--)
            {
                c1=i1[j]-'0';
                int ans=c1*c2+car;
                int put=ans%10;
                car=ans/10;
                i3[ind3]=put+'0';
                ind3--;
            }
            if(car==0)
            {
                 char * temp=intal_add(i3,r);
                char *temp2=r;
                r=temp;
                //r=intal_add(i3,r);
                free(temp2);
                //temp=NULL;
            }
            else
            {
                char* new=(char*)malloc(sizeof(char)*(l1+z+2));new[0]=car+'0';new[l1+z+1]='\0';
                for(int p=l1+z;p>=1;p--)
                {
                    new[p]=i3[p-1];
                }
                //r=intal_add(new,r);
                char * temp=intal_add(new,r);
                char *temp2=r;
                r=temp;
                free(temp2);
                //temp=NULL;
                free(new);
            }
            free(i3);
            z++;
        }
        return r;
   
}

static int which(const char *f,const char *s)
{
for(int i=0;i<strlen(s);i++)
{
if(s[i]>f[i])
{
    return 0;
}
else if(f[i]>s[i])
{
    return 1;
    
}
}
return 1;
}

char* intal_mod(const char* intal1, const char* intal2)
{
    //char*r=NULL;return r;
    // int l1=strlen(intal1);
    // int l2=strlen(intal2);
    // if(intal_compare(intal1,intal2)==-1)
    // {
    //     char *r=(char*)malloc(sizeof(char)*(l1+1));
    //     r[l1]='\0';
    //     for(int i=l1-1;i>=0;i--)
    //     {
    //         r[i]=intal1[i];
    //     }
    //     return r;
    // }
    // int dif=l2-l1;
    // char *r=(char*)malloc(sizeof(char)*(l1));
    //     for(int i=l1-1;i>=0;i--)
    //     {
    //         r[i]=intal1[i];
    //     }

    // while(dif>=1 && intal_compare(r,b)==1)
    // {
    //     int z=dif;
    //     char* b=(char*)malloc(sizeof(char)*(l2+dif))
    //     for(;z>0;z--)
    //     {
    //         b[l2+z-1]='0';
    //     }
    //     while(intal_compare)
    // }
        int l1=strlen(intal1);
    int l2=strlen(intal2);
    if(intal_compare(intal1,intal2)==-1)
    {
        char *r=(char*)malloc(sizeof(char)*(l1+1));
        r[l1]='\0';
        for(int i=l1-1;i>=0;i--)
        {
            r[i]=intal1[i];
        }
        return r;
    }
    
    char *r=(char*)malloc(sizeof(char)*(l1+1));r[l1]='\0';
        for(int i=l1-1;i>=0;i--)
        {
            r[i]=intal1[i];
        }

        while(intal_compare(r,intal2)!=-1)
        {
            int diff=strlen(r)-l2;
            
            while(diff>0)
            {
                
                int rbit=(which(r,intal2)==1)?0:1;
                diff=diff-rbit;
                char *e=malloc(sizeof(char)*(l2+diff+1));
                for(int i=0;i<l2;i++)
                    {
                        e[i]=intal2[i];
                    }
                    
                    for(int i=0;i<diff;i++)
                    {
                        e[i+l2]='0';
                    }
                    e[diff+l2]='\0';
                    char *temp2=r;
                     char* temp=intal_diff(r,e);
                    r=temp;
                    //temp=NULL;//free(temp2);//comment free temp2
                    free(temp2);
                    free(e);
                    diff=strlen(r)-l2;
                    rbit=(which(r,intal2)==1)?0:1;
                    diff=diff-rbit;
            }
            char *temp2=r;
             char* temp=intal_diff(r,intal2);
            r=temp;
            free(temp2);//free(temp);
        }
        int fl=strlen(r);
        char *rr=(char*)malloc(sizeof(char)*(fl+1));
        rr[fl]='\0';
    for(int o=fl-1;o>=0;o--)
    {
        rr[o]=r[o];
    }
    free(r);
    return rr;
}
static char* find_power(const char* intal1,unsigned int n)
{
    if(n==0)
    {
        char * p=(char *)malloc(sizeof(char)*2);p[0]='1';p[1]='\0';
        return p;
    }
    
    char *r=find_power(intal1,(n/2));
    //r=intal_multiply(r,r);
    char *tt=intal_multiply(r,r);
    char *tt2=r;
    r=tt;
    free(tt2);
    if(n%2==1)
    {
        char *temp=intal_multiply(r,intal1);
        char* temp2=r;
        r=temp;
        free(temp2);
        //r=intal_multiply(r,intal1);
    }
    return r;
}
char* intal_pow(const char* intal1, unsigned int n)
{
    int l1=strlen(intal1);
    char * r=find_power(intal1,n);
    int len=strlen(r);
    char * rr=(char*)malloc(sizeof(char)*(len+1));
    rr[len]='\0';
    for(int i=len-1;i>=0;i--)
    {
        rr[i]=r[i];
    }
    //r=NULL;
    free(r);
return rr;
}

char* intal_gcd(const char* intal1, const char* intal2)
{
if(strcmp(intal2,"0")==0)
    {
        int l=strlen(intal1);
        char*f=(char*)malloc(sizeof(char)*(l+1));
        f[l]='\0';
        for(int i=l-1;i>=0;i--)
        {
            f[i]=intal1[i];
        }
        return f;
    }
    else
    {
        char * r=intal_gcd(intal2,intal_mod(intal1,intal2));
        return r;
    }
    

}
char* intal_fibonacci(unsigned int n)
{
    if(n==0)
    {
    char *r=(char*)malloc(sizeof(char)*2);r[0]='0';r[1]='\0';
    return r;
    }
    else if(n==1)
    {
    char *r=(char*)malloc(sizeof(char)*2);r[0]='1';r[1]='\0';
    return r;
    }
    else
    {
     /*   int i;
         char *a="0";
         char *b="1";
        int l;
        const char *c;
        for(i=3;i<=n;i++)
        {
            c=intal_add(a,b);
            const char *temp=b;
            a=NULL;
            strcpy(a,temp);
            temp=NULL;
            strcpy(b,c);
            //temp=NULL;
             l=strlen(c);
        }
        
        char *r=(char*)malloc(sizeof(char)*(l+1));
        r[l]='\0';
        for(int f=l-1;f>=0;f--)
        {
            r[f]=c[f];
        }
        r=NULL;
        return r;*/
       /* char **a = (char**) malloc((n+1) * sizeof(char*));
	     for(int i = 0; i < 2; i++) 
             a[i] = (char*) malloc(1 * sizeof(char));
         strcpy(a[0],"0");
         strcpy(a[1],"1");
         for(int i=2;i<=n;i++)
         {
             const char *r=intal_add(a[i-1],a[i-2]);
             int l=strlen(r);
             a[i]=(char*)malloc(sizeof(char)*l);
             strcpy(a[i],r);
             // printf("%s\n",a[i]);
             // free(a[i-2]);
         }
         // free(a[n-2]);
         int ll=strlen(a[n]);
         char *rr=(char*)malloc(sizeof(char)*(ll+1));
         rr[ll]='\0';
         for(int j=ll-1;j>=0;j--)
         {
             rr[j]=a[n][j];
         }
        // free(a[n-1]);
         for(int k=0;k<=n;k++)
         {
             free(a[k]);
         }
         free(a);
         return rr;
    }
    */
    char* r[n+1];r[0]="0";r[1]="1";
    for(int i=2;i<=n;i++)
    {
        r[i]=intal_add(r[i-1],r[i-2]);
    }
    for(int i=2;i<n;i++)
    {
        free(r[i]);
    }
    return r[n];
    }
}
char* intal_factorial(unsigned int n)
{
    unsigned int nn=n;
    int len=0;
    while (nn>0)
    {
        len++;
        nn=nn/10;
    }
    char * d=(char*)malloc(sizeof(char)*(len+1));
         nn=n;d[len]='\0';
    char *m=(char*)malloc(sizeof(char)*2);m[0]='1';m[1]='\0';
    for(int i=len-1;i>=0;i--)
    {
        int p=nn%10;
        nn=nn/10;
        d[i]=p+'0';
    }
    
    for(int i=n;i>=1;i--)
    {
        char *temp=intal_multiply(d,m);
        char* temp2=m;
        m=temp;
        free(temp2);
        char *ttt=intal_diff(d,"1");
        char* ttt2=d;
        d=ttt;
        free(ttt2);
    }
    len=strlen(m);
    char* r=(char*)malloc(sizeof(char)*(len+1));
    r[len]='\0';
    for(int y=len-1;y>=0;y--)
    {
        r[y]=m[y];
    }
    free(d);free(m);
return r;
}
char* intal_bincoeff(unsigned int n, unsigned int k)
{
 //   return NULL;
    if(n-k<k)
    k=n-k;
    if(k==0)
    {
        char *r=(char*)malloc(sizeof(char)*2);r[0]='1';r[1]='\0';
        return r;
    }
    
    char *t[k+1];
    t[0]=(char*)malloc(sizeof(char)*2);t[0][0]='1';t[0][1]='\0';
    for(int i=1;i<=k;i++)
    {
        t[i]=(char*)malloc(sizeof(char)*2);t[i][0]='0';t[i][1]='\0';
    }
    for(int i=1;i<=n;i++)
    {
        int which=i>k?k:i;
        for(int m=which;m>0;m--)
        {
                //char *p=(char*)malloc(sizeof(char)*1);p[0]='\0';
                  //  char *temp=intal_add(t[m],t[m-1]);
                  char* p=intal_add(t[m],t[m-1]);
                   // char*temp2=p;
                   // p=temp;
                    //free(temp2);
                   int f=strlen(p);
                   
                   t[m]=(char*)realloc(t[m],sizeof(char)*(f+1));
                   t[m][f]='\0';
                    for(int h=f-1;h>=0;h--)
                    {
                        t[m][h]=p[h];
                    }                    
            //if(strcmp(t[m],"0")!=0)
            free(p);
        }
    }
    for(int i=0;i<k;i++)
    {
        free(t[i]);
    }
    return t[k];
    
   
}
int intal_max(char **arr, int n)
{
    int max=0;
    for(int i=1;i<n;i++)
    {
        int which=intal_compare(arr[max],arr[i]);
        if(which==-1)
        max=i;
    }
    return max;
}
int intal_min(char **arr, int n)
{
    int min=0;
    for(int i=1;i<n;i++)
    {
        int which=intal_compare(arr[min],arr[i]);
        if(which==1)
        min=i;
    }
    return min;

}
int intal_search(char **arr, int n, const char* key)
{
    for(int i=0;i<n;i++)
    {
        int which=intal_compare(arr[i],key);
        if(which==0)
        return i;
    }
    return -1;
}

static void merge(char **arr,int s,int m,int en)
{
    int i=s;int j=m+1;int k=0;
    char **b=(char**)malloc(sizeof(char*)*(en-s+1));
    for(int l=0;l<(en-s+1);l++)
    {
        b[l]=(char*)malloc(sizeof(char)*1001);
        b[l][1001]='\0';
    }
    while(i<=m && j<=en)
    {
        int which=intal_compare(arr[i],arr[j]);
        if(which==-1||which==0)
        {
            const char* r=arr[i];
            strcpy(b[k],r);
            int fo=strlen(arr[i]);
            b[k][fo+1]='\0';
           
                        k++;i++;
        }
        else
        {
         const char* r=arr[j];
            strcpy(b[k],r);
            int fo=strlen(arr[j]);
            b[k][fo+1]='\0'; 
                      
                                    k++;j++;
        }
    }
    while(i<=m)
    {
        const char* r=arr[i];
            strcpy(b[k],r);
            int fo=strlen(arr[i]);
            b[k][fo+1]='\0';
                 
                                k++;i++;
    }
    while(j<=en)
    {
        const char* r=arr[j];
            strcpy(b[k],r);
            int fo=strlen(arr[j]);
            b[k][fo+1]='\0';
                     
                                    k++;j++;
    }int x=s;
    for(int g=0;g<en-s+1;g++)
    {
        const char*r=b[g];
        strcpy(arr[x],r);
                    
                            x++;
    }
    for(int l=0;l<(en-s+1);l++)
    {
        free(b[l]);
    }
    free(b);

}
static void mergesort(char** arr,int s,int en)
{
    if(s<en)
    {
    int m=(s+en)/2;
    mergesort(arr,s,m);   
    mergesort(arr,m+1,en);
    merge(arr,s,m,en);

    }
    
}
void intal_sort(char **arr, int n)
{

 mergesort(arr,0,n-1);
 
 }

int intal_binsearch(char **arr, int n, const char* key)
{
    int l=0;int h=n-1;
    //intal_sort(arr,n);
    while(l<=h)
    {
        int m=(l+h)/2;
        int which=intal_compare(arr[m],key);
        if(which==0)
        {
            if (m == 0 || intal_compare(key,arr[m-1])==1)
            return m;
        }
        else if(which==1)
        {
            h=m-1;
        }
        else
        {
            l=m+1;
        }
        
    }
    return -1;
}

char* coin_row_problem(char **arr,int n)
{
    
    //char **t=(char**)malloc(sizeof(char*)*(n+1));
    char *t;char *t1;
    t=(char*)malloc(sizeof(char)*2);
    t[0]='0';t[1]='\0';
    t1=(char*)malloc(sizeof(char)*(strlen(arr[0])+1));
    t1[strlen(arr[0])]='\0';
    for(int i=strlen(arr[0])-1;i>=0;i--)
    {
        t1[i]=arr[0][i];
    }
    
    
    for(int i=2;i<=n;i++)
    {
       /* char *r1=(char*)malloc(sizeof(char)*1);r1[0]='\0';
        char* ttt=intal_add(arr[i-1],t[i-2]);
        char *ttt2=r1;
        r1=ttt;
        free(ttt2);
        int which=intal_compare(r1,t[i-1]);
        if(which==1 || which==0)
        {
        t[i]=(char*)malloc(sizeof(char)*strlen(r1));
        strcpy(t[i],r1);
        }
        else
        {   
            t[i]=(char*)malloc(sizeof(char)*strlen(t[i-1]));
            
        strcpy(t[i],t[i-1]);
        }
        
        free(r1);
        */
        char *r1=intal_add(arr[i-1],t);
        int which=intal_compare(r1,t1);
        if(which==1 || which==0)
        {
            if(t!=t1)free(t);
            t=t1;
            t1=r1;
            r1=NULL;
        }
        else
        {
            free(t);
            t=t1;
            r1=NULL;
        }
    }
    char* rr=(char*)malloc(sizeof(char)*(strlen(t1)+1)); 
    for(int i=strlen(t1)-1;i>=0;i--)
    {
        rr[i]=t1[i];
    }
    rr[strlen(t1)]='\0';
   /* for(int i=0;i<=n;i++)
    {
        free(t[i]);
      }*/
      //free(t);
      if(t1==t){
      free(t);      }
      else
      {free(t1);free(t);
      }
    return rr;
}


