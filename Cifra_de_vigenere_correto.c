//Denis S. G. de Araújo 14/0136282 Turma 01
// Obs: projeto desenvolvido na plataforma windows usando a IDE CodeBlocks.
#include<stdio.h>
#include<stdlib.h>
void Preenche_tabua();
void Cifra();
void Decifra();
void Ataque();
int menu();
char tabua_cifra[26][26];
//-----------------------------------------------------------------------------------------------------------------------------
void Preenche_tabua(char tabua[26][26])
                   {
                     int i, j, aux = 0;

                     for(i = 0; i < 26; i++)

                          for(j = 0; j < 26; j++)

                               tabua[i][j] = 97 + ((i + aux++) % 26);
                   }
//-----------------------------------------------------------------------------------------------------------------------------
int menu()
        {
          int opcao = 0;

          do{
              printf("Escolha a op\x87\xc6o desejada:\n");

              printf("1 - Cifrar\n");

              printf("2 - Decifrar\n");

              printf("3 - Atacar\n");

              printf("4 - Sair\n");

              scanf("%d", &opcao);

              system("cls");

            }while(opcao < 1 || opcao > 4);

           system("cls");

           return opcao;
        }
//-----------------------------------------------------------------------------------------------------------------------------
void Cifra(char *texto_fonte, char *palavra_chave, char *texto_cifrado)
          {
            int i = 0, j = 0;

            printf("Digite o texto a ser cifrado:\n");

            fgets(texto_fonte, 10000, stdin);

            printf("Digite a palavra chave: ");

            scanf("%s", palavra_chave);
                                       //Aqui começa a conversão de caracteres maiúsculos para minúsculos, inclusive da chave de cifração.
            while(texto_fonte[i])
                 {
                   if(texto_fonte[i] >= 65 && texto_fonte[i] <= 90)

                      texto_fonte[i] += 32;

                   i++;
                 }

            while(palavra_chave[j])
                 {
                   if(palavra_chave[j] >= 65 && palavra_chave[j] <= 90)

                      palavra_chave[j] += 32;

                   j++;
                 }

            i = j = 0;
                                                     //Aqui termina a conversão de caracteres maiúsculos para minúsculos.
                                        //Aqui começa a cifração do texto sem levar em consideração caracteres fora da faixa de a à z.
            while(texto_fonte[i])
                 {
                   if(texto_fonte[i] >= 97 && texto_fonte[i] <= 122)
                      {
                        texto_cifrado[i] = tabua_cifra[texto_fonte[i] - 97][palavra_chave[j] - 97];

                        j++;

                        if(palavra_chave[j] == '\0')

                            j = 0;
                      }

                   else

                       texto_cifrado[i] = texto_fonte[i];

                   i++;
                 }

              texto_cifrado[i] = '\0';
                                        //Aqui termina a cifração do texto sem levar em consideração caracteres fora da faixa de a à z.
              printf("O texto cifrado \x82:\n");

              printf("%s\n", texto_cifrado);
          }
//-----------------------------------------------------------------------------------------------------------------------------
void Decifra(char *texto_cifrado, char *palavra_chave, char *texto_decifrado)
            {
              int i = 0, j = 0, c = 0, linha;
                                 //Aqui começa a conversão de caracteres maiúsculos para minúsculos, inclusive da chave de cifração.
              while(texto_cifrado[i])
                 {
                   if(texto_cifrado[i] >= 65 && texto_cifrado[i] <= 90)

                      texto_cifrado[i] += 32;

                   i++;
                 }

              i = 0;

              while(palavra_chave[j])
                 {
                   if(palavra_chave[j] >= 65 && palavra_chave[j] <= 90)

                      palavra_chave[j] += 32;

                   j++;
                 }

              j = 0;
                          //Aqui termina a conversão de caracteres maiúsculos para minúsculos.
                                        //Aqui o texto começa a ser decifrado.
              while(texto_cifrado[i])
                  {
                    if(texto_cifrado[i] >= 97 && texto_cifrado[i] <= 122)
                      {
                        linha = palavra_chave[j] - 97;

                        while(tabua_cifra[linha][c] != texto_cifrado[i])

                               c++;

                        texto_decifrado[i] = tabua_cifra[0][c];

                        c = 0;

                        j++;

                         if(palavra_chave[j] == '\0')

                             j = 0;
                      }

                    else

                        texto_decifrado[i] = texto_cifrado[i];

                    i++;
                  }
                                                           //Aqui o texto termina de ser decifrado.
                    texto_decifrado[i] = '\0';

                    printf("O texto decifrado \x82:\n");

                    printf("%s", texto_decifrado);
            }
//-----------------------------------------------------------------------------------------------------------------------------
void Ataque(char *texto_cifrado, char *texto_decifrado)
           {
             int especula_chave[31] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, tam_prov_chave[3][3] = {{},{-10, -10, -10}}, tamanho_chave = 2, tamanho_real_chave , aux = 0, i = 0, j = 0, portugues = 0, ingles = 0;
             char vetor_aux[10000], chave[31];
             double frequencia_portugues[26] = {14.63, 1.04, 3.88, 4.99, 12.57, 1.02, 1.30, 1.28, 6.18, 0.40, 0.02, 2.78, 4.74, 5.05, 10.73, 2.52, 1.20, 6.53, 7.81, 4.34, 4.63, 1.67, 0.01, 0.21, 0.01, 0.47};
             double frequencia_ingles[26] = {8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.966, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987, 6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074};

             printf("Digite o texto a ser atacado:\n");

             fgets(texto_cifrado, 10000, stdin);

             system("cls");
                                          //Aqui começa a conversão de caracteres maiúsculos para minúsculos.
             while(texto_cifrado[i])
                  {
                    if(texto_cifrado[i] >= 65 && texto_cifrado[i] <= 90)

                       texto_cifrado[i] += 32;

                    i++;
                  }

            i = 0;
                                         //Aqui termina a conversão de caracteres maiúsculos para minúsculos.
                                         //Aqui começa o preenchimento de um vetor auxiliar apenas com caracteres na faixa de a à z.
            while(texto_cifrado[i] != '\0')
                 {
                   if(texto_cifrado[i] >= 97 && texto_cifrado[i] <= 122)
                     {
                       vetor_aux[j] = texto_cifrado[i];

                       i++;

                       j++;
                     }

                   else

                       i++;
                 }

             vetor_aux[j] = '\0';
                                         //Aqui termina o preenchimento de um vetor auxiliar apenas com caracteres na faixa de a à z.
             i = 0;

             j = 0;

             while (vetor_aux[aux] != '\0')

                    aux++;
                                        //Aqui começa o a procura das trincas de letras repetidas para a especulação dos possíveis tamanhos de chaves.
             while(i <= (aux - 6))
                  {
                    j = i + 3;

                    while((vetor_aux[i] != vetor_aux[j] || vetor_aux[i + 1] != vetor_aux[j + 1] || vetor_aux[i + 2] != vetor_aux[j + 2]) && j <= (aux - 3))

                           j++;

                           if(j <= (aux - 3))
                             {
                               int espacamento = j - i;

                               while(tamanho_chave < 31)
                                    {
                                      int acha_divisores = espacamento % tamanho_chave;

                                      if(acha_divisores == 0)

                                          especula_chave[tamanho_chave] += 1;

                                          tamanho_chave++;
                                    }

                               tamanho_chave = 2;

                             }
                    i++;

                  }
                                         //Aqui termina o a procura das trincas de letras repetidas para a especulação dos possíveis tamanhos de chaves.
                                         //Aqui começa do código para determinar quais os três valores de tamanho de chaves mais prováveis.
                j = 0;

                while(j++ <= 30)
                     {
                       if(especula_chave[j] >= tam_prov_chave[1][0])
                         {
                           tam_prov_chave[1][2] = tam_prov_chave[1][1];
                           tam_prov_chave[0][2] = tam_prov_chave[0][1];

                           tam_prov_chave[1][1] = tam_prov_chave[1][0];
                           tam_prov_chave[0][1] = tam_prov_chave[0][0];

                           tam_prov_chave[1][0] = especula_chave[j];
                           tam_prov_chave[0][0] = j;
                         }

                       else if(especula_chave[j] >= tam_prov_chave[1][1])
                              {
                                tam_prov_chave[1][2] = tam_prov_chave[1][1];
                                tam_prov_chave[0][2] = tam_prov_chave[0][1];

                                tam_prov_chave[1][1] = especula_chave[j];
                                tam_prov_chave[0][1] = j;
                              }

                       else if(especula_chave[j] >= tam_prov_chave[1][2])
                           {
                             tam_prov_chave[1][2] = especula_chave[j];
                             tam_prov_chave[0][2] = j;
                           }
                     }

                   tamanho_real_chave = tam_prov_chave[0][0];

                   i = 1;

                   while(i <= 2)
                      {
                        int compara = tam_prov_chave[0][i] % tam_prov_chave[0][0];

                        if( compara == 0)

                             tamanho_real_chave = tam_prov_chave[0][i];

                        i++;
                       }
                //Aqui termina do código para determinar quais os três valores de tamanho de chaves mais prováveis, escolhendo-se o mais conveniente deles.

                    double vetor_idioma[tamanho_real_chave][26];

                  //Aqui começa a análise do texto cifrado para inferir em qual idioma o texto original foi escrito.
                  portugues = 0;

                  ingles = 0;

                  int m;

                  int k;

                  int controle;

                  double menor_portugues;

                  double menor_ingles;

                  for(i = 0; i < tamanho_real_chave; i++)
                       {
                         int k = 0;

                         while(k < 26)
                              {
                                vetor_idioma[i][k] = 0;

                                k++;
                              }

                         double soma_portugues = 0;

                         double soma_ingles = 0;

                         j = i;

                         int qtd_caracteres = 0;

                         while(j < aux)
                              {
                                vetor_idioma[i][vetor_aux[j] - 97] += 1;

                                qtd_caracteres++;

                                j += tamanho_real_chave;
                              }

                         j = 0;

                         while(j < 26)
                              {
                                vetor_idioma[i][j] = (vetor_idioma[i][j] / qtd_caracteres) * 100;

                                j++;
                              }
                       }

                   i = 0;

                  while(i < tamanho_real_chave)
                       {
                         j = 0;

                         double casamento_portugues = 100;

                         double casamento_ingles = 100;

                         while(j < 26)
                              {
                                double encontra_padrao_portugues = 0;

                                double encontra_padrao_ingles = 0;

                                k = j;

                                m = 0;

                                while(m < 26)
                                     {
                                       controle = k % 26;

                                       menor_portugues = vetor_idioma[i][controle] - frequencia_portugues[m];

                                       menor_ingles = vetor_idioma[i][controle] - frequencia_ingles[m];

                                       if(menor_portugues < 0)

                                           menor_portugues = menor_portugues * (-1);

                                       if(menor_ingles < 0)

                                           menor_ingles = menor_ingles * (-1);

                                       encontra_padrao_portugues += menor_portugues;

                                       encontra_padrao_ingles += menor_ingles;

                                       m++;

                                       k++;
                                     }

                                if(encontra_padrao_portugues < casamento_portugues)

                                    casamento_portugues = encontra_padrao_portugues;

                                if(encontra_padrao_ingles < casamento_ingles)

                                    casamento_ingles = encontra_padrao_ingles;

                                j++;

                              }

                           if(casamento_portugues < casamento_ingles)

                               portugues++;

                           if(casamento_ingles < casamento_portugues)

                               ingles++;

                           i++;
                       }

               //Aqui termina a análise do texto cifrado para inferir em qual idioma o texto original foi escrito.
              // aqui começa o processo de descoberta da palavra chave baseada em qual idioma o texto original foi escrito.
              if(portugues > ingles)
                {
                  i = 0;

                  int m;

                  int k;

                  int controle;

                  double menor;

                  int posicao_certa;

                  while(i < tamanho_real_chave)
                       {
                         j = 0;

                         double casamento = 100;

                         while(j < 26)
                              {
                                double encontra_padrao = 0;

                                k = j;

                                m = 0;

                                while(m < 26)
                                     {
                                       controle = k % 26;

                                       menor = vetor_idioma[i][controle] - frequencia_portugues[m];

                                       if(menor < 0)

                                           menor = menor * (-1);

                                       encontra_padrao += menor;

                                       m++;

                                       k++;
                                     }

                                if(encontra_padrao < casamento)
                                  {
                                    casamento = encontra_padrao;

                                    posicao_certa = j;
                                  }

                                j++;

                              }

                           chave[i] = 97 + posicao_certa;

                           i++;
                       }

                   chave[i] = '\0';

                }

              if(ingles > portugues)
                {
                  i = 0;

                  int m;

                  int k;

                  int controle;

                  double menor;

                  int posicao_certa;

                  while(i < tamanho_real_chave)
                       {
                         j = 0;

                         double casamento = 100;

                         while(j < 26)
                              {
                                double encontra_padrao = 0;

                                k = j;

                                m = 0;

                                while(m < 26)
                                     {
                                       controle = k % 26;

                                       menor = vetor_idioma[i][controle] - frequencia_ingles[m];

                                       if(menor < 0)

                                           menor = menor * (-1);

                                       encontra_padrao += menor;

                                       m++;

                                       k++;
                                     }

                                if(encontra_padrao < casamento)
                                  {
                                    casamento = encontra_padrao;

                                    posicao_certa = j;
                                  }

                                j++;

                              }

                           chave[i] = 97 + posicao_certa;

                           i++;
                       }

                   chave[i] = '\0';

                }
                    // aqui termina o processo de descoberta da palavra chave baseada em qual idioma o texto original foi escrito.

                  printf("A chave \x82: %s\n\n", chave);

                  Decifra(texto_cifrado, chave, texto_decifrado);
           }
//-----------------------------------------------------------------------------------------------------------------------------
void main(void){

int opcao;
char palavra_chave[30], texto_fonte[10000], texto_cifrado[10000], texto_decifrado[10000];

Preenche_tabua(tabua_cifra);

do{
    opcao = menu();

    if(opcao == 1)
      {
        fflush(stdin);

        Cifra(texto_fonte, palavra_chave, texto_cifrado);
      }

    if(opcao == 2)
      {
        fflush(stdin);

        printf("Digite o texto a ser decifrado:\n");

        fgets(texto_cifrado, 10000, stdin);

        printf("Digite a palavra chave: ");

        scanf("%s", palavra_chave);

        Decifra(texto_cifrado, palavra_chave, texto_decifrado);
      }

    if(opcao == 3)
      {
        fflush(stdin);

        Ataque(texto_cifrado, texto_decifrado);
      }

  }while(opcao != 4);
}
