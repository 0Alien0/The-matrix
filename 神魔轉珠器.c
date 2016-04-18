#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define PACE 15
//�W 0 �U 1 �� 2 �k 3
//�� 0 �� 1 �� 2 �� 3 �t 4 �� 5
void in();
void out();
void slip(int,int,int);
void change(int,int,int,int);
void dig(int,int);
int clear();

int map[5][6];
int imap[5][6];
int jmap[5][6];
int best_map[5][6];
int block[5][6]; 
int pace[25];
int best_pace[25];
int max=0;
int hand_x,hand_y;
int act;
int study;
int my;
int block_len;
int block_x[10];
int block_y[10]; 
int color[7];
int best_color[6];
int limit;

int main(int argc, char *argv[])
{
  int i,j;
  char action;  
  color[6]=1;
  printf("=============== ������ ===============\n\n");
  printf("�y��x������\n�y��y���\n\n");
  printf("�ݩ���Ʀr��p�U:\n�� 0 �� 1 �� 2 �� 3 �t 4 �� 5");
  printf("\n\n(�����N���~��)");
  action=getch();
  system("cls");
  while(1){
    max=0;
    my=0;
    in();
    for(i=0;i<5;i++){
      for(j=0;j<6;j++){
        if(block[i][j] == 0){ 
          slip(i,j,0);        
        } 
      }      
    }
    out();
  }
  return 0;
}
void in(void){
  int i,j;
  printf("�п�J�]�]��:\n");
  for(i=0;i<5;i++){
    for(j=0;j<6;j++){
      scanf("%d",&map[i][j]);      
    }      
  }
  printf("�̦h�n�Xcombo?");
  scanf("%d",&study);     
  printf("���X�����Ư]?(�S���п�J0)");
  scanf("%d",&block_len); 
  if(block_len > 0 && block_len <= 10){
    for(i=0;i<block_len;i++){
      printf("��%d�խ��Ư](x,y):",i+1); 
      scanf("%d %d",&block_x[i],&block_y[i]);
      block_x[i]--;
      block_y[i]--;      
    }         
  }
  else{
    block_len=0;     
  }
  for(i=0;i<5;i++){
    for(j=0;j<6;j++){
      block[i][j]=0;      
    }      
  }
  for(i=0;i<block_len;i++){
    block[block_x[i]][block_y[i]]=1;      
  } 
  printf("�A���@�w�n��ԣ��?(�S���п�6)");
  scanf("%d",&limit); 
}
void out(void){
  int i,j;
  printf("combo�̰�:%d\n",max);
  printf("�_��]:%d %d",hand_x,hand_y);
  printf("���|�p�U:");
  for(i=0;i<act;i++){
    if(best_pace[i] == 0){
      printf("�W");     
    }
    if(best_pace[i] == 1){
      printf("�U");     
    }
    if(best_pace[i] == 2){
      printf("��");     
    }
    if(best_pace[i] == 3){
      printf("�k");     
    }      
  }
  printf("\n");
  printf("������:\n");
  for(i=0;i<5;i++){
    for(j=0;j<6;j++){
      printf("%d ",best_map[i][j]);      
    }
    printf("\n");      
  }
  printf("\n");
  printf("���ݩʮ��F%dcombo\n",best_color[0]);
  printf("���ݩʮ��F%dcombo\n",best_color[1]);
  printf("���ݩʮ��F%dcombo\n",best_color[2]);
  printf("���ݩʮ��F%dcombo\n",best_color[3]);
  printf("�t�ݩʮ��F%dcombo\n",best_color[4]);
  printf("���ݩʮ��F%dcombo\n",best_color[5]);  
  printf("\n");  
}
void slip(int x,int y,int move){
  int combo;
  int bug;
  int i,j;
  combo=0;
  if(max < study){
    combo=clear();
  }
  if(max == study){
    move=100;     
  }
  if(combo > max && color[limit] != 0){
    for(i=0;i<6;i++){
      best_color[i]=color[i];      
    }
    act=move;
    max=combo;     
    for(i=0;i<move;i++){
      best_pace[i]=pace[i];      
    }
    hand_x=x+1;
    hand_y=y+1;
    for(i=move-1;i>=0;i--){
      if(pace[i] == 0){
        hand_x++;     
      }
      else if(pace[i] == 1){
        hand_x--;     
      }
      else if(pace[i] == 2){
        hand_y++;     
      }
      else if(pace[i] == 3){
        hand_y--;     
      }      
    }
    for(i=0;i<5;i++){
      for(j=0;j<6;j++){
        best_map[i][j]=map[i][j];      
      }      
    }
    if(my < 1){
      max=0;
      my++;     
    }
  }
  bug=move-1;
  if(bug >= 0){
    bug=pace[bug];       
  }
  else{
    bug=100;
  }
  if(move < PACE){
    if(x > 0 && bug != 1 && block[x-1][y] == 0){
      pace[move]=0;
      change(x,y,x-1,y);
      slip(x-1,y,move+1);
      change(x,y,x-1,y);     
    } 
    if(x < 4 && bug != 0 && block[x+1][y] == 0){
      pace[move]=1;
      change(x,y,x+1,y);
      slip(x+1,y,move+1);
      change(x,y,x+1,y);     
    }
    if(y > 0 && bug != 3 && block[x][y-1] == 0){
      pace[move]=2;
      change(x,y,x,y-1);
      slip(x,y-1,move+1);
      change(x,y,x,y-1);     
    }
    if(y < 5 && bug != 2 && block[x][y+1] == 0){
      pace[move]=3;
      change(x,y,x,y+1);
      slip(x,y+1,move+1);
      change(x,y,x,y+1);     
    }       
  }   
}
int clear(void){
  int i,j,k;
  int key;
  int combo;
  for(i=0;i<6;i++){
    color[i]=0;      
  }
  combo=0;
  for(i=0;i<5;i++){
    for(j=0;j<6;j++){
      jmap[i][j]=map[i][j];      
    }      
  }
  while(1){
           
  key=0;
  for(i=0;i<5;i++){
    for(j=0;j<6;j++){
      imap[i][j]=6;      
    }      
  }
  for(i=0;i<5;i++){
    for(j=0;j<6;j++){
      if(jmap[i][j] == 6){
        continue;     
      }
      if(i > 0 && i < 4){
        if(jmap[i][j] == jmap[i+1][j] && jmap[i][j] == jmap[i-1][j]){
          imap[i][j]=jmap[i][j];
          key++;
          continue;       
        }     
      }
      if(j > 0 && j < 5){
        if(jmap[i][j] == jmap[i][j+1] && jmap[i][j] == jmap[i][j-1]){
          imap[i][j]=jmap[i][j];
          key++;
          continue;     
        }      
      }
      if(i > 1){
        if(jmap[i][j] == jmap[i-1][j] && jmap[i][j] == jmap[i-2][j]){
          imap[i][j]=jmap[i][j];
          key++; 
          continue;    
        }     
      }
      if(i < 3){
        if(jmap[i][j] == jmap[i+1][j] && jmap[i][j] == jmap[i+2][j]){
          imap[i][j]=jmap[i][j];
          key++;
          continue;     
        }     
      }
      if(j > 1){
        if(jmap[i][j] == jmap[i][j-1] && jmap[i][j] == jmap[i][j-2]){
          imap[i][j]=jmap[i][j];
          key++;
          continue;     
        }      
      }
      if(j < 4){
        if(jmap[i][j] == jmap[i][j+1] && jmap[i][j] == jmap[i][j+2]){
          imap[i][j]=jmap[i][j];
          key++;
          continue;     
        }     
      }      
    }      
  }
  if(key == 0){
    break;     
  }
  for(i=0;i<5;i++){
    for(j=0;j<6;j++){
      if(imap[i][j] != 6){
        for(k=i-1;k>=0;k--){
          jmap[k+1][j]=jmap[k][j];        
        }
        jmap[0][j]=6;       
      }      
    }      
  }
  for(i=0;i<5;i++){
    for(j=0;j<6;j++){
      if(imap[i][j] != 6){
        color[imap[i][j]]++;
        dig(i,j);
        combo++;       
      }      
    }      
  }
  
  }
  return combo;                 
}
void change(int x,int y,int m,int n){
  int a;
  a=map[x][y];
  map[x][y]=map[m][n];
  map[m][n]=a;         
}
void dig(int x,int y){
  int a;
  a=imap[x][y];
  imap[x][y]=6;
  if(x < 4 && a == imap[x+1][y]){
    dig(x+1,y);     
  }
  if(x > 0 && a == imap[x-1][y]){
    dig(x-1,y);     
  }
  if(y < 5 && a == imap[x][y+1]){
    dig(x,y+1);     
  }
  if(x > 0 && a == imap[x][y-1]){
    dig(x,y-1);     
  }         
}
