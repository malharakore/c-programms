/*program to generate electricity bill*/
/* ht=high tension
   lt=low tension*/
/* 5% tax */
/* 7 type of electricity connection */
/* 1.lt2au(used in homes and small shops in urban area) minimum charge is 15rs, if consumed units under 0-30 then cost per unit is 2.70 rs,if consumed units under 31-100 then cost per unit is 4.00 rs,if consumed unit under 101-200 then cost per unit is 5.25 rs,if consumed unit above 200 then cost per unit is 6.25 rs*/
/* 2.lt2ar(used in homes and small shops in rural area) minimum charge is 15rs, if consumed units under 0-30 then cost per unit is 2.60 rs,if consumed units under 31-100 then cost per unit is 3.70 rs,if consumed unit under 101-200 then cost per unit is 4.95 rs,if consumed unit above 200 then cost per unit is 5.75 rs*/
/* 3.lt3(used in commercial area) minimum charge is 50rs, if consumed units under 0-50 then cost per unit is 6.45 rs,if consumed unit above 51 then cost per unit is 7.45 rs */
/* 4.lt4(used in irigation purpose in farm) minimum charge is 100rs,measured in hp,1 hp=735 units, if consumed hp under 0-10 then cost per hp is 3.36 rs,if consumed hp above 10 then cost per hp is 1.7 rs */
/* 5.lt5(used in industrial area) minimum charge is 50rs, if consumed units under 0-500 then cost per unit is 4.25 rs,if consumed units under 501-1000 then cost per unit is 4.95 rs,if consumed unit above 1000 then cost per unit is 5.25 rs*/
/* 6.lt6(used in temparary connection) minimum charge is 600rs,3.20 rs per unit*/
/* 7.ht2a(used in large industrial area) minimum charge is 10000rs,7 paisa per unit*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	int customer_id,unit_consumption,type;
	float rate,tax=5,amount=0,total_amount=0,hp=0,minmum_charge;
	char name[25];
	clrscr();
	printf("Enter the customer identification number: ");
	scanf("%d",&customer_id);
	printf("Enter customer name: ");
	scanf("%s",name);
	printf("Enter units consumed by customer: ");
	scanf("%d",&unit_consumption);
	printf("1.lt2au\n2.lt2ar\n3.lt3\n4.lt4\n5.lt5\n6.lt6\n7.ht2a\n\n Enter the type of connection: ");
	scanf("%d",&type);

	switch(type)
	{
		case 1:
				if (unit_consumption>0&& unit_consumption<=30)
					rate=2.70;
				else if(unit_consumption>30&& unit_consumption<=100)
					rate=4.00;

				else if(unit_consumption>100&& unit_consumption<=200)
					rate=5.25;
				else
					rate=6.25;
					minmum_charge=15.0;
				amount=unit_consumption*rate;
				break;
		case 2:
				minmum_charge=15;
				if (unit_consumption>0&& unit_consumption<=30)
					rate=2.60;
				else if(unit_consumption>=31&& unit_consumption<=100)
					rate=3.70;

				else if(unit_consumption>100&& unit_consumption<=200)
					rate=4.95;
				else
					rate=5.75;

				amount=unit_consumption*rate;
				break;

		case 3:
				minmum_charge=50;
				if (unit_consumption>0&& unit_consumption<=50)
					rate=6.45;
				else
					rate=7.45;

				amount=unit_consumption*rate;
				break;


		case 4:
				minmum_charge=100;
				hp=unit_consumption/735;
				if (hp<=10)
					rate=3.36;
				else
					rate=1.75;

				amount=hp*rate;

				break;
		case 5:
				minmum_charge=500;
				if (unit_consumption>0&& unit_consumption<=500)
					rate=4.25;
				else if(unit_consumption>500&& unit_consumption<=1000)
					rate=4.95;

				else
					rate=5.25;

				amount=unit_consumption*rate;

				
		case 6:
				minmum_charge=600;

				if (unit_consumption>0)	
					rate=3.20;

				amount=unit_consumption*rate;

				break;

		case 7:
				minmum_charge=10000;
				if (unit_consumption>0)
					rate=0.07;

				amount=unit_consumption*rate;

				break;
		default :	printf("specify correct connection type");
				 getch();
				 break;

	}


	clrscr();
	if(minmum_charge>amount)
	{
		total_amount=minmum_charge;
	}
	if(amount>minmum_charge)
	{
		total_amount=amount+((amount*tax)/100);
	}
	printf("\t\t\tElectricity Bill\n\n");
	printf("Customer IDNO:  %d",customer_id);
	printf("\nCustomer Name:  %s",name);
	printf("\nunit Consumed:  %d",unit_consumption);
	printf("\nAmount Charges at %f per unit:  %f",rate,amount);
	printf("\nNet Amount Paid By the Customer with 5%% tax:  %f",total_amount);
	getch();
}
