#include<stdio.h>
#include<string.h>
#include<fstream>
#include<Windows.h>
#include <WinDef.h>
#include <iostream>
FILE *fi1; //ori dps
FILE *fi2; //con dps
FILE *fo; //ori f/s
FILE *fo2; //con f/s

FILE *fin; //data
FILE *fout; //����

void main(){

	fout=fopen("output.txt","w");
	fprintf(fout,"@relation ''\n@attribute Protoss_Cyber1 real\n@attribute Protoss_Robo1 real\n@attribute Protoss_Adun real\n@attribute Protoss_Observertory real\n@attribute Protoss_Dragon_num real\n@attribute Protoss_Zealot_num real\n@attribute Protoss_Gateway1_time real\n@attribute Protoss_Gateway2_time real\n@attribute Protoss_Gateway3_time real\n@attribute Protoss_Nexus1_time real\n@attribute Protoss_Nexus2_time real\n@attribute Protoss_Templar_archive_time real\n@attribute Protoss_Probe_num real\n@attribute Protoss_Pylon_num real\n@attribute Protoss_gas_time real\n@attribute class {3gate, observer,dark,nexus}\n@data\n");


	for(int i=101;i<=999;i++)
	{

		//arff data �ҷ�����
		char pre_word_arff[1024] = "arff\\";
		char last_word_arff[1024] = ".txt";
		char center_word_arff[1024];


		sprintf(center_word_arff,"%d",i);
		strcat(pre_word_arff,center_word_arff);
		strcat(pre_word_arff,last_word_arff);


		fin = fopen(pre_word_arff,"r");
		strcpy(pre_word_arff,"arff\\");

		//original �ҷ�����
		char pre_word_original[1024] = "original\\";
		char last_word_original[1024] = ".txt";
		char center_word_original[1024];


		sprintf(center_word_original,"%d",i);
		strcat(pre_word_original,center_word_original);
		strcat(pre_word_original,last_word_original);


		fi1 = fopen(pre_word_original,"r");
		strcpy(pre_word_original,"original\\");

		//converse �ҷ�����
		char pre_word_converse[1024] = "converse\\";
		char last_word_converse[1024] = ".txt";
		char center_word_converse[1024];


		sprintf(center_word_converse,"%d",i);
		strcat(pre_word_converse,center_word_converse);
		strcat(pre_word_converse,last_word_converse);


		fi2 = fopen(pre_word_converse,"r");
		strcpy(pre_word_converse,"converse\\");


		//answer�� �����ϱ�
		char pre_word_answer[1024] = "original_enemy\\";
		char last_word_answer[1024] = ".txt";
		char center_word_answer[1024];


		sprintf(center_word_answer,"%d",i);
		strcat(pre_word_answer,center_word_answer);
		strcat(pre_word_answer,last_word_answer);


		//fi1 = fopen(pre_word_answer,"r");


		//answer�� �����ϱ�
		char pre_word_answer_converse[1024] = "converse_enemy\\";
		char last_word_answer_converse[1024] = ".txt";
		char center_word_answer_converse[1024];


		sprintf(center_word_answer_converse,"%d",i);
		strcat(pre_word_answer_converse,center_word_answer_converse);
		strcat(pre_word_answer_converse,last_word_answer_converse);


		//fi1 = fopen(pre_word_answer,"r");




		///���� �ҷ����� ��



		int time;

		float a,b;
		int dumunit1,dumunit2,dumunit3,dumunit4,dumunit5,dumunit6,dumunit7,dumunit8;

		int compare=-1,comparetime;
		int de=0;
		int flag=1;
		int unit=1; 
		int starttime=0,starttime2=0;
		int sum;

		int cnt=0,ff=0;


		int flog=0;



		//original
		while(fscanf(fi1,"%d %f %d %d %d %d %d %d %d %d",&time,&a,&dumunit1,&dumunit2,&dumunit3,&dumunit4,&dumunit5,&dumunit6,&dumunit7,&dumunit8)!=EOF){
			sum = dumunit1 + dumunit2;

			if(compare < sum){ //����
				unit = sum;

				if(de==1){
					flag=1;

					de=0;
				}
			}

			else{ //����
				de=1;
				if(flag==1){ //ó���� �ð� �˷��ַ���
					if(ff==0){
						unit = compare;
					}
					starttime=time;
					flag=0;
				}
			}
			if(unit/2 > sum){
				//fprintf(fo,"%d ",starttime);
				flog=1;
				break;
			}
			compare = sum;
		}



		compare=-1;
		de=0;
		flag=1;
		unit=1; 

		cnt=0,ff=0;
		int flfl=0;



		//converse
		while(fscanf(fi2,"%d %f %d %d %d %d %d %d %d %d",&time,&a,&dumunit1,&dumunit2,&dumunit3,&dumunit4,&dumunit5,&dumunit6,&dumunit7,&dumunit8)!=EOF){
			sum = dumunit1 + dumunit2;

			if(compare < sum){ //����
				unit = sum;

				if(de==1){
					flag=1;

					de=0;
				}
			}

			else{ //����
				de=1;
				if(flag==1){ //ó���� �ð� �˷��ַ���
					if(ff==0){
						unit = compare;
					}
					starttime2=time;
					flag=0;
				}
			}
			if(unit/2 > sum){
				//fprintf(fo,"%d ",starttime2);
				flfl=1;
				break;
			}
			compare = sum;
		}


		//answer�� ��� ������ֱ�.


		/////�����ð�, ��������

		int time1,id1;
		char unit1[100];

		int answer[100]={0,};
		int build_jungdap_answer[100] = {0,};

		int Dragoon_id_cnt=0;
		int Zealot_id_cnt=0;
		int Gateway_id_cnt=0;
		int Nexus_id_cnt=0;
		int Probe_id_cnt=0;
		int Pylon_id_cnt=0;

		int Protoss_Dragoon_id[100]={0,};
		int Protoss_Zealot_id[100]={0,};
		int Protoss_Gateway_id[100]={0,};
		int Protoss_Nexus_id[100] ={0,};
		int Protoss_Probe_id[100]={0,};
		int Protoss_Pylon_id[100]={0,};
		
		int build_jungdap_Zealot_id_cnt=0;
		int build_jungdap_Gateway_id_cnt=0;
		int build_jungdap_Nexus_id_cnt=0;
		int build_jungdap_Protoss_Zealot_id[100]={0,};
		int build_jungdap_Protoss_Gateway_id[100]={0,};
		int build_jungdap_Protoss_Nexus_id[100] ={0,};


		
		int flag1=0;


		//fast, slow ���� �������ִ� ������
		bool fast_right= false;
		bool fast_right_han_bun_man = false;

		int fast_slow_answer[100]={0,};
		int build_answer[100] = {0,};
		
		int fast_slow_Zealot_id_cnt=0;
		int fast_slow_Protoss_Zealot_id[100]={0.};
		int fast_slow_flag = 0;

		while(fscanf(fin,"%d %s %d",&time1,unit1,&id1)!=EOF){
		

			//���̹��׽�ƽ�ھ� ���������� ����
			if(time1<=300)
			{
			
			//~!! �ð� �����ֱ�
			if(strstr(unit1,"Cybernetics_Core")){
				if(answer[0]==0) //ó���ϳ��� ����
					answer[0]=1; //�� �־��ְ�
			}

				if(strstr(unit1,"Robotics_Facility")){
				if(answer[1]==0) //ó���ϳ��� ����
					answer[1]=1; //�� �־��ְ�
			}

					if(strstr(unit1,"Citadel_of_Adun")){
				if(answer[2]==0) //ó���ϳ��� ����
					answer[2]=1; //�� �־��ְ�
			}

						if(strstr(unit1,"Observatory")){
				if(answer[3]==0) //ó���ϳ��� ����
					answer[3]=1; //�� �־��ְ�
			}
						
						if(strstr(unit1,"Assimilator")){
				if(answer[14]==0) //ó���ϳ��� ����
					answer[14]=1; //�� �־��ְ�
			}

					

			//~!!! �ð� �����ֱ� ��


			//~!!! ���ְ��� �����ֱ� ����~!!!//

				//��󱺰���
			if(strstr(unit1,"Dragoon")){
				for(int j=0;j<=answer[4];j++){
					if(Protoss_Dragoon_id[j] == id1){ 
						flag1=1;
						break;
					}
				}
				if(flag1==0){
					answer[4]++; //���� ���� ����
					Protoss_Dragoon_id[Dragoon_id_cnt]=id1;
					Dragoon_id_cnt++;
				}

				flag1=0;
			}

			//��������
			if(strstr(unit1,"Zealot")){
				for(int j=0;j<=answer[5];j++){
					if(Protoss_Zealot_id[j] == id1){ 
						flag1=1;
						break;
					}
				}
				if(flag1==0){
					answer[5]++; //���� ���� ����
					Protoss_Zealot_id[Zealot_id_cnt]=id1;
					Zealot_id_cnt++;
				}

				flag1=0;
			}


			//����Ʈ���� �ð�
			if(strstr(unit1,"Gateway")){
				for(int j=0;j<=3;j++){
					if(Protoss_Gateway_id[j] == id1){ 
						flag1=1;
						break;
					}
				}
				if(flag1==0){
					if(answer[6] ==0)
						answer[6]=1;
					else if(answer[7]==0)
						answer[7]=1;
					else if(answer[8]==0)
						answer[8]=1;
					Protoss_Gateway_id[Gateway_id_cnt]=id1;
					Gateway_id_cnt++;
				}

				flag1=0;
			}

	
	
					//�ؼ��� �ð�
			if(strstr(unit1,"Nexus")){
				for(int j=0;j<=2;j++){
					if(Protoss_Nexus_id[j] == id1){  
						flag1=1;
						break;
					}
				}
				if(flag1==0){
					if(answer[9] ==0)
						answer[9]=1;
					else if(answer[10]==0)
						answer[10]=1;
					Protoss_Nexus_id[Nexus_id_cnt]=id1;
					Nexus_id_cnt++;
				}

				flag1=0;
			}

			
			//���÷� ��ī�̺� �ð�
			if(strstr(unit1,"Protoss_Templar_Archives")){
				if(answer[11]==0) //ó���ϳ��� ����
					answer[11]=1; //�� �־��ְ�
			}


			
			//���κ갳��
			if(strstr(unit1,"Probe")){
				for(int j=0;j<=answer[12];j++){
					if(Protoss_Probe_id[j] == id1){ 
						flag1=1;
						break;
					}
				}
				if(flag1==0){
					answer[12]++; //���� ���� ����
					Protoss_Probe_id[Probe_id_cnt]=id1;
					Probe_id_cnt++;
				}

				flag1=0;
			}

			//���Ϸ�����
			if(strstr(unit1,"Pylon")){
				for(int j=0;j<=answer[13];j++){
					if(Protoss_Pylon_id[j] == id1){ 
						flag1=1;
						break;
					}
				}
				if(flag1==0){
					answer[13]++; //���� ���� ����
					Protoss_Pylon_id[Pylon_id_cnt]=id1;
					Pylon_id_cnt++;
				}

				flag1=0;
			}





			//~!!! ���ְ��� �����ֱ� ��~!!!//

			}


			////~!!!!�ð� ������� �������� ���ϱ�  ����

				//����Ʈ���� �ð�
			if(strstr(unit1,"Gateway")){
				for(int j=0;j<=3;j++){
					if(build_jungdap_Protoss_Gateway_id[j] == id1){ 
						flag1=1;
						break;
					}
				}
				if(flag1==0){
					if(build_jungdap_answer[6] ==0)
						build_jungdap_answer[6]=time1;
					else if(build_jungdap_answer[7]==0)
						build_jungdap_answer[7]=time1;
					else if(build_jungdap_answer[8]==0)
						build_jungdap_answer[8]=time1;
					build_jungdap_Protoss_Gateway_id[build_jungdap_Gateway_id_cnt]=id1;
					build_jungdap_Gateway_id_cnt++;
				}

				flag1=0;
			}

	
	
					//�ؼ��� �ð�
			if(strstr(unit1,"Nexus")){
				for(int j=0;j<=2;j++){
					if(build_jungdap_Protoss_Nexus_id[j] == id1){  
						flag1=1;
						break;
					}
				}
				if(flag1==0){
					if(build_jungdap_answer[9] ==0)
						build_jungdap_answer[9]=time1;
					else if(build_jungdap_answer[10]==0)
						build_jungdap_answer[10]=time1;
					build_jungdap_Protoss_Nexus_id[build_jungdap_Nexus_id_cnt]=id1;
					build_jungdap_Nexus_id_cnt++;
				}

				flag1=0;
			}


				////~!!!!�ð� ������� �������� ���ϱ�  ��




			/*
			//fast, slow ���� ���ϴ� ��������
				if(strstr(unit1,"Zealot") ){
				for(int j=0;j<=fast_slow_answer[1];j++){
					if(fast_slow_Protoss_Zealot_id[j] == id1){ 
						fast_slow_flag=1;
						break;
					}
				}
				if(fast_slow_flag==0){
					fast_slow_answer[1]++; //���� ���� ����
					fast_slow_Protoss_Zealot_id[fast_slow_Zealot_id_cnt]=id1;
					fast_slow_Zealot_id_cnt++;
				}

				fast_slow_flag=0;
				}
				*/

				//���� ���� ���ϴ� 3����Ʈ�ð�
				build_answer[0]=build_jungdap_answer[8];
				

				//���� ���� ���ϴ� �������ð�
				if(strstr(unit1,"Protoss_Observatory")){
				if(build_answer[1]==0) //ó���ϳ��� ����
					build_answer[1]=time1; //�� �־��ְ�
				}
			

				//���� ���� ���ϴ� ��ũ�ð�
				if(strstr(unit1,"Templar_Archives")){
				if(build_answer[2]==0) //ó���ϳ��� ����
					build_answer[2]=time1; //�� �־��ְ�
			}

				//���� ���� ���ϴ� �ι�° �ؼ����ð�
				build_answer[3] = build_jungdap_answer[10];

				

			if(time1 >= 200 && fast_right_han_bun_man == false)
			{
				fast_right_han_bun_man = true;
			if(time1 >= 200 && fast_slow_answer[1] >= 5)
				fast_right = true;
			else
				fast_right = false;			
				
			
			}
		}

		
		

		//���������� slow �� ���� �������� fast �̴�.. �� �ݴ뵵 ��������
		bool original_fast = false;
		bool converse_fast = false;


		/*
		char original_answer_fast[1024] = {0,};
		strcpy(original_answer_fast,pre_word_answer);
		strcat(original_answer_fast,"fast_protoss");
		strcat(original_answer_fast,".txt");

		char original_answer_slow[1024] = {0,};
		strcpy(original_answer_slow,pre_word_answer);
		strcat(original_answer_slow,"slow_protoss");
		strcat(original_answer_slow,".txt");


		if(starttime <= 345 && flog == 1)
			original_fast = true;

		if(starttime2 <= 345 && flfl==1)
			converse_fast = true;;





		if(starttime <= 345 && flog == 1 && converse_fast == false)
			rename(pre_word_answer,original_answer_fast);
		else if(starttime > 345 && flog == 1 && converse_fast == true)
			rename(pre_word_answer,original_answer_slow);


		char converse_answer_fast[1024] = {0,};
		strcpy(converse_answer_fast,pre_word_answer_converse);
		strcat(converse_answer_fast,"fast_protoss");
		strcat(converse_answer_fast,".txt");

		char converse_answer_slow[1024] = {0,};
		strcpy(converse_answer_slow,pre_word_answer_converse);
		strcat(converse_answer_slow,"slow_protoss");
		strcat(converse_answer_slow,".txt");

		*/


	//	if(starttime2 <= 345 && flfl==1 && original_fast == false)
			//rename(pre_word_answer_converse,converse_answer_fast);





		
		
		bool all_zero = false;
		//��� 0�̸� ����
		if(answer[0]==0 && answer[1]==0 && answer[2]==0 && answer[3] == 0 && answer[4]==0 && answer[5]==0 && answer[6]==0 && answer[7] == 0 && answer[8] == 0 && answer[9] == 0 && answer[10] == 0&& answer[11] == 0&& answer[12] == 0&& answer[13] == 0&& answer[14] == 0)
		{
			all_zero=true;
		}

			

		if(all_zero == false)
		{
			///!!! fast, slow�� �������ִ� �� �ּ�ó���س���.
			/*
		//fast�� ���
		if(fast_right == true)
			fprintf(fout,"%d,%d,%d,%d,%d,%d,%d,%d,%d,fast\n",answer[0],answer[1],answer[2],answer[3],answer[4],answer[5],answer[6],answer[7],answer[8]);
			//else if(starttime2 > 345 && flfl == 1 && original_fast == true)
			//rename(pre_word_answer_converse,converse_answer_slow);


		//slow�� ���
		else
			fprintf(fout,"%d,%d,%d,%d,%d,%d,%d,%d,%d,slow\n",answer[0],answer[1],answer[2],answer[3],answer[4],answer[5],answer[6],answer[7],answer[8]);
		
		*/

			
			
			//����� �����ϱ�
			int build_time_answer_min;
			static int sum=0,cnt=0;

			build_time_answer_min = 9999999;
			for(int c=0; c<=3;c++)
			{
				if(build_time_answer_min > build_answer[c] && build_answer[c] != 0)
					build_time_answer_min = build_answer[c];
			}

			if(build_time_answer_min != 9999999)
			{
			sum +=build_time_answer_min;
			cnt++;

			}
			//fprintf(fout,"\n��հ�: %lf\n",(double)sum/cnt);
			
			
			if(build_time_answer_min ==  build_answer[0])
				fprintf(fout,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,3gate\n",answer[0],answer[1],answer[2],answer[3],answer[4],answer[5],answer[6],answer[7],answer[8],answer[9],answer[10],answer[11],answer[12],answer[13],answer[14]);
			if(build_time_answer_min ==  build_answer[1])
				fprintf(fout,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,observer\n",answer[0],answer[1],answer[2],answer[3],answer[4],answer[5],answer[6],answer[7],answer[8],answer[9],answer[10],answer[11],answer[12],answer[13],answer[14]);
			if(build_time_answer_min ==  build_answer[2])
				fprintf(fout,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,dark\n",answer[0],answer[1],answer[2],answer[3],answer[4],answer[5],answer[6],answer[7],answer[8],answer[9],answer[10],answer[11],answer[12],answer[13],answer[14]);
			if(build_time_answer_min ==  build_answer[3])
				fprintf(fout,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,nexus\n",answer[0],answer[1],answer[2],answer[3],answer[4],answer[5],answer[6],answer[7],answer[8],answer[9],answer[10],answer[11],answer[12],answer[13],answer[14]);			




		strcpy(pre_word_answer,"original_enemy\\");
		strcpy(pre_word_answer_converse,"converse_enemy\\");

		}
		

		fclose(fi1);
		fclose(fi2);
		//fclose(fo);
		//fclose(fo2);


	}
}

