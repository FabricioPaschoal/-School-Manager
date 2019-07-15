#include "trabFinalED.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");


    int resp=0;
    static int matric = 0;
    CONTALUNO estudante;
    char aux[100];
    int i=0;
    int num, bim;
    int exclu;
    SALA basico, medio, intermediario, avancado;
    int auxTam;
    inicializarListaAlunos(&basico.turma.listaAlunos);
    strcpy(basico.turma.horario, "SEGUNDA E QUARTA DAS 13:00 ÀS 15:00");
    strcpy(basico.turma.professor, "JOÃO CRISTOVAM");
    for(i=0; i<50;i++){
        strcpy(basico.turma.conteudos[i].conteudos, "0");
        strcpy(basico.turma.conteudos[i].data, "0");
    }

    inicializarListaAlunos(&medio.turma.listaAlunos);
    strcpy(medio.turma.horario, "TERÇA E QUINTA DAS 13:00 ÀS 15:00");
    strcpy(medio.turma.professor, "JOÃO CRISTOVAM");
    for(i=0; i<50;i++){
        strcpy(medio.turma.conteudos[i].conteudos, "0");
        strcpy(medio.turma.conteudos[i].data, "0");
    }

    inicializarListaAlunos(&intermediario.turma.listaAlunos);
    strcpy(intermediario.turma.horario, "SEGUNDA E QUARTA DAS 19:00 ÀS 21:00");
    strcpy(intermediario.turma.professor, "JOAQUIM SILVÉRIO");
    inicializarListaAlunos(&avancado.turma.listaAlunos);
    for(i=0; i<50;i++){
        strcpy(intermediario.turma.conteudos[i].conteudos, "0");
        strcpy(intermediario.turma.conteudos[i].data, "0");
    }

    strcpy(avancado.turma.horario, "TERÇA E QUINTA DAS 19:00 ÀS 21:00");
    strcpy(avancado.turma.professor, "JOAQUIM SILVÉRIO");
    for(i=0; i<50;i++){
        strcpy(avancado.turma.conteudos[i].conteudos, "0");
        strcpy(avancado.turma.conteudos[i].data, "0");
    }
    printf("############ BEM VINDO AO SOFTWARE IES ############");

     char elemento[10];
    int recuo = 0;

    // Atribuindo um título a janela.

    //scanf("%s", &elemento);
    strcpy(elemento,"ESTRUTURA");
    printf("\n\n\n\n\t");

    int linha, coluna, TAMANHO = 20;

    for (linha = 1; linha <= TAMANHO; linha++) {

        for (coluna = 1; coluna <= TAMANHO; coluna++) {

            if (coluna == linha || (coluna == TAMANHO - recuo))
                printf("%s", elemento);
            else
                printf(" ");

            if (coluna == TAMANHO) {
                recuo++;
                printf("\n\t");
            }
        }
    }

    getch();



    getchar();
    do{


        system("cls");
        printf("    ####################### MENU #######################\n\n");

        printf("1 - VISUALIZAR INFORMAÇÕES DA TURMA ! \n");
        printf("2 - INSERIR ALUNOS ! \n");
        printf("3 - BUSCAR ALUNO ! \n");
        printf("4 - ACESSAR DIÁRIO DE TURMA ! \n");
        printf("5 - MEDIA FINAL DO MÓDULO ! \n");
        printf("6 - EXCLUIR ALUNO ! \n");
        printf("7 - EXIBIR HORÁRIOS DAS TURMAS! \n");
        printf("8 - SAIR ! \n");
        printf("\nOPÇÃO DIGITADA: ");
        scanf("%i", &resp);
        fflush(stdin);

        switch(resp){
            case 1:
                system("cls");
                printf("               INFORMAÇÕES               ");
                printf("\n\nSelecione o nível da turma para exibição das informações ?\n\n");
                printf("(1) Básico.\n");
                printf("(2) Médio.\n");
                printf("(3) Intermediário.\n");
                printf("(4) Avançado.\n");
                printf("\nOPÇÃO DIGITADA: ");
                scanf("%i", &resp);
                fflush(stdin);
                switch(resp){
                    case 1:
                        exibirListaAlunos(&basico.turma.listaAlunos);
                        break;
                    case 2:
                        exibirListaAlunos(&medio.turma.listaAlunos);
                        break;
                    case 3:
                        exibirListaAlunos(&intermediario.turma.listaAlunos);
                        break;
                    case 4:
                        exibirListaAlunos(&avancado.turma.listaAlunos);
                        break;
                    default:
                        printf("Opção inválida !");
                        break;
                }

                fflush(stdin);
                getchar();
                printf("PRESSIONE ENTER PARA CONTINUAR...");
                break;
            case 2:
                system("cls");
                printf("               MATRICULAR               ");
                printf("\n\nEm qual nível o aluno será matriculado?\n\n");
                printf("(1) Básico.\n");
                printf("(2) Médio.\n");
                printf("(3) Intermediário.\n");
                printf("(4) Avançado.\n");
                printf("\nOPÇÃO DIGITADA: ");
                scanf("%i", &resp);
                fflush(stdin);
                matric ++;
                estudante.matricula=matric;
                printf("\nInsira o nome do aluno: ");
                gets(estudante.nome);
                fflush(stdin);
                printf("\nInsira o endereço do aluno: ");
                gets(estudante.endereco);
                fflush(stdin);
                printf("\nInsira o telefone do aluno: ");
                gets(estudante.telefone);
                fflush(stdin);


                switch(resp){//SWITCH CASE 2
                    case 1:

                        inserirAluno(&basico, estudante);
                        break;
                    case 2:

                        inserirAluno(&medio, estudante);
                        break;
                    case 3:
                        inserirAluno(&intermediario, estudante);
                        break;
                    case 4:
                        inserirAluno(&avancado, estudante);
                        break;
                    default:
                        printf("Opção inválida!");
                        break;
                }
                getchar();
                printf("PRESSIONE ENTER PARA CONTINUAR...");
                break;
            case 3:
                system("cls");
                printf("               BUSCA               \n\n");
                printf("(1) Buscar aluno por Matricula!\n");
                printf("(2) Buscar aluno por Nome!\n");
                fflush(stdin);
                printf("\nOPÇÃO DIGITADA: ");
                scanf("%i", &resp);
                fflush(stdin);
                switch(resp){//SWITCH CASE 3
                    case 1:
                        system("cls");
                        printf("               BUSCA               \n\n");
                        printf("Insira o numero da matricula do Aluno!\n");
                        printf("\nOPÇÃO DIGITADA: ");
                        scanf("%i", &num);
                        fflush(stdin);
                        printf("\nInsira o nível em que o aluno está matriculado!\n\n");
                        printf("(1) Básico.\n");
                        printf("(2) Médio.\n");
                        printf("(3) Intermediário.\n");
                        printf("(4) Avançado.\n");
                        printf("\nOPÇÃO DIGITADA: ");
                        scanf("%i", &i);
                            switch(i){
                                case 1:
                                    buscaAlunoMatric(&basico, num);
                                    break;
                                case 2:
                                    buscaAlunoMatric(&medio, num);
                                    break;
                                case 3:
                                    buscaAlunoMatric(&intermediario, num);
                                    break;
                                case 4:
                                    buscaAlunoMatric(&avancado, num);
                                    break;
                            }
                        break;
                    case 2:
                        system("cls");
                        printf("               BUSCA               \n\n");
                        printf("Insira o nome do Aluno!\n");
                        fflush(stdin);
                        gets(aux);
                        fflush(stdin);
                        printf("Insira o nível em que o aluno está matriculado!\n\n");
                        printf("(1) Básico.\n");
                        printf("(2) Médio.\n");
                        printf("(3) Intermediário.\n");
                        printf("(4) Avançado.\n");
                        printf("\nOPÇÃO DIGITADA: ");
                        scanf("%i", &i);
                        switch(i){
                                case 1:
                                    buscaAlunoNome(&basico, aux);
                                    break;
                                case 2:
                                    buscaAlunoNome(&medio, aux);
                                    break;
                                case 3:
                                    buscaAlunoNome(&intermediario, aux);
                                    break;
                                case 4:
                                    buscaAlunoNome(&avancado, aux);
                                    break;
                        }
                        break;


            }
            getchar();
            printf("PRESSIONE ENTER PARA CONTINUAR...");
            break;
            case 4:
                system("cls");
                printf("               DIÁRIO DE TURMA               \n\n");
                printf("(1) Lançamento das Notas\n");
                printf("(2) Acessar opções de conteúdo\n");
                printf("(3) Para fazer a chamada\n");
                printf("\nOPÇÃO DIGITADA: ");
                scanf("%i", &i);
                fflush(stdin);
                system("cls");
                switch(i){
                    case 1:
                        printf("               DIÁRIO DE TURMA               \n\n");
                        printf("Deseja manipular/visualizar as notas de qual turma?\n\n");
                        printf("(1) Básico.\n");
                        printf("(2) Médio.\n");
                        printf("(3) Intermediário.\n");
                        printf("(4) Avançado.\n");
                        printf("\nOPÇÃO DIGITADA: ");
                        scanf("%i", &resp);
                        fflush(stdin);
                        switch(resp){
                            case 1:

                                printf("\n\nDigite o bimestre para inserção de notas (1, 2, 3 ou 4): ");
                                printf("\n\nOPÇÃO DIGITADA: ");
                                scanf("%i", &bim);
                                fflush(stdin);
                                if(bim < 1 || bim > 4){
                                printf("\nBimestre inválido...\n Retornando ao Menu");
                                printf("\nPRESSIONE ENTER PARA CONTINUAR......");
                                getchar();
                                break;
                                }
                                lancarNotas(&basico.turma.listaAlunos, bim);
                                break;
                            case 2:
                                printf("\n\nDigite o bimestre para inserção de notas (1, 2, 3 ou 4): ");
                                printf("\n\nOPÇÃO DIGITADA: ");
                                scanf("%i", &bim);
                                fflush(stdin);
                                if(bim < 1 || bim > 4){
                                printf("\nBimestre inválido...\n Retornando ao menu");
                                getchar();
                                printf("\nPRESSIONE ENTER PARA CONTINUAR......");
                                break;
                                }
                                lancarNotas(&medio.turma.listaAlunos, bim);
                                break;
                            case 3:
                                printf("\n\nDigite o bimestre para inserção de notas (1, 2, 3 ou 4): ");
                                printf("\n\nOPÇÃO DIGITADA: ");
                                scanf("%i", &bim);
                                fflush(stdin);
                                if(bim < 1 || bim > 4){
                                printf("\nBimestre inválido...\n Retornando ao menu");
                                printf("\nPRESSIONE ENTER PARA CONTINUAR......");
                                getchar();
                                break;
                                }
                                lancarNotas(&intermediario.turma.listaAlunos, bim);
                                break;
                            case 4:
                                printf("\n\nDigite o bimestre para inserção de notas (1, 2, 3 ou 4): ");
                                printf("\n\nOPÇÃO DIGITADA: ");
                                scanf("%i", &bim);
                                fflush(stdin);
                                if(bim < 1 || bim > 4){
                                printf("\nBimestre inválido...\n Retornando ao menu");
                                printf("\nPRESSIONE ENTER PARA CONTINUAR......");
                                getchar();
                                break;
                                }
                                lancarNotas(&avancado.turma.listaAlunos, bim);
                                break;
                        }
                    break;
                    case 2:
                        printf("               DIÁRIO DE TURMA               \n\n");
                        printf("\nSelecione o nível da Turma para Opções de Conteúdos\n\n");
                        printf("(1) Básico.\n");
                        printf("(2) Médio.\n");
                        printf("(3) Intermediário.\n");
                        printf("(4) Avançado.\n");
                        printf("\nOPÇÃO DIGITADA: ");
                        scanf("%i", &resp);
                        fflush(stdin);
                        system("cls");
                        printf("               DIÁRIO DE TURMA               \n\n");
                        switch(resp){
                            case 1:
                                printf("(1) Cadastrar conteudo\n");
                                printf("(2) Exibir conteudo\n");
                                printf("\nOPÇÃO DIGITADA: ");
                                scanf("%i", &resp);
                                fflush(stdin);
                                switch(resp){
                                    case 1:
                                        printf("\nInsira o numero da aula: ");
                                        scanf("%i", &num);
                                        fflush(stdin);
                                        conteudosMinistrados(&basico, num);
                                        break;
                                    case 2:
                                        exibirConteudosMinistrados(&basico);
                                        break;
                                }
                            break;
                                case 2:
                                    printf("(1) Cadastrar conteudo\n");
                                    printf("(2) Exibir conteudo.\n");
                                    printf("\nOPÇÃO DIGITADA: ");
                                    scanf("%i", &resp);
                                    fflush(stdin);
                                    switch(resp){
                                        case 1:
                                            printf("\nInsira o numero da aula !\n");
                                            scanf("%i", &num);
                                            fflush(stdin);
                                            conteudosMinistrados(&medio, num);
                                            break;
                                        case 2:
                                            exibirConteudosMinistrados(&medio);
                                            break;
                                    }
                                    break;
                                case 3:
                                    printf("(1) Cadastrar conteudo\n");
                                    printf("(2) Exibir conteudo.\n");
                                    printf("\nOPÇÃO DIGITADA: ");
                                    scanf("%i", &resp);
                                    fflush(stdin);
                                    switch(resp){
                                        case 1:
                                            printf("\nInsira o numero da aula !\n");
                                            scanf("%i", &num);
                                            fflush(stdin);
                                            conteudosMinistrados(&intermediario, num);
                                            break;
                                        case 2:
                                            exibirConteudosMinistrados(&intermediario);
                                            break;
                                    }
                                    break;
                                case 4:
                                    printf("(1) Cadastrar conteudo\n");
                                    printf("(2) Exibir conteudo.\n");
                                    printf("\nOPÇÃO DIGITADA: ");
                                    scanf("%i", &resp);
                                    fflush(stdin);
                                    switch(resp){
                                        case 1:
                                            printf("\nInsira o numero da aula !\n");
                                            scanf("%i", &num);
                                            fflush(stdin);
                                            conteudosMinistrados(&avancado, num);
                                            break;
                                        case 2:
                                            exibirConteudosMinistrados(&avancado);
                                            break;
                                    }
                                    break;
                                break;
                        }
                        break;
                    case 3:
                        printf("               DIÁRIO DE TURMA               \n\n");
                        printf("Opções de Frequencia\n");
                        printf("(1) Básico.\n");
                        printf("(2) Médio.\n");
                        printf("(3) Intermediário.\n");
                        printf("(4) Avançado.\n");
                        printf("\nOPÇÃO DIGITADA: ");
                        scanf("%i", &resp);
                        fflush(stdin);
                        system("cls");
                        printf("               DIÁRIO DE TURMA               \n\n");
                        switch(resp){
                            case 1:
                                printf("(1) Inserir presenças\n");
                                printf("(2) Exibir frequências\n");
                                printf("\nOPÇÃO DIGITADA: ");
                                scanf("%i", &resp);
                                fflush(stdin);
                                switch(resp){
                                    case 1:
                                        printf("\nInsira o numero da aula !\n");
                                        scanf("%i", &num);
                                        fflush(stdin);
                                        inserirPresenca(&basico.turma.listaAlunos, num);
                                        break;
                                    case 2:
                                        controleFrequencia(&basico.turma.listaAlunos);
                                        break;
                                }
                            break;
                            case 2:
                                printf("(1) Cadastrar conteudo\n");
                                printf("(2) Exibir conteudo.\n");
                                printf("\nOPÇÃO DIGITADA: ");
                                scanf("%i", &resp);
                                fflush(stdin);
                                system("cls");
                                switch(resp){
                                    case 1:
                                        printf("\nInsira o numero da aula !\n");
                                        scanf("%i", &num);
                                        fflush(stdin);
                                        inserirPresenca(&medio.turma.listaAlunos, num);
                                        break;
                                    case 2:
                                        controleFrequencia(&medio.turma.listaAlunos);
                                        break;
                                }
                            break;
                            case 3:
                                printf("(1) Cadastrar conteudo\n");
                                printf("(2) Exibir conteudo.\n");
                                printf("\nOPÇÃO DIGITADA: ");
                                scanf("%i", &resp);
                                fflush(stdin);
                                switch(resp){
                                    case 1:
                                        printf("\nInsira o numero da aula !\n");
                                        scanf("%i", &num);
                                        fflush(stdin);
                                        inserirPresenca(&intermediario.turma.listaAlunos, num);
                                        break;
                                    case 2:
                                        controleFrequencia(&intermediario.turma.listaAlunos);
                                        break;
                                }
                                    break;
                            case 4:
                                printf("(1) Cadastrar conteudo\n");
                                printf("(2) Exibir conteudo.\n");
                                printf("\nOPÇÃO DIGITADA: ");
                                scanf("%i", &resp);
                                fflush(stdin);
                                switch(resp){
                                    case 1:
                                        printf("\nInsira o numero da aula !\n");
                                        scanf("%i", &num);
                                        fflush(stdin);
                                        inserirPresenca(&avancado.turma.listaAlunos, num);
                                        break;
                                    case 2:
                                        controleFrequencia(&avancado.turma.listaAlunos);
                                        break;
                                }
                                break;
                        }
                }
                getchar();
                printf("PRESSIONE ENTER PARA CONTINUAR...");
                    break;
            case 5:





                system("cls");
                printf("               MÉDIA               \n\n");
                printf("(1) Média módulo basico\n");
                printf("(2) Média módulo medio\n");
                printf("(3) Média módulo intermediário\n");
                printf("(4) Média módulo avançado\n");
                printf("\nOPÇÃO DIGITADA: ");
                scanf("%i", &i);
                fflush(stdin);
                switch(i){
                    case 1:
                        mediaNotasAluno(&basico);
                        auxTam = tamanhoListaAlunos(&basico.turma.listaAlunos);

                        mediaModuloFinal(&basico, auxTam);
                        break;
                    case 2:
                        mediaNotasAluno(&medio);
                        auxTam = tamanhoListaAlunos(&medio.turma.listaAlunos);

                        mediaModuloFinal(&medio, auxTam);
                        break;
                    case 3:
                        mediaNotasAluno(&intermediario);
                        auxTam = tamanhoListaAlunos(&intermediario.turma.listaAlunos);
                        mediaModuloFinal(&intermediario, auxTam);
                        break;
                    case 4:
                        mediaNotasAluno(&avancado);
                        auxTam = tamanhoListaAlunos(&avancado.turma.listaAlunos);
                        mediaModuloFinal(&avancado, auxTam);
                        break;
                }
                getchar();
                printf("\nPRESSIONE ENTER PARA CONTINUAR...");
                break;
            case 6 :

                system("cls");
                printf("               EXCLUIR ALUNO               \n\n");
                printf("(1) Excluir aluno do módulo basico\n");
                printf("(2) Excluir aluno do módulo medio\n");
                printf("(3) Excluir aluno do módulo intermediário\n");
                printf("(4) Excluir aluno do módulo avançado\n");
                printf("\nOPÇÃO DIGITADA: ");
                scanf("%i", &i);
                printf("\nDigite a metricula do aluno:  ");
                scanf("%i", &exclu);
                fflush(stdin);
                printf("\n");
                switch(i){
                    case 1:
                        excluiAluno(&basico,exclu);
                        break;
                    case 2:
                        excluiAluno(&medio,exclu);
                        break;
                    case 3:
                        excluiAluno(&intermediario,exclu);
                        break;
                    case 4:
                        excluiAluno(&avancado,exclu);
                        break;
                }
                getchar();
                break;
                    case 7:
                        system("cls");
                        printf("               HORÁRIOS DE TURMA               \n\n");
                        printf("\nPRESSIONE ENTER PARA CONTINUAR...");
                        getchar();
                        system("cls");
                        printf("               HORÁRIOS DE TURMA               \n\n");
                        exibirHorarios(&basico, &medio, &intermediario, &avancado);
                        printf("\nPRESSIONE ENTER PARA CONTINUAR...");
                        getchar();
                        break;
                    case 8:
                        break;
                break;
                    default:
                        printf("\nOPÇÃO INVÁLIDA !");
                        getchar();
                        break;
        }
    }while(resp!=8);

}


