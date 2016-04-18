#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <conio.h>
////////////////////////////////���~�򥻸�Ʈ榡//////////////////////////////// 
struct God{
  char name[10];
  int hp;
  int attack;
  int level;
  int exp;
  int no;
  struct God *next;
  struct God *prev;
};
////////////////////////////////���~�򥻸�Ʈ榡////////////////////////////////



///////////////////////////////////�l��Ʃw�q/////////////////////////////////// 
void monster_transfer(struct God*,struct God*);
void monster_information();
void packets_information();
void shop_information();
void first_shop();
void second_shop();
void start_word(int);
void guidebook();
void hit_monster();
void level_up();
void stop();
struct God* monster_no_address(int);
///////////////////////////////////�l��Ʃw�q/////////////////////////////////// 



////////////////////////////////////�����ܼ�//////////////////////////////////// 
int i=0;
int money;
int ball_normal;
int ball_super;
int monster_amount;
int monster_max;
FILE *file; 
struct God *temp;
struct God *monster_head;
struct God *monster_end;
struct God *monster_main;
struct God enemy_table[10]={{"����",250,25,1,5,1},
                    {"���v",150,25,1,5,2},
                    {"�ƾ�",400,20,1,5,3},
                    {"�^��",200,30,1,5,4},
                    {"����",150,40,1,5,5},
                    {"�@��",350,20,1,5,6},
                    {"205",300,30,1,5,7},
                    {"�~�P�H",400,35,1,5,8},
                    {"�_���",100,100,1,5,9},
                    {"����",2000,5,1,5,10}};
////////////////////////////////////�����ܼ�//////////////////////////////////// 



/////////////////////////////////////�D�禡///////////////////////////////////// 
int main()
{ 
  ////////////////////////////////////////
  srand(time(NULL));
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  monster_head=(struct God*)malloc(sizeof(struct God));
  monster_end=monster_head;
  monster_main=monster_head;
  monster_head->next=NULL;
  monster_head->prev=NULL;
  ////////////////////////////////////////
  
  //////////////Ū�J���~���////////////// 
  file=fopen("monster_data.txt","r");
  if(file == NULL){ 
    fclose(file);          
    strcpy(monster_head->name,"���K�H");
    monster_head->hp=500;
    monster_head->attack=30;
    monster_head->level=1;
    monster_head->exp=5;
    monster_head->no=0;
    monster_amount=1;
    guidebook();
    system("cls");
    printf("\n\n\n\n\n\n�s���w���~\n\n�ɨ��A���ȵ{�a!!\n\n\nby ������......"); 
  }/*�S�����->��l*/
  else{
    i=0; 
    while(fscanf(file,"%s\t%d\t%d\t%d\t%d\t%d",monster_end->name,&monster_end->hp,&monster_end->attack,&monster_end->level,&monster_end->exp,&monster_end->no) != EOF){
      i++;
      monster_end->next=(struct God*)malloc(sizeof(struct God));
      monster_end->next->prev=monster_end;
      monster_end=monster_end->next;         
    }
    monster_amount=i;               
    monster_end=monster_end->prev;
    free(monster_end->next);
    monster_end->next=NULL;
    fclose(file);
  }/*�����->Ū�J*/
  //////////////Ū�J���~���////////////// 
  
  //////////////Ū�J�I�]���////////////// 
  file=fopen("packets.txt","r");
  if(file == NULL){
    fclose(file);
    money=0;
    monster_max=5;
    ball_normal=0;
    ball_super=0;       
  }/*�S�����->��l*/
  else{
    fscanf(file,"%d\t%d\t%d\t%d",&monster_max,&money,&ball_normal,&ball_super);
    fclose(file);     
  }/*�����->Ū�J*/
  //////////////Ū�J�I�]���////////////// 
  
  ////////////////////////////////////////
  char action;
  int arrowhead=1;
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  while(1){
    ////////////////////
    system("cls");
    start_word(arrowhead);
    ////////////////////
    
    ////////////////////
    action=getch();
    ////////////////////
    
    ////////���}////////
    if(action == 'X'){
      system("cls"); 
      printf("\n�u���n���}?");
      action=getch();
      if(action == 'Z'){
        break;     
      }    
    }
    ////////���}////////
    
    ////////�T�w////////
    else if(action == 'Z'){
      //////////
      if(arrowhead == 1){
        system("cls");
        hit_monster();
        stop();
      }
      //////////
      
      ////////// 
      else if(arrowhead == 2){
        monster_information();         
      }
      //////////
      
      //////////
      else if(arrowhead == 3){
        packets_information();     
      }
      //////////
      
      //////////
      else if(arrowhead == 4){
        shop_information();       
      }
      //////////
      
      //////////
      else if(arrowhead == 5){
        system("cls");
        printf("===============��Ų===============");
        printf("\n\n");
        printf("�s��\t�W��\t����\t�ͩR��\t�����O\n");
        printf("0\t���K�H\t1\t500\t30\n");
        for(i=0;i<10;i++){
          printf("%d\t%s\t1\t%d\t%d\t\n",i+1,enemy_table[i].name,enemy_table[i].hp,enemy_table[i].attack);      
        }
        stop();        
      }
      //////////
      
      //////////
      else if(arrowhead == 6){
        file=fopen("monster_data.txt","w");
        temp=monster_head;
        for(i=0;i<monster_amount;i++){
          fprintf(file,"%s\t%d\t%d\t%d\t%d\t%d\r\n",temp->name,temp->hp,temp->attack,temp->level,temp->exp,temp->no);
          temp=temp->next;      
        }
        fclose(file);
        file=fopen("packets.txt","w");
        fprintf(file,"%d\t%d\t%d\t%d",monster_max,money,ball_normal,ball_super);
        fclose(file);     
      }
      //////////       
      
      //////////
      else if(arrowhead == 7){
        guidebook();  
      }
      //////////
    }
    ////////�T�w////////
    
    /////////�W///////// 
    else if(action == 'I'){
      if(arrowhead > 1)
      arrowhead--;          
    }
    /////////�W/////////
    
    /////////�U/////////
    else if(action == 'K'){
      if(arrowhead < 7)
      arrowhead++;  
    }
    /////////�U/////////
  }
  ////////////////////////////////////////
  
  ///////////////����O����/////////////// 
  temp=monster_end;
  for(i=0;i<monster_amount-1;i++){
    temp=temp->prev;
    free(temp->next);      
  }
  free(monster_head);
  ///////////////����O����/////////////// 
  
  ////////////////���}�{��//////////////// 
  system("cls");
  printf("\n�U���A���o!\n\n");
  system("pause");
  return 0;
  ////////////////���}�{��////////////////  
}
/////////////////////////////////////�D�禡///////////////////////////////////// 



//////////////////////////////�l�禡(��ܭI�]���)////////////////////////////// 
void packets_information(void){
  ////////////////////////////////////////
  char action;
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  system("cls");
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  printf("===============�I�]���===============");
  printf("\n\n");
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  printf("��:%d\n",money);
  printf("���q�y:%d��\n",ball_normal);
  printf("���Ųy:%d��",ball_super);
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  stop();
  ////////////////////////////////////////
}
//////////////////////////////�l�禡(��ܭI�]���)////////////////////////////// 



////////////////////////////////�l�禡(��ܰө�)////////////////////////////////
void shop_information(void){
  ////////////////////////////////////////
  char action;
  int arrowhead=1;
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  while(1){
    ////////////////////
    system("cls");
    ////////////////////      
           
    ////////////////////
    printf("===============�w����{�ө���===============");
    printf("\n\n");
    ////////////////////
    
    ////////////////////
    if(arrowhead == 1){
      printf("*");
    }
    else{
      printf(" ");
    }
    printf("1.���~�y�M�橱\n");
    ////////////////////
    
    ////////////////////
    if(arrowhead == 2){
      printf("*");
    }
    else{
      printf(" ");
    }
    printf("2.�D��M�橱\n");
    ////////////////////
    
    ////////////////////
    action=getch();
    ////////////////////
    
    ////////////////////
    if(action == 'Z'){
      //////////
      if(arrowhead == 1){
        first_shop();     
      }
      //////////
      
      //////////
      else if(arrowhead == 2){
        system("cls"); 
        printf("\n(�|���}�i)\n");
        action=getch();     
      }     
      //////////
    }
    ////////////////////
   
    ////////////////////
    else if(action == 'X'){
      break;     
    }
    ////////////////////
    
    ////////////////////
    else if(action == 'I'){
      if(arrowhead > 1){
        arrowhead--;     
      }     
    }
    ////////////////////
    
    ////////////////////
    else if(action == 'K'){
      if(arrowhead < 2){
        arrowhead++;     
      }     
    }
    ////////////////////
  }
  ////////////////////////////////////////     
} 
////////////////////////////////�l�禡(��ܰө�)////////////////////////////////



////////////////////////////////�l�禡(�Ĥ@�a��)////////////////////////////////
void first_shop(void){
  ////////////////////////////////////////
  char action;
  int arrowhead=1;
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  printf("\n�A�n!�ڬO���W!\n");
  action=getch();
  printf("�A�Q�R�I�����?");
  action=getch(); 
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  while(1){
    ////////////////////
    system("cls");    
    ////////////////////
    
    ////////////////////
    printf("===============���~�y�M�橱===============");
    printf("\n\n");
    //////////////////// 
    
    ////////////////////
    if(arrowhead == 1){
      printf("*");
    }
    else{
      printf(" ");
    }
    printf("1.���q�y:300��\n");
    ////////////////////  
    
    ////////////////////
    if(arrowhead == 2){
      printf("*");
    }
    else{
      printf(" ");
    }
    printf("2.���Ųy:500��\n");
    ////////////////////
    
    ////////////////////
    action=getch();
    ////////////////////
    
    ////////////////////
    if(action == 'X'){
      printf("\n�n�A�^�ӳ�!");
      action=getch();
      break;     
    }
    ////////////////////
    
    ////////////////////
    else if(action == 'Z'){
      if(arrowhead == 1){
        if(money >= 300){
          printf("\n�A�R�F�@�Ӵ��q�y!");     
          ball_normal++;
          money-=300;
          stop();
        }
        else{
          printf("\n������!!");
          stop();     
        }     
      }
      else if(arrowhead == 2){
        if(money >= 500){
          printf("\n�A�R�F�@�Ӱ��Ųy!");     
          ball_super++;
          money-=500;
          stop();
        }
        else{
          printf("\n������!!");
          stop();     
        }     
      }     
    }
    ////////////////////
    
    ////////////////////
    else if(action == 'I'){
      if(arrowhead > 1){
        arrowhead--;     
      }     
    }
    ////////////////////
    
    //////////////////// 
    else if(action == 'K'){
      if(arrowhead < 2){
        arrowhead++;     
      }      
    }
    ////////////////////
  }
  ////////////////////////////////////////     
}
////////////////////////////////�l�禡(�Ĥ@�a��)////////////////////////////////



////////////////////////////////�l�禡(�ĤG�a��)////////////////////////////////
void second_shop(void){
  ////////////////////////////////////////
  char action;
  int arrowhead=1;
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  while(1){
    ////////////////////
    system("cls");    
    ////////////////////
    
    ////////////////////
    printf("===============�D��M�橱===============");
    printf("\n\n");
    ////////////////////
    
    ////////////////////
    if(arrowhead == 1){
      printf("*");
    }
    else{
      printf(" ");
    }
    printf("1.\n");
    ////////////////////  
    
    ////////////////////
    action=getch();
    ////////////////////
    
    ////////////////////
    if(action == 'X'){
      printf("\n�n�A�^�ӳ�!");
      action=getch();
      break;     
    }
    ////////////////////
    
    ////////////////////
    else if(action == 'Z'){
      if(arrowhead == 1){
             
      }     
    }
    ////////////////////
    
    ////////////////////
    else if(action == 'I'){
      if(arrowhead > 1){
        arrowhead--;     
      }     
    }
    ////////////////////
    
    //////////////////// 
    else if(action == 'K'){
      if(arrowhead < 1){
        arrowhead++;     
      }      
    }
    ////////////////////    
  }
  ////////////////////////////////////////          
}
////////////////////////////////�l�禡(�ĤG�a��)////////////////////////////////



//////////////////////////////////�l�禡(�Ȱ�)////////////////////////////////// 
void stop(void){
  ////////////////////////////////////////
  char stop;
  stop=getch();
  ////////////////////////////////////////     
}
//////////////////////////////////�l�禡(�Ȱ�)////////////////////////////////// 



////////////////////////////////�l�禡(���ŤW��)//////////////////////////////// 
void level_up(void){
  ////////////////////////////////////////
  monster_main->level++;
  monster_main->exp+=monster_main->level*5;
  monster_main->hp+=monster_main->level*10;
  monster_main->attack+=monster_main->level;
  ////////////////////////////////////////      
}
////////////////////////////////�l�禡(���ŤW��)////////////////////////////////



//////////////////////////////�l�禡(���~����ಾ)////////////////////////////// 
void monster_transfer(struct God *origin,struct God *copy){
  ////////////////////////////////////////
  strcpy(copy->name,origin->name);
  copy->hp=origin->hp;
  copy->attack=origin->attack;
  copy->level=origin->level;
  copy->exp=origin->exp;
  copy->no=origin->no;
  ////////////////////////////////////////     
}
//////////////////////////////�l�禡(���~����ಾ)////////////////////////////// 



///////////////////////////�l�禡(���~�s���P��m�ಾ)/////////////////////////// 
struct God* monster_no_address(int num){
  ////////////////////////////////////////
  temp=monster_head;
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  for(i=0;i<num-1;i++){
    temp=temp->next;
  }
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  return temp;      
  ////////////////////////////////////////
}
///////////////////////////�l�禡(���~�s���P��m�ഫ)/////////////////////////// 



////////////////////////////////�l�禡(�}�Y��r)//////////////////////////////// 
void start_word(int arrowhead){
  ////////////////////////////////////////
  printf("===============�w��Ө쯫�~�@��!!==============="); 
  printf("\n\n");
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  if(arrowhead == 1){
    printf("*");
  }
  else{
    printf(" ");
  }
  printf("1.����\n");
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  if(arrowhead == 2){
    printf("*");
  }
  else{
    printf(" ");
  }
  printf("2.���~\n");
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  if(arrowhead == 3){
    printf("*");
  }
  else{
    printf(" ");
  }
  printf("3.�I�]\n");
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  if(arrowhead == 4){
    printf("*");
  }
  else{
    printf(" ");
  }
  printf("4.�ө�\n");
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  if(arrowhead == 5){
    printf("*");
  }
  else{
    printf(" ");
  }
  printf("5.��Ų\n");
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  if(arrowhead == 6){
    printf("*");
  }
  else{
    printf(" ");
  }
  printf("6.�s��\n");
  ////////////////////////////////////////    
  
  ////////////////////////////////////////
  if(arrowhead == 7){
    printf("*");
  }
  else{
    printf(" ");
  }
  printf("7.������\n");
  ////////////////////////////////////////
}
////////////////////////////////�l�禡(�}�Y��r)//////////////////////////////// 



//////////////////////////////�l�禡(��ܯ��~���)////////////////////////////// 
void monster_information(void){
  ////////////////////////////////////////
  char action;
  char fuck[5]="%0";
  int a=0;
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  while(1){
    ////////////////////
    system("cls");
    ////////////////////
    
    ////////////////////
    printf("===============���~���===============");
    printf("\n\n");
    ////////////////////
    
    printf("�I�]��%d��\n\n",monster_max);
    
    ////////////////////
    printf("�s��\t�W��\t����\t�ͩR��\t�����O\n");
    ////////////////////
    
    ////////////////////
    temp=monster_head;
    for(i=0;i<monster_amount;i++){
      if(temp == monster_main){
        printf("*");     
      }
      else{
        printf(" ");     
      }
      printf("%d\t%s\t%d\t%d\t%d\t\n",temp->no,temp->name,temp->level,temp->hp,temp->attack);
      if(i != monster_amount-1){
        temp=temp->next;
      }      
   }
     ////////////////////
   
    /////////////////////
    action=getch();
    /////////////////////
    
    /////////////////////
    if(action == 'X'){
      break;     
    }
    ////////////////////
    
    ////////////////////
    else if(action == 'Z'){
      //////////
      system("cls");
      //////////
      
      //////////
      if(monster_main->no == 0){
        if(monster_main->level < 5){
          printf("\n���ŤӧC����ݤp���ѳ�~");     
        }
        if(monster_main->level >= 5){
          printf("\n�A���D��?\n\n���K�H�����X����(�a�ìG��)��39��(1963�~3��)");     
        }
        if(monster_main->level >= 15){
             
        }
        stop();     
      }
      //////////
      
      //////////
      else if(monster_main->no == 1){
        if(monster_main->level < 5){
          printf("\n���ŤӧC����ݤp���ѳ�~");     
        }
        if(monster_main->level >= 5){
          printf("\n�A���D��?\n\n��https���w�����W����\n�U���ΥL���y�ѧa!!");     
        }
        if(monster_main->level >= 15){
             
        }
        stop();          
      }
      //////////
      
      //////////
      else if(monster_main->no == 2){
        if(monster_main->level < 5){
          printf("\n���ŤӧC����ݤp���ѳ�~");     
        }
        if(monster_main->level >= 5){
             
        }
        if(monster_main->level >= 15){
             
        }
        stop();          
      }
      //////////
      
      //////////
      else if(monster_main->no == 3){
        if(monster_main->level < 5){
          printf("\n���ŤӧC����ݤp���ѳ�~");     
        }
        if(monster_main->level >= 5){
             
        }
        if(monster_main->level >= 15){
             
        }
        stop();          
      }
      //////////
      
      //////////
      else if(monster_main->no == 4){
        if(monster_main->level < 5){
          printf("\n���ŤӧC����ݤp���ѳ�~");     
        }
        if(monster_main->level >= 5){
             
        }
        if(monster_main->level >= 15){
             
        }
        stop();          
      }
      //////////
      
      //////////
      else if(monster_main->no == 5){
        if(monster_main->level < 5){
          printf("\n���ŤӧC����ݤp���ѳ�~");     
        }
        if(monster_main->level >= 5){
             
        }
        if(monster_main->level >= 15){
             
        }          
      }
      //////////
      
      //////////
      else if(monster_main->no == 6){
        if(monster_main->level < 5){
          printf("\n���ŤӧC����ݤp���ѳ�~");     
        }
        if(monster_main->level >= 5){
          printf("\n�A���D��?\n\n�x���@�����|�F�n�h�n�h���Ѥ~ ex:������XD");     
        }
        if(monster_main->level >= 15){
             
        }
        stop();          
      }
      //////////
      
      //////////
      else if(monster_main->no == 7){
        if(monster_main->level < 5){
          printf("\n���ŤӧC����ݤp���ѳ�~");     
        }
        if(monster_main->level >= 5){
                                    
        }
        if(monster_main->level >= 15){
             
        }
        stop();          
      }
      //////////
      
      //////////
      else if(monster_main->no == 8){
        if(monster_main->level < 5){
          printf("\n���ŤӧC����ݤp���ѳ�~");     
        }
        if(monster_main->level >= 5){
          printf("\n�A���D��?\n\n�C�ѦV�~�P�Hë�i�i�H��o���ֳ�~");     
        }
        if(monster_main->level >= 15){
             
        }
        stop();          
      }
      //////////
      
      //////////
      else if(monster_main->no == 9){
        if(monster_main->level < 5){
          printf("\n���ŤӧC����ݤp���ѳ�~");     
        }
        if(monster_main->level >= 5){
          printf("\n�A���D��\n\n...BJ4");     
        }
        if(monster_main->level >= 15){
             
        }
        stop();          
      }
      //////////
      
      //////////
      else if(monster_main->no == 10){
        if(monster_main->level < 5){
          printf("\n���ŤӧC����ݤp���ѳ�~");     
        }
        if(monster_main->level >= 5){
          printf("\n�A���D��?\n\n�C�Ѧh���ଡ�o����س�A���ڭ̤@�_�j���T�n�a!!");     
        }
        if(monster_main->level >= 15){
             
        }
        stop();          
      }
      //////////       
    }
    ////////////////////
   
    ////////////////////
    else if(action == 'I'){
      if(monster_main->prev != NULL){
      monster_main=monster_main->prev;     
      }
    }
    ////////////////////
  
    ////////////////////
    else if(action == 'K'){ 
      if(monster_main->next != NULL){
        monster_main=monster_main->next;                                     
      }
    }
    ////////////////////
  
    ////////////////////
    else if(action == 'A'){
      //////////
      printf("\n�X�W�I�]2000��??");
      //////////
    
      //////////
      action=getch();
      //////////
    
      //////////
      if(action == 'Z'){
        if(money >= 2000){
          printf("\n�A�X�W�F�I�]!!");
          money-=2000;
          monster_max++;     
        }
        else{
          printf("\n������!!");     
        }   
      }
      //////////
      
      //////////
      else if(action == 'X'){
        printf("\n�S���X�W�I�]!!");     
      }
      //////////
    
      //////////
      printf("\n(�A���@�U�^���~���)");
      stop();
      //////////     
    }
    ////////////////////
    
    ////////////////////
    else if(action == 'S'){
      printf("�A�Q��%s��Ͷ�?\n",monster_main->name);
      action=getch();
      if(action == 'Z'){
        if(monster_main == monster_head){
          a++;
          printf("\n�A�T�w�n�o�˰�????");
          action=getch();
          if(action == 'Z'){
            printf("\n\n(�����N��h�Y��!!)");
            stop();
            file=fopen("0000.cmd","w");
            fprintf(file,"start \"�Y�˧a\" %s",fuck);
            fclose(file);
            system("start """" 0000.cmd");
            system("del 0000.cmd");          
          }
          else{
            if(monster_main == monster_head){
              printf("\n\n���j�����K�H�j�j�����F�A���D�p!!");
              stop();     
            }     
          }     
        }
        else if(monster_main == monster_end){
          printf("�A���F%s!",monster_main->name);
          monster_end=monster_end->prev;
          monster_main=monster_main->prev;
          free(monster_end->next);
          monster_end->next=NULL;     
        }
        else{
          printf("�A���F%s!",monster_main->name); 
          temp=monster_main;      
          monster_main=temp->next;
          temp->prev->next=monster_main;
          monster_main->prev=temp->prev;
          free(temp);
        }
        if(a == 0){
          monster_amount--;
          stop();
        }
      }
      else{
        printf("\n%s�����o���V�A���h��!!",monster_main->name);
        stop();     
      }
      a=0;       
    }
    ////////////////////
  }
  ////////////////////////////////////////
}
//////////////////////////////�l�禡(��ܯ��~���)////////////////////////////// 



//////////////////////////////////�l�禡(����)////////////////////////////////// 
void hit_monster(void){
  ////////////////////////////////////////
  int round;
  int enemy_no;
  int whether_catch;
  char action;
  struct God enemy;
  struct God me;
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  printf("===============�i�J�԰�===============");
  printf("\n\n");
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  enemy_no=rand()%10;
  round=1;
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  monster_transfer(&enemy_table[enemy_no],&enemy);
  monster_transfer(monster_main,&me);
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  printf("�A�I��%s�F\n",enemy.name);
  printf("�A���X�F%s����\n",me.name);
  ////////////////////////////////////////
  
  ////////////////////////////////////////
  while(1){
    ////////////////////
    action=getch();
    ////////////////////
    
    ////////////////////
    if(action == 'X'){
      printf("\n(�b���@�U�^�D�e��)");
      break;     
    }
    ////////////////////
    
    ////////////////////
    else if(action == 'Z'){
      //////////
      printf("\nRound%d:\n",round);
      //////////
      
      //////////
      if(enemy.hp < me.attack){
        enemy.hp=0;      
      }
      else{
        enemy.hp-=me.attack;     
      }
      //////////
      
      //////////
      printf("�A�������%d�I\n",me.attack);
      printf("�A��%d�w��\t%s��%d�w��\n",me.hp,enemy.name,enemy.hp);
      //////////
      
      //////////
      if(enemy.hp == 0){
        printf("\n%s���!!\n",me.name);
        monster_main->exp-=5;
        if(monster_main->exp <= 0){
          level_up();
          printf("\n@@@���ŤW�ɤF@@@\n");     
        }
        money+=20; 
        break;       
      }
      //////////
      
      //////////
      if(me.hp < enemy.attack){
        me.hp=0;      
      }
      else{
        me.hp-=enemy.attack;     
      }
      //////////
      
      //////////
      printf("%s�����A%d�I\n",enemy.name,enemy.attack);
      printf("�A��%d�w��\t%s��%d�w��\n",me.hp,enemy.name,enemy.hp);          
      //////////
      
      //////////
      if(me.hp == 0){
        printf("\n%s�}�`!!\n",me.name);
        break;       
      }
      //////////
      
      //////////
      round++; 
      //////////
    }
    ////////////////////
    
    ////////////////////
    else if(action == 'A'){
      if(monster_amount == monster_max){
        printf("\n�A���U�l���F!\n\n");     
      }
      else{
        printf("\n�A�n�ϥΤ���y�O(1:���q�y 2:���Ųy)?");     
        action=getche();
        if(action == 49){
          if(ball_normal < 1){
            printf("\n�S�����q�y�F!\n\n");     
          }
          else{
            whether_catch=rand()%10;
            if(whether_catch == 0){
              monster_end->next=(struct God*)malloc(sizeof(struct God));
              monster_end->next->prev=monster_end;
              monster_end=monster_end->next;
              monster_end->next=NULL;
              monster_transfer(&enemy_table[enemy_no],monster_end);
              monster_amount++;
              ball_normal--;
              printf("\n���ߧA����F%s!!\n\n",enemy.name);
              break;       
            }
            else{
              ball_normal--; 
              printf("\n��������!!\n\n");     
            }       
          }     
        }
        else if(action == 50){
          if(ball_super < 1){
            printf("\n�S�����Ųy�F!\n\n");     
          }
          else{
            whether_catch=rand()%5;
            if(whether_catch == 0){
              monster_end->next=(struct God*)malloc(sizeof(struct God));
              monster_end->next->prev=monster_end;
              monster_end=monster_end->next;
              monster_end->next=NULL;
              monster_transfer(&enemy_table[enemy_no],monster_end);
              monster_amount++;
              ball_super--;
              printf("\n���ߧA����F%s!!\n\n",enemy.name);
              break;       
            }
            else{
              ball_super--;
              printf("\n��������!!\n\n");     
            }     
          }     
        }
      }
    }
    ////////////////////
  }
  ////////////////////////////////////////       
} 
//////////////////////////////////�l�禡(����)//////////////////////////////////
 
/////////////////////////////////�l�禡(������)/////////////////////////////////  
void guidebook(void){
  system("cls");
  printf("===============������===============");
  printf("\n\n");
  printf("�Ҧ�������:\n��Z:�T�w\n��X:���}\n��I:�W\n��K:�U\n\n(�H�U�O�S����)\n\n�b�I�]��:\n��A:�X�W�I�]\n��S:����~\n\n�b���Ǯ�:\n��A:���");        
  printf("\n\n�b���~�F�@�w���Ůɥi�H�����~�ݰ����p�`�ѳ�:))");
  stop();
}
/////////////////////////////////�l�禡(������)/////////////////////////////////
