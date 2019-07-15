#include <stdio.h>
#include <stdlib.h>
#include "trabFinalED.h"

void inicializarListaAlunos(LISTAALUNOS *l){//INICIALIZA A LISTA, COM INICIO RECEBENDO NULL
    l->inicio = NULL;
}

int tamanhoListaAlunos(LISTAALUNOS *l){//FUNÇÃO PARA RETORNAR O TAMANHO DA LISTA(QUANTOS ELEMENTOS EXISTEM ALOCADOS)
    PONTALUNO end = l->inicio;
    int tam=0;
    while(end != NULL){
        tam++;
        end = end->prox;
    }
    //printf("tamanho  =  %i", tam);
    return tam;
}

void exibirListaAlunos(LISTAALUNOS *l){//FAZ A EXIBIÇÃO DAS INFORMAÇÕES BÁSICAS DE TODOS OS ALUNOS EXISTENTES NA LISTA
    PONTALUNO end = l->inicio;
    int i;
    printf("\nLista de alunos: \n");
    printf("\n\n--------------------------------------------\n\n");
    while(end != NULL){
        printf("\nMATRICULA: %i\n", end->dados.matricula);
        printf("NOME: %s\n", end->dados.nome);
        printf("ENDEREÇO: %s\n", end->dados.endereco);
        printf("TELEFONE: %s\n", end->dados.telefone);

        printf("NOTAS: ");
        for(i=0;i<4;i++){
            printf("%0.2lf - ", end->dados.notas[i]);
        }
        printf("MEDIA: %.2lf\n", end->dados.media);
        printf("\n\n--------------------------------------------\n\n");
        i=0;
        end = end->prox;
    }
}

void exibirHorarios(SALA *b, SALA *m, SALA *i, SALA *a){
    printf("-----TURMA BÁSICA-----\n");
    printf("Horário da turma: %s\n", b->turma.horario);
    printf("Professor: %s\n", b->turma.professor);
    //exibirListaAlunos(&b->turma.listaAlunos);
    printf("\n\n");
    printf("-----TURMA MÉDIA-----\n");
    printf("Horário da turma: %s\n", m->turma.horario);
    printf("Professor: %s\n", m->turma.professor);
    //exibirListaAlunos(&m->turma.listaAlunos);
    printf("\n\n");
    printf("-----TURMA INTERMEDIÁRIA-----\n");
    printf("Horário da turma: %s\n", i->turma.horario);
    printf("Professor: %s\n", i->turma.professor);
    //exibirListaAlunos(&i->turma.listaAlunos);
    printf("\n\n");
    printf("-----TURMA AVANÇADA-----\n");
    printf("Horário da turma: %s\n", a->turma.horario);
    printf("Professor: %s\n", a->turma.professor);
    //exibirListaAlunos(&a->turma.listaAlunos);



}

void exibirAluno(CONTALUNO al){//FUNÇÃO ESPECIFICA, PARA EXIBIR INFORMAÇÕES DE APENAS 1 ALUNO
    int i;
    printf("\nMATRICULA: %i\n", al.matricula);
    printf("NOME: %s\n", al.nome);
    printf("ENDEREÇO: %s\n", al.endereco);
    printf("TELEFONE: %s\n", al.telefone);
    printf("NOTAS: ");
    for(i=0;i<4;i++){
        printf("%0.2lf - ", al.notas[i]);
    }
    printf("MEDIA: %.2lf", al.media);
    i=0;
    fflush(stdin);
}

void buscaAlunoMatric(SALA *s, int matric){//REALIZA A BUSCA DENTRO DA LISTA, ATRAVÉS DA COMPARAÇÃO DE MATRICULA
    PONTALUNO aluno;
        aluno = s->turma.listaAlunos.inicio;

        while(aluno != NULL){
            if(aluno->dados.matricula == matric){
                exibirAluno(aluno->dados); return;
            }
            else aluno = aluno->prox;
        }
    printf("Aluno não encontrado !\n");
    //printf("\nPRESSIONE ENTER PARA CONTINUAR.....\n");
    getchar();
}

PONTALUNO buscaPosAluno(LISTAALUNOS *l, int matric, PONTALUNO *ant){//REALIZA A BUSCA DENTRO DA LISTA, ATRAVÉS DA COMPARAÇÃO DE MATRICULA, MAS ESTÁ FUNÇÃO RETORNA UM PONTEIRO, COM O ENDEREÇO DE ONDE ESTE ALUNO ESTÁ
        PONTALUNO aluno;
        *ant = NULL;
        aluno = l->inicio;

        while(aluno != NULL && aluno->dados.matricula < matric){
            *ant = aluno;
            aluno = aluno->prox;
        }
        if(aluno != NULL && aluno->dados.matricula == matric) return aluno;
        return NULL;
}

void buscaAlunoNome(SALA *s, char nome[]){//REALIZA A BUSCA DENTRO DA LISTA, ATRAVÉS DA COMPARAÇÃO DO NOME
    PONTALUNO aluno;
    int i;
    char aux[100];
    for(i = 0; nome[i] != '\0'; i++) nome[i] = toupper(nome[i]);//FAZ COM QUE A VARIAVEL A SER COMPARADA TENHA TODOS OS SEUS CARACTERS DO MESMO FORMATO
        //printf("%s\n", nome);
        aluno = s->turma.listaAlunos.inicio;
            while(aluno != NULL){
                strcpy(aux, aluno->dados.nome);
                for(i = 0; aux[i] != '\0'; i++) aux[i] = toupper(aux[i]);
               // printf("%s\n", aux);
                if(strcmp(aux, nome) == 0){//COMPARAÇÃO PARA VER SE EXISTE ALGUEM COM O NOME PESQUISADO DENTRE OS ELEMETOS DA LISTA
                    exibirAluno(aluno->dados);//EXIBIÇÃO DOS DADOS DESSE ALUNO, SE ENCONTRADO
                    return;
                }
                else aluno = aluno->prox;
        }
    printf("Aluno não encontrado");
    //printf("\nPRESSIONE ENTER PARA CONTINUAR.....\n");
    getchar();
}

void inicializarFrequencia(CONTALUNO *al){//INICALIZA TODAS AS POSIÇÕES DA FREQUENCIA DO ALUNO COM VALORES NÃO UTILIZADOS, PARA FAZER COMPARAÇÕES
    int i;
    for(i = 0; i<50; i++){
        strcpy(al->frequencia[i].data, "NULL");
        al->frequencia[i].presenca = 'N';
        al->frequencia[i].pos = -1;
    }
}

int inserirAluno(SALA *sala, CONTALUNO aluno){//FUNÇÃO DE INSERÇÃO DO ALUNO, DINAMICAMENTE ALOCADA
    char aux[100];
    int i;

    if(sala->turma.listaAlunos.inicio == NULL){//VERIFICA O INICIO DA LISTA, SE ELE ESTIVER VAZIO, JÁ FAZ A INCLUSÃO
        sala->turma.listaAlunos.inicio = (PONTALUNO) malloc(sizeof(ALUNO));
        inicializarFrequencia(&aluno);
        sala->turma.listaAlunos.inicio->dados = aluno;
        sala->turma.listaAlunos.inicio->prox = NULL;
        return 0;
    }
    else{//SE NÃO, ANDA NOS PONTEIROS ATÉ CHEGAR A NULL E FAZ A ALOCAÇÃO
        PONTALUNO posicao = sala->turma.listaAlunos.inicio;
        PONTALUNO anterior;
        while(posicao != NULL){
            anterior = posicao;
            posicao = posicao->prox;
        }
        posicao = (PONTALUNO) malloc(sizeof(ALUNO));

        inicializarFrequencia(&aluno);
        posicao->dados = aluno;
        anterior->prox = posicao;
        posicao->prox = NULL;
        return 0;
    }
    return -1;
}

int excluiAluno(SALA *sala, int m){//FUNÇÃO DE EXCLUSÃO DE ALUNOS DENTRO DA LISTA, REALIZANDO A LIBERAÇÃO DE MEMÓRIA
    PONTALUNO anterior, retornoPosicao;//PONTEIRO PARA GUARDAR A POSIÇÃO ANTERIOR E UM PARA O RESULTADO DA FUNÇÃO
    LISTAALUNOS listaAuxiliar = sala->turma.listaAlunos;//LISTA AUXILIAR PARA PASSAR PARA A FUNÇÃO
    retornoPosicao = buscaPosAluno(&listaAuxiliar, m, &anterior);//FUNÇÃO QUE RETORNA O ENDEREÇO DO ALUNO A SER EXCLUIDO
    if(retornoPosicao==NULL){
            printf("Falha ao excluir aluno, verifique o número da matricula através da função busca e tente novamente !");
            return -1;
    }
    if(anterior==NULL) sala->turma.listaAlunos.inicio = retornoPosicao->prox;
    else anterior->prox = retornoPosicao->prox;
    free(retornoPosicao);//LIBERAÇÃO DE MEMÓRIA
    printf("Aluno excluído com sucesso !");
    return 0;
}

void lancarNotas(LISTAALUNOS *l, int bim){//FUNÇÃO ESPECÍFICA PARA REALIZAR A INSERÇÃO DE NOTAS DE CADA ALUNO PRESENTE NA SALA
    PONTALUNO aux = l->inicio;
    double nota = 0;
    while(aux != NULL){
        int valida = 0;
        exibirAluno(aux->dados);
        printf("\nINSIRA A NOTA DO %dº BIMESTRE DESSE ALUNO ", bim);
        while (valida != 1){
        scanf("%lf", &nota);
        fflush(stdin);
            if ( nota >=0 && nota<= 10){
                aux->dados.notas[bim-1] = nota;
                printf("\nNota Registrada com Sucesso \n", bim);
                valida = 1;
                aux = aux->prox;
            }
            else printf("\nInsira uma nota de 0 a 10: ");
        }
    }
}

void conteudosMinistrados(SALA *s, int aula){// REALIZA A INTRODUÇÃO DOS CONTEUDOS QUE FORAM MINISTRADOS EM AULAS
    char aux[100], dt[12];
    printf("Qual o conteudo ministrado na %dº aula ?\n", aula);
    fflush(stdin);
    gets(aux);
    fflush(stdin);
    printf("Qual a data da aula ?\n");
    scanf("%s", &dt);
    fflush(stdin);
    strcpy(s->turma.conteudos[aula-1].conteudos, aux);
    strcpy(s->turma.conteudos[aula-1].data, dt);
}

void exibirConteudosMinistrados(SALA *s){//REALIZA A EXIBIÇÃO DOS CONTEUDOS ARMAZENADOS
    int i=0;
    for(i=0;i<50;i++){
        if(s->turma.conteudos[i].conteudos[0] == '0')break;
        printf("\nConteudo: %s - DATA: %s\n", s->turma.conteudos[i].conteudos, s->turma.conteudos[i].data);

    }
   // printf("\nPRESSIONE ENTER PARA CONTINUAR.....\n");
    getchar();
}

void inserirPresenca(LISTAALUNOS *l, int aula){//MANIPULA A FREQUENCIA DOS ALUNOS EM DETERMINADA AULA, CADA NUMERO É UMA PSIÇÃO NO ARRAY
        PONTALUNO aux = l->inicio;
        char pres, dt[12];

        printf("Insira a data da aula  ");
        scanf("%s", &dt);
        fflush(stdin);
        printf("INSIRA AS PRESENÇAS DA AULA %i, C para presente F para falta\n", aula);
        while(aux !=NULL){
            printf("%s: ", aux->dados.nome);
            scanf("%c", &pres);
            fflush(stdin);
            pres = tolower(pres);
            aux->dados.frequencia[aula-1].presenca = pres;
            strcpy(aux->dados.frequencia[aula-1].data, dt);
            aux->dados.frequencia[aula-1].pos = aula;
            aux = aux->prox;
        }
        printf("Fim da lista");
        //printf("\nPRESSIONE ENTER PARA CONTINUAR.....\n");
        getchar();
}

void controleFrequencia(LISTAALUNOS *l){// FAZ A EXIBIÇÃO DA MÉDIA DE FREQUENCIA DE CADA ALUNO
    PONTALUNO aux = l->inicio;
    double freq;
    printf("\n\n--------------------------------------------\n\n");
    while(aux != NULL){
        int cont = 0;
        int i = 0;
        printf("ALUNO: %s", aux->dados.nome);
        while(aux->dados.frequencia[i].pos != -1){

            if(aux->dados.frequencia[i].presenca == 'c'){

                    cont++;
            }
            i++;
        }
        cont =  cont*100;
        freq = (double)(cont/i);
        printf("\nFrequência do Aluno: %0.2lf%\%", freq);
        //printf("\nPRESSIONE ENTER PARA CONTINUAR.....\n");
        aux=aux->prox;
        printf("\n\n--------------------------------------------\n\n");

    }
    getchar();
}

void mediaNotasAluno(SALA *s){//SOMA AS 4 NOTAS DO ALUNO E TIRA SUA MÉDIA, E ARMAZENA EM UMA VARIÁVEL
    PONTALUNO end = s->turma.listaAlunos.inicio;
    while(end!=NULL){
        end->dados.media = (end->dados.notas[0]+end->dados.notas[1]+end->dados.notas[2]+end->dados.notas[3]);
        end->dados.media = end->dados.media/4;
        end = end->prox;
    }
}

void mediaModuloFinal(SALA *s, int cont){//FAZ A SOMA DE TODAS AS MÉDIAS E DIVIDE PELO NUMERO DE ALUNOS, E JÁ FAZ A EXIBIÇAO EM ORDEM CRESCENTE E DECRESCENTE
    PONTALUNO andar = s->turma.listaAlunos.inicio;
    double notasModulo[cont];
    int j=-1;
    int i = 0;
    double mediaModulo = 0.0;
    while(andar != NULL){
        j++;
        notasModulo[j] = andar->dados.media;
        andar = andar->prox;
    }
    for(i=0;i<cont;i++){
        mediaModulo = mediaModulo+notasModulo[i];
    }
    printf("\n\nNOTAS antes de ordenar: ");
    for(i=0;i<cont;i++){
        printf("%.2lf, ", notasModulo[i]);
    }
    quicksort(&notasModulo, 0, cont-1);
    //ordenaNota(&notasModulo,cont);
    printf("\n\nNOTAS DECRESCENTES: ");
    for(i=0;i<cont;i++){
        printf("%.2lf, ", notasModulo[i]);
    }


    printf("\n\nNOTAS CRESCENTES: ");


    for(i=cont-1;i>=0;i--){
        printf("%.2lf, ", notasModulo[i]);
    }

    printf("\n\nMEDIA FINAL DO MÓDULO:  %.2lf", mediaModulo/cont);

    //printf("\nPRESSIONE ENTER PARA CONTINUAR.....\n");
    getchar();
}

void troca(int *v, int i, int j){
    int aux;
    aux=v[i];
    v[i]=v[j];
    v[j]=aux;
}

int particao(int *x, int p, int r){
   int pivo, i, j;
   i=p-1;
   j=r+1;
   pivo=x[(int)floor((p+r)/2)];
   while(i<j){
       do{
          j--;
       }while((!(x[j]<=pivo)) && j>=0);
       do{
          i++;
       }while((!(x[i]>=pivo)) && i<=r);
       if(i<j) troca(x, i, j);
   }
   return j;
}

void quicksort(int *x, int p, int r){
    int q;
    if(p<r){
        q = particao(x, p, r);
        quicksort(x, p, q);
        quicksort(x, q+1, r);
    }
}


