typedef struct aluno Aluno;
struct aluno{
    int matricula;
    char nome[81];
    char endereco[121];
    char telefone[21];
};

void inicializa(int n, Aluno** tab);

void preenche(int n, Aluno** tab, int i,int matricula, char nome[],char endereco[],char telefone[]);

void deletar(int n, Aluno** tab, int i);

void atualiza(int n, Aluno** tab, int i,int matricula, char nome[],char endereco[],char telefone[]);

int busca_linear(int n, Aluno** tab, char nome[]);