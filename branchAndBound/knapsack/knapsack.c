
/*
   As seguintes funções, descritas no enunciado do trabalho, devem ser implementadas:
  
    - greedyFractionalKnapsack: Algoritmo Guloso para o Problema da Mochila Fracionária
    - dynamicProgrammingBinaryKnapsack: Algoritmo de Programação Dinâmica para o Problema da Mochila Binária
    - branchAndBoundBinaryKnapsack: Algoritmo Branch and Bound para o Problema da Mochila Binária

   Todas estas funções recebem uma instância do Problema da Mochila (Binária ou Fracionária)
   cujos dados são armazenados na estrutura de dados definida pelo tipo KnapsackInstance (veja o arquivo knapsack.h).
   O atribuito n desta estrutura corresponde a quantidade de itens disponíveis para se colocar
   na mochila. O peso e custo de cada item são armazenados no atributo items (vetor de n posições do tipo KnapsackItem).
   A capacidade da mochila é definida pelo valor do atributo capacity.
  
   Além da instância, estes métodos também recebem um vetor de n números de ponto flutuante (double)
   onde deve ser armazenada a solução ótima computada. O valor na posição 0 <= i <= (n-1) do vetor solution
   deve ser a fração (0.0 ou 1.0 caso seja o Problema da Mochila Binária) do item na posição i do vetor instance->items
   que será colocada na mochila.
  
   O valor retornado pelos métodos deve ser o custo ótimo da solução encontrada.
  
   ATENÇÃO: Não altere os dados da instância pois a mesma é utilizada pelos três métodos!
*/

#include "knapsack.h"

using namespace std;

static int comp2 ( const void *a, const void *b )
{
    return ( ((FKP*)a)->density - ((FKP*)b)->density < EPS );
}

bool nodeComp ( const node a, const node b )
{
    return ( a.Z < b.Z );
}

double greedyFractionalKnapsack(const KnapsackInstance *instance, double *solution)
{
   double solutionCost = 0;
   int n = instance->n;

   /* Implemente aqui o método guloso
      para o Problema da Mochila Fracionária */

   //double* den = (double*) alloca ( sizeof (double) * instance->n );
   FKP* bag = (FKP*) alloca ( sizeof (FKP) * instance->n );

   for ( int i = 0; i < instance->n; i++ )
   {
     //  den[i] = (double)(instance->items[i].cost)/instance->items[i].weight;
       bag[i].density = (double)(instance->items[i].cost)/instance->items[i].weight;
       bag[i].number = i;
   }

   /*
   for ( int i = 0; i < instance->n; i++ )
   {
       printf ( "%lf ", bag[i].density );
   }
   printf ( "\n" );
   */

//   qsort ( den, n, sizeof (double), comp );
   qsort ( bag, n, sizeof (FKP), comp2 );

   /*
   for ( int i = 0; i < instance->n; i++ )
   {
       //printf ( "%lf ", den[i] );
       printf ( "%lf ", bag[i].density );
   }
   printf ( "\n" );
   */

   int i =0;
   int j;
   double c, w;
   double W = instance->capacity;
   double Wb;
   double sum =0;
   while ( W > EPS )
   {
       j = bag[i].number;
       w = instance->items[j].weight;
       c = instance->items[j].cost;

       Wb = MIN ( (double)W/w, 1 );
       sum += Wb*w;
       solution[j] = Wb;
       solutionCost += Wb*c;
       W -= Wb*w;
       i++;
   }
   /*
   for ( int i = 0; i < instance->n; i++ )
   {
       //printf ( "%lf ", den[i] );
       printf ( "%lf ", solution [i] );
   }
   printf ( "\n" );
   printf ( "%lf W:%d  sum: %lf\n", solutionCost, instance->capacity, sum );
         */  
   
   return solutionCost;
}

double dynamicProgrammingBinaryKnapsack(const KnapsackInstance *instance, double *solution)
{
   double solutionCost = 0;

   /* Implemente aqui o método de programação dinâmica
      para o Problema da Mochila Binária */
   
   int n = instance->n;
   int W = instance->capacity;

   int* c= (int* ) malloc ( sizeof(int) * (n+1) );
   int* w = (int *) malloc ( sizeof (int) * (n+1) );
   int** z = (int** ) malloc ( sizeof (int*) * (n+1) );

   for ( int i =0; i <= n; i++ )
   {
      z[i] = (int *) malloc ( sizeof (int) * (W+1) );
   }
   for ( int i =1; i <= n; i++ )
   {
      w[i] = instance->items[i-1].weight;
      c[i] = instance->items[i-1].cost;
   }

   /*
   for ( int i =1; i <= n; i++ )
   {
       printf ( "%d|%d ", w[i], c[i] );
   }
   printf ( "\n" );
   */

   for ( int i =0; i <= W; i++ )
   {
       z[0][i] = 0;
   }

   for ( int i = 1; i <= n; i++ )
   {
       z[i][0] = 0;
   }

   for ( int k = 1; k <= n; k++ )
   {
       for ( int d = 1; d <= W; d++ )
       {
           z[k][d] = z[k-1][d];
           if ( w [k] <= d )
           {
               if ( (z [k-1] [ d - w[k] ] + c [k]) > z[k][d] )
               {
                   z[k][d] = c[k] + z[k-1][d-w[k]];
               }
           }
       }
   }

   for ( int i = 0; i < n; i++ )
   {
       solution [i] = 0;
   }

   int k = n;
   int d = W;
   while ( k != 0 )
   {
       if ( z[k][d] == z[k-1][d] )
       {
           solution[k-1] = 0;
       }
       else
       {
           d -= w[k];
           solution[k-1] = 1;
       }
       k--;
   }

   solutionCost = z[n][W];
   
   for ( int i =0; i <= n; i++ )
   {
       free ( z[i] );
   }

   free (c);
   free (w);
   free (z);
   
   return solutionCost;
}

node createNode ( const KnapsackInstance *instance, int k, bool add, 
                    double* solution, int partialCap, int* partialSel )
{
    node No;
    No.freed = false;
    No.Z = 0;
    No.cost = 0;
    No.k = k;

    No.selected = (int* ) malloc ( sizeof ( int ) * instance->n );
    No.myInstance = (KnapsackInstance* ) malloc ( sizeof (KnapsackInstance) );
    No.myInstance->items = (KnapsackItem*)malloc((instance->n)*sizeof(KnapsackItem));
    No.myInstance->capacity = partialCap;
    No.myInstance->n = instance->n;

    memcpy ( No.selected, partialSel, sizeof( int ) * instance->n );
    memcpy ( No.myInstance->items, instance->items, sizeof( KnapsackItem) *instance->n );

    No.myInstance->items[k].weight = INT_MAX;
    
    // Se k participa da solução
    if ( add )
    {
        //No.Z += instance->items[k].cost;
        No.myInstance->capacity -= instance->items[k].weight;

        if ( No.myInstance->capacity < 0 )
        {
            free ( No.selected );
            free ( No.myInstance->items );
            free ( No.myInstance );
            No.freed = true;
            return No;
        }

        No.selected[k] = 1;
    }
    else
    {
        No.selected[k] = 0;
    }

    // Adicionando custos dos elementos já selecionados
    for ( int i = 0; i <= k; i++ )
    {
        if ( No.selected [i] )
        {
            No.cost += instance->items[i].cost;
            No.Z += instance->items[i].cost;
        }
        else
        {
            No.myInstance->items[i].weight = INT_MAX;
        }
    }

    // Estimando melhor valor para solução
    No.Z += greedyFractionalKnapsack ( No.myInstance, solution );

    return No;
}

void freeNode ( node no )
{
    if ( no.freed == false )
    {
        free ( no.selected );
        free ( no.myInstance->items );
        free ( no.myInstance );
        no.freed = true;
    }
}

double branchAndBoundBinaryKnapsack(const KnapsackInstance *instance, double *solution)
{
   double solutionCost = 0;
   int n = instance->n;
   int best = -1;

   vector < node > nosAtivos;

   int* initialSel = (int* ) malloc ( n * sizeof ( int ) );

   for ( int i = 0; i < n; i++ )
   {
       initialSel[i] = 0;
   }

   /* Implemente aqui o método de branch and bound
      para o Problema da Mochila Binária */

   node firstLeft = createNode ( instance, 0, true, solution, instance->capacity, initialSel );
   node firstRight = createNode ( instance, 0, false, solution, instance->capacity, initialSel  );

   free ( initialSel );
   /*
   printf ( "\nSelectedLeft: " );
   for ( int i = 0; i < 5; i++ )
   {
       printf ( "%d ", firstLeft.selected [i] );
   }
   printf ( "\t--- Z = %lf\tcost = %d \n", firstLeft.Z, firstLeft.cost );

   printf ( "\nSelectedRight: " );
   for ( int i = 0; i < 5; i++ )
   {
       printf ( "%d ", firstRight.selected [i] );
   }
   printf ( "\t--- Z = %lf\tcost = %d \n", firstRight.Z, firstRight.cost );

   printf ( "Lcap: %d\tRcap: %d\n", firstLeft.myInstance->capacity,
                                firstRight.myInstance->capacity );
                                */

   nosAtivos.push_back( firstLeft );
   nosAtivos.push_back( firstRight );

   make_heap ( nosAtivos.begin(), nosAtivos.end(), nodeComp );

   // Enquanto a fila de nos ativos não está vazia
   while ( nosAtivos.size() )
   {
       // Best Bound: escolher nó com melhor estimativa
       pop_heap ( nosAtivos.begin(), nosAtivos.end(), nodeComp );
       node atual = nosAtivos.back ();
       nosAtivos.pop_back ();

       // Achando a melhor solução até agora
       best = MAX ( best, atual.cost );

       /*
       printf ( "\nSelected (%d): ", atual.k );
       for ( int i = 0; i < 5; i++ )
       {
           printf ( "%d ", atual.selected [i] );
       }
       printf ( "\t--- Z = %lf\tcost = %d \n", atual.Z, atual.cost );
       */

       // Se o nó atual já é uma solução ótima, retornar
       if ( atual.k == n - 1 )
       {
           //printf ( "Melhor solução encontrada!! = %d\n", atual.cost );
           for ( int i = 0; i < n; i++ )
           {
               solution[i] = atual.selected[i];
           }

           solutionCost = atual.cost;
           freeNode ( atual );
           break;
       }
       // Gerando filhos do nó atual
       node left = createNode ( atual.myInstance, atual.k+1, true, solution, atual.myInstance->capacity, atual.selected );
       node right = createNode ( atual.myInstance, atual.k+1, false, solution, atual.myInstance->capacity, atual.selected );


       /*
         printf ( "Lcap: %d\tRcap: %d\n", left.myInstance->capacity,
                                right.myInstance->capacity );
                                */


       // Amadurecendo filhos caso haja invalidez ou via limitante
       if ( left.myInstance->capacity >= 0 || left.Z > best )
       {
           nosAtivos.push_back( left );
           push_heap ( nosAtivos.begin(), nosAtivos.end(), nodeComp );
       }
       if ( right.myInstance->capacity >= 0 || right.Z > best  )
       {
           nosAtivos.push_back( right );
           push_heap ( nosAtivos.begin(), nosAtivos.end(), nodeComp );
       }

       freeNode ( atual );
   }
   
   /*
   for ( unsigned int i = 0; i < nosAtivos.size(); i++ )
   {
       freeNode ( nosAtivos[i] );
       printf ( "%u of %u freed!\n", i, nosAtivos.size() );
   }

   printf ( "freed!\n" );
   */
   return solutionCost;
}

