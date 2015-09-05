/**************************************************     
  Author: wxudong     
  Date: 2015-09-05
  Description: 创建hash搜索表，构造哈希函数的方法为除留余数法
			   处理哈希冲突的方法为链地址法
**************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define HASHSIZE 26

typedef struct hashNode
{
       char *str;
       unsigned int key;
       struct hashNode *next;
}hashNode;

hashNode *hashTable[HASHSIZE];

/* initialize hash table */
void hashTableInit()
{
	 memset(hashTable, 0, sizeof(hashNode*) * HASHSIZE);
}

/* change string into key_value */
unsigned int strToKey(const char *str)
{
    unsigned int value=0;
    if(*str > 'a' && *str < 'z')
		value = (unsigned int)(*str - 'a');
	if(*str > 'A' && *str < 'Z')
		value = (unsigned int)(*str - 'A');
	return value;
}

/* hash function */
unsigned int hashPosition( unsigned int kvalue, unsigned int hash_len)
{
         return(kvalue % hash_len);
}

/* insert key to hash table */
void hashTableInsert(const char *str)
{
    unsigned int position=hashPosition(strToKey(str),HASHSIZE);
    hashNode *phead=hashTable[position];
    while(phead)
    {
          if(strcmp(phead->str,str)==0)
          {
             printf("%s already exists !\n",str);
             return;
          }
          phead=phead->next;
    }
    
    hashNode *pnewnode=(hashNode *)malloc(sizeof(hashNode));
    memset(pnewnode, 0, sizeof(hashNode));
    pnewnode->str=(char *)malloc(sizeof(char) * (strlen(str)+1));
    strcpy(pnewnode->str,str);
    pnewnode->key=strToKey(str);
    pnewnode->next=hashTable[position];
    hashTable[position]=pnewnode;
}

/* lookup a key in hash table */
hashNode *hashTableSearch(const char *str)
{
         unsigned int position=hashPosition(strToKey(str),HASHSIZE);
         if(hashTable[position])
         {
            hashNode *phead=hashTable[position];
            while(phead)
            {
               if(strcmp(phead->str,str)==0)
                  return phead;
               phead = phead->next;
            }
         }
         return NULL;
}

/* remove key from hash table */
void hashTableRemove(const char *str)
{
     unsigned int position=hashPosition(strToKey(str),HASHSIZE);
     if(hashTable[position])
     {
        hashNode *phead=hashTable[position];
        hashNode *plast=NULL;
        hashNode *premove=NULL;
        while(phead)
        {
           if(strcmp(phead->str,str)==0)
           {
              premove=phead;
              break;
           }
           plast=phead;
           phead=plast->next;
        }
        if(premove)
        {
           if(plast)
              plast->next = premove->next;
           else
              hashTable[position] = NULL;
           free(premove->str);
           free(premove);
        }
     }
}

/* print the content of hash table */
void hashTablePrint()
{
     printf("*********** the content of hash table ************\n");
     int i;
     for(i=0;i<HASHSIZE;i++)
     {
         if(hashTable[i])
         {
            hashNode *phead = hashTable[i];
            printf("position:%d => ",i);
            while(phead)
            {
               printf("%s(%d) -> ",phead->str, phead->key);
               phead = phead->next;
            }
            printf("NULL\n");
         }
     }
}

/* delete the hash table */
void hashTableDelete()
{
     int i;
     for(i=0; i<HASHSIZE; i++)
     {
       if(hashTable[i])
       {
         hashNode *phead = hashTable[i];
         while(phead)
         {
            hashNode *ptemp = phead;
            phead = phead->next;
            if(ptemp)
            {
               free(ptemp->str);
               free(ptemp);
            }
         }
       }
     }            
}

int main()
{
     const char *str1="aaa";
     const char *str2="abc";
     const char *str3="ccc";
     const char *str4="fff";
     const char *str5="hhh";
     const char *str6="www";
     
     hashNode *pnode;
     hashTableInit();
     
     hashTableInsert(str1);
     hashTableInsert(str2);
     hashTableInsert(str3);
     hashTableInsert(str4);
     hashTableInsert(str5);
     hashTableInsert(str6);
     
     hashTablePrint();
     
     hashTableRemove("ccc");
     hashTablePrint();
     
     hashTableDelete();
     
}



