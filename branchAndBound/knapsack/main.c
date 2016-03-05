/*
  Utilize este modelo para simplificar seu trabalho. Não é necessário
  modificar a função main(). São fornecidas a leitura das instâncias,
  a medição do tempo e a saída dos resultados no formato especificado.
  Apenas implemente os algoritmos pedidos no enunciado nas funções
  especificadas no arquivo knapsack.c.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "knapsack.h"

KnapsackInstance* readInstance(const char *filename)
{
   int i;
   FILE *fp;

   KnapsackInstance *instance = (KnapsackInstance*)malloc(sizeof(KnapsackInstance));

   fp = fopen(filename, "r");

   if(!fp)
   {
      fprintf(stdout, "Nao foi possivel abrir o arquivo de entrada.\n");
      exit(0);
   }
   
   fscanf(fp, "%d", &(instance->n));
   fscanf(fp, "%d", &(instance->capacity));
   
   instance->items = (KnapsackItem*)malloc((instance->n)*sizeof(KnapsackItem));
   
   for (i = 0; i < instance->n; i++)
   {
      fscanf(fp, "%d", &(instance->items[i].weight));
      fscanf(fp, "%d", &(instance->items[i].cost));
   }
   
   fclose(fp);

   return instance;
}

void verifyAndPrintSolution(const KnapsackInstance *instance, double *solution, double solutionCost, int checkBinary)
{
   double cost, weight;
   int i;

   for (i = 0; i < instance->n; i++)
      if ((solution[i] < -1e-3) || (solution[i] > 1.0+1e-3))
      {
         fprintf(stdout, "Incorrect solution: domain violation!\n");         
         return;
      }


   if (checkBinary)
      for (i = 0; i < instance->n; i++)
         if ((fabs(solution[i]) > 1e-3) && (fabs(solution[i] - 1.0) > 1e-3))
         {
	        fprintf(stdout, "Incorrect solution: fractional solution!\n");         
            return;
         }

   cost = 0.0;
   weight = 0.0;
   
   for (i = 0; i < instance->n; i++)
   {
      weight += solution[i] * instance->items[i].weight;
      cost += solution[i] * instance->items[i].cost;
   }
   
   if (weight > instance->capacity + 1e-3)
      fprintf(stdout, "Incorrect solution: weight exceeded!\n");
   else if (fabs(cost - solutionCost) > 1e-3)
      fprintf(stdout, "Incorrect solution: wrong cost!\n");
   else
   {
      fprintf(stdout, "Solution weight: %.2f\n", weight);      
      fprintf(stdout, "Solution cost: %.2f\n", solutionCost);      
   }
}

int main(int argc, char **argv)
{
   KnapsackInstance *instance;
   double *solution, solutionCost;
   int i;
   clock_t time;

   if(argc != 2)
   {
      fprintf(stdout, "Uso: %s <instancia>\n", argv[0]);
      return 0;
   }

   instance = readInstance(argv[1]);

   solution = (double*)malloc(instance->n*sizeof(double));

   fprintf(stdout, "\n");      

   // Greedy Fractional Knapsack

   for (i = 0; i < instance->n; i++)
      solution[i] = 0.0;

   time = clock();

   solutionCost = greedyFractionalKnapsack(instance, solution);

   fprintf(stdout, "Greedy Fractional Knapsack\n");      

   verifyAndPrintSolution(instance, solution, solutionCost, 0);

   fprintf(stdout, "Running time: %.2f\n\n", ((clock() - time) / (float)CLOCKS_PER_SEC));

   // Dynamic Programming Binary Knapsack

   for (i = 0; i < instance->n; i++)
      solution[i] = 0.0;

   time = clock();

   solutionCost = dynamicProgrammingBinaryKnapsack(instance, solution);

   fprintf(stdout, "Dynamic Programming Binary Knapsack\n");      

   verifyAndPrintSolution(instance, solution, solutionCost, 1);

   fprintf(stdout, "Running time: %.2f\n\n", ((clock() - time) / (float)CLOCKS_PER_SEC));

   // Branch And Bound Binary Knapsack

   for (i = 0; i < instance->n; i++)
      solution[i] = 0.0;

   time = clock();

   solutionCost = branchAndBoundBinaryKnapsack(instance, solution);

   fprintf(stdout, "Branch and Bound Binary Knapsack\n");      

   verifyAndPrintSolution(instance, solution, solutionCost, 1);

   fprintf(stdout, "Running time: %.2f\n\n", ((clock() - time) / (float)CLOCKS_PER_SEC));

   free(instance->items);
   free(instance);
   free(solution);

   return 0;
}


