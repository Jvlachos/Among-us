/***************************************************************
 *                                                             *
 * file: main.cpp                                              *
 *                                                             *
 * @Author  Dimitris Vlachos                                   *
 * @ID      csd 4492               		                       *
 * @Version 21-12-2020                            			   *
 * @email   csd4492@csd.uoc.gr                                 *
 *                                                             *
 * @brief   Main function and implemetantion of among_us.h     *
 *          for the needs of CS-240 project 2020               *
 *                                                             *
 ***************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include  <assert.h>
#include <cmath>
#include <array>
#include "among_us.h"


unsigned int primes_g[650] = { 
                                 179,    181,    191,    193,    197,    199,    211,    223,    227,    229, 
                                 233,    239,    241,    251,    257,    263,    269,    271,    277,    281, 
                                 283,    293,    307,    311,    313,    317,    331,    337,    347,    349, 
                                 353,    359,    367,    373,    379,    383,    389,    397,    401,    409, 
                                 419,    421,    431,    433,    439,    443,    449,    457,    461,    463, 
                                 467,    479,    487,    491,    499,    503,    509,    521,    523,    541, 
                                 547,    557,    563,    569,    571,    577,    587,    593,    599,    601, 
                                 607,    613,    617,    619,    631,    641,    643,    647,    653,    659, 
                                 661,    673,    677,    683,    691,    701,    709,    719,    727,    733, 
                                 739,    743,    751,    757,    761,    769,    773,    787,    797,    809, 
                                 811,    821,    823,    827,    829,    839,    853,    857,    859,    863, 
                                 877,    881,    883,    887,    907,    911,    919,    929,    937,    941, 
                                 947,    953,    967,    971,    977,    983,    991,    997,   1009,   1013, 
                                1019,   1021,   1031,   1033,   1039,   1049,   1051,   1061,   1063,   1069, 
                                1087,   1091,   1093,   1097,   1103,   1109,   1117,   1123,   1129,   1151, 
                                1153,   1163,   1171,   1181,   1187,   1193,   1201,   1213,   1217,   1223, 
                                1229,   1231,   1237,   1249,   1259,   1277,   1279,   1283,   1289,   1291, 
                                1297,   1301,   1303,   1307,   1319,   1321,   1327,   1361,   1367,   1373, 
                                1381,   1399,   1409,   1423,   1427,   1429,   1433,   1439,   1447,   1451, 
                                1453,   1459,   1471,   1481,   1483,   1487,   1489,   1493,   1499,   1511, 
                                1523,   1531,   1543,   1549,   1553,   1559,   1567,   1571,   1579,   1583, 
                                1597,   1601,   1607,   1609,   1613,   1619,   1621,   1627,   1637,   1657, 
                                1663,   1667,   1669,   1693,   1697,   1699,   1709,   1721,   1723,   1733, 
                                1741,   1747,   1753,   1759,   1777,   1783,   1787,   1789,   1801,   1811, 
                                1823,   1831,   1847,   1861,   1867,   1871,   1873,   1877,   1879,   1889, 
                                1901,   1907,   1913,   1931,   1933,   1949,   1951,   1973,   1979,   1987, 
                                1993,   1997,   1999,   2003,   2011,   2017,   2027,   2029,   2039,   2053, 
                                2063,   2069,   2081,   2083,   2087,   2089,   2099,   2111,   2113,   2129, 
                                2131,   2137,   2141,   2143,   2153,   2161,   2179,   2203,   2207,   2213, 
                                2221,   2237,   2239,   2243,   2251,   2267,   2269,   2273,   2281,   2287, 
                                2293,   2297,   2309,   2311,   2333,   2339,   2341,   2347,   2351,   2357, 
                                2371,   2377,   2381,   2383,   2389,   2393,   2399,   2411,   2417,   2423, 
                                2437,   2441,   2447,   2459,   2467,   2473,   2477,   2503,   2521,   2531, 
                                2539,   2543,   2549,   2551,   2557,   2579,   2591,   2593,   2609,   2617, 
                                2621,   2633,   2647,   2657,   2659,   2663,   2671,   2677,   2683,   2687, 
                                2689,   2693,   2699,   2707,   2711,   2713,   2719,   2729,   2731,   2741, 
                                2749,   2753,   2767,   2777,   2789,   2791,   2797,   2801,   2803,   2819, 
                                2833,   2837,   2843,   2851,   2857,   2861,   2879,   2887,   2897,   2903, 
                                2909,   2917,   2927,   2939,   2953,   2957,   2963,   2969,   2971,   2999, 
                                3001,   3011,   3019,   3023,   3037,   3041,   3049,   3061,   3067,   3079, 
                                3083,   3089,   3109,   3119,   3121,   3137,   3163,   3167,   3169,   3181, 
                                3187,   3191,   3203,   3209,   3217,   3221,   3229,   3251,   3253,   3257, 
                                3259,   3271,   3299,   3301,   3307,   3313,   3319,   3323,   3329,   3331, 
                                3343,   3347,   3359,   3361,   3371,   3373,   3389,   3391,   3407,   3413, 
                                3433,   3449,   3457,   3461,   3463,   3467,   3469,   3491,   3499,   3511, 
                                3517,   3527,   3529,   3533,   3539,   3541,   3547,   3557,   3559,   3571, 
                                3581,   3583,   3593,   3607,   3613,   3617,   3623,   3631,   3637,   3643, 
                                3659,   3671,   3673,   3677,   3691,   3697,   3701,   3709,   3719,   3727, 
                                3733,   3739,   3761,   3767,   3769,   3779,   3793,   3797,   3803,   3821, 
                                3823,   3833,   3847,   3851,   3853,   3863,   3877,   3881,   3889,   3907, 
                                3911,   3917,   3919,   3923,   3929,   3931,   3943,   3947,   3967,   3989, 
                                4001,   4003,   4007,   4013,   4019,   4021,   4027,   4049,   4051,   4057, 
                                4073,   4079,   4091,   4093,   4099,   4111,   4127,   4129,   4133,   4139, 
                                4153,   4157,   4159,   4177,   4201,   4211,   4217,   4219,   4229,   4231, 
                                4241,   4243,   4253,   4259,   4261,   4271,   4273,   4283,   4289,   4297, 
                                4327,   4337,   4339,   4349,   4357,   4363,   4373,   4391,   4397,   4409, 
                                4421,   4423,   4441,   4447,   4451,   4457,   4463,   4481,   4483,   4493, 
                                4507,   4513,   4517,   4519,   4523,   4547,   4549,   4561,   4567,   4583, 
                                4591,   4597,   4603,   4621,   4637,   4639,   4643,   4649,   4651,   4657, 
                                4663,   4673,   4679,   4691,   4703,   4721,   4723,   4729,   4733,   4751, 
                                4759,   4783,   4787,   4789,   4793,   4799,   4801,   4813,   4817,   4831, 
                                4861,   4871,   4877,   4889,   4903,   4909,   4919,   4931,   4933,   4937, 
                                4943,   4951,   4957,   4967,   4969,   4973,   4987,   4993,   4999,   5003, 
                                5009,   5011,   5021,   5023,   5039,   5051,   5059,   5077,   5081,   5087, 
                                5099,   5101,   5107,   5113,   5119,   5147,   5153,   5167,   5171,   5179, 
                            };


unsigned int p,a,b;
int count=1;
int Player_Count=0;

struct Task **array_1;
struct Task **array_2;
struct Task **merged;

struct Player *chain_tree_root;
void calculate();
/**
 * @brief Optional function to initialize data structures that 
 *        need initialization
 *
 * @return 1 on success
 *         0 on failure
 */
int initialize() {
	//initialization of player's dummy head
    struct Player *node=new Player;
	node->evidence=-1;
	node->is_alien=-1;
	node->lc=NULL;
	node->rc=NULL;
	node->parrent=NULL;
	node->tasks=NULL;
	node->pid=-1;
    players_tree=node;
    //initialize hash_table
	struct General_Tasks_HT *t=new General_Tasks_HT;
	t->count=0;
	t->tasks=new HT_Task*[max_tasks_g];
	for(int i=0; i<max_tasks_g; i++){
		t->tasks[i]=NULL;
	}
	
	table=t;
	table->count=0;
	
	//initialize array
    completed_tasks_pq=new Completed_Tasks_PQ;
	completed_tasks_pq->size=0;
	completed_tasks_pq->tasks=new HT_Task*[max_tasks_g];
	
	

	//calculate values for hashing
    calculate();
	  
	
    return 1;
}

/**
 * @brief Register Player
 *
 * @param pid The player's id
 *
 * @param is_alien The variable that decides if he is an alien or not
 * @return 1 on success
 *         0 on failure
 */
int register_player(int pid, int is_alien) {
	struct Player *root=NULL;
	struct Player *node=NULL;
	struct Player *prev=NULL;
	root=players_tree;
	node=new Player;
    node->pid=pid;
    node->is_alien=is_alien;
    node->evidence=0;
    node->tasks=NULL;
    node->rc=node->lc=NULL;
	Player_Count++;
   if(root->pid==-1){
	  node->parrent=NULL;
      players_tree=node;
   }
    else{
		while(root!=NULL){
         prev=root;
		  if (pid < root->pid){
			  
           root = root->lc;
          }
          else {
          root = root->rc;
		 
         }
	   }

if(pid<prev->pid){
	prev->lc=node;
	node->parrent=prev;
    }else{
	prev->rc=node;
	node->parrent=prev;
    }
}
    return 1;
}
void print_player_taskTree(Task *root){
	if(root==NULL)
	return;

	
	print_player_taskTree(root->lc);
	printf("<tid:%d ,difficulty %d>,",root->tid,root->difficulty);
	print_player_taskTree(root->rc);

}

void print_players_withTasks(Player *root){
	if(root==NULL)
	return;

     print_players_withTasks(root->lc);
     printf("Player:%d=",root->pid);
	 print_player_taskTree(root->tasks);
	 printf("\n");
     
	 print_players_withTasks(root->rc);
}
void print_players_withEvidence(Player *root){
	if(!root)
	return;

     print_players_withEvidence(root->lc);
     printf("Player:%d ,evidence:%d=",root->pid,root->evidence);
	 print_player_taskTree(root->tasks);
	 printf("\n");
     
	 print_players_withEvidence(root->rc);
}



 int hash_function(int tid){

	return ((a*tid+b)%p)%max_tasks_g;

}

void calculate(){
	
	for(int i=0; i<650; i++){
		if(primes_g[i]-1>max_tid_g){
			p=primes_g[i];
			break;
		}
	}
     a=rand()%(p-1)-1+1;
	 b=rand()%(p-1)-0+1;
	
	}
	


/**
 * @brief Insert Task in the general task hash table
 *
 * @param tid The task id
 * 
 * @param difficulty The difficulty of the task
 *
 * @return 1 on success
 *         0 on failure
 */
int insert_task(int tid, int difficulty) {
	int index=hash_function(tid);
	
	struct HT_Task *node=new HT_Task;
	struct HT_Task *p;
	node->difficulty=difficulty;
	node->tid=tid;
	node->next=NULL;
	if(table->tasks[index]==NULL){
	table->tasks[index]=node;
	}
	else{
		p=table->tasks[index];
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=node;
        
	}
	table->count++;

return 1;
}
//find a node specified by index in player's tasks tree
void find_index(const int index,Player *root,Player *&found){
	
	assert(index>=1);
	if(root->lc!=NULL ){
		find_index(index,root->lc,found);
	}
	if(count==index ){
		found=root;
		
	 if(root->is_alien==1){
		   if(root->lc!=NULL && root->lc->is_alien!=1){
			   found=found->lc;
		
		   }else if(root->rc!=NULL && root->rc->is_alien!=1){

			      found=found->rc;
		   }else{
			   found=root->parrent;
		   }
	}
}
	
	count++;
	if(root->rc!=NULL ){
		find_index(index,root->rc,found);
	}
    

}
//print given tree inorder
void print_inorder(Player *root){
	if(!root)
	return;
    
	print_inorder(root->lc);
	printf("<pid:%d>,",root->pid);
	print_inorder(root->rc);
	
	
}
//function to insert a node in tasks' tree
void insert_to_taskTree(Task *&root,int tid,int difficulty){
     struct Task *node=new Task;
	 struct Task *p=root;
	 struct Task *prev=NULL;
	 
	 node->difficulty=difficulty;
	 node->tid=tid;
	 node->lcnt=0;
	 node->rc=node->lc=NULL;
	 
	 if(root==NULL){
		 root=node;
	 }
	 else{
		 while(p!=NULL){
			 prev=p;
			 if(tid<p->tid){
				 prev->lcnt++;
				 p=p->lc;
				 
			 }else{
				 p=p->rc;
			 }
		 }

		if(tid<prev->tid){
			
			prev->lc=node;
			
		}else{
			prev->rc=node;
		}
	 }

}

/**
 * @brief Distribute Tasks to the players
 * @return 1 on success
 *         0 on failure
 */
int distribute_tasks() {
    struct Player *p;
	struct Player *root=players_tree;
	struct HT_Task *k;
	int task_counter=1;
	int index;
	
	for(int i=0; i<max_tasks_g; i++){
         
	    if(table->tasks[i]!=NULL){

            k=table->tasks[i];

			while(k!=NULL){
				index=task_counter%Player_Count;
				 if(task_counter%Player_Count==0){
					 index=Player_Count;
				 }
				 
                 find_index(index,root,p);
				if(p!=NULL){
					
				 insert_to_taskTree(p->tasks,k->tid,k->difficulty);
				}
			     count=1;
				 k=k->next;
				 task_counter++;
	             
	             
			}
	    }
	}
	
	print_players_withTasks(players_tree);
	
    return 1;
}

struct Task *find_min(Task *node){
    while(node->lc!=NULL){
		node=node->lc;
	}
	return node;
}

struct Task *find_parrent(Task *node,Task *root){
   if((root->rc!=NULL && root->rc->tid==node->tid) || (root->lc!=NULL && root->lc->tid==node->tid)){
	   
	   return root;
   }
   if(root->tid==node->tid){
	   return NULL;
   }
   if(root->tid>node->tid){
	  return find_parrent(node,root->lc);
   }else{
	  return find_parrent(node,root->rc);
   }
  
}


void finde_task_successor(Task *root,Task *&successor,int tid){
	if(!root){
		successor=NULL;
		return;
	}
	if(root->tid==tid){
		if(root->rc!=NULL){
			successor=find_min(root->rc);
		}

	}else if(tid<root->tid){
		successor=root;
		finde_task_successor(root->lc,successor,tid);

	}else{
		finde_task_successor(root->rc,successor,tid);
	}

}


//function to search for a task with a given tid
struct Task *search_Task(Task *root,int tid){
	if(root==NULL || root->tid==tid){
		return root;
	}
	if(root->tid>tid){
	return	search_Task(root->lc,tid);
	}else{
	return	search_Task(root->rc,tid);
	}

   
}

struct Task* delete_Task_node(Task *root,int tid){
     struct Task *to_delete=NULL;
	 struct Task *temp_1=NULL;
	 struct Task *temp_2=NULL;
	 struct Task *temp1_parrent=NULL;
	 struct Task *temp2_parrent=NULL;


	 to_delete=search_Task(root,tid);
	if(to_delete->lc==NULL || to_delete->rc==NULL){
		temp_1=to_delete;
	}else{
		finde_task_successor(to_delete,temp_1,to_delete->tid);
	}
	if(temp_1->lc!=NULL){
		temp_2=temp_1->lc;
	}else{
		temp_2=temp_1->rc;
	}
	if(temp_2!=NULL){
		temp2_parrent=find_parrent(temp_1,root);
	}
	if(find_parrent(temp_1,root)==NULL){
		return temp_2;
	}
	else if(temp_1==find_parrent(temp_1,root)->lc){
		find_parrent(temp_1,root)->lc=temp_2;
	}
	else{
		find_parrent(temp_1,root)->rc=temp_2;
	}
	if(temp_1!=to_delete){
		to_delete->tid=temp_1->tid;
		to_delete->difficulty=temp_1->difficulty;
		to_delete->lcnt=temp_1->lcnt;
	}
	return root;



}
//function to search for a player with given pid
struct Player *search_player(int pid,Player *root){
	if(root==NULL || root->pid==pid){
		return root;
	}
	if(root->pid>pid){
		return search_player(pid,root->lc);
	}else{
		 return search_player(pid,root->rc);
	}
	

}

int counters(Task *node, int ind) {
    if (!node) 
	return 0;
    int x = ind + counters(node->lc, 1) + counters(node->rc, 0);
    node->lcnt=x;
    return x;
}

void print_heap(){
	printf("Completed Tasks=");
	for(int i=0; i<completed_tasks_pq->size; i++){
		printf("tid:%d,difficulty:%d\n",completed_tasks_pq->tasks[i]->tid,completed_tasks_pq->tasks[i]->difficulty);
	}
}

void insert_to_heap(Task *node,int difficulty){
	struct HT_Task *new_node=new HT_Task;
	if(completed_tasks_pq->size==max_tasks_g){
		printf("heap is full\n");
		return;
	}
	new_node->tid=node->tid;
	new_node->difficulty=difficulty;
	int m=completed_tasks_pq->size;
	while(m>0 && difficulty>completed_tasks_pq->tasks[(m-1)/2]->difficulty){
		completed_tasks_pq->tasks[m]=completed_tasks_pq->tasks[(m-1)/2];
		m=(m-1)/2;
		
	}
	
	completed_tasks_pq->tasks[m]=new_node;
	completed_tasks_pq->size++;


}

/**
 * @brief Implement Task
 *
 * @param pid The player's id
 *
 * @param tid The task's tid
 *
 * @return 1 on success
 *         0 on failure
 */
int implement_task(int pid, int tid) {
	struct Player *player;
	struct Task *n;
	
	
	 
	player=search_player(pid,players_tree);
	if(player){
	
	n=search_Task(player->tasks,tid);
	if(!n){
		printf("Task <%d> does not exist in Player's <%d> Task Tree\n",tid,player->pid);
		return 0;
	}else{
		
		
		insert_to_heap(n,n->difficulty);
		struct Task *par=find_parrent(n,player->tasks);
		
	   player->tasks= delete_Task_node(player->tasks,n->tid);
	   counters(player->tasks,0);
	   
	   /*comment for faster execution*/
	   print_players_withTasks(players_tree);
	   
	}
	}else{
		printf("Player <%d> does not exist\n",pid);
		return 0;
	}	
	
    
    return 1;
}

struct Task *merge_trees(int first,int last){
         if(first>last){
			 return NULL;
		 }
          int mid=(first+last)/2;
		 struct Task *root=merged[mid];
		 root->lc=merge_trees(first,mid-1);
		 root->rc=merge_trees(mid+1,last);

		  return root;
}

 void merge_arrays(int length_1,int length_2,int i=0,int j=0,int k=0){
	 if(i<length_1 && j<length_2){
		 if(array_1[i]->tid<array_2[j]->tid){
			 merged[k]=array_1[i];
			 k++;
			 i++;
		 }else{
			 merged[k]=array_2[j];
			 k++;
			 j++;
		 }
		 merge_arrays(length_1,length_2,i,j,k);
	 }else{
		 if(i<length_1){
			 merged[k]=array_1[i];
			 k++;
			 i++;
			 merge_arrays(length_1,length_2,i,j,k);
		 }
		 if(j<length_2){
			 merged[k]=array_2[j];
			 k++;
			 j++;
			 merge_arrays(length_1,length_2,i,j,k);
		 }
	 }
    
 }


 void store_in_array(Task *root,Task **array,int *index){
	
	if(!root)
	return;

	store_in_array(root->lc,array,index);
	
	array[*index]=root;
	(*index)++;
	store_in_array(root->rc,array,index);
	
}




int node_count(Task *root){
	if(root==NULL)
     return 0;

return 1+node_count(root->rc)+node_count(root->lc);
}
/**
 * @brief Eject Player
 * 
 * @param pid_1 The ejected player's id
 *
 * @param pid_2 The crewmates id
 *
 * @return 1 on success
 *         0 on failure
 */
struct Player *find_Player_min(Player *node){
    while(node->lc!=NULL){
		node=node->lc;
	}
	return node;
}



void find_player_successor(Player *root,Player *&succ,int pid){
	if(!root){
		succ=NULL;
		return;
	}
	if(root->pid==pid){
		if(root->rc!=NULL){
			succ=find_Player_min(root->rc);
		}

	}else if(pid<root->pid){
		succ=root;
		find_player_successor(root->lc,succ,pid);

	}else{
		find_player_successor(root->rc,succ,pid);
	}

}

struct Player *delete_Player(Player *root,int pid){
       
 struct Player *to_delete=NULL;
	 struct Player *temp_1=NULL;
	 struct Player *temp_2=NULL;
	
	 


	 to_delete=search_player(pid,players_tree);
	
	if(to_delete->lc==NULL || to_delete->rc==NULL){
		temp_1=to_delete;
		
	}else{
		find_player_successor(to_delete,temp_1,to_delete->pid);
		
	}
	if(temp_1->lc!=NULL){
       
		temp_2=temp_1->lc;
	}else{
		
		temp_2=temp_1->rc;
	}
	if(temp_2!=NULL){
		
		temp_2->parrent=temp_1->parrent;
	}
	if(temp_1->parrent==NULL){
		return temp_2;
	}
	else if(temp_1==temp_1->parrent->lc){
		temp_1->parrent->lc=temp_2;
	}
	else{
		temp_1->parrent->rc=temp_2;
	}
	if(temp_1!=to_delete){
		
		to_delete->pid=temp_1->pid;
		to_delete->evidence=temp_1->evidence;
		to_delete->is_alien=temp_1->is_alien;
	}
	return root;
}

int eject_player(int pid_1, int pid_2) {
	struct Player *p1=NULL;
	struct Player *p2=NULL;
    int length_1;
	int length_2;
	int i=0;
	int j=0;
	
	p1=search_player(pid_1,players_tree);
	
	p2=search_player(pid_2,players_tree);

	if(!p1){
		printf("Player with id <%d> does not exist\n",pid_1);
		
		return 0;
	}
	if(!p2){
		printf("Player with id <%d> does not exist\n",pid_2);
		return 0;
	}
	
	if(p1->tasks==NULL){
		printf("Player <%d> does not have any tasks\n",p1->pid);
		players_tree=delete_Player(players_tree,p1->pid);
		print_players_withTasks(players_tree);
		Player_Count--;
		return 1;
	}
	length_1=node_count(p1->tasks);
	length_2=node_count(p2->tasks);
	
    array_1=new Task*[length_1];
	array_2=new Task*[length_2];
	store_in_array(p1->tasks,array_1,&i);
	
	store_in_array(p2->tasks,array_2,&j);
	
	merged=new Task*[length_1+length_2];
	
	merge_arrays(length_1,length_2);
	
	p2->tasks=NULL;
	p1->tasks=NULL;
	players_tree=delete_Player(players_tree,p1->pid);
	Player_Count--;
	p2->tasks=merge_trees(0,(length_1+length_2)-1);
	
	print_players_withTasks(players_tree);
	
	
	return 1;
	}
    
struct HT_Task *delete_from_heap(){
     if(completed_tasks_pq->size==0){
		 return NULL;
	 }
	 int p=0;
	 int size=completed_tasks_pq->size;
   struct HT_Task *node;
   struct HT_Task *slide;
   node=completed_tasks_pq->tasks[0];
   slide=completed_tasks_pq->tasks[size-1];
   completed_tasks_pq->size--;
   size--;
   if(size==1)
   return node;

   int m=0;
   while((2*m+1<size && slide->difficulty<completed_tasks_pq->tasks[2*m+1]->difficulty) || (2*m+2<size && slide->difficulty<completed_tasks_pq->tasks[2*m+2]->difficulty)){
	   if(2*m+2<size){
		   if(completed_tasks_pq->tasks[2*m+1]->difficulty>completed_tasks_pq->tasks[2*m+2]->difficulty){
                  p=2*m+1;

		   }else{
			   p=2*m+2;
		   }
	   }else{
		   p=size-1;
		   
	   }
	   completed_tasks_pq->tasks[m]=completed_tasks_pq->tasks[p];
	    m=p;
	 
   }
     completed_tasks_pq->tasks[m]=slide;
	   return node;


}

/**
 * @brief Witness Eject Player
 *
 * @param pid_1 The ejected player's id
 * 
 * @param pid_2 The crewmate's pid
 *
 * @param pid_a The alien's pid
 * 
 * @param number_of_witnesses The number of witnesses
 *
 * @return 1 on success
 *         0 on failure
 */
int witness_eject(int pid_1, int pid_2, int pid_a, int number_of_witnesses){
        struct Player *p1=NULL;
		struct Player *p2=NULL;
		struct Player *alien=NULL;
       p1=search_player(pid_1,players_tree);
	   p2=search_player(pid_2,players_tree);
	   if(!p1){
		   printf("player with pid <%d> does not exist\n",pid_1);
		   return 0;
	   }
	   if(!p2){
		   printf("Player with pid <%d> does not exist\n",pid_2);
		   return 0;
	   }
	   eject_player(p1->pid,p2->pid);
	   printf("\n");
	   alien=search_player(pid_a,players_tree);
	   alien->evidence+=number_of_witnesses;
	   
	   printf("Printing players + evidence....\n");
	   print_players_withEvidence(players_tree);
	  
    return 1;
}





void transform_to_chaintree(Player *node){
	struct Player *chain_node=new Player;
	chain_node->is_alien=node->is_alien;
	chain_node->pid=node->pid;
	chain_node->rc=NULL;
	chain_node->lc=NULL;
	struct Player *p=chain_tree_root;
	if(chain_tree_root==NULL){
		chain_node->lc=NULL;
		chain_tree_root=chain_node;
		return;
	}
    
	while(p->rc!=NULL){
		p=p->rc;
	}
	p->rc=chain_node;
	chain_node->lc=p;
}
   
   void inorder_add(Player *root){
	if(!root)
	return;

	inorder_add(root->lc);
	transform_to_chaintree(root);
	inorder_add(root->rc);

}
struct Player *find_successor(Player *player){
    player=player->rc;
    
	while(player->is_alien==1){
		player=player->rc;
	}
return player;

}

struct Player *find_predecessor(Player *player,int num){
     int i=0;
   
   while(i<num){
         player=player->lc;
		 
		 i++;
	 }

     while(player->is_alien==1){
		player=player->lc;
	 }
   return player;
	 

}

/**
 * @brief Sabotage
 *
 * @param number_of_tasks The number of tasks to be sabotaged
 *
 * @param pid The player's id
 * 
 * @return 1 on success
 *         0 on failure
 */
int sabotage(int number_of_tasks, int pid) {
	struct Player *p=NULL;
	struct Player *last=NULL;
	int i=0;
	struct Player *player=NULL;
	struct Player *predecessor=NULL;
	chain_tree_root=NULL;
    inorder_add(players_tree);
	 
	p=chain_tree_root;
	
	while(p!=NULL){
	
		if(p->pid==pid){
			player=p;
			
		}
		last=p;
		p=p->rc;
	}
	
	
	
	last->rc=chain_tree_root;
	
	chain_tree_root->lc=last;
	
    predecessor=find_predecessor(player,number_of_tasks/2);
	
	
	while(i<number_of_tasks){
	
		struct Player *successor=find_successor(predecessor);
		 predecessor=successor;
		
		struct Player *to_give=search_player(successor->pid,players_tree);
	
		struct HT_Task *task=delete_from_heap();
		if(task==NULL){
			printf("heap is empty,no more tasks to give\n");
			return 1;
		}
		insert_to_taskTree(to_give->tasks,task->tid,task->difficulty);
		counters(to_give->tasks,0);	

		i++;
	}
	print_players_withTasks(players_tree);

    return 1;
}

void find_max_evidence(Player *root,Player *&max,int max_val=-1){
    if(!root)
	return;
     if(root->evidence>max_val){
		
		max=root;
	}
	 find_max_evidence(root->lc,max,max->evidence);
	
     find_max_evidence(root->rc,max,max->evidence);

}
/**
 * @brief Vote
 *
 * @param pid_1 The suspicious player's id
 *
 * @param pid_2 The crewmate's pid
 * 
 * @param vote_evidence The vote's evidence
 *
 * @return 1 on success
 *         0 on failure
 */
int vote(int pid_1, int pid_2, int vote_evidence) {
	struct Player *max;
	struct Player *p;
	p=search_player(pid_1,players_tree);
	if(!p){
		printf("Player with id <%d> does not exist\n",pid_1);
		return 0;
	}
	p->evidence=vote_evidence;
	find_max_evidence(players_tree,max);
	
	eject_player(max->pid,pid_2);
	 printf("\n");
	 printf("Printing players + evidence....\n");
	 print_players_withEvidence(players_tree);

    return 1;
}
struct Task *split(Task *&root,int k,Task *&tree1){
	struct Task *p1=NULL;
	struct Task *p2=NULL;
	
	struct Task *tree2=NULL;
	struct Task *q=root;
	struct Task *prev=NULL;
	int counter=0;

	while(q!=NULL && counter<k){
		if(counter+q->lcnt+1<=k){
			if(tree1==NULL){
				tree1=q;
				p1=q;
			}
			else{
				p1->rc=q;
				p1=q;
			}
			if(tree2==NULL && counter+q->lcnt+1<k){
				tree2=q->rc;
			}
			counter=counter+q->lcnt+1;
			prev=q;
			q=q->rc;
			prev->rc=NULL;
		}
		else if(counter+q->lcnt+1>k){
			if(tree2==NULL){
				tree2=q;
				p2=q;
			}else{
				p2->lc=q;
				p2=q;
			}
			prev=q;
			q=q->lc;
			prev->lc=NULL;
		}else{
			return tree2;
		}
	}
}
/**
 * @brief Give Away Work
 *
 * @param pid_1 The existing crewmate's id
 *
 * @param pid_2 The new crewmate's pid
 *
 * @return 1 on success
 *         0 on failure
 */
int give_work(int pid_1, int pid_2) {
	struct Player *p=NULL;
	struct Task *splited=NULL;
	struct Task *tree1=NULL;
	struct Player *p2=NULL;
	
	p=search_player(pid_1,players_tree);
	
    int k=node_count(p->tasks);
	
	splited=split(p->tasks,k,tree1);
	
	p->tasks=NULL;
	p->tasks=splited;
	register_player(pid_2,0);
	
    p2=search_player(pid_2,players_tree);
	
	p2->tasks=NULL;
     p2->tasks=tree1;
	 
	 print_players_withTasks(players_tree);
	 
    return 1;
}
void count_aliens(Player *root,int *counter){
	if(!root){
		return;
	}
	if(root->is_alien==1){
		(*counter)++;
	}
	count_aliens(root->lc,counter);
	count_aliens(root->rc,counter);
}

/**
 * @brief Terminate
 *
 * @return 1 on success
 *         0 on failure
 */
int terminate() {
	int count=0;
	count_aliens(players_tree,&count);
	
	Player_Count=Player_Count-count;
	if(Player_Count>count || completed_tasks_pq->size==max_tasks_g){
		printf("Crewmates Win\n");
	}else{
		printf("Aliens Win\n");
	}
    return 1;
}

/**
 * @brief Print Players
 *
 * @return 1 on success
 *         0 on failure
 */
int print_players() {
	printf("Players=");
	print_inorder(players_tree);
	return 1;
	
	
}

/**
 * @brief Print Tasks
 *
 * @return 1 on success
 *         0 on failure
 */
int print_tasks() {
	struct HT_Task *p;

	for(int i=0; i<max_tasks_g; i++){
		
		if(table->tasks[i]!=NULL){
			p=table->tasks[i];
			 printf("Chain%d:<tid:%d,difficulty:%d>,",i,table->tasks[i]->tid,table->tasks[i]->difficulty);
			 while(p->next!=NULL){
				 printf("<tid:%d,difficulty:%d>",p->next->tid,p->next->difficulty);
				 p=p->next;
			 }
			 printf("\n");
		}
	}
    return 1;
}

/**
 * @brief Print Priority Queue
 *
 * @return 1 on success
 *         0 on failure
 */
int print_pq() {
	print_heap();
    return 1;
}

/**
 * @brief Print Players & Task tree
 *
 * @return 1 on success
 *         0 on failure
 */
int print_double_tree() {
	print_players_withTasks(players_tree);
    return 1;
}

/**
 * @brief Free resources
 *
 * @return 1 on success
 *         0 on failure
 */
void free_tasks(Task *root){
	if(!root)
	return;

	free_tasks(root->rc);
	free_tasks(root->lc);
    
	delete root;
	
}

void free_double_tree(Player *root){
	if(!root)
	return;

		free_double_tree(root->rc);
		free_double_tree(root->lc);
        free_tasks(root->tasks);
		delete root;
}


int free_all(void) {
	free_double_tree(players_tree);
    for(int i=0; i<max_tasks_g; i++){
		delete[] table->tasks[i];
	}
	delete[]table;
    
    for(int i=0; i<completed_tasks_pq->size; i++){
		delete[]completed_tasks_pq->tasks[i];
	}
	delete [] completed_tasks_pq->tasks;
	delete completed_tasks_pq;
    
	for(int i=0; i<sizeof(array_1)/sizeof(array_1[0]); i++ ){
		delete[]array_1[i];
	}
	delete[] array_1;
	for(int i=0; i<sizeof(array_2)/sizeof(array_2[0]); i++ ){
		delete[]array_2[i];
	}
	delete[] array_2;
    for(int i=0; i<sizeof(merged)/sizeof(merged[0]); i++ ){
		delete[]merged[i];
	}
	delete[] merged;
    

    return 1;
}

#define BUFFER_SIZE 1024 /* Maximum length of a line in input file */


#define DEBUG
#ifdef DEBUG
#define DPRINT(...) fprintf(stderr, __VA_ARGS__);
#else /* DEBUG */
#define DPRINT(...)
#endif /* DEBUG */

/**
 * @brief The main function
 *
 * @param argc Number of arguments
 * @param argv Argument vector
 *
 * @return 0 on success
 *         1 on failure
 */
int main(int argc, char **argv)
{
	FILE *fin = NULL;
	char buff[BUFFER_SIZE], event='\0';

	/* Check command buff arguments */
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <input_file> <>\n", argv[0]);
		return EXIT_FAILURE;
	}

	/* Open input file */
	if ((fin = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "\n Could not open file: %s\n", argv[1]);
		perror("Opening test file\n");
		return EXIT_FAILURE;
	}

	// Read max enemy soldiers' number
	fgets(buff, BUFFER_SIZE, fin);
	sscanf(buff, "%d", &max_tasks_g);
	DPRINT("Max number of tasks: %d\n", max_tasks_g)

	// Read max enemy soldiers' ID
	fgets(buff, BUFFER_SIZE, fin);
	sscanf(buff, "%d", &max_tid_g);
	DPRINT("Max task tid: %d\n", max_tid_g)

	/* Initializations */
	initialize();

	/* Read input file buff-by-buff and handle the events */
	while (fgets(buff, BUFFER_SIZE, fin))
	{

		DPRINT("\n>>> Event: %s", buff);

		switch (buff[0])
		{

		/* Comment */
		case '#':
			break;

		/* Register Player
		 * P <pid> <is_alien> */
		case 'P':
		{
			
			int pid;
			int is_alien;
			sscanf(buff, "%c %d %d", &event, &pid, &is_alien);
			DPRINT("%c %d %d\n", event, pid, is_alien);

			if (register_player(pid, is_alien))
			{
				DPRINT("P %d %d succeeded\n", pid, is_alien);
			}
			else
			{
				fprintf(stderr, "P %d %d failed\n", pid, is_alien);
			}
			
            print_players();
			break;
		}

		/* Insert Task
		 * T <tid> <difficulty>  */
		case 'T':
		{
			int tid, difficulty;

			sscanf(buff, "%c %d %d", &event, &tid, &difficulty);
			DPRINT("%c %d %d\n", event, tid, difficulty);

			if (insert_task(tid, difficulty))
			{
				DPRINT("%c %d %d succeded\n", event, tid, difficulty);
			}
			else
			{
				fprintf(stderr, "%c %d %d failed\n", event, tid, difficulty);
			}
            print_tasks();
			break;
		}

		/* Distribute Tasks
		 * D */
		case 'D':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (distribute_tasks())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}

		/* Implement Task
		 * I <pid> <tid> */
		case 'I':
		{
			int pid, tid;

			sscanf(buff, "%c %d %d", &event, &pid, &tid);
			DPRINT("%c %d %d \n", event, pid, tid);

			if (implement_task(pid, tid))
			{
				DPRINT("%c %d %d succeeded\n", event, pid, tid);
			}
			else
			{
				fprintf(stderr, "%c %d %d failed\n", event, pid, tid);
			}

			break;
		}

		/* Eject Player
		 * E <pid_1> <pid_2>*/
		case 'E':
		{
			int pid_1, pid_2;

			sscanf(buff, "%c %d %d", &event, &pid_1, &pid_2);
			DPRINT("%c %d %d\n", event, pid_1, pid_2);

			if (eject_player(pid_1, pid_2))
			{
				DPRINT("%c %d %d succeeded\n", event, pid_1, pid_2);
			}
			else
			{
				fprintf(stderr, "%c %d %d failed\n", event, pid_1, pid_2);
			}

			break;
		}

		/* Witness Ejection
		 * W <pid> <pid_a> <number_of_witnesses>
		 */
		case 'W':
		{
			int pid_1, pid_2 ,pid_a ,number_of_witnesses;

			sscanf(buff, "%c %d %d %d %d", &event, &pid_1, &pid_2, &pid_a, &number_of_witnesses);
			DPRINT("%c %d %d %d %d\n", event, pid_1, pid_2, pid_a, number_of_witnesses);

			if (witness_eject(pid_1, pid_2, pid_a, number_of_witnesses))
			{
				DPRINT("%c %d %d %d %d succeded\n", event, pid_1, pid_2, pid_a, number_of_witnesses);
			}
			else
			{
				fprintf(stderr, "%c %d %d %d %d failed\n", event, pid_1, pid_2, pid_a, number_of_witnesses);
			}

			break;
		}

		/* Sabotage
		 * S <number_of_tasks> <pid> */
		case 'S':
		{
			int number_of_tasks, pid;

			sscanf(buff, "%c %d %d\n", &event, &number_of_tasks, &pid);
			DPRINT("%c %d %d\n", event, number_of_tasks, pid);

			if (sabotage(number_of_tasks, pid))
			{
				DPRINT("%c %d %d succeeded\n", event, number_of_tasks, pid);
			}
			else
			{
				fprintf(stderr, "%c %d %d failed\n", event, number_of_tasks, pid);
			}

			break;
		}

		/* Vote
		 * V <pid_1> <pid_2> <vote_evidence> */
		case 'V':
		{
			int pid_1, pid_2, vote_evidence;

			sscanf(buff, "%c %d %d %d\n", &event, &pid_1, &pid_2, &vote_evidence);
			DPRINT("%c %d %d %d\n", event, pid_1, pid_2, vote_evidence);

			if (vote(pid_1, pid_2, vote_evidence))
			{
				DPRINT("%c %d %d %d succeeded\n", event, pid_1, pid_2, vote_evidence);
			}
			else
			{
				fprintf(stderr, "%c %d %d %d failed\n", event, pid_1, pid_2, vote_evidence);
			}

			break;
		}

		/* Give Away Work
		 * G <pid_1> <pid_2> */
		case 'G':
		{
			int pid_1, pid_2;

			sscanf(buff, "%c %d %d", &event, &pid_1, &pid_2);
			DPRINT("%c %d %d\n", event, pid_1, pid_2);

			if (give_work(pid_1, pid_2))
			{
				DPRINT("%c %d %d succeeded\n", event, pid_1, pid_2);
			}
			else
			{
				fprintf(stderr, "%c %d %d failed\n", event, pid_1, pid_2);
			}

			break;
		}

		/* Terminate
		 * F */
		case 'F':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (terminate())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}

		/* Print Players
		 * X */
		case 'X':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (print_players())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}

		/* Print Tasks
		 * Y */
		case 'Y':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (print_tasks())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}

		/* Print Priority Queue
		 * Z */
		case 'Z':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (print_pq())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}

		/* Print Players & Tasks tree
		 * F */
		case 'U':
		{
			sscanf(buff, "%c", &event);
			DPRINT("%c\n", event);

			if (print_double_tree())
			{
				DPRINT("%c succeeded\n", event);
			}
			else
			{
				fprintf(stderr, "%c failed\n", event);
			}

			break;
		}

		/* Empty line */
		case '\n':
			break;

		/* Ignore everything else */
		default:
			DPRINT("Ignoring buff: %s \n", buff);

			break;
		}
	}

	free_all();
	return (EXIT_SUCCESS);
}
