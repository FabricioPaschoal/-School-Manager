#ifndef TRABFINALED_H_INCLUDED
#define TRABFINALED_H_INCLUDED

typedef struct{
    char presenca;
    char data[12];
    int pos;
}FREQUENCIA;

typedef struct {
    int matricula;
    char nome[100];
    char endereco[100];
    char telefone[100];
    double notas[4];
    FREQUENCIA frequencia[50];
    double media;
}CONTALUNO;

typedef struct aux{
    CONTALUNO dados;
    struct aux* prox;
}ALUNO;

typedef ALUNO* PONTALUNO;

typedef struct{
    char conteudos[100];
    char data[12];
}CONTEUDOS;

typedef struct{
    PONTALUNO inicio;
}LISTAALUNOS;

typedef struct{
    char modulo[100];
    char horario[100];
    char professor[100];
    double mediaModulo;
    LISTAALUNOS listaAlunos;
    CONTEUDOS conteudos[50];
}TURMA;

typedef struct {
    TURMA turma;
}SALA;




void inicializarListaAlunos(LISTAALUNOS *l);
void exibirHorarios(SALA *b, SALA *m, SALA *i, SALA *a);
int tamanhoListaAlunos(LISTAALUNOS *l);
void exibirListaAlunos(LISTAALUNOS *l);
void exibirAluno(CONTALUNO al);
void buscaAlunoMatric(SALA *s, int matric);
void buscaAlunoNome(SALA *s, char nome[]);
int inserirAluno(SALA *s, CONTALUNO al);
void inicializarFrequencia(CONTALUNO *al);
PONTALUNO buscaPosAluno(LISTAALUNOS *l, int matric, PONTALUNO *ant);
int excluiAluno(SALA *sala, int m);
void lancarNotas(LISTAALUNOS *l, int bim);
void exibirConteudosMinistrados(SALA *s);
void conteudosMinistrados(SALA *s, int aula);
void inserirPresenca(LISTAALUNOS *l, int aula);
void controleFrequencia(LISTAALUNOS *l);
void mediaNotasAluno(SALA *s);
void ordenaNota(double vet[], int tam);
void mediaModuloFinal(SALA *s, int cont);

#endif // TRABFINALED_H_INCLUDED
