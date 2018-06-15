 #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void menu(){

system("cls");
	printf(" ___________________________\n"); //MENU 
	printf("|   CONFEITARIA DO SARTORI  |\n");
	printf("|---------------------------|\n");
	printf("|-----Menu de Produtos------|\n");
	printf("|1 - Incluir                |\n");
	printf("|2 - Editar                 |\n");
	printf("|3 - Excluir                |\n");
	printf("|4 - Consultar              |\n");
	printf("|5 - Relatorio              |\n");
	printf("|6 - Salvar e Sair          |\n");
	printf("|___________________________|\n");
	printf("Digite a opcao desejada:");
};
struct produtos{ //estrutura do produto
		char nome[50];//descrição do produto
		int quant;//quantidade do produto
		float preco;//preço de compra do produto
		int ativo;//ativo ou nao
		 
};

int main(){
	int i=0,opc_menu,x=0,g,pos,c,a;
	int count=1;
	float acp=0;//acumulador preco
	int acq=0;//acumulador quantidade
	struct produtos p[200];
	
	 FILE *pont_arq;
  	 char texto_str[250];
 	 char *token;
 	 
 	 pont_arq=fopen("database.txt", "r");
 	 while(fgets(texto_str, 250, pont_arq) != NULL) {
  	
	token=strtok(texto_str, "@");
    
    while (token!=NULL) {
        
      if (x==0)   {
	  
        strcpy(p[i].nome,token);
        x++;
      } else if (x==1) {
      
		p[i].quant=atoi(token); 
        x++;
	  }
	  
	  else if (x==2) {
	  	sscanf(token,"%f",&p[i].preco);
		x++;
	  }
	  
	  else if (x==3) {
	  	
      	p[i].ativo=atoi(token);
        x++;
	  }
	  	     token=strtok(NULL, "@");
       
    }
     x=0; 
     i++;
}
  
  fclose(pont_arq);
	
	
  
  	
	menu();
	scanf("%d", &opc_menu);
	
		while(opc_menu!=6){
			switch(opc_menu){
				case 1: //Incluir
				system("cls");
				printf("-------INCLUSAO-------\n\n");
				printf("Registro:%d\n\n", i);
				printf("Nome do produto:");
				fflush(stdin);
				gets(p[i].nome);
				printf("\nQuantidade de %s:", p[i].nome);
				scanf("%d", &p[i].quant);
				printf("\nPreco do %s: R$", p[i].nome);
				scanf("%f", &p[i].preco);
				p[i].ativo=1;
				acp=acp+p[i].preco;
				acq=acq+p[i].quant;
				i++;
				count++;
			break;
				case 2: //Editar
				system ("cls");
				printf("-------EDITAR-------\n\n");
				printf("Digite o codigo do registro: ");
  				scanf("%d",&pos);
  				if(pos<=count){
  				printf("Registro: %d\n", pos);
				printf("\n\n%s - %d un. - R$ %.2f\n\n"), p[pos].nome, p[pos].quant, p[pos].preco;
  				printf("Nome do produto:");
				fflush(stdin);
				gets(p[pos].nome);
  				acq=acq-p[pos].quant;
  				printf("Quantidade:");
				scanf("%d",&p[pos].quant);
  				acq=acq+p[pos].quant;
				acp=acp-p[pos].preco;
				printf("Preco: R$ ");
  				scanf("%f",&p[pos].preco);
  				acp=acp+p[pos].preco;
             }
             else{
             system("cls");
                      printf("Registro invalido!\n\n");
				 	sleep(1);                 
                  };
			  break;
  				case 3: //Excluir
  				system("cls");
  				printf("-------EXCLUSAO-------\n\n");
  				printf("Digite o codigo do registro: ");
  				scanf("%d",&pos);
  				if(pos<=count){	
  				p[pos].ativo=0;
  				acp=acp-p[pos].preco;
  				acq=acq-p[pos].quant;
  				sleep(2);
  				printf("\nRegistro excluido!\n\n");
  				sleep(1);
  				count--;
  			}
  				else{
  					printf("Registro invalido!\n\n");
				 	sleep(1);
				  };
  				system("pause");
  			break;
  				case 4: //Consultar
  				system("cls");
  				printf("-------CONSULTA-------\n\n");
				printf("Digite o codigo do registro: ");
  				scanf("%d",&pos);
  				system("cls");
  					
					  if(pos<count){
  				printf("\n\nProduto -------- %s",p[pos].nome);
  				printf("\nQuantidade ----- %d un",p[pos].quant);
  				printf("\nPreco ---------- R$ %.2f\n\n",p[pos].preco);
  				sleep(3);
			}
				else{
					printf("\n");
				  	printf("Registro invalido!\n\n");
				 	sleep(1);
			};
				system("pause");
  		 break;
  				
  				case 5:
  						system("cls");
  						printf("___________________________\n"); //MENU 
						printf("   CONFEITARIA DO SARTORI  \n");
						printf("---------------------------\n");
						printf("----Relatorio de estoque---\n");
						printf("---------------------------\n\n");
						printf("Total de produtos: %d\n", acq);
						printf("---------------------------\n\n");
						printf("Somatoria total:R$%.2f\n\n", acp);
						printf("---------------------------\n\n");
  						system("pause");
				  break;
			  default:
  				printf("Opcao invalida!\n");
		      break;  
		}
		menu();
		scanf("%d", &opc_menu);
	}
	pont_arq=fopen("database.txt", "w");
  
  for(g=0;g<i;g++) {
  	
    if (p[g].ativo==1){
	  	fprintf(pont_arq,"%s@%d@%.2f@%d\n", p[g].nome, p[g].quant, p[g].preco, p[g].ativo);
    }
  }
  
  fclose(pont_arq);

	

	return 0;
	system("exit");
};
